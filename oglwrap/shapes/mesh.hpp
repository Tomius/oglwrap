/** @file mesh.hpp
    @brief A Mesh loader using assimp
*/

#ifndef SHAPES_MESH_HPP
#define SHAPES_MESH_HPP

#include <string>
#include <vector>
#include <climits>
#include <iostream>
#include <stdexcept>
#include <GL/glew.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "../error.hpp"
#include "../enums.hpp"
#include "../buffer.hpp"
#include "../vertexAttrib.hpp"
#include "../textures/texture_2D.hpp"

namespace oglwrap {

/// A class that can load in and draw meshes from over 30 file formats using assimp.
class Mesh : protected RefCounted {
protected:

    struct MeshEntry {
        VertexArray vao;
        ArrayBuffer verts, normals, texCoords;
        IndexBuffer indices;
        unsigned idxCount, materialIndex;
        DataType idxType;

        MeshEntry() : materialIndex(0xFFFFFFFF) {} // Invalid material
    };

    // The scene will actually belong to the importer. It is dynamically allocated,
    // as we don't want its copy constructor to run, when we create a copy of a Mesh.
    Assimp::Importer *importer;
    const aiScene* scene;

    std::string filename;
    bool rdy2draw, useMaterials;
    // Coping these will only copy the handles, the actual OpenGL object won't be duplicated.
    std::vector<MeshEntry> entries;
    std::vector<Texture2D> textures;

public:
    Mesh(const std::string& filename, unsigned int flags)
        : importer(new Assimp::Importer)
        , scene(importer->ReadFile(
              filename.c_str(),
              flags | aiProcess_Triangulate
          ))
        , filename(filename)
        , rdy2draw(false)
        , useMaterials(false)
        , entries(scene->mNumMeshes) {

        if(!scene) {
            throw std::runtime_error("Error parsing " + filename + " : " + importer->GetErrorString());
        }
    }

    ~Mesh() {
        if(isDeletable())
            delete importer;
    }

private:
    template <class IdxType>
    /// A template for setting different types (byte/short/int) of indices.
    /** This expect the correct vao to be already bound!! */
    /// @param index - The index of the entry
    void SetIndices(size_t index) {
        const aiMesh* paiMesh = scene->mMeshes[index];

        std::vector<IdxType> indicesVector;
        indicesVector.reserve(paiMesh->mNumFaces * 3);

        for(size_t i = 0; i < paiMesh->mNumFaces; i++) {
            const aiFace& face = paiMesh->mFaces[i];
            if(face.mNumIndices == 3) { // The invalid vertices are just ignored.
                indicesVector.push_back(face.mIndices[0]);
                indicesVector.push_back(face.mIndices[1]);
                indicesVector.push_back(face.mIndices[2]);
            }
        }

        entries[index].indices.Bind();
        entries[index].indices.Data(indicesVector);
        entries[index].idxCount = indicesVector.size();
    }

public:
    /// Loads in vertex positions and indices, and uploads the former into an attribute array.
    /** Uploads the vertex positions data to an attribute array, and sets it up for use.
      * Calling this function changes the currently active VAO and ArrayBuffer.
      * The mesh cannot be drawn without calling this function. */
    /// @param attrib - The attribute array to use as destination.
    void Positions(VertexAttribArray attrib) {
        for(size_t i = 0; i < entries.size(); i++) {
            const aiMesh* paiMesh = scene->mMeshes[i];

            // ~~~~~~<{ Load the vertices }>~~~~~~

            std::vector<aiVector3D> vertsVector;
            size_t vertNum = paiMesh->mNumVertices;
            vertsVector.reserve(vertNum);

            for(size_t i = 0; i < vertNum; i++) {
                vertsVector.push_back(paiMesh->mVertices[i]);
            }

            entries[i].vao.Bind();

            entries[i].verts.Bind();
            entries[i].verts.Data(vertsVector);
            attrib.Setup<float>(3).Enable();

            // ~~~~~~<{ Load the indices }>~~~~~~

            if(paiMesh->mNumFaces * 3 < UCHAR_MAX) {
                entries[i].idxType = DataType::UnsignedByte;
                SetIndices<unsigned char>(i);
            } else if(paiMesh->mNumFaces * 3 < USHRT_MAX) {
                entries[i].idxType = DataType::UnsignedShort;
                SetIndices<unsigned short>(i);
            } else {
                entries[i].idxType = DataType::UnsignedInt;
                SetIndices<unsigned int>(i);
            }
        }

        VertexArray::Unbind();
        rdy2draw = true;
    }

