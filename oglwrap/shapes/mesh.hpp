/** @file mesh.hpp
    @brief A Mesh loader using assimp
*/

#ifndef SHAPES_MESH_HPP
#define SHAPES_MESH_HPP

#include <string>
#include <vector>
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

class Mesh {

    struct MeshEntry {
        VertexArray vao;
        ArrayBuffer verts, normals, texCoords;
        IndexBuffer indices;
        unsigned materialIndex;

        #define INVALID_MATERIAL 0xFFFFFFFF
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

    void Positions(VertexAttribArray attrib) {
        for(size_t i = 0; i < entries.size(); i++) {

            const aiMesh* paiMesh = pScene->mMeshes[i];

            std::vector<aiVector3D> vertsVector;
            std::vector<unsigned> indicesVector;

            size_t vertNum = paiMesh->mNumVertices;
            vertsVector.reserve(vertNum);
            // The indices vector may actually be smaller if there
            // are invalid vertices, from non-triangle-faces
            indicesVector.reserve(paiMesh->mNumFaces * 3);

            for(size_t i = 0; i < vertNum; i++) {
                vertsVector.push_back(paiMesh->mVertices[i]);
            }

            for(size_t i = 0; i < paiMesh->mNumFaces; i++) {
                const aiFace& face = paiMesh->mFaces[i];
                if(face.mNumIndices == 3) {
                    indicesVector.push_back(face.mIndices[0]);
                    indicesVector.push_back(face.mIndices[1]);
                    indicesVector.push_back(face.mIndices[2]);
                }
            }

            entries[i].vao.Bind();

            entries[i].verts.Bind();
            entries[i].verts.Data(vertsVector);
            attrib.Setup<float>(3).Enable();

            entries[i].indices.Bind();
            entries[i].indices.Data(indicesVector);
        }

        VertexArray::Unbind();
        rdy2draw = true;
    }

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

    bool HasTexCoords() {
        for(size_t i = 0; i < entries.size(); i++) {
            if(pScene->mMeshes[i]->HasTextureCoords(0)) {
                return true;
            }
        }

        return false;
    }

    bool EveryEntryHasTexCoords() {
        for(size_t i = 0; i < entries.size(); i++) {
            if(!pScene->mMeshes[i]->HasTextureCoords(0)) {
                return false;
            }
        }

        return true;
    }

    void TexCoords(VertexAttribArray attrib) {

        // Initialize TexCoords
        for(size_t i = 0; i < entries.size(); i++) {
            const aiMesh* paiMesh = pScene->mMeshes[i];
            entries[i].materialIndex = paiMesh->mMaterialIndex;

            std::vector<aiVector2D> texCoordsVector;

            size_t vertNum = paiMesh->mNumVertices;
            if(paiMesh->HasTextureCoords(0)) {
                texCoordsVector.reserve(vertNum);
                for(size_t i = 0; i < vertNum; i++) {
                    const aiVector3D& texC = paiMesh->mTextureCoords[0][i];
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

            glDrawElements(
                GL_TRIANGLES,
                entries[i].indices.Size() / sizeof(unsigned),
                GL_UNSIGNED_INT,
                0
            );
        }

        VertexArray::Unbind();
    }

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

                if(maxes.x < paiMesh->mVertices[i].x)mins
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
