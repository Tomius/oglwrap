/** @file animationMesh.hpp
    @brief An animation loader using assimp
*/

#pragma once

#include "mesh.hpp"

namespace oglwrap {

// Conversion between oglplus and glm matrices
static inline glm::mat4 convertMatrix(const aiMatrix4x4& m) {
    return glm::transpose(glm::make_mat4(&m.a1));
}

static inline glm::mat4 convertMatrix(const aiMatrix3x3& m) {
    return glm::mat4(glm::transpose(glm::make_mat3(&m.a1)));
}

static inline aiMatrix4x4 convertMatrix(const glm::mat4& m) {
    return aiMatrix4x4 {
        m[0][0], m[1][0], m[2][0], m[3][0],
        m[0][1], m[1][1], m[2][1], m[3][1],
        m[0][2], m[1][2], m[2][2], m[3][2],
        m[0][3], m[1][3], m[2][3], m[3][3]
    };
}

static inline bool isIdentity(const glm::mat4& m) {
    glm::mat4 identity;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(fabs(identity[i][j] - m[i][j]) > 1e-5)
                return false;
        }
    }
    return true;
}

static inline std::ostream& operator<<(std::ostream& os, const glm::vec3& v) {
    os << v.x << ", " << v.y << ", " << v.z;
    return os;
}

template <unsigned char numBoneAttribs = 1>
/// A class for loading and displaying nearly any kind of animated mesh.
/** Usage: specify the numBoneAttribs to be the maximum of bone influences per
  * vertex divided by four, counted up. You should specify the skinned mesh's
  * filename in the constructor, and add it's animations manually, with the
  * AddAnimation function. It is recommended to only export the animated bones
  * to these files. Currently it does not support multiple animation per file,
  * as I'm unable to export that way from either Blender or Maya or 3Ds max,
  * but if you can do it, please send me mail, and I'll implement it. */
class AnimatedMesh : public Mesh {
    template<class Index_t>
    struct VertexBoneData_PerAttribute {
        Index_t ids[4];
        float weights[4];

        VertexBoneData_PerAttribute() {
            memset(ids, 0, sizeof(ids));
            memset(weights, 0, sizeof(weights));
        };
    };

    template<class Index_t>
    struct VertexBoneData {
        VertexBoneData_PerAttribute<Index_t> data[numBoneAttribs];

        void AddBoneData(Index_t boneID, float weight) {
            for(int i = 0; i < numBoneAttribs; i++) {
                for(int j = 0; j < 4; j++) {
                    if(data[i].weights[j] < 1e-10) { // if equals 0
                        data[i].ids[j] = boneID;
                        data[i].weights[j] = weight;
                        return;
                    }
                }
            }

            // If there wasn't enough space to "allocate" a new slot for the bone:
            // replace the bone with the smallest influence
            size_t minMajorIndex = 0, minMinorIndex = 0;
            for(int i = 0; i < numBoneAttribs; i++) {
                for(int j = 0; j < 4; j++) {
                    if(data[i].weights[j] < data[minMajorIndex].weights[minMinorIndex]){
                        minMajorIndex = i;
                        minMinorIndex = j;
                    }
                }
            }

            data[minMajorIndex].ids[minMinorIndex] = boneID;
            data[minMajorIndex].weights[minMinorIndex] = weight;
        }
    };

    struct BoneInfo {
        glm::mat4 boneOffset;
        glm::mat4 finalTransformation;
    };

    std::vector<ArrayBuffer> boneBuffers;
    std::vector<BoneInfo> boneInfo;
    std::map<std::string, unsigned> boneMapping; // maps a bone name to its index

    size_t numBones;
    glm::mat4 globalInverseTransform;

    // vector::push_back(Assimp::Importer()) wouldn't work, because it has
    // a weird copy constructor, that doesn't actually copy. It must be dynamic.
    std::vector<Assimp::Importer*> animationImporters;
    std::vector<const aiScene*> animations;
    std::map<std::string, size_t> animNames; // maps user defined animation names to indexes.


    const aiScene *lastAnim, *currentAnim;
    float endOfLastAnim, transitionTime, lastPeriodTime;

    size_t currIdx, lastIdx;
    std::vector<glm::vec3> startOffsets;
    std::vector<glm::vec3> endOffsets;

    glm::vec3 lastOffset, currentOffset, lastTransitionOffset;
    unsigned lastLoopCount;