    /// Loads in vertex normals, and uploads it to an attribute array.
    /** Uploads the vertex normals data to an attribute array, and sets it up for use.
      * Calling this function changes the currently active VAO and ArrayBuffer. */
    /// @param attrib - The attribute array to use as destination.
    void Normals(VertexAttribArray attrib) {
        for(size_t i = 0; i < entries.size(); i++) {
            const aiMesh* paiMesh = scene->mMeshes[i];

            std::vector<aiVector3D> normalsVector;

            size_t vertNum = paiMesh->mNumVertices;
            normalsVector.reserve(vertNum);

            for(size_t i = 0; i < vertNum; i++) {
                normalsVector.push_back(paiMesh->mNormals[i]);
            }

            entries[i].vao.Bind();

            entries[i].normals.Bind();
            entries[i].normals.Data(normalsVector);
            attrib.Setup<float>(3).Enable();
        }

        VertexArray::Unbind();
    }

    /// Checks if at least one mesh has texcoords
    /** Returns true if at least one mesh in the scene has texture
      * coordinates in the specified texture coordinate set. */
    /// @param texCoordSet - Specifies the index of the texture coordinate set that should be inspected
    bool HasTexCoords(unsigned char texCoordSet = 0) {
        for(size_t i = 0; i < entries.size(); i++) {
            if(scene->mMeshes[i]->HasTextureCoords(texCoordSet)) {
                return true;
            }
        }

        return false;
    }

    /// Checks if every mesh has texcoords
    /** Returns true if all of the meshes in the scene have texture
      * coordinates in the specified texture coordinate set. */
    /// @param texCoordSet - Specifies the index of the texture coordinate set that should be inspected
    bool EveryEntryHasTexCoords(unsigned char texCoordSet = 0) {
        for(size_t i = 0; i < entries.size(); i++) {
            if(!scene->mMeshes[i]->HasTextureCoords(texCoordSet)) {
                return false;
            }
        }

        return true;
    }

    /// Loads in vertex texture coordinates (the 0th set), and the materials.
    /** Uploads the vertex textures coordinates data to an attribute array,
      * and sets it up for use. Also loads in the materials (textures) for
      * the mesh. May write to the stderr if a material is missing.
      * Calling this function changes the currently active VAO and ArrayBuffer. */
    /// @param attrib - The attribute array to use as destination.
    /// @param texCoordSet - Specifies the index of the texture coordinate set that should be used
    void TexCoords(VertexAttribArray attrib, unsigned char texCoordSet = 0) {

        // Initialize TexCoords
        for(size_t i = 0; i < entries.size(); i++) {
            const aiMesh* paiMesh = scene->mMeshes[i];
            entries[i].materialIndex = paiMesh->mMaterialIndex;

            std::vector<aiVector2D> texCoordsVector;

            size_t vertNum = paiMesh->mNumVertices;
            if(paiMesh->HasTextureCoords(texCoordSet)) {
                texCoordsVector.reserve(vertNum);
                for(size_t i = 0; i < vertNum; i++) {
                    const aiVector3D& texC = paiMesh->mTextureCoords[texCoordSet][i];
                    texCoordsVector.push_back(aiVector2D(texC.x, texC.y));
                }
            } else {
                texCoordsVector.resize(vertNum);
            }

            entries[i].vao.Bind();

            entries[i].texCoords.Bind();
            entries[i].texCoords.Data(texCoordsVector);
            attrib.Setup<float>(2).Enable();
        }

        VertexArray::Unbind();

        // Then initialize the materials (they can't be used without texture coordinates).
        textures.resize(scene->mNumMaterials);
        if(scene->mNumMaterials) {
            useMaterials = true;

            // Extract the directory part from the file name
            std::string::size_type SlashIndex = filename.find_last_of("/");
            std::string dir;

            if(SlashIndex == std::string::npos) {
                dir = "./";
            } else if(SlashIndex == 0) {
                dir = "/";
            } else {
                dir = filename.substr(0, SlashIndex + 1);
            }

            // Initialize the materials
            for(unsigned int i = 0; i < scene->mNumMaterials; i++) {
                const aiMaterial* pMaterial = scene->mMaterials[i];

                aiString filepath;
                if(pMaterial->GetTextureCount(aiTextureType_DIFFUSE) > 0 &&
                        pMaterial->GetTexture(aiTextureType_DIFFUSE, 0, &filepath,
                                              NULL, NULL, NULL, NULL, NULL) == AI_SUCCESS) {
                    textures[i].Bind();
                    textures[i].LoadTexture(dir + filepath.data);
                    textures[i].MinFilter(MinF::Linear);
                    textures[i].MagFilter(MagF::Linear);
                }
            }
        }
    }

