/** @file mesh.hpp
    @brief A Mesh loader using assimp
*/

#pragma once

#include <climits>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

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

    Assimp::Importer importer;
    const aiScene* scene;

    std::string filename;
    std::vector<MeshEntry> entries;
    std::vector<Texture2D> textures;

    bool is_setup_positions, is_setup_normals, is_setup_texcoords, useMaterials;

    // It shouldn't be copyable
    Mesh(const Mesh& src);
    void operator=(const Mesh& rhs);

public:
    Mesh(const std::string& filename, unsigned int flags)
        : scene(importer.ReadFile(
              filename.c_str(),
              flags | aiProcess_Triangulate
          ))
        , filename(filename)
        , entries(scene->mNumMeshes)
        , is_setup_positions(false)
        , is_setup_normals(false)
        , is_setup_texcoords(false)
        , useMaterials(false) {

        if(!scene) {
            throw std::runtime_error("Error parsing " + filename + " : " + importer.GetErrorString());
        }
    }

private:
    template <class IdxType>
    /// @brief A template for setting different types (byte/short/int) of indices.
    /** This expect the correct vao to be already bound!! */
    /// @param index - The index of the entry
    void setIndices(size_t index) {
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

        entries[index].indices.bind();
        entries[index].indices.data(indicesVector);
        entries[index].idxCount = indicesVector.size();
    }

