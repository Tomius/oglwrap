/** @file animatedMesh.hpp
    @brief An animation loader using assimp
*/

#pragma once

#include "mesh.hpp"

#define MOVE_SPEED_HACK 1.0f // for debugging only!
#define ANIM_SPEED_HACK 1.0f // for debugging only!

namespace oglwrap {

// Conversion between oglplus and glm matrices

/// Converts an assimp aiMatrix4x4 to glm mat4
/// @param m - the matrix to convert
static inline glm::mat4 convertMatrix(const aiMatrix4x4& m) {
    return glm::transpose(glm::make_mat4(&m.a1));
}

/// Converts an assimp aiMatrix3x3 to glm mat4
/// @param m - the matrix to convert
static inline glm::mat4 convertMatrix(const aiMatrix3x3& m) {
    return glm::mat4(glm::transpose(glm::make_mat3(&m.a1)));
}

/// Converts a glm mat4 to an assimp aiMatrix4x4
/// @param m - the matrix to convert
static inline aiMatrix4x4 convertMatrix(const glm::mat4& m) {
    return aiMatrix4x4 {
        m[0][0], m[1][0], m[2][0], m[3][0],
        m[0][1], m[1][1], m[2][1], m[3][1],
        m[0][2], m[1][2], m[2][2], m[3][2],
        m[0][3], m[1][3], m[2][3], m[3][3]
    };
}

namespace _AnimFlag {
/// Animation modifying flags.
enum AnimFlag {
    /// Doesn't do anything.
    None = 0x0,

    /// Repeats the animation until it's interrupted by another animation.
    Repeat = 0x1,

    /// Repeats the animation, but repeats it like OpenGL's MirroredRepeat.
    /** You can get this effect by setting repeat to true, and negating the
      * mirrored and backwards flags after every repetition. */
    MirroredRepeat = 0x3,

    /// Mirrors the movement during the animation.
    /** For example, for a walking with Mirrored flag will cause Moonwalk.
      * (The character will be animated as he/she was moving forwards, back
      * he/she actually moves backwards.) */
    Mirrored = 0x4,

    /// Plays the animation backwards
    Backwards = 0x8,

    /// Marks the animation as interruptable by other animations.
    /** Tip: if your animation is a cycle, 99% that you'll want it be
      * interruptable, however, single animations like a jump, usually
      * shouldn't be interrupted by another animations. */
    Interruptable = 0x10
};
}
typedef _AnimFlag::AnimFlag AnimFlag;

class AnimatedMesh : public Mesh {

    template<class Index_t>
    /// A struct containing an "ivec4" for the boneIDs, and a vec4 for bone weights.
    /** The boneIDs part is not fixed to be int (unsigned), it becomes the smallest type
      * that possible to store the all the ids of the bones. */
    struct VertexBoneData_PerAttribute {
        Index_t ids[4];
        float weights[4];

        VertexBoneData_PerAttribute() {
            memset(ids, 0, sizeof(ids));
            memset(weights, 0, sizeof(weights));
        };
    };

    template<class Index_t>
    /// Contains an array of VertexBoneData_PerAttribute. The size ma
    struct VertexBoneData {
        std::vector<VertexBoneData_PerAttribute<Index_t>> data;

        void AddBoneData(Index_t boneID, float weight) {
            do {
                for(size_t i = 0; i < data.size(); i++) {
                    for(int j = 0; j < 4; j++) {
                        if(data[i].weights[j] < 1e-10) { // if equals 0
                            data[i].ids[j] = boneID;
                            data[i].weights[j] = weight;
                            return;
                        }
                    }
                }

                // If there isn't enough space yet, then make some new
                data.push_back(VertexBoneData_PerAttribute<Index_t>());

            } while(data.size() < 8); // Bone attributes shouldn't use up all the 16 attribute slots.
        }
    };

    /// A structure for storing the default, relative-to-parent, and current transformations.
    struct BoneInfo {
        glm::mat4 bone_offset;
        glm::mat4 final_transform;
    };

    /// The OpenGL buffers for the bones.
    std::vector<ArrayBuffer> bone_buffers;

    /// The transformations of the bones.
    std::vector<BoneInfo> bone_info;

    /// Maps a bone name to its index.
    /** It is needed as usually multiply meshes share the same bone, but with
      * different index. The only way to reference it, without getting too much
      * multiplies, is to reference them by their name */
    std::map<std::string, unsigned> bone_mapping;

    /// The number of the bones.
    size_t num_bones;

    /// The maximum of per mesh bone attribute number's maximum for the entire scene.
    unsigned char max_bone_attrib_num;

    /// The maximum of per mesh bone attribute number's maximum per mesh.
    std::vector<unsigned char> per_mesh_attrib_max;

    /// Stores if setup_bones is called. It shouldn't be called more than once.
    bool is_setup_bones;

    /// Stores the root node transform's inverse-
    glm::mat4 global_inverse_transform;