    /// Renders the mesh.
    void Render() {
        if(!rdy2draw) {
            return;
        }
        for(unsigned int i = 0 ; i < entries.size(); i++) {
            entries[i].vao.Bind();

            if(useMaterials) {
                const unsigned int materialIndex = entries[i].materialIndex;
                if(materialIndex < textures.size()) {
                    textures[materialIndex].Bind();
                }
            }

            gl(DrawElements(
                   GL_TRIANGLES,
                   entries[i].idxCount,
                   entries[i].idxType,
                   0
               ));
        }

        VertexArray::Unbind();
    }

    /// Gives information about the mesh's bounding cuboid.
    /// @param center - The vec3 where bounding cuboid's center is to be returned.
    /// @param edges - The vec3 where bounding cuboid's edge lengths are to be returned.
    void BoundingCuboid(glm::vec3& center, glm::vec3& edges) {
        // Idea: get the minimums and maximums of the vertex positions
        // in each coordinate. Then the average of the mins and maxes
        // will be the center of the cuboid
        glm::vec3 mins, maxes;
        for(size_t entry = 0; entry < entries.size(); entry++) {
            const aiMesh* paiMesh = scene->mMeshes[entry];

            for(size_t i = 0; i < paiMesh->mNumVertices; i++) {
                if(paiMesh->mVertices[i].x < mins.x) {
                    mins.x = paiMesh->mVertices[i].x;
                }
                if(paiMesh->mVertices[i].y < mins.y) {
                    mins.y = paiMesh->mVertices[i].y;
                }
                if(paiMesh->mVertices[i].z < mins.z) {
                    mins.z = paiMesh->mVertices[i].z;
                }

                if(maxes.x < paiMesh->mVertices[i].x) {
                    maxes.x = paiMesh->mVertices[i].x;
                }
                if(maxes.y < paiMesh->mVertices[i].y) {
                    maxes.y = paiMesh->mVertices[i].y;
                }
                if(maxes.z < paiMesh->mVertices[i].z) {
                    maxes.z = paiMesh->mVertices[i].z;
                }
            }
        }

        center = (mins + maxes) / 2.0f;
        edges = glm::abs(maxes - mins);
    }

    /// Returns the center (as xyz) and radius (as w) of the bounding sphere.
    glm::vec4 BoundingSphere() {
        glm::vec3 center, edges;
        BoundingCuboid(center, edges);
        return glm::vec4(center, std::max(edges.x, std::max(edges.y, edges.z)));
    }

    /// Returns the center of the bounding sphere.
    glm::vec3 BoundingSphere_Center() {
        glm::vec3 center, edges;
        BoundingCuboid(center, edges);
        return center;
    }

    /// Returns the radius of the bounding sphere.
    float BoundingSphere_Radius() {
        glm::vec3 center, edges;
        BoundingCuboid(center, edges);
        return std::max(edges.x, std::max(edges.y, edges.z));
    }