    std::string rootBone;

public:
    AnimatedMesh(const std::string& filename, unsigned int flags)
        : Mesh(filename, flags)
        , boneBuffers(scene->mNumMeshes)
        , numBones(0)
        , lastAnim(nullptr)
        , currentAnim(nullptr)
        , endOfLastAnim(0)
        , transitionTime(0)
        , lastPeriodTime(0)
        , currIdx(0)
        , lastIdx(0)
        , lastLoopCount(0) {

        glm::mat4 matrix = convertMatrix(scene->mRootNode->mTransformation);
        globalInverseTransform = glm::inverse(matrix);

        if(numBoneAttribs != getRecommendedNumBoneAttribs())
            std::cerr << "Error in AnimatedMesh '" << filename << "'\n" <<
            "The class was created with " << (int)numBoneAttribs << " bone "
            "attribute(s), but the mesh needs " << (int)getRecommendedNumBoneAttribs() <<
            " bone attribute(s) to do its best." << std::endl;

    }

    ~AnimatedMesh() {
        for(auto i = animationImporters.begin(); i != animationImporters.end(); i++)
            delete *i;
    }

private:
    // It shouldn't be copyable
    AnimatedMesh(const AnimatedMesh& src);
    void operator=(const AnimatedMesh& rhs);

public:
    unsigned char getNumBoneAttribs() {
        return numBoneAttribs;
    }

    void addAnimation(const std::string& filename, const std::string& animName) {
        if(animNames.find(animName) != animNames.end()){
            std::string err = "Animation name '" + animName + "' isn't unique for '" + filename + "'";
            throw std::runtime_error(err);
        }
        size_t idx = animations.size();
        animNames[animName] = idx;
        animationImporters.push_back(new Assimp::Importer());
        animations.push_back(animationImporters[idx]->ReadFile(filename, aiProcess_Debone));

        if(!animations[idx]) {
            throw std::runtime_error("Error parsing " + filename
                + " : " + animationImporters[idx]->GetErrorString());
        }

        auto node = getRootBone(scene->mRootNode, animations[idx]);
        if(!node) {
            throw std::runtime_error(
                "Animation error: The mesh's skeleton, and the animated skeleton '" +
                animName + "' doesn't have a single bone in common.");
        }

        aiVector3D v = node->mPositionKeys[0].mValue;
        startOffsets.push_back(glm::vec3(v.x, v.y, v.z));
        v = node->mPositionKeys[node->mNumPositionKeys - 1].mValue;
        endOffsets.push_back(glm::vec3(v.x, v.y, v.z));
    }

    void setCurrentAnimation(const std::string& animName, float currentTime, float transitionTime = 0.0f) {
        if(animNames.find(animName) == animNames.end()) {
            throw std::invalid_argument(
                "Tried to set current animation to '" + animName + "', "
                "but the AnimatedMesh doesn't have an animation with name"
            );
        }

        setCurrentAnimation(animNames[animName], currentTime, transitionTime);
    }

    void setCurrentAnimation(size_t animIndex, float currentTime, float transitionTime = 0.0f) {
        size_t tempLastIdx = currIdx;
        currIdx = animIndex;

        auto nextanim = animations[currIdx];
        if(currentAnim == nextanim || (endOfLastAnim + this->transitionTime) > currentTime)
            return;
        lastIdx = tempLastIdx;
        lastAnim = currentAnim;
        currentAnim = nextanim;
        this->transitionTime = transitionTime;
        lastPeriodTime = currentTime - endOfLastAnim;
        lastTransitionOffset = glm::vec3();
        endOfLastAnim = currentTime;
        if(lastAnim)
            lastOffset = startOffsets[currIdx];
        else
            lastAnim = currentAnim;
        currentOffset = startOffsets[currIdx];
    }