public:
    /// @brief Loads in vertex positions and indices, and uploads the former into an attribute array.
    /** Uploads the vertex positions data to an attribute array, and sets it up for use.
      * Calling this function changes the currently active VAO and ArrayBuffer.
      * The mesh cannot be drawn without calling this function. */
    /// @param attrib - The attribute array to use as destination.
    void setup_positions(VertexAttribArray attrib) {
        if(is_setup_positions) {
            std::logic_error("Mesh::setup_position is called multiply times on the same object");
        } else {
            is_setup_positions = true;
        }

        for(size_t i = 0; i < entries.size(); i++) {
            const aiMesh* paiMesh = scene->mMeshes[i];

            // ~~~~~~<{ Load the vertices }>~~~~~~

            std::vector<aiVector3D> vertsVector;
            size_t vertNum = paiMesh->mNumVertices;
            vertsVector.reserve(vertNum);

            for(size_t i = 0; i < vertNum; i++) {
                vertsVector.push_back(paiMesh->mVertices[i]);
            }

            entries[i].vao.bind();

            entries[i].verts.bind();
            entries[i].verts.data(vertsVector);
            attrib.setup<float>(3).enable();

            // ~~~~~~<{ Load the indices }>~~~~~~

            if(paiMesh->mNumFaces * 3 < UCHAR_MAX) {
                entries[i].idxType = DataType::UnsignedByte;
                setIndices<unsigned char>(i);
            } else if(paiMesh->mNumFaces * 3 < USHRT_MAX) {
                entries[i].idxType = DataType::UnsignedShort;
                setIndices<unsigned short>(i);
            } else {
                entries[i].idxType = DataType::UnsignedInt;
                setIndices<unsigned int>(i);
            }
        }

        VertexArray::unbind();
    }

    /// @brief Loads in vertex normals, and uploads it to an attribute array.
    /** Uploads the vertex normals data to an attribute array, and sets it up for use.
      * Calling this function changes the currently active VAO and ArrayBuffer. */
    /// @param attrib - The attribute array to use as destination.
    void setup_normals(VertexAttribArray attrib) {

        if(is_setup_normals) {
            std::logic_error("Mesh::setup_normals is called multiply times on the same object");
        } else {
            is_setup_normals = true;
        }

        for(size_t i = 0; i < entries.size(); i++) {
            const aiMesh* paiMesh = scene->mMeshes[i];

            std::vector<aiVector3D> normalsVector;

            size_t vertNum = paiMesh->mNumVertices;
            normalsVector.reserve(vertNum);

            for(size_t i = 0; i < vertNum; i++) {
                normalsVector.push_back(paiMesh->mNormals[i]);
            }

            entries[i].vao.bind();

            entries[i].normals.bind();
            entries[i].normals.data(normalsVector);
            attrib.setup<float>(3).enable();
        }

        VertexArray::unbind();
    }

    /// Checks if every mesh in the scene has texcoords
    /** Returns true if all of the meshes in the scene have texture
      * coordinates in the specified texture coordinate set. */
    /// @param texCoordSet - Specifies the index of the texture coordinate set that should be inspected
    bool hasTexCoords(unsigned char texCoordSet = 0) {
        for(size_t i = 0; i < entries.size(); i++) {
            if(!scene->mMeshes[i]->HasTextureCoords(texCoordSet)) {
                return false;
            }
        }

        return true;
    }

    /// @brief Loads in vertex texture coordinates (the 0th set), and the materials.
    /** Uploads the vertex textures coordinates data to an attribute array,
      * and sets it up for use. Also loads in the materials (textures) for
      * the mesh. May write to the stderr if a material is missing.
      * Calling this function changes the currently active VAO and ArrayBuffer. */
    /// @param attrib - The attribute array to use as destination.
    /// @param texCoordSet - Specifies the index of the texture coordinate set that should be used
    void setup_texCoords(VertexAttribArray attrib, unsigned char texCoordSet = 0) {

        if(is_setup_texcoords) {
            std::logic_error("Mesh::setup_texCoords is called multiply times on the same object");
        } else {
            is_setup_texcoords = true;
        }

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

            entries[i].vao.bind();

            entries[i].texCoords.bind();
            entries[i].texCoords.data(texCoordsVector);
            attrib.setup<float>(2).enable();
        }

        VertexArray::unbind();

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
                    textures[i].bind();
                    textures[i].loadTexture(dir + filepath.data);
                    textures[i].minFilter(MinF::Linear);
                    textures[i].magFilter(MagF::Linear);
                }
            }
        }
    }

    /// Renders the mesh.
    void render() {
        if(!is_setup_positions) {
            return;
        }
        for(unsigned int i = 0 ; i < entries.size(); i++) {
            entries[i].vao.bind();

            if(useMaterials) {
                const unsigned int materialIndex = entries[i].materialIndex;
                if(materialIndex < textures.size()) {
                    textures[materialIndex].bind();
                }
            }

            gl(DrawElements(
                   GL_TRIANGLES,
                   entries[i].idxCount,
                   entries[i].idxType,
                   0
               ));
        }

        VertexArray::unbind();
    }

    /// Gives information about the mesh's bounding cuboid.
    /// @param center - The vec3 where bounding cuboid's center is to be returned.
    /// @param edges - The vec3 where bounding cuboid's edge lengths are to be returned.
    void boundingCuboid(glm::vec3& center, glm::vec3& edges) {
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
    glm::vec4 boundingSphere() {
        glm::vec3 center, edges;
        boundingCuboid(center, edges);
        return glm::vec4(center, std::max(edges.x, std::max(edges.y, edges.z)) / 2);
    }

    /// Returns the center of the bounding sphere.
    glm::vec3 boundingSphere_Center() {
        glm::vec3 center, edges;
        boundingCuboid(center, edges);
        return center;
    }

    /// Returns the radius of the bounding sphere.
    float boundingSphere_Radius() {
        glm::vec3 center, edges;
        boundingCuboid(center, edges);
        return std::max(edges.x, std::max(edges.y, edges.z)) / 2;
    }

    /// @brief This is for animated meshes, to figure out the template argument for the skinned mesh class.
    /** Without this, you would have to create a AnimatedMesh in order to know how to create the AnimatedMesh*/
    unsigned char maxBonesPerVertex() const {
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

    /// Returns the recommended number of bone attributes you should use for this (skinned) mesh.
    /** It's a helper function for the AnimatedMesh class */
    unsigned char getRecommendedNumBoneAttribs() const {
        const unsigned char mbpv = maxBonesPerVertex();
        return (mbpv%4 == 0) ? (mbpv/4) : (mbpv/4 + 1);
    }
}; // Mesh class

} // namespace oglwrap