    /// Stores the importers that store the additional animations loaded by addAnimation calls.
    /** Has to be a pointer. vector::push_back(Assimp::Importer()) wouldn't work, because it has
      * a weird copy constructor, that doesn't actually copy. It must be dynamic. */
    std::vector<Assimp::Importer*> animation_importers;

    /// Handles for the animations
    std::vector<const aiScene*> animations;

    /// maps user defined animation names to indexes.
    std::map<std::string, size_t> anim_names;

    /// The handle for the previous animation.
    /** It is stored for transitions between animations. */
    const aiScene *last_anim;

    /// The handle to the currently running animation.
    const aiScene *current_anim;

    /// The index of the default animation.
    size_t default_idx;

    /// The index of the previous animation.
    /** It is stored for transitions between animations. */
    size_t last_idx;

    /// The index of the currently running animation.
    size_t curr_idx;

    /// The fading time that is used when changing the animation back to the default one.
    float default_transition_time;

    /// The fading time between the previous and the current animation.
    float transition_time;

    /// The time of when did the last animation end.
    /** It is needed to know the time in the current animation. */
    float end_of_last_anim;

    /// The animation of time the previous animation.
    /** It is needed to make the transition between two animations. */
    float last_period_time;

    /// The offset values at the starts of the animations
    std::vector<glm::vec3> start_offsets;

    /// The offset values at the ends of the animations
    std::vector<glm::vec3> end_offsets;

    /// The offset value in the last frame.
    /** It is needed to know how much did the offset change,
      * and that value is used to move the character. */
    glm::vec3 last_offset;

    /// The current offset of the root bone of the animated object inside the animation, on the XZ plain.
    glm::vec3 current_offset;

    /// The transition offset in the last frame.
    /** transition offset difference is used to move the character
      * from the origin to the starting position of the animation linearly */
    glm::vec3 last_transition_offset;

    /// It is used to detect when did the animation start a new cycle.
    /** For animations that have AnimFlag::Repeat flag specified only, of course. */
    unsigned last_loop_count;

    /// The name of the root bone. It's usually not equal to the root node. It is need to get the offsets.
    std::string root_bone;

    /// Default animation flags specified in the addAnimation function.
    std::vector<unsigned> default_flags;

    /// The flags of the last animation. Some flags might modify how transitions should be made.
    unsigned last_flags;

    /// The current animation modifier flags.
    unsigned current_flags;

    /// Speed modifier
    float current_speed;

    /// Last speed modifier
    float last_speed;

    /// Default speed modifiers
    std::vector<float> speed_modifiers;

public:
    AnimatedMesh(const std::string& filename, unsigned int flags)
        : Mesh(filename, flags)
        , bone_buffers(scene->mNumMeshes)
        , num_bones(0)
        , max_bone_attrib_num(0)
        , is_setup_bones(false)
        , last_anim(nullptr)
        , current_anim(nullptr)
        , default_idx(0)
        , last_idx(0)
        , curr_idx(0)
        , default_transition_time(0)
        , transition_time(0)
        , end_of_last_anim(0)
        , last_period_time(0)
        , last_loop_count(0)
        , last_flags(0)
        , current_flags(0)
        , current_speed(1.0f)
        , last_speed(1.0f) {

        glm::mat4 matrix = convertMatrix(scene->mRootNode->mTransformation);
        global_inverse_transform = glm::inverse(matrix);
    }

    ~AnimatedMesh() {
        for(auto i = animation_importers.begin(); i != animation_importers.end(); i++)
            delete *i;
    }

private:

    /// Just a private declaration of the copy constructor... it shouldn't be copyable.
    AnimatedMesh(const AnimatedMesh& src);

    /// Just a private declaration of the assign operator... it shouldn't be copyable.
    void operator=(const AnimatedMesh& rhs);

/*         //=====:==-==-==:=====\\                                 //=====:==-==-==:=====\\
    <---<}>==~=~=~==--==--==~=~=~==<{>----- Skin definition -----<}>==~=~=~==--==--==~=~=~==<{>--->
           \\=====:==-==-==:=====//                                 \\=====:==-==-==:=====//          */

    /// Fills the bone_mapping with data.
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

    /// A recursive functions that should be started from the root node, and it returns the first bone under it.
    const aiNodeAnim* getRootBone(const aiNode* node, const aiScene* anim) {
        std::string nodeName(node->mName.data);

        const aiAnimation* animation = anim->mAnimations[0];
        const aiNodeAnim* nodeAnim = findNodeAnim(animation, nodeName);

        if(nodeAnim) {
            if(root_bone.empty()) {
                root_bone = nodeName;
            } else {
                if(root_bone != nodeName) {
                    throw std::runtime_error(
                        "Animation error: the animated skeletons have different root bones."
                    );
                }
            }
            return nodeAnim;
        }
        else {
            for(unsigned i = 0; i < node->mNumChildren; i++) {
                auto childsReturn = getRootBone(node->mChildren[i], anim);
                if(childsReturn)
                    return childsReturn;
            }
        }

        return nullptr;
    }