    glm::vec3 offsetSinceLastFrame() {
        auto ret = currentOffset - lastOffset;
        lastOffset = currentOffset;
        ret.y = 0; // FIXME
        return ret;
    }

/*         //=====:==-==-==:=====\\                                 //=====:==-==-==:=====\\
    <---<}>==~=~=~==--==--==~=~=~==<{>----- Skin definition -----<}>==~=~=~==--==--==~=~=~==<{>--->
           \\=====:==-==-==:=====//                                 \\=====:==-==-==:=====//          */

private:
    void mapBones() {
        for(size_t entry = 0; entry < entries.size(); entry++) {
            const aiMesh* pMesh = scene->mMeshes[entry];

            for(unsigned i = 0; i < pMesh->mNumBones; i++) {
                std::string boneName(pMesh->mBones[i]->mName.data);
                size_t boneIndex = 0;

                // Search for this bone in the BoneMap
                if(boneMapping.find(boneName) == boneMapping.end()) {
                    // Allocate an index for the new bone
                    boneIndex = numBones++;
                    boneInfo.push_back(BoneInfo());
                    boneInfo[boneIndex].boneOffset = convertMatrix(pMesh->mBones[i]->mOffsetMatrix);
                    boneMapping[boneName] = boneIndex;
                }
            }
        }
    }

    const aiNodeAnim* getRootBone(const aiNode* pNode, const aiScene* anim) {
        std::string nodeName(pNode->mName.data);

        const aiAnimation* pAnimation = anim->mAnimations[0];
        const aiNodeAnim* pNodeAnim = findNodeAnim(pAnimation, nodeName);

        if(pNodeAnim) {
            if(rootBone.empty()) {
                rootBone = nodeName;
            } else {
                if(rootBone != nodeName) {
                    throw std::runtime_error(
                        "Animation error: the animated skeletons have different root bones."
                    );
                }
            }
            return pNodeAnim;
        }
        else {
            for(unsigned i = 0; i < pNode->mNumChildren; i++) {
                auto childsReturn = getRootBone(pNode->mChildren[i], anim);
                if(childsReturn)
                    return childsReturn;
            }
        }

        return nullptr;
    }

    template <class Index_t>
    void loadBones(DataType idx_t,
                   LazyVertexAttribArray boneIDs,
                   LazyVertexAttribArray boneWeights) {
        std::vector<std::vector<VertexBoneData<Index_t>>> bones(entries.size());

        for(size_t entry = 0; entry < entries.size(); entry++) {
            const aiMesh* pMesh = scene->mMeshes[entry];
            bones[entry].resize(pMesh->mNumVertices);

            // -------======{[ Create the bone ID's and weights data ]}======-------
            for(unsigned i = 0; i < pMesh->mNumBones; i++) {
                std::string boneName(pMesh->mBones[i]->mName.data);
                size_t boneIndex = boneMapping[boneName];

                for(unsigned j = 0; j < pMesh->mBones[i]->mNumWeights; j++) {
                    unsigned vertexID = pMesh->mBones[i]->mWeights[j].mVertexId;
                    float weight = pMesh->mBones[i]->mWeights[j].mWeight;
                    bones[entry][vertexID].AddBoneData(boneIndex, weight);
                }
            }

            // -------======{[ Upload the bone data ]}======-------
            for(int boneAttribSet = 0;
                boneAttribSet < std::min(getRecommendedNumBoneAttribs(), numBoneAttribs);
                boneAttribSet++
            ) {
                entries[entry].vao.bind();
                boneBuffers[entry].bind();
                boneBuffers[entry].data(bones[entry]);

                const size_t stride = sizeof(VertexBoneData<Index_t>);
                intptr_t baseOffset =
                    boneAttribSet * sizeof(VertexBoneData_PerAttribute<Index_t>);
                intptr_t weightOffset = baseOffset + 4 * sizeof(Index_t);

                boneIDs[boneAttribSet].setup(4, idx_t, stride, (const void*)baseOffset).enable();
                boneWeights[boneAttribSet].setup(4, DataType::Float, stride, (const void*)weightOffset).enable();
            }

            VertexArray::unbind();
        }

    }

public:

