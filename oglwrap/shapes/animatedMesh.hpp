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

static inline std::ostream& operator<<(std::ostream& os, const glm::vec3& v) {
    os << v.x << ", " << v.y << ", " << v.z;
    return os;
}

namespace _AnimFlag {
enum AnimFlag {
    None = 0x0,
    Repeat = 0x1,
    // MirroredRepeat sets the Repeat flag, and MirroredRepeat is not the same as (Mirrored & Repeat)
    MirroredRepeat = 0x3,
    Mirrored = 0x4,
    Backwards = 0x8,
    Interruptable = 0x10
};
}
typedef _AnimFlag::AnimFlag AnimFlag;

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
        glm::mat4 bone_offset;
        glm::mat4 final_transform;
    };

    std::vector<ArrayBuffer> bone_buffers;
    std::vector<BoneInfo> bone_info;
    std::map<std::string, unsigned> bone_mapping; // maps a bone name to its index

    size_t num_bones;
    glm::mat4 global_inverse_transform;

    // vector::push_back(Assimp::Importer()) wouldn't work, because it has
    // a weird copy constructor, that doesn't actually copy. It must be dynamic.
    std::vector<Assimp::Importer*> animation_importers;
    std::vector<const aiScene*> animations;
    std::map<std::string, size_t> anim_names; // maps user defined animation names to indexes.

    const aiScene *last_anim, *current_anim;
    float default_transition_time, transition_time, end_of_last_anim, last_period_time;

    size_t default_idx, curr_idx, last_idx;
    std::vector<glm::vec3> start_offsets;
    std::vector<glm::vec3> end_offsets;

    glm::vec3 last_offset, current_offset, last_transition_offset;
    unsigned last_loop_count;

    std::string root_bone;

    std::vector<unsigned> default_flags;
    unsigned last_flags, current_flags;

public:
    AnimatedMesh(const std::string& filename, unsigned int flags)
        : Mesh(filename, flags)
        , bone_buffers(scene->mNumMeshes)
        , num_bones(0)
        , last_anim(nullptr)
        , current_anim(nullptr)
        , default_transition_time(0)
        , transition_time(0)
        , end_of_last_anim(0)
        , last_period_time(0)
        , default_idx(0)
        , curr_idx(0)
        , last_idx(0)
        , last_loop_count(0)
        , last_flags(0)
        , current_flags(0) {

        glm::mat4 matrix = convertMatrix(scene->mRootNode->mTransformation);
        global_inverse_transform = glm::inverse(matrix);

        if(numBoneAttribs != getRecommendedNumBoneAttribs())
            std::cerr << "Error in AnimatedMesh '" << filename << "'\n" <<
            "The class was created with " << (int)numBoneAttribs << " bone "
            "attribute(s), but the mesh needs " << (int)getRecommendedNumBoneAttribs() <<
            " bone attribute(s) to do its best." << std::endl;

    }

    ~AnimatedMesh() {
        for(auto i = animation_importers.begin(); i != animation_importers.end(); i++)
            delete *i;
    }

private:

    // It shouldn't be copyable
    AnimatedMesh(const AnimatedMesh& src);
    void operator=(const AnimatedMesh& rhs);