    template <class Index_t>
    /// Creates bone attributes data.
    /** It is a template, as the type of boneIDs shouldn't be fix. Most of the times,
      * a skeleton won't contain more than 256 bones, but that doesn't mean boneIDs
      * should be forced to GLubyte, it works with shorts and even ints too. Although
      * I really doubt anyone would be using a skeleton with more than 65535 bones... */
    void loadBones() {

        const size_t per_attrib_size = sizeof(VertexBoneData_PerAttribute<Index_t>);

        per_mesh_attrib_max.resize(entries.size());

        for(size_t entry = 0; entry < entries.size(); entry++) {
            std::vector<VertexBoneData<Index_t>> bones;
            const aiMesh* pMesh = scene->mMeshes[entry];
            bones.resize(pMesh->mNumVertices);

            // -------======{[ Create the bone ID's and weights data ]}======-------

            for(unsigned i = 0; i < pMesh->mNumBones; i++) {
                std::string boneName(pMesh->mBones[i]->mName.data);
                size_t boneIndex = bone_mapping[boneName];

                for(unsigned j = 0; j < pMesh->mBones[i]->mNumWeights; j++) {
                    unsigned vertexID = pMesh->mBones[i]->mWeights[j].mVertexId;
                    float weight = pMesh->mBones[i]->mWeights[j].mWeight;
                    bones[vertexID].AddBoneData(boneIndex, weight);
                }
            }

            // -------======{[ Upload the bone data ]}======-------

            entries[entry].vao.bind();
            bone_buffers[entry].bind();

            // I can't just upload to the buffer with .data(), as bones aren't stored in a continuous buffer,
            // and it is an array of not fixed sized arrays, but OpenGL needs it in fix sized parts.

            // Get the current number of max bone attributes.
            unsigned char& current_attrib_max = per_mesh_attrib_max[entry];
            for(size_t i = 0; i < bones.size(); i++) {
                if(bones[i].data.size() > current_attrib_max)
                    current_attrib_max = bones[i].data.size();
            }

            if(current_attrib_max > max_bone_attrib_num)
                max_bone_attrib_num = current_attrib_max;

            size_t per_vertex_size = current_attrib_max * per_attrib_size;

            // First we have to allocate the buffer's storage.
            bone_buffers[entry].data(
                bones.size() * per_vertex_size,
                (void*)0
            );

            // Then upload the bones data in continuous, fix-sized parts.
            {
                // The map gets unmapped when it's lifetime ends
                ArrayBuffer::Map bones_buffer_map(BufferMapAccess::Write);
                GLintptr offset = 0;
                for(size_t i = 0; i < bones.size(); i++) {
                    size_t curr_size = bones[i].data.size() * per_attrib_size;

                    // Copy the bone data
                    memcpy(
                        (GLbyte*)bones_buffer_map.data() + offset, // destination
                        bones[i].data.data(),  // source
                        curr_size // length
                    );

                    // Zero out all the remaining memory. Remember a
                    // bone with a 0.0f weight doesn't have any influence
                    if(per_vertex_size > curr_size) {
                        memset(
                            (GLbyte*)bones_buffer_map.data() + offset + curr_size, // memory place
                            0, // value
                            per_vertex_size - curr_size // length
                        );
                    }

                    offset += per_vertex_size;
                }
            }
        }

        // Unbind our things, so they won't be modified from outside
        VertexArray::Unbind();
        ArrayBuffer::Unbind();
    }

    /// Creates the bone attributes data (the skinning.)
    /** It actually just calls the loadBones function with the appropriate template parameter */
    void create_bones_data() {
        mapBones();

        if(num_bones < UCHAR_MAX)
            loadBones<unsigned char>();
        else if(num_bones < USHRT_MAX)
            loadBones<unsigned short>();
        else // more than 65535 bones? WTF???
            loadBones<unsigned int>();
    }