    /// Loads in bone weight and id information to the given array of attribute arrays.
    /** Uploads the bone weight and id to an array of attribute arrays, and sets it up for use.
      * For example if you specified "in vec4 boneIds[3]" you have to give "prog | boneIds"
      * Calling this function changes the currently active VAO and ArrayBuffer.
      * The mesh cannot be drawn without calling this function. */
    /// @param boneIDs - The array of attributes array to use as destination for bone IDs.
    /// @param boneWeights - The array of attributes array to use as destination for bone weights.
    void setup_bones(LazyVertexAttribArray boneIDs, LazyVertexAttribArray boneWeights) {
        mapBones();

        if(numBones < UCHAR_MAX)
            loadBones<unsigned char>(DataType::UnsignedByte, boneIDs, boneWeights);
        else if(numBones < USHRT_MAX)
            loadBones<unsigned short>(DataType::UnsignedShort, boneIDs, boneWeights);
        else // more than 65535 bones? WTF???
            loadBones<unsigned int>(DataType::UnsignedInt, boneIDs, boneWeights);
    }

/*         //=====:==-==-==:=====\\                           //=====:==-==-==:=====\\
    <---<}>==~=~=~==--==--==~=~=~==<{>----- Animation -----<}>==~=~=~==--==--==~=~=~==<{>--->
           \\=====:==-==-==:=====//                           \\=====:==-==-==:=====//          */

private:

    unsigned findPosition(float animationTime, const aiNodeAnim* pNodeAnim) {
        // Find the first one that is bigger or equals
        for(unsigned i = 0; i < pNodeAnim->mNumPositionKeys - 1; i++) {
            if(animationTime <= (float)pNodeAnim->mPositionKeys[i + 1].mTime) {
                return i;
            }
        }
        // Should never get here
        throw std::runtime_error("Animation Error - Position keyframe not found");
    }

    unsigned findRotation(float animationTime, const aiNodeAnim* pNodeAnim) {
        for(unsigned i = 0; i < pNodeAnim->mNumRotationKeys - 1; i++) {
            if(animationTime <= (float)pNodeAnim->mRotationKeys[i + 1].mTime) {
                return i;
            }
        }
        throw std::runtime_error("Animation Error - Rotation keyframe not found");
    }

    unsigned findScaling(float animationTime, const aiNodeAnim* pNodeAnim) {
        for(unsigned i = 0; i < pNodeAnim->mNumScalingKeys - 1; i++) {
            if(animationTime <= (float)pNodeAnim->mScalingKeys[i + 1].mTime) {
                return i;
            }
        }
        throw std::runtime_error("Animation Error - Scaling keyframe not found");
    }

    template<class T>
    T interpolate(const T& a, const T& b, float alpha) {
        return a + alpha * (b - a);
    }

    void calcInterpolatedPosition(aiVector3D& out, float animTime, const aiNodeAnim* pNodeAnim) {
        const auto& keys = pNodeAnim->mPositionKeys;
        const auto& numKeys = pNodeAnim->mNumPositionKeys;

        if(numKeys == 1) {
            out = keys[0].mValue;
            return;
        }

        size_t i = findPosition(animTime, pNodeAnim);
        float deltaTime = keys[i + 1].mTime - keys[i].mTime;
        float factor = (animTime - (float)keys[i].mTime) / deltaTime;
        if(factor < 0.0f)
            factor = 0.0f;
        if(factor > 1.0f)
            factor = 1.0f;

        const aiVector3D& start = keys[i].mValue;
        const aiVector3D& end   = keys[i + 1].mValue;
        out = interpolate(start, end, factor);
    }

    void calcInterpolatedRotation(aiQuaternion& out, float animTime, const aiNodeAnim* pNodeAnim) {
        const auto& keys = pNodeAnim->mRotationKeys;
        const auto& numKeys = pNodeAnim->mNumRotationKeys;

        if(numKeys == 1) {
            out = keys[0].mValue;
            return;
        }

        size_t i = findRotation(animTime, pNodeAnim);
        float deltaTime = keys[i + 1].mTime - keys[i].mTime;
        float factor = (animTime - (float)keys[i].mTime) / deltaTime;
        if(factor < 0.0f)
            factor = 0.0f;
        if(factor > 1.0f)
            factor = 1.0f;

        const aiQuaternion& start = keys[i].mValue;
        const aiQuaternion& end   = keys[i + 1].mValue;
        aiQuaternion::Interpolate(out, start, end, factor); // spherical interpolation
        out = out.Normalize();
    }

    void calcInterpolatedScaling(aiVector3D& out, float animTime, const aiNodeAnim* pNodeAnim) {
        const auto& keys = pNodeAnim->mScalingKeys;
        const auto& numKeys = pNodeAnim->mNumScalingKeys;

        if(numKeys == 1) {
            out = keys[0].mValue;
            return;
        }

        size_t i = findRotation(animTime, pNodeAnim);
        float deltaTime = keys[i + 1].mTime - keys[i].mTime;
        float factor = (animTime - (float)keys[i].mTime) / deltaTime;
        if(factor < 0.0f)
            factor = 0.0f;
        else if(factor > 1.0f)
            factor = 1.0f;

        const aiVector3D& start = keys[i].mValue;
        const aiVector3D& end   = keys[i + 1].mValue;
        out = interpolate(start, end, factor);
    }