    /// @brief This is for animated meshes, to figure out the template argument for the skinned mesh class.
    /** Without this, you would have to create a AnimatedMesh in order to know how to create the AnimatedMesh*/
    unsigned char MaxBonesPerVertex() const {
        std::vector<unsigned char> bonesPerVertex[scene->mNumMeshes];
        for(size_t entry = 0; entry < entries.size(); entry++) {
            const aiMesh* pMesh = scene->mMeshes[entry];
            bonesPerVertex[entry].resize(pMesh->mNumVertices);
            for(unsigned i = 0; i < pMesh->mNumBones; i++) {
                for(unsigned j = 0; j < pMesh->mBones[i]->mNumWeights; j++) {
                    unsigned vertexID = pMesh->mBones[i]->mWeights[j].mVertexId;
                    bonesPerVertex[entry][vertexID]++;
                }
            }
        }

        unsigned char max = 0;
        for(size_t i = 0; i < scene->mNumMeshes; i++) {
            for(size_t j = 0; j < scene->mMeshes[i]->mNumVertices; j++) {
                if(bonesPerVertex[i][j] > max) {
                    max = bonesPerVertex[i][j];
                }
            }
        }
        return max;
    }

    unsigned char NumBoneAttribs() const {
        const unsigned char mbpv = MaxBonesPerVertex();
        return (mbpv%4 == 0) ? (mbpv/4) : (mbpv/4 + 1);
    }
};

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

template <unsigned char numBoneAttribs = 1>
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
public:
    AnimatedMesh(const std::string& filename, unsigned int flags)
        : Mesh(filename, flags)
        , boneBuffers(scene->mNumMeshes)
        , numBones(0) {

        glm::mat4 matrix = convertMatrix(scene->mRootNode->mTransformation);
        globalInverseTransform = glm::inverse(matrix);

        if(MaxBonesPerVertex() > 4 * numBoneAttribs)
            std::cerr << "Error in AnimatedMesh: " << filename << "\n" <<
            "Some vertices depend on " << MaxBonesPerVertex() << " bones, " <<
            "but you only specified " << 4 * numBoneAttribs << " bone slots per vertex.\n" <<
            "For these vertices some of the lowest influence bones will be ignored. \n"
            "You would probably want to increase the numBoneAttribs template argument" << std::endl;
    }

    AnimatedMesh(const Mesh& src)
        : Mesh(src) // Copy ctor doesn't duplicate the actual data.
        , boneBuffers(scene->mNumMeshes)
        , numBones(0) {

        glm::mat4 matrix = convertMatrix(scene->mRootNode->mTransformation);
        globalInverseTransform = glm::inverse(matrix);

        if(MaxBonesPerVertex() > 4 * numBoneAttribs)
            std::cerr << "Error in AnimatedMesh: " << filename << "\n" <<
            "Some vertices depend on " << MaxBonesPerVertex() << " bones, " <<
            "but you only specified " << 4 * numBoneAttribs << " bone slots per vertex.\n" <<
            "For these vertices some of the lowest influence bones will be ignored. \n"
            "You would probably want to increase the numBoneAttribs template argument" << std::endl;
    }

/*         //=====:==-==-==:=====\\                                 //=====:==-==-==:=====\\
    <---<}>==~=~=~==--==--==~=~=~==<{>----- Skin definition -----<}>==~=~=~==--==--==~=~=~==<{>--->
           \\=====:==-==-==:=====//                                 \\=====:==-==-==:=====//          */

private:
    void MapBones() {
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

    template <class Index_t>
    void LoadBones(DataType idx_t,
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
            for(int boneAttribSet = 0; boneAttribSet < numBoneAttribs; boneAttribSet++) {
                entries[entry].vao.Bind();
                boneBuffers[entry].Bind();
                boneBuffers[entry].Data(bones[entry]);

                const size_t stride = sizeof(VertexBoneData<Index_t>);
                intptr_t baseOffset =
                    boneAttribSet * sizeof(VertexBoneData_PerAttribute<Index_t>);
                intptr_t weightOffset = baseOffset + 4 * sizeof(Index_t);

                boneIDs[boneAttribSet].Setup(4, idx_t, stride, (const void*)baseOffset).Enable();
                boneWeights[boneAttribSet].Setup(4, DataType::Float, stride, (const void*)weightOffset).Enable();
            }

            VertexArray::Unbind();
        }

    }

public:

    void Bones(LazyVertexAttribArray boneIDs, LazyVertexAttribArray boneWeights) {
        MapBones();

        if(numBones < UCHAR_MAX)
            LoadBones<unsigned char>(DataType::UnsignedByte, boneIDs, boneWeights);
        else if(numBones < USHRT_MAX)
            LoadBones<unsigned short>(DataType::UnsignedShort, boneIDs, boneWeights);
        else // more than 65535 bones? WTF???
            LoadBones<unsigned int>(DataType::UnsignedInt, boneIDs, boneWeights);
    }

/*         //=====:==-==-==:=====\\                           //=====:==-==-==:=====\\
    <---<}>==~=~=~==--==--==~=~=~==<{>----- Animation -----<}>==~=~=~==--==--==~=~=~==<{>--->
           \\=====:==-==-==:=====//                           \\=====:==-==-==:=====//          */

private:

    unsigned FindPosition(float animationTime, const aiNodeAnim* pNodeAnim) {
        // Find the first one that is bigger
        for(unsigned i = 0; i < pNodeAnim->mNumPositionKeys - 1; i++) {
            if(animationTime < (float)pNodeAnim->mPositionKeys[i + 1].mTime) {
                return i;
            }
        }
        // Should never get here
        throw std::runtime_error("Animation Error - Position keyframe not found");
    }

    unsigned FindRotation(float animationTime, const aiNodeAnim* pNodeAnim) {
        for(unsigned i = 0; i < pNodeAnim->mNumRotationKeys - 1; i++) {
            if(animationTime < (float)pNodeAnim->mRotationKeys[i + 1].mTime) {
                return i;
            }
        }
        throw std::runtime_error("Animation Error - Rotation keyframe not found");
    }

    unsigned FindScaling(float animationTime, const aiNodeAnim* pNodeAnim) {
        for(unsigned i = 0; i < pNodeAnim->mNumScalingKeys - 1; i++) {
            if(animationTime < (float)pNodeAnim->mScalingKeys[i + 1].mTime) {
                return i;
            }
        }
        throw std::runtime_error("Animation Error - Scaling keyframe not found");
    }

    void CalcInterpolatedPosition(aiVector3D& out, float animTime, const aiNodeAnim* pNodeAnim) {
        const auto& keys = pNodeAnim->mPositionKeys;
        const auto& numKeys = pNodeAnim->mNumPositionKeys;

        if(numKeys == 1) {
            out = keys[0].mValue;
            return;
        }

        size_t i = FindPosition(animTime, pNodeAnim);
        float deltaTime = keys[i + 1].mTime - keys[i].mTime;
        float factor = (animTime - (float)keys[i].mTime) / deltaTime;
        if(factor < 0.0f)
            factor = 0.0f;
        if(factor > 1.0f)
            factor = 1.0f;

        const aiVector3D& start = keys[i].mValue;
        const aiVector3D& end   = keys[i + 1].mValue;
        out = start + factor * (end - start);
    }

    void CalcInterpolatedRotation(aiQuaternion& out, float animTime, const aiNodeAnim* pNodeAnim) {
        const auto& keys = pNodeAnim->mRotationKeys;
        const auto& numKeys = pNodeAnim->mNumRotationKeys;

        if(numKeys == 1) {
            out = keys[0].mValue;
            return;
        }

        size_t i = FindRotation(animTime, pNodeAnim);
        float deltaTime = keys[i + 1].mTime - keys[i].mTime;
        float factor = (animTime - (float)keys[i].mTime) / deltaTime;
        if(factor < 0.0f)
            factor = 0.0f;
        if(factor > 1.0f)
            factor = 1.0f;

        const aiQuaternion& start = keys[i].mValue;
        const aiQuaternion& end   = keys[i + 1].mValue;
        aiQuaternion::Interpolate(out, start, end, factor);
        out = out.Normalize();
    }