    template <class Index_t>
    /// Shader plumbs the bone data.
    /** It is a template, as the type of boneIDs shouldn't be fix. Most of the times,
      * a skeleton won't contain more than 256 bones, but that doesn't mean boneIDs
      * should be forced to GLubyte, it works with shorts and even ints too. Although
      * I really doubt anyone would be using a skeleton with more than 65535 bones...
      * @param idx_t - The oglwrap enum, naming the data type that should be used.
      * @param boneIDs - Should be an array of attributes, that will be shader plumbed for the boneIDs data.
      * @param boneWeights - Should be an array of attributes, that will be shader plumbed for the boneWeights data. */
    void shader_plumb_bones(DataType idx_t, LazyVertexAttribArray boneIDs, LazyVertexAttribArray boneWeights) {
        const size_t per_attrib_size = sizeof(VertexBoneData_PerAttribute<Index_t>);

        for(size_t entry = 0; entry < entries.size(); entry++) {

            entries[entry].vao.bind();
            bone_buffers[entry].bind();
            unsigned char current_attrib_max = per_mesh_attrib_max[entry];

            for(unsigned char boneAttribSet = 0; boneAttribSet < current_attrib_max; boneAttribSet++) {
                const size_t stride = current_attrib_max * per_attrib_size;

                intptr_t baseOffset = boneAttribSet * per_attrib_size;
                intptr_t weightOffset = baseOffset + 4 * sizeof(Index_t);

                boneIDs[boneAttribSet].setup(4, idx_t, stride, (const void*)baseOffset).enable();
                boneWeights[boneAttribSet].setup(4, DataType::Float, stride, (const void*)weightOffset).enable();
            }

            // static setup the VertexArrays that aren't enabled, to all zero.
            // Remember (0, 0, 0, 1) is the default, which isn't what we want.
            for(int i = current_attrib_max; i < max_bone_attrib_num; i++) {
                boneIDs[i].static_setup(glm::ivec4(0, 0, 0, 0));
                boneWeights[i].static_setup(glm::vec4(0, 0, 0, 0));
            }
        }

        // Unbind our things, so they won't be modified from outside
        VertexArray::Unbind();
        ArrayBuffer::Unbind();
    }

public:
    /// Returns the number of bones this scene has.
    /** May change the currently active VAO and ArrayBuffer at the first call. */
    size_t get_num_bones() {

        // If loadBones hasn't been called yet, than have to create
        // the bones data first to know the number of bones.
        if(per_mesh_attrib_max.size() == 0)
            create_bones_data();

        return num_bones;
    }

    /// Returns the size that boneIds and BoneWeights attribute arrays should be.
    /** May change the currently active VAO and ArrayBuffer at the first call. */
    size_t get_bone_attrib_num() {

        // If loadBones hasn't been called yet, than have to create
        // the bones data first to know max_bone_attrib_num.
        if(per_mesh_attrib_max.size() == 0)
            create_bones_data();

        return max_bone_attrib_num;
    }

    /// Loads in bone weight and id information to the given array of attribute arrays.
    /** Uploads the bone weight and id to an array of attribute arrays, and sets it up for use.
      * For example if you specified "in vec4 boneIds[3]" you have to give "prog | boneIds"
      * Calling this function changes the currently active VAO and ArrayBuffer.
      * @param boneIDs - The array of attributes array to use as destination for bone IDs.
      * @param boneWeights - The array of attributes array to use as destination for bone weights. */
    void setup_bones(LazyVertexAttribArray boneIDs, LazyVertexAttribArray boneWeights) {

        if(is_setup_bones) {
            throw std::logic_error("AnimatedMesh::setup_bones is called multiply times on the same object");
        } else {
            is_setup_bones = true;
        }

        // If the bones data hasn't been created yet, than call the function to do it.
        if(per_mesh_attrib_max.size() == 0)
            create_bones_data();

        if(num_bones < UCHAR_MAX)
            shader_plumb_bones<unsigned char>(DataType::UnsignedByte, boneIDs, boneWeights);
        else if(num_bones < USHRT_MAX)
            shader_plumb_bones<unsigned short>(DataType::UnsignedShort, boneIDs, boneWeights);
        else // more than 65535 bones? WTF???
            shader_plumb_bones<unsigned int>(DataType::UnsignedInt, boneIDs, boneWeights);
    }

/*         //=====:==-==-==:=====\\                           //=====:==-==-==:=====\\
    <---<}>==~=~=~==--==--==~=~=~==<{>----- Animation -----<}>==~=~=~==--==--==~=~=~==<{>--->
           \\=====:==-==-==:=====//                           \\=====:==-==-==:=====//          */

private:

    /// Returns the index of the currently active translation keyframe for the given animation and time.
    /// @param animationTime - The time elapsed since the start of this animation.
    /// @param nodeAnim - The animation node, in which the function should search for a keyframe.
    unsigned findPosition(float animationTime, const aiNodeAnim* nodeAnim) {
        // Find the first one that is bigger or equals
        for(unsigned i = 0; i < nodeAnim->mNumPositionKeys - 1; i++) {
            if(animationTime <= (float)nodeAnim->mPositionKeys[i + 1].mTime) {
                return i;
            }
        }
        // Should never get here
        throw std::runtime_error("Animation Error - Position keyframe not found");
    }

    /// Returns the index of the currently active rotation keyframe for the given animation and time.
    /// @param animationTime - The time elapsed since the start of this animation.
    /// @param nodeAnim - The animation node, in which the function should search for a keyframe.
    unsigned findRotation(float animationTime, const aiNodeAnim* nodeAnim) {
        for(unsigned i = 0; i < nodeAnim->mNumRotationKeys - 1; i++) {
            if(animationTime <= (float)nodeAnim->mRotationKeys[i + 1].mTime) {
                return i;
            }
        }
        throw std::runtime_error("Animation Error - Rotation keyframe not found");
    }