    const aiNodeAnim* findNodeAnim(const aiAnimation* pAnimation, const std::string nodeName) {
        for(unsigned i = 0; i < pAnimation->mNumChannels; i++) {
            const aiNodeAnim* pNodeAnim = pAnimation->mChannels[i];

            if(std::string(pNodeAnim->mNodeName.data) == nodeName) {
                return pNodeAnim;
            }
        }

        return nullptr;
    }

    // Recursive function that travels through the entire node hierarchy
    void readNodeHeirarchy(float animationTime,
                           const aiNode* pNode,
                           const glm::mat4& parentTransform = glm::mat4(),
                           bool root = true) {
        using namespace glm;

        std::string nodeName(pNode->mName.data);

        // You probably want to be able to select different than animations than the 0th.
        // But with Maya's DAE_FBX exporter, it is not possible.
        const aiAnimation* pAnimation = currentAnim->mAnimations[0];
        const aiNodeAnim* pNodeAnim = findNodeAnim(pAnimation, nodeName);

        mat4 nodeTransform = convertMatrix(pNode->mTransformation);

        if(pNodeAnim) {
            // Interpolate the transformations and get the matrices
            aiVector3D scaling;
            calcInterpolatedScaling(scaling, animationTime, pNodeAnim);
            mat4 scalingM = scale(mat4(), vec3(scaling.x, scaling.y, scaling.z));

            aiQuaternion rotation;
            calcInterpolatedRotation(rotation, animationTime, pNodeAnim);
            mat4 rotationM = convertMatrix(rotation.GetMatrix());

            aiVector3D translation;
            calcInterpolatedPosition(translation, animationTime, pNodeAnim);
            mat4 translationM;

            if(nodeName == rootBone) {
                currentOffset = vec3(translation.x, 0, translation.z);
                translationM = translate(mat4(), vec3(0, translation.y, 0)); // FIXME!!
                root = false;
            } else {
                translationM = translate(mat4(), vec3(translation.x, translation.y, translation.z));
            }

            // Combine the transformations
            nodeTransform = translationM * rotationM * scalingM;
        }

        mat4 globalTransformation = parentTransform * nodeTransform;

        if(boneMapping.find(nodeName) != boneMapping.end()) {
            unsigned boneIndex = boneMapping[nodeName];
            boneInfo[boneIndex].finalTransformation =
                globalInverseTransform * globalTransformation * boneInfo[boneIndex].boneOffset;
        }

        for(unsigned i = 0; i < pNode->mNumChildren; i++) {
            readNodeHeirarchy(animationTime, pNode->mChildren[i], globalTransformation, root);
        }
    }