    void CalcInterpolatedScaling(aiVector3D& out, float animTime, const aiNodeAnim* pNodeAnim) {
        const auto& keys = pNodeAnim->mScalingKeys;
        const auto& numKeys = pNodeAnim->mNumScalingKeys;

        if(numKeys == 1) {
            out = keys[0].mValue;
            return;
        }

        size_t i = FindRotation(animTime, pNodeAnim);
        float deltaTime = keys[i + 1].mTime - keys[i].mTime;
        float factor = (animTime - (float)keys[i].mTime) / deltaTime;
        if(factor < 0.0f)
            factor = 0.0f;
        else if(factor > 1.0f)
            factor = 1.0f;

        const aiVector3D& start = keys[i].mValue;
        const aiVector3D& end   = keys[i + 1].mValue;
        out = start + factor * (end - start);
    }

    const aiNodeAnim* FindNodeAnim(const aiAnimation* pAnimation, const std::string nodeName) {
        for(unsigned i = 0; i < pAnimation->mNumChannels; i++) {
            const aiNodeAnim* pNodeAnim = pAnimation->mChannels[i];

            if(std::string(pNodeAnim->mNodeName.data) == nodeName) {
                return pNodeAnim;
            }
        }

        return nullptr;
    }

    // Recursive function that travels through the entire node hierarchy
    void ReadNodeHeirarchy(float animationTime, const aiNode* pNode, const glm::mat4& parentTransform) {
        std::string nodeName(pNode->mName.data);

        // FIXME
        const aiAnimation* pAnimation = scene->mAnimations[0];
        const aiNodeAnim* pNodeAnim = FindNodeAnim(pAnimation, nodeName);

        glm::mat4 nodeTransform = convertMatrix(pNode->mTransformation);

        if(pNodeAnim) {
            // Interpolate the transformations and get the matrices
            aiVector3D scaling;
            CalcInterpolatedScaling(scaling, animationTime, pNodeAnim);
            glm::mat4 scalingM = glm::scale(glm::mat4(), glm::vec3(scaling.x, scaling.y, scaling.z));

            aiQuaternion rotation;
            CalcInterpolatedRotation(rotation, animationTime, pNodeAnim);
            glm::mat4 rotationM = convertMatrix(rotation.GetMatrix());

            aiVector3D translation;
            CalcInterpolatedPosition(translation, animationTime, pNodeAnim);
            glm::mat4 translationM =
                glm::translate(glm::mat4(), glm::vec3(translation.x, translation.y, translation.z));

            // Combine the transformations
            nodeTransform = translationM * rotationM * scalingM;
        }

        glm::mat4 globalTransformation = parentTransform * nodeTransform;

        if(boneMapping.find(nodeName) != boneMapping.end()) {
            unsigned boneIndex = boneMapping[nodeName];
            boneInfo[boneIndex].finalTransformation =
                globalInverseTransform * globalTransformation * boneInfo[boneIndex].boneOffset;
        }

        for(unsigned i = 0; i < pNode->mNumChildren; i++) {
            ReadNodeHeirarchy(animationTime, pNode->mChildren[i], globalTransformation);
        }
    }

public:

    void UpdateBoneInfo(float timeInSeconds) {
        float ticksPerSecond = scene->mAnimations[0]->mTicksPerSecond > 1e-10 ? // != 0
                               scene->mAnimations[0]->mTicksPerSecond : 24.0f;
        float timeInTicks = timeInSeconds * ticksPerSecond;
        float animationTime = fmod(timeInTicks, (float)scene->mAnimations[0]->mDuration);

        ReadNodeHeirarchy(animationTime, scene->mRootNode, glm::mat4());
    }

    void BoneTransform(float timeInSeconds,
                       LazyUniform<glm::mat4>& bones) {
        UpdateBoneInfo(timeInSeconds);

        for(unsigned i = 0; i < numBones; i++) {
            bones[i] = boneInfo[i].finalTransformation;
        }
    }
}; // AnimatedMesh

} // namespace oglwrap

#endif // include guard