/*         //=====:==-==-==:=====\\                                 //=====:==-==-==:=====\\
    <---<}>==~=~=~==--==--==~=~=~==<{>----- Skin definition -----<}>==~=~=~==--==--==~=~=~==<{>--->
           \\=====:==-==-==:=====//                                 \\=====:==-==-==:=====//          */

    void mapBones() {
        for(size_t entry = 0; entry < entries.size(); entry++) {
            const aiMesh* pMesh = scene->mMeshes[entry];

            for(unsigned i = 0; i < pMesh->mNumBones; i++) {
                std::string boneName(pMesh->mBones[i]->mName.data);
                size_t boneIndex = 0;

                // Search for this bone in the BoneMap
                if(bone_mapping.find(boneName) == bone_mapping.end()) {
                    // Allocate an index for the new bone
                    boneIndex = num_bones++;
                    bone_info.push_back(BoneInfo());
                    bone_info[boneIndex].bone_offset = convertMatrix(pMesh->mBones[i]->mOffsetMatrix);
                    bone_mapping[boneName] = boneIndex;
                }
            }
        }
    }

    const aiNodeAnim* getRootBone(const aiNode* pNode, const aiScene* anim) {
        std::string nodeName(pNode->mName.data);

        const aiAnimation* pAnimation = anim->mAnimations[0];
        const aiNodeAnim* pNodeAnim = findNodeAnim(pAnimation, nodeName);

        if(pNodeAnim) {
            if(root_bone.empty()) {
                root_bone = nodeName;
            } else {
                if(root_bone != nodeName) {
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
                size_t boneIndex = bone_mapping[boneName];

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
                bone_buffers[entry].bind();
                bone_buffers[entry].data(bones[entry]);

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

    unsigned char getNumBoneAttribs() {
        return numBoneAttribs;
    }

    /// Loads in bone weight and id information to the given array of attribute arrays.
    /** Uploads the bone weight and id to an array of attribute arrays, and sets it up for use.
      * For example if you specified "in vec4 boneIds[3]" you have to give "prog | boneIds"
      * Calling this function changes the currently active VAO and ArrayBuffer.
      * The mesh cannot be drawn without calling this function. */
    /// @param boneIDs - The array of attributes array to use as destination for bone IDs.
    /// @param boneWeights - The array of attributes array to use as destination for bone weights.
    void setup_bones(LazyVertexAttribArray boneIDs, LazyVertexAttribArray boneWeights) {
        mapBones();

        if(num_bones < UCHAR_MAX)
            loadBones<unsigned char>(DataType::UnsignedByte, boneIDs, boneWeights);
        else if(num_bones < USHRT_MAX)
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
                           const glm::mat4& parentTransform = glm::mat4()) {
        using namespace glm;

        std::string nodeName(pNode->mName.data);

        // You probably want to be able to select different than animations than the 0th.
        // But with Maya's DAE_FBX exporter, it is not possible.
        const aiAnimation* pAnimation = current_anim->mAnimations[0];
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

            if(nodeName == root_bone) {
                if(current_flags & AnimFlag::Mirrored) {
                    current_offset = -vec3(translation.x, 0, translation.z);
                } else {
                    current_offset = vec3(translation.x, 0, translation.z);
                }

                translationM = translate(mat4(), vec3(0, translation.y, 0)); // FIXME!!
            } else {
                translationM = translate(mat4(), vec3(translation.x, translation.y, translation.z));
            }

            // Combine the transformations
            nodeTransform = translationM * rotationM * scalingM;
        }

        mat4 globalTransformation = parentTransform * nodeTransform;

        if(bone_mapping.find(nodeName) != bone_mapping.end()) {
            unsigned boneIndex = bone_mapping[nodeName];
            bone_info[boneIndex].final_transform =
                global_inverse_transform * globalTransformation * bone_info[boneIndex].bone_offset;
        }

        for(unsigned i = 0; i < pNode->mNumChildren; i++) {
            readNodeHeirarchy(animationTime, pNode->mChildren[i], globalTransformation);
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
        const aiAnimation* prevAnimation = last_anim->mAnimations[0];
        const aiAnimation* nextAnimation = current_anim->mAnimations[0];
        const aiNodeAnim* prevNodeAnim = findNodeAnim(prevAnimation, nodeName);
        const aiNodeAnim* nextNodeAnim = findNodeAnim(nextAnimation, nodeName);

        mat4 nodeTransform = convertMatrix(pNode->mTransformation);

        if(prevNodeAnim && nextNodeAnim) {
            float factor;
            if(current_flags & AnimFlag::Backwards) {
                factor = transition_time > 1e-10 ?
                    ( ((float)current_anim->mAnimations[0]->mDuration - nextAnimationTime)
                       / transition_time )
                    : 0.0f;
            } else {
                factor = transition_time > 1e-10 ? (nextAnimationTime / transition_time) : 0.0f;
            }

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

            if(nodeName == root_bone) {
                // Transition Offset is a utility that helps you in creating better transitions between
                // animations. For example, if you want one of the character's leg to stay in it's place,
                // throughout the transition, it might only be possible if the character's center of mass
                // doesn't start from the origin on the XZ axis in the new animation. This utility is about
                // to interpolate the position of the center of mass from the origin to the place, where
                // it starts in the new animation. It isn't necessary, just makes the transition more
                // realistic. But it definitely has no use, when the animation is played backwards.
                vec3 transitionOffset;
                if(!(current_flags & AnimFlag::Backwards)) {
                    transitionOffset = (start_offsets[curr_idx] - start_offsets[last_idx]) * factor;
                }
                current_offset =
                    vec3(nextTranslation.x, 0, nextTranslation.z) +
                    transitionOffset - last_transition_offset;

                if(current_flags & AnimFlag::Mirrored) {
                    current_offset *= -1;
                }

                last_transition_offset = transitionOffset;
                translationM = translate(mat4(), vec3(0, translation.y, 0)); // FIXME!!
            } else {
                translationM = translate(mat4(), vec3(translation.x, translation.y, translation.z));
            }

            // Combine the transformations
            nodeTransform = translationM * rotationM * scalingM;
        }

        mat4 globalTransformation = parentTransform * nodeTransform;

        if(bone_mapping.find(nodeName) != bone_mapping.end()) {
            unsigned boneIndex = bone_mapping[nodeName];
            bone_info[boneIndex].final_transform =
                global_inverse_transform * globalTransformation * bone_info[boneIndex].bone_offset;
        }

        for(unsigned i = 0; i < pNode->mNumChildren; i++) {
            transitionReadNodeHeirarchy(
                prevAnimationTime, nextAnimationTime, pNode->mChildren[i], globalTransformation
            );
        }
    }

    void updateBoneInfo(float time_in_seconds) {
        if(!current_anim || current_anim->mAnimations == 0 ||
           !last_anim || last_anim->mAnimations == 0) {
            throw std::runtime_error("Tried to run an invalid animation.");
        }


        float last_ticks_per_second = last_anim->mAnimations[0]->mTicksPerSecond > 1e-10 ? // != 0
                                      last_anim->mAnimations[0]->mTicksPerSecond : 24.0f;

        float last_time_in_ticks = last_period_time * last_ticks_per_second;
        float last_animation_time;
        if(last_flags & AnimFlag::Repeat) {
            last_animation_time = fmod(last_time_in_ticks, (float)last_anim->mAnimations[0]->mDuration);
        } else {
            last_animation_time = std::min(last_time_in_ticks, (float)last_anim->mAnimations[0]->mDuration);
        }

        if(last_flags & AnimFlag::Backwards) {
            last_animation_time = (float)last_anim->mAnimations[0]->mDuration - last_animation_time;
        }


        float current_ticks_per_second = current_anim->mAnimations[0]->mTicksPerSecond > 1e-10 ? // != 0
                                         current_anim->mAnimations[0]->mTicksPerSecond : 24.0f;

        float current_time_in_ticks = (time_in_seconds - end_of_last_anim) * current_ticks_per_second;
        float current_animation_time;
        if(current_flags & AnimFlag::Repeat) {
            current_animation_time = fmod(current_time_in_ticks, (float)current_anim->mAnimations[0]->mDuration);
        } else {
            if(current_time_in_ticks < (float)current_anim->mAnimations[0]->mDuration)
                current_animation_time = current_time_in_ticks;
            else {
                force_anim_to_default(time_in_seconds);
                updateBoneInfo(time_in_seconds);
                return;
            }
        }

        if(current_flags & AnimFlag::Backwards) {
            current_animation_time = (float)current_anim->mAnimations[0]->mDuration - current_animation_time;
        }

        if(end_of_last_anim + transition_time < time_in_seconds) {
            // Normal animation
            readNodeHeirarchy(current_animation_time, scene->mRootNode);
        } else {
            // Transition between two animations.
            transitionReadNodeHeirarchy(last_animation_time, current_animation_time, scene->mRootNode);
        }

        // Start a new loop if necessary
        if(current_flags & AnimFlag::Repeat) {

            unsigned loop_count = current_time_in_ticks / (float)current_anim->mAnimations[0]->mDuration;

            if(loop_count > last_loop_count) {
                if((current_flags & AnimFlag::MirroredRepeat) == AnimFlag::MirroredRepeat) {
                    current_flags ^= AnimFlag::Mirrored;
                    current_flags ^= AnimFlag::Backwards;
                }

                if(current_flags & AnimFlag::Backwards) {
                    last_offset = current_offset = end_offsets[curr_idx];
                } else {
                    last_offset = current_offset = start_offsets[curr_idx];
                }

                if(current_flags & AnimFlag::Mirrored) {
                    last_offset *= -1;
                    current_offset *= -1;
                }
            }

            last_loop_count = loop_count;
        }
    }

public:
    // -------======{[ Bone transformation updater ]}======-------

    void boneTransform(float time_in_seconds,
                       LazyUniform<glm::mat4>& bones) {
        updateBoneInfo(time_in_seconds);

        for(unsigned i = 0; i < num_bones; i++) {
            bones[i] = bone_info[i].final_transform;
        }
    }

    // -------======{[ Animation changers ]}======-------

    void add_animation(const std::string& filename,
                       const std::string& animName,
                       unsigned flags = AnimFlag::None) {

        if(anim_names.find(animName) != anim_names.end()){
            std::string err = "Animation name '" + animName + "' isn't unique for '" + filename + "'";
            throw std::runtime_error(err);
        }
        size_t idx = animations.size();
        anim_names[animName] = idx;
        animation_importers.push_back(new Assimp::Importer());
        animations.push_back(animation_importers[idx]->ReadFile(filename, aiProcess_Debone));

        if(!animations[idx]) {
            throw std::runtime_error("Error parsing " + filename
                + " : " + animation_importers[idx]->GetErrorString());
        }

        auto node = getRootBone(scene->mRootNode, animations[idx]);
        if(!node) {
            throw std::runtime_error(
                "Animation error: The mesh's skeleton, and the animated skeleton '" +
                animName + "' doesn't have a single bone in common.");
        }

        aiVector3D v = node->mPositionKeys[0].mValue;
        start_offsets.push_back(glm::vec3(v.x, v.y, v.z));
        v = node->mPositionKeys[node->mNumPositionKeys - 1].mValue;
        end_offsets.push_back(glm::vec3(v.x, v.y, v.z));

        default_flags.push_back(flags);
    }

    void set_default_animation(const std::string& animName,
                               float default_transition_time = 0.0f) {

        if(anim_names.find(animName) == anim_names.end()) {
            throw std::invalid_argument(
                "Tried to set current animation to '" + animName + "', "
                "but the AnimatedMesh doesn't have an animation with name"
            );
        }

        set_default_animation(anim_names[animName], default_transition_time);
    }

    void set_default_animation(size_t animIndex,
                               float default_transition_time = 0.0f) {

        if(!(default_flags[animIndex] & AnimFlag::Repeat)) {
            throw std::invalid_argument(
                "Tried to set a default animation that didn't have the repeat "
                "flag, but the default animation must be a cycle."
            );
        }

        default_idx = animIndex;
        this->default_transition_time = default_transition_time;
    }

private:
    void change_animation(size_t animIndex,
                          float currentTime,
                          float transition_time,
                          unsigned flags) {

        last_idx = curr_idx;
        curr_idx = animIndex;
        last_anim = current_anim;
        current_anim = animations[animIndex];
        this->transition_time = transition_time;
        last_period_time = currentTime - end_of_last_anim;
        last_transition_offset = glm::vec3();
        end_of_last_anim = currentTime;

        if(flags & AnimFlag::Backwards) {
            last_offset = current_offset = end_offsets[curr_idx];
        } else {
            last_offset = current_offset = start_offsets[curr_idx];
        }

        if(flags & AnimFlag::Mirrored) {
            last_offset *= -1;
            current_offset *= -1;
        }

        if(!last_anim) {
            last_offset = glm::vec3();
            last_anim = current_anim;
        }

        last_flags = current_flags;
        current_flags = flags;
    }

public:
    void set_current_animation(const std::string& animName,
                              float currentTime,
                              float transition_time,
                              unsigned flags) {

        if((end_of_last_anim + this->transition_time) <= currentTime
           && (current_flags & AnimFlag::Interruptable)
        ) {
            force_current_animation(animName, currentTime, transition_time, flags);
        }
    }

    void force_current_animation(const std::string& animName,
                                 float currentTime,
                                 float transition_time,
                                 unsigned flags) {

        if(anim_names.find(animName) == anim_names.end()) {
            throw std::invalid_argument(
                "Tried to set current animation to '" + animName + "', "
                "but the AnimatedMesh doesn't have an animation with name"
            );
        }

        size_t animIndex = anim_names[animName];

        if(current_anim == animations[animIndex]) {
            return;
        }

        change_animation(animIndex, currentTime, transition_time, flags);
    }

    void set_current_animation(const std::string& animName,
                               float currentTime,
                               float transition_time = 0.0f) {

        if((end_of_last_anim + this->transition_time) <= currentTime
           && (current_flags & AnimFlag::Interruptable)
        ) {
            force_current_animation(animName, currentTime, transition_time);
        }
    }

    void force_current_animation(const std::string& animName,
                                 float currentTime,
                                 float transition_time = 0.0f) {

        if(anim_names.find(animName) == anim_names.end()) {
            throw std::invalid_argument(
                "Tried to set current animation to '" + animName + "', "
                "but the AnimatedMesh doesn't have an animation with name"
            );
        }

        size_t animIndex = anim_names[animName];

        if(current_anim == animations[animIndex]) {
            return;
        }

        change_animation(animIndex, currentTime, transition_time, default_flags[animIndex]);
    }

    void set_anim_to_default(float currentTime) {
        if(current_flags & AnimFlag::Interruptable)
            force_anim_to_default(currentTime);
    }

    void force_anim_to_default(float currentTime) {
        assert(default_flags[default_idx] & AnimFlag::Repeat);
        if(current_anim == animations[default_idx])
            return;

        change_animation(default_idx, currentTime, default_transition_time, default_flags[default_idx]);
    }

    glm::vec3 offset_since_last_frame() {
        auto ret = current_offset - last_offset;
        last_offset = current_offset;
        ret.y = 0; // FIXME
        return ret;
    }

}; // AnimatedMesh

} // namespace oglwrap