    // ReadNodeHierarchy for transitions between animations.
    void transitionReadNodeHeirarchy(float prevAnimationTime,
                                     float nextAnimationTime,
                                     const aiNode* pNode,
                                     const glm::mat4& parentTransform  = glm::mat4()) {
        using namespace glm;

        std::string nodeName(pNode->mName.data);

        // You probably want to be able to select different than animations than the 0th.
        // But with Maya's DAE_FBX exporter, it is not possible.
        const aiAnimation* prevAnimation = lastAnim->mAnimations[0];
        const aiAnimation* nextAnimation = currentAnim->mAnimations[0];
        const aiNodeAnim* prevNodeAnim = findNodeAnim(prevAnimation, nodeName);
        const aiNodeAnim* nextNodeAnim = findNodeAnim(nextAnimation, nodeName);

        mat4 nodeTransform = convertMatrix(pNode->mTransformation);

        if(prevNodeAnim && nextNodeAnim) {
            float factor = transitionTime > 1e-10 ? (nextAnimationTime / transitionTime) : 0.0f;

            // Interpolate the transformations and get the matrices
            aiVector3D prevScaling, nextScaling;
            calcInterpolatedScaling(prevScaling, prevAnimationTime, prevNodeAnim);
            calcInterpolatedScaling(nextScaling, nextAnimationTime, nextNodeAnim);
            aiVector3D scaling = interpolate(prevScaling, nextScaling, factor);
            mat4 scalingM = scale(mat4(), vec3(scaling.x, scaling.y, scaling.z));

            aiQuaternion prevRotation, nextRotation, rotation;
            calcInterpolatedRotation(prevRotation, prevAnimationTime, prevNodeAnim);
            calcInterpolatedRotation(nextRotation, nextAnimationTime, nextNodeAnim);
            // spherical interpolation, and it always chooses the shorter path (exactly what we want).
            aiQuaternion::Interpolate(rotation, prevRotation, nextRotation, factor);
            mat4 rotationM = convertMatrix(rotation.GetMatrix());

            aiVector3D prevTranslation, nextTranslation;
            calcInterpolatedPosition(prevTranslation, prevAnimationTime, prevNodeAnim);
            calcInterpolatedPosition(nextTranslation, nextAnimationTime, nextNodeAnim);
            aiVector3D translation = interpolate(prevTranslation, nextTranslation, factor);
            mat4 translationM;

            if(nodeName == rootBone) {
                vec3 transitionOffset = (startOffsets[currIdx] - startOffsets[lastIdx]) * factor;
                currentOffset =
                    vec3(nextTranslation.x, 0, nextTranslation.z) +
                    transitionOffset - lastTransitionOffset;
                lastTransitionOffset = transitionOffset;
                translationM = translate(mat4(), vec3(0, translation.y, 0)); // FIXME!!
            } else {
                translationM = translate(mat4(), vec3(translation.x, translation.y, translation.z));
            }

            // Combine the transformations
            nodeTransform = translationM * rotationM * scalingM;
        }

        mat4 globalTransformation = parentTransform * nodeTransform;

        if(boneMapping.find(nodeName) != boneMapping.end()) {
            unsigned boneIndex = boneMapping[nodeName];
            boneInfo[boneIndex].finalTransformation =
                globalInverseTransform * globalTransformation * boneInfo[boneIndex].boneOffset;
        }

        for(unsigned i = 0; i < pNode->mNumChildren; i++) {
            transitionReadNodeHeirarchy(
                prevAnimationTime, nextAnimationTime, pNode->mChildren[i], globalTransformation
            );
        }
    }

public:

    void updateBoneInfo(float timeInSeconds) {
        if(!currentAnim || currentAnim->mAnimations == 0 ||
           !lastAnim || lastAnim->mAnimations == 0) {
            throw std::runtime_error("Tried to run an invalid animation.");
        }

        float prevTicksPerSecond = lastAnim->mAnimations[0]->mTicksPerSecond > 1e-10 ? // != 0
                                   lastAnim->mAnimations[0]->mTicksPerSecond : 24.0f;
        float nextTicksPerSecond = currentAnim->mAnimations[0]->mTicksPerSecond > 1e-10 ? // != 0
                                   currentAnim->mAnimations[0]->mTicksPerSecond : 24.0f;

        float prevTimeInTicks = lastPeriodTime * prevTicksPerSecond;
        float currentTimeInTicks = (timeInSeconds - endOfLastAnim) * nextTicksPerSecond;
        float prevAnimationTime = fmod(prevTimeInTicks, (float)lastAnim->mAnimations[0]->mDuration);
        float currentAnimationTime = fabs(fmod(currentTimeInTicks, (float)currentAnim->mAnimations[0]->mDuration));

        unsigned loopCount = currentTimeInTicks / (float)currentAnim->mAnimations[0]->mDuration;
        if(loopCount > lastLoopCount) {
            lastOffset -= endOffsets[currIdx] - startOffsets[currIdx];
        }
        lastLoopCount = loopCount;

        if(endOfLastAnim + transitionTime < timeInSeconds) {
            // Normal animation
            readNodeHeirarchy(currentAnimationTime, scene->mRootNode);
        } else {
            // Transition between two animations.
            transitionReadNodeHeirarchy(prevAnimationTime, currentAnimationTime, scene->mRootNode);
        }
    }

    void boneTransform(float timeInSeconds,
                       LazyUniform<glm::mat4>& bones) {
        updateBoneInfo(timeInSeconds);

        for(unsigned i = 0; i < numBones; i++) {
            bones[i] = boneInfo[i].finalTransformation;
        }
    }
}; // AnimatedMesh

} // namespace oglwrap
