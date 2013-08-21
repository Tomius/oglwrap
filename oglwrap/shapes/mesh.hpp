/** @file mesh.hpp
    @brief A Mesh loader using assimp
*/

#ifndef SHAPES_MESH_HPP
#define SHAPES_MESH_HPP

#include <map>
#include <string>
#include <vector>
#include <iostream>
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

    #define INVALID_MATERIAL 0xFFFFFFFF

    struct MeshEntry {
        VertexArray vao;
        ArrayBuffer verts, normals, texCoords;
        IndexBuffer indices;
        unsigned materialIndex;

        MeshEntry() : materialIndex(INVALID_MATERIAL) {}

        void Init(const std::vector<aiVector3D>& Verts,
                  const std::vector<aiVector3D>& Normals,
                  const std::vector<aiVector2D>& TexCoords,
                  const std::vector<unsigned int>& Indices) {

            vao.Bind();

            verts.Bind();
            verts.Data(Verts);
            VertexAttribArray(0).Setup<float>(3).Enable();

            normals.Bind();
            normals.Data(Normals);
            VertexAttribArray(1).Setup<float>(3).Enable();

            texCoords.Bind();
            texCoords.Data(TexCoords);
            VertexAttribArray(2).Setup<float>(2).Enable();

            indices.Bind();
            indices.Data(Indices);

            vao.Unbind();
        }
    };

    std::vector<MeshEntry> entries;
    std::vector<Texture2D> textures;

    void InitFromScene(const aiScene* pScene, const std::string& filename) {
        entries.resize(pScene->mNumMeshes);
        textures.resize(pScene->mNumMaterials);

        for(size_t i = 0; i < entries.size(); i++) {
            InitMesh(i, pScene->mMeshes[i]);
        }

        if(pScene->mNumMaterials)
            InitMaterials(pScene, filename);
    }

    void InitMesh(unsigned int Index, const aiMesh* paiMesh) {
        entries[Index].materialIndex = paiMesh->mMaterialIndex;

        std::vector<aiVector3D> Verts, Normals;
        std::vector<aiVector2D> TexCoords;
        std::vector<unsigned> Indices;

        size_t vertNum = paiMesh->mNumVertices;
        Verts.reserve(vertNum);
        Normals.reserve(vertNum);
        if(paiMesh->HasTextureCoords(0))
            TexCoords.reserve(vertNum);
        else
            TexCoords.resize(vertNum);
        Indices.reserve(paiMesh->mNumFaces * 3);

        for(size_t i = 0; i < vertNum; i++) {
            Verts.push_back(paiMesh->mVertices[i]);
            Normals.push_back(paiMesh->mNormals[i]);
            if(paiMesh->HasTextureCoords(0)) {
                const aiVector3D& texC = paiMesh->mTextureCoords[0][i];
                TexCoords.push_back(aiVector2D(texC.x, texC.y));
            }
        }

        for(size_t i = 0; i < paiMesh->mNumFaces; i++) {
            const aiFace& face = paiMesh->mFaces[i];
            assert(face.mNumIndices == 3);
            Indices.push_back(face.mIndices[0]);
            Indices.push_back(face.mIndices[1]);
            Indices.push_back(face.mIndices[2]);
        }

        entries[Index].Init(Verts, Normals, TexCoords, Indices);
    }

    void InitMaterials(const aiScene* pScene, const std::string& filename) {
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

public:
    Mesh(const std::string& filename, unsigned int flags) {
        Assimp::Importer Importer;
        const aiScene* pScene = Importer.ReadFile(
            filename.c_str(),
            flags | aiProcess_Triangulate
        );

        if(pScene)
            InitFromScene(pScene, filename);
        else
            throw std::runtime_error("Error parsing " + filename + " : " + Importer.GetErrorString());
    }

    void Render() {
        for(unsigned int i = 0 ; i < entries.size(); i++) {
            entries[i].vao.Bind();

            const unsigned int materialIndex = entries[i].materialIndex;
            if(materialIndex < textures.size()) {
                textures[materialIndex].Bind();
            }

            glDrawElements(
                GL_TRIANGLES,
                entries[i].verts.Size(),
                GL_UNSIGNED_INT,
                0
            );
        }

        VertexArray::Unbind();
    }

};

} // namespace oglwrap

#endif // include guard