    /// Returns the index of the currently active scaling keyframe for the given animation and time.
    /// @param animationTime - The time elapsed since the start of this animation.
    /// @param nodeAnim - The animation node, in which the function should search for a keyframe.
    unsigned findScaling(float animationTime, const aiNodeAnim* nodeAnim) {
        for(unsigned i = 0; i < nodeAnim->mNumScalingKeys - 1; i++) {
            if(animationTime <= (float)nodeAnim->mScalingKeys[i + 1].mTime) {
                return i;
            }
        }
        throw std::runtime_error("Animation Error - Scaling keyframe not found");
    }

    template<class T>
    /// Interpolates two things.
    /// @param a - the first thing.
    /// @param b - the second thing.
    /// @param alpha - Specifies how 'b' will the result be.
    T interpolate(const T& a, const T& b, float alpha) {
        return a + alpha * (b - a);
    }

    /// Returns a linearly interpolated value between the previous and next translation keyframes.
    /// @param out - Returns the result here.
    /// @param animationTime - The time elapsed since the start of this animation.
    /// @param nodeAnim - The animation node, in which the function should search for the keyframes.
    void calcInterpolatedPosition(aiVector3D& out, float animTime, const aiNodeAnim* nodeAnim) {
        const auto& keys = nodeAnim->mPositionKeys;
        const auto& numKeys = nodeAnim->mNumPositionKeys;

        if(numKeys == 1) {
            out = keys[0].mValue;
            return;
        }

        size_t i = findPosition(animTime, nodeAnim);
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

    /// Returns a spherically interpolated value (always choosing the short path) between the previous and next rotation keyframes.
    /// @param out - Returns the result here.
    /// @param animationTime - The time elapsed since the start of this animation.
    /// @param nodeAnim - The animation node, in which the function should search for the keyframes.
    void calcInterpolatedRotation(aiQuaternion& out, float animTime, const aiNodeAnim* nodeAnim) {
        const auto& keys = nodeAnim->mRotationKeys;
        const auto& numKeys = nodeAnim->mNumRotationKeys;

        if(numKeys == 1) {
            out = keys[0].mValue;
            return;
        }

        size_t i = findRotation(animTime, nodeAnim);
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

    /// Returns a linearly interpolated value between the previous and next scaling keyframes.
    /** @param out - Returns the result here.
      * @param animationTime - The time elapsed since the start of this animation.
      * @param nodeAnim - The animation node, in which the function should search for the keyframes. */
    void calcInterpolatedScaling(aiVector3D& out, float animTime, const aiNodeAnim* nodeAnim) {
        const auto& keys = nodeAnim->mScalingKeys;
        const auto& numKeys = nodeAnim->mNumScalingKeys;

        if(numKeys == 1) {
            out = keys[0].mValue;
            return;
        }

        size_t i = findRotation(animTime, nodeAnim);
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

    /// Returns the animation node in the given animation, referenced by its name.
    /** Returns nullptr if it doesn't find a node with that name,
      * which usually means that it's not a bone.
      * @param animation - The animation, this function should search in.
      * @param nodeName - The name of the bone to search. */
    const aiNodeAnim* findNodeAnim(const aiAnimation* animation, const std::string nodeName) {
        for(unsigned i = 0; i < animation->mNumChannels; i++) {
            const aiNodeAnim* nodeAnim = animation->mChannels[i];

            if(std::string(nodeAnim->mNodeName.data) == nodeName) {
                return nodeAnim;
            }
        }

        return nullptr;
    }

    /// Recursive function that travels through the entire node hierarchy, and creates transformation values in world space.
    /** Bone transformations are stored relative to their parents. That's why it is needed.
      * Also note, that the translation of the root node on the XZ plane is treated differently, that offset isn't
      * baked into the animation, you can get the offset with the offset_since_last_frame() function, and you have to
      * externally do the object's movement, as normally it will stay right where it was at the start of the animation.
      * @param animationTime - The current animation time.
      * @param node - The node (bone) whose, and whose child's transformation should be updated. You should call this function with the root node.
      * @param parentTransform - The transformation of the parent node. You should call it with an identity matrix. */
    void readNodeHeirarchy(float animationTime,
                           const aiNode* node,
                           const glm::mat4& parentTransform = glm::mat4()) {

        std::string nodeName(node->mName.data);

        // You probably want to be able to select different than animations than the 0th.
        // But with Maya's DAE_FBX exporter, it is not possible.
        const aiAnimation* animation = current_anim->mAnimations[0];
        const aiNodeAnim* nodeAnim = findNodeAnim(animation, nodeName);

        glm::mat4 nodeTransform = convertMatrix(node->mTransformation);

        if(nodeAnim) {
            // Interpolate the transformations and get the matrices
            aiVector3D scaling;
            calcInterpolatedScaling(scaling, animationTime, nodeAnim);
            glm::mat4 scalingM = glm::scale(glm::mat4(), glm::vec3(scaling.x, scaling.y, scaling.z));

            aiQuaternion rotation;
            calcInterpolatedRotation(rotation, animationTime, nodeAnim);
            glm::mat4 rotationM = convertMatrix(rotation.GetMatrix());

            aiVector3D translation;
            calcInterpolatedPosition(translation, animationTime, nodeAnim);
            glm::mat4 translationM;

            if(nodeName == root_bone) {
                current_offset = glm::vec3(translation.x, 0, translation.z) * MOVE_SPEED_HACK;

                if(current_flags & AnimFlag::Mirrored) {
                    current_offset *= -1;
                }

                translationM = glm::translate(glm::mat4(), glm::vec3(0, translation.y, 0));
            } else {
                translationM = glm::translate(glm::mat4(), glm::vec3(translation.x, translation.y, translation.z));
            }

            // Combine the transformations
            nodeTransform = translationM * rotationM * scalingM;
        }

        glm::mat4 globalTransformation = parentTransform * nodeTransform;

        if(bone_mapping.find(nodeName) != bone_mapping.end()) {
            unsigned boneIndex = bone_mapping[nodeName];
            bone_info[boneIndex].final_transform =
                global_inverse_transform * globalTransformation * bone_info[boneIndex].bone_offset;
        }

        for(unsigned i = 0; i < node->mNumChildren; i++) {
            readNodeHeirarchy(animationTime, node->mChildren[i], globalTransformation);
        }
    }

    /// Does the same thing as readNodeHierarchy, but it is used to create transitions between animations, so it interpolates between four keyframes not two.
    /** @param prevAnimationTime - The animation time of when, the last animation was interrupted.
      * @param nextAnimationTime - The current animation time.
      * @param node - The node (bone) whose, and whose child's transformation should be updated. You should call this function with the root node.
      * @param parentTransform - The transformation of the parent node. You should call it with an identity matrix. */
    void transitionReadNodeHeirarchy(float prevAnimationTime,
                                     float nextAnimationTime,
                                     const aiNode* node,
                                     const glm::mat4& parentTransform  = glm::mat4()) {

        std::string nodeName(node->mName.data);

        // You probably want to be able to select different than animations than the 0th.
        // But with Maya's DAE_FBX exporter, it is not possible.
        const aiAnimation* prevAnimation = last_anim->mAnimations[0];
        const aiAnimation* nextAnimation = current_anim->mAnimations[0];
        const aiNodeAnim* prevNodeAnim = findNodeAnim(prevAnimation, nodeName);
        const aiNodeAnim* nextNodeAnim = findNodeAnim(nextAnimation, nodeName);

        glm::mat4 nodeTransform = convertMatrix(node->mTransformation);

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

            factor = fmod(factor, 1.0f);

            // Interpolate the transformations and get the matrices
            aiVector3D prevScaling, nextScaling;
            calcInterpolatedScaling(prevScaling, prevAnimationTime, prevNodeAnim);
            calcInterpolatedScaling(nextScaling, nextAnimationTime, nextNodeAnim);
            aiVector3D scaling = interpolate(prevScaling, nextScaling, factor);
            glm::mat4 scalingM = glm::scale(glm::mat4(), glm::vec3(scaling.x, scaling.y, scaling.z));

            aiQuaternion prevRotation, nextRotation, rotation;
            calcInterpolatedRotation(prevRotation, prevAnimationTime, prevNodeAnim);
            calcInterpolatedRotation(nextRotation, nextAnimationTime, nextNodeAnim);
            // spherical interpolation, and it always chooses the shorter path (exactly what we want).
            aiQuaternion::Interpolate(rotation, prevRotation, nextRotation, factor);
            glm::mat4 rotationM = convertMatrix(rotation.GetMatrix());

            aiVector3D prevTranslation, nextTranslation;
            calcInterpolatedPosition(prevTranslation, prevAnimationTime, prevNodeAnim);
            calcInterpolatedPosition(nextTranslation, nextAnimationTime, nextNodeAnim);
            aiVector3D translation = interpolate(prevTranslation, nextTranslation, factor);
            glm::mat4 translationM;

            if(nodeName == root_bone) {
                // Transition Offset is a utility that helps you in creating better transitions between
                // animations. For example, if you want one of the character's leg to stay in it's place,
                // throughout the transition, it might only be possible if the character's center of mass
                // doesn't start from the origin on the XZ axis in the new animation. This utility is about
                // to interpolate the position of the center of mass from the origin to the place, where
                // it starts in the new animation. It isn't necessary, just makes the transition more
                // realistic. But it definitely has no use, when the animation is played backwards.
                glm::vec3 transitionOffset;
                if(!(current_flags & AnimFlag::Backwards)) {
                    transitionOffset = (start_offsets[curr_idx] - start_offsets[last_idx]) * factor;
                }
                current_offset =
                    (glm::vec3(nextTranslation.x, 0, nextTranslation.z) +
                    transitionOffset - last_transition_offset) * MOVE_SPEED_HACK;

                if(current_flags & AnimFlag::Mirrored) {
                    current_offset *= -1;
                }

                last_transition_offset = transitionOffset;
                translationM = glm::translate(glm::mat4(), glm::vec3(0, translation.y, 0));
            } else {
                translationM = glm::translate(glm::mat4(), glm::vec3(translation.x, translation.y, translation.z));
            }

            // Combine the transformations
            nodeTransform = translationM * rotationM * scalingM;
        }

        glm::mat4 globalTransformation = parentTransform * nodeTransform;

        if(bone_mapping.find(nodeName) != bone_mapping.end()) {
            unsigned boneIndex = bone_mapping[nodeName];
            bone_info[boneIndex].final_transform =
                global_inverse_transform * globalTransformation * bone_info[boneIndex].bone_offset;
        }

        for(unsigned i = 0; i < node->mNumChildren; i++) {
            transitionReadNodeHeirarchy(
                prevAnimationTime, nextAnimationTime, node->mChildren[i], globalTransformation
            );
        }
    }

    /// Does what it's name says, updates the bones transformations.
    /** @param time_in_seconds - Expected to be a time value in seconds. It doesn't matter, since when does it count the time, just it should be counting up. */
    void updateBoneInfo(float time_in_seconds) {

        time_in_seconds *= ANIM_SPEED_HACK; // for debugging

        if(!current_anim || current_anim->mAnimations == 0 ||
           !last_anim || last_anim->mAnimations == 0) {
            throw std::runtime_error("Tried to run an invalid animation.");
        }


        float last_ticks_per_second = last_anim->mAnimations[0]->mTicksPerSecond > 1e-10 ? // != 0
                                      last_anim->mAnimations[0]->mTicksPerSecond : 24.0f;

        float last_time_in_ticks = last_period_time * (last_speed * last_ticks_per_second);
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

        float current_time_in_ticks =
            (time_in_seconds - end_of_last_anim) * (current_speed * current_ticks_per_second);
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

        if(transition_time < current_speed * (time_in_seconds - end_of_last_anim)) {
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

    /// Updates the bones transformation and uploads them into the given uniforms.
    /** @param time_in_seconds - Expect a time value as a float, optimally since the start of the program.
      * @param bones - The uniform naming the bones array. It should be indexable. */
    void boneTransform(float time_in_seconds,
                       LazyUniform<glm::mat4>& bones) {
        updateBoneInfo(time_in_seconds);

        for(unsigned i = 0; i < num_bones; i++) {
            bones[i] = bone_info[i].final_transform;
        }
    }

    // -------======{[ Animation changers ]}======-------

    /// Adds an external animation from a file.
    /** You should give this animation a name, you will be able to
      * reference it with this name in the future. You can also set
      * the default animation modifier flags for this animation.
      * These flags will be used everytime you change to this animation
      * without explicitly specifying new flags.
      * @param filename - The name of the file, from where to load the animation.
      * @param animName - The name with you wanna reference this animation.
      * @param flags - You can specify animation modifiers, like repeat the animation after it ends, play it backwards, etc...
      * @param speed - Sets the default speed of the animation. If it's 1, it will be played with the its default speed. If it's negative, it will be played backwards. */
    void add_animation(const std::string& filename,
                       const std::string& animName,
                       unsigned flags = AnimFlag::None,
                       float speed = 1.0f) {

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
        speed_modifiers.push_back(speed);
    }

    /// Sets the default animation, that will be played if you don't set to play another one.
    /** @param animName - The user-defined name of the animation that should be set to be default.
      * @param default_transition_time - The fading time that should be used when changing to the default animation. */
    void set_default_animation(const std::string& animName,
                               float default_transition_time = 0.0f) {

        if(anim_names.find(animName) == anim_names.end()) {
            throw std::invalid_argument(
                "Tried to set default animation to '" + animName + "', "
                "but the AnimatedMesh doesn't have an animation with that name"
            );
        }

        default_idx = anim_names[animName];
        this->default_transition_time = default_transition_time;

        if(!(default_flags[default_idx] & AnimFlag::Repeat)) {
            throw std::invalid_argument(
                "Tried to set a default animation that didn't have the "
                "repeat flag, but the default animation must be a cycle."
            );
        }
    }

private:
    /// Changes the current animation to a specified one.
    /** @param animIndex - The index of the new animation.
      * @param currentTime - The current time in seconds, optimally since the start of the program.
      * @param transition_time - The fading time to be used for the transition.
      * @param flags - A bitfield containing the animation specifier flags.
      * @param speed - Sets the speed of the animation. If it's 0, will play with the speed specified at the addAnim. If it's negative, it will be played backwards. */
    void change_animation(size_t animIndex,
                          float currentTime,
                          float transition_time,
                          unsigned flags,
                          float speed = 1.0f) {

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
        if(speed > 0.0f) {
            current_flags = flags;
        } else {
            speed *= -1;
            current_flags = flags ^ AnimFlag::Backwards;
        }

        last_speed = current_speed;
        current_speed = speed;
    }

public:
    /// Tries to change the current animation to a specified one.
    /** Only changes it if the current animation is interruptable,
      * it's not currently in a transition, and new animation is
      * not the same as the one currently playing.
      * @param animName - The user-defined name of the animation.
      * @param currentTime - The current time in seconds, optimally since the start of the program.
      * @param transition_time - The fading time to be used for the transition.
      * @param flags - A bitfield containing the animation specifier flags.
      * @param speed - Sets the speed of the animation. If it's 0, will play with the speed specified at the addAnim. If it's negative, it will be played backwards. */
    void set_current_animation(const std::string& animName,
                               float currentTime,
                               float transition_time,
                               unsigned flags,
                               float speed = 0.0f) {

        if((end_of_last_anim + this->transition_time) <= currentTime
           && (current_flags & AnimFlag::Interruptable)
        ) {
            force_current_animation(animName, currentTime, transition_time, flags, speed);
        }
    }

    /// Forces the current animation to a specified one.
    /** Only changes it if the new animation is not the same as the one currently playing.
      * @param animName - The user-defined name of the animation.
      * @param currentTime - The current time in seconds, optimally since the start of the program.
      * @param transition_time - The fading time to be used for the transition.
      * @param flags - A bitfield containing the animation specifier flags.
      * @param speed - Sets the speed of the animation. If it's 0, will play with the speed specified at the addAnim. If it's negative, it will be played backwards. */
    void force_current_animation(const std::string& animName,
                                 float currentTime,
                                 float transition_time,
                                 unsigned flags,
                                 float speed = 0.0f) {

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

        if(fabs(speed) < 1e-5) {
            change_animation(
                animIndex,
                currentTime,
                transition_time,
                flags,
                speed_modifiers[animIndex]
            );
        } else {
            change_animation(
                animIndex,
                currentTime,
                transition_time,
                flags,
                speed
            );
        }
    }

    /// Tries to change the current animation to a specified one, using the default anim modifier flags specified for this anim.
    /** Only changes it if the current animation is interruptable,
      * it's not currently in a transition, and new animation is
      * not the same as the one currently playing.
      * @param animName - The user-defined name of the animation.
      * @param currentTime - The current time in seconds, optimally since the start of the program.
      * @param transition_time - The fading time to be used for the transition.
      * @param speed - Sets the speed of the animation. If it's 0, will play with the speed specified at the addAnim. If it's negative, it will be played backwards. */
    void set_current_animation(const std::string& animName,
                               float currentTime,
                               float transition_time = 0.0f,
                               float speed = 0.0f) {

        if((end_of_last_anim + this->transition_time) <= currentTime
           && (current_flags & AnimFlag::Interruptable)
        ) {
            force_current_animation(animName, currentTime, transition_time, speed);
        }
    }

    /// Forces the current animation to a specified one, using the default anim modifier flags specified for this anim.
    /** Only changes it if the new animation is not the same as the one currently playing.
      * @param animName - The user-defined name of the animation.
      * @param currentTime - The current time in seconds, optimally since the start of the program.
      * @param transition_time - The fading time to be used for the transition.
      * @param speed - Sets the speed of the animation. If it's 0, will play with the speed specified at the addAnim. If it's negative, it will be played backwards. */
    void force_current_animation(const std::string& animName,
                                 float currentTime,
                                 float transition_time = 0.0f,
                                 float speed = 0.0f) {

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

        if(fabs(speed) < 1e-5) {
            change_animation(
                animIndex,
                currentTime,
                transition_time,
                default_flags[animIndex],
                speed_modifiers[animIndex]
            );
        } else {
            change_animation(
                animIndex,
                currentTime,
                transition_time,
                default_flags[animIndex],
                speed
            );
        }
    }

    /// Tries to change the current animation to the default one.
    /** Only changes it if the current animation is interruptable,
      * it's not currently in a transition, and new animation is
      * not the same as the one currently playing. Will use the default
      * anim modifier flags for the default anim.
      * @param currentTime - The current time in seconds, optimally since the start of the program. */
    void set_anim_to_default(float currentTime) {
        if(current_flags & AnimFlag::Interruptable)
            force_anim_to_default(currentTime);
    }

    /// Forces the current animation to the default one.
    /** Only changes it if the new animation is not the same as the one currently
      * playing. Will use the default anim modifier flags for the default anim.
      * @param currentTime - The current time in seconds, optimally since the start of the program. */
    void force_anim_to_default(float currentTime) {
        assert(default_flags[default_idx] & AnimFlag::Repeat);
        if(current_anim != animations[default_idx])
            change_animation(
                default_idx,
                currentTime,
                default_transition_time,
                default_flags[default_idx],
                speed_modifiers[default_idx]
            );
    }

    /// Returns the offset of the root bone, since it was last queried.
    /** It should be queried every frame (hence the name),
      * but it works even if you only query every 10th frame,
      * just the animation will "lag", and will look bad. */
    glm::vec3 offset_since_last_frame() {
        auto ret = current_offset - last_offset;
        last_offset = current_offset;
        ret.y = 0;
        return ret;
    }

}; // AnimatedMesh

} // namespace oglwrap

