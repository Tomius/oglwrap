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

const unsigned INVALID_MATERIAL = 0xFFFFFFFF;

/// A class that can load in and draw meshes from over 30 file formats using assimp.
class Mesh {
    struct MeshEntry {
        VertexArray vao;
        ArrayBuffer verts, normals, texCoords;
        IndexBuffer indices;
        unsigned idxCount, materialIndex;
        DataType idxType;

        MeshEntry() : materialIndex(INVALID_MATERIAL) {}
    };

    // We don't actually need to store this, but is needed to initialize pScene
    Assimp::Importer importer;
    const aiScene* pScene;

    std::string filename;
    bool rdy2draw, useMaterials;
    std::vector<MeshEntry> entries;
    std::vector<Texture2D> textures;

public:
    Mesh(const std::string& filename, unsigned int flags)
        : pScene(importer.ReadFile(
                     filename.c_str(),
                     flags | aiProcess_Triangulate
          ))
        , filename(filename)
        , rdy2draw(false)
        , useMaterials(false)
        , entries(pScene->mNumMeshes) {

        if(!pScene)
            throw std::runtime_error("Error parsing " + filename + " : " + importer.GetErrorString());
    }

private:
    template <class IdxType>
    /// A template for setting different types (byte/short/int) of indices.
    /** This expect the correct vao to be already bound!! */
    /// @param index - The index of the entry
    void SetIndices(size_t index) {
        const aiMesh* paiMesh = pScene->mMeshes[index];

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
            const aiMesh* paiMesh = pScene->mMeshes[i];

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
            const aiMesh* paiMesh = pScene->mMeshes[i];

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
            if(pScene->mMeshes[i]->HasTextureCoords(texCoordSet)) {
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
            if(!pScene->mMeshes[i]->HasTextureCoords(texCoordSet)) {
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
            const aiMesh* paiMesh = pScene->mMeshes[i];
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
        textures.resize(pScene->mNumMaterials);
        if(pScene->mNumMaterials) {
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
            for(unsigned int i = 0; i < pScene->mNumMaterials; i++) {
                const aiMaterial* pMaterial = pScene->mMaterials[i];

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
        if(!rdy2draw)
            return;
        for(unsigned int i = 0 ; i < entries.size(); i++) {
            entries[i].vao.Bind();

            if(useMaterials) {
                const unsigned int materialIndex = entries[i].materialIndex;
                if(materialIndex < textures.size()) {
                    textures[materialIndex].Bind();
                }
            }

            oglwrap_PreCheckError();

            glDrawElements(
                GL_TRIANGLES,
                entries[i].idxCount,
                entries[i].idxType,
                0
            );

            oglwrap_CheckError();
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
            const aiMesh* paiMesh = pScene->mMeshes[entry];

            for(size_t i = 0; i < paiMesh->mNumVertices; i++) {
                if(paiMesh->mVertices[i].x < mins.x)
                    mins.x = paiMesh->mVertices[i].x;
                if(paiMesh->mVertices[i].y < mins.y)
                    mins.y = paiMesh->mVertices[i].y;
                if(paiMesh->mVertices[i].z < mins.z)
                    mins.z = paiMesh->mVertices[i].z;

                if(maxes.x < paiMesh->mVertices[i].x)
                    maxes.x = paiMesh->mVertices[i].x;
                if(maxes.y < paiMesh->mVertices[i].y)
                    maxes.y = paiMesh->mVertices[i].y;
                if(maxes.z < paiMesh->mVertices[i].z)
                    maxes.z = paiMesh->mVertices[i].z;
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

};

} // namespace oglwrap

#endif // include guard
