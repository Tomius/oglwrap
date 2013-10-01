/** @file mesh.hpp
    @brief A Mesh loader using assimp
*/

#ifndef OGLWRAP_MESH_MESH_HPP_
#define OGLWRAP_MESH_MESH_HPP_

#include <climits>
#include "../assimp.hpp"

namespace oglwrap {

/// A class that can load in and draw meshes from over 30 file formats using assimp.
class Mesh : protected RefCounted {
protected:

  /// A class to store per mesh data (the class loads in a scene, that might contain multiply meshes).
  struct MeshEntry {
    VertexArray vao;
    ArrayBuffer verts, normals, texCoords;
    IndexBuffer indices;
    unsigned idxCount, materialIndex;
    DataType idxType;

    MeshEntry() : materialIndex(0xFFFFFFFF) {} // Invalid material
  };

  /// The assimp importer. The scene actually belongs to this.
  Assimp::Importer importer_;

  /// A pointer to the scene stored by the importer. But this is the working interface for it.
  const aiScene* scene_;

  /// The name of the file loaded in. It is stored to be able to print it out if an error happens.
  std::string filename_;

  /// The vao-s and buffers per mesh.
  std::vector<MeshEntry> entries_;

  /// A struct containin the state and data of a material type.
  struct MaterialInfo {
    bool active;
    int texUnit;
    std::vector<Texture2D> textures;

    MaterialInfo()
      : active(false), texUnit(0) {
    }
  };

  /// The materials.
  std::map<aiTextureType, MaterialInfo> materials_;

  /// Stores if the setupPositions function is called (they shouldn't be called more than once).
  bool is_setup_positions_;
  /// Stores if the setupNormals function is called (they shouldn't be called more than once).
  bool is_setup_normals_;
  /// Stores if the setup_texcoords function is called (they shouldn't be called more than once).
  bool is_setup_texcoords_;

  /// It shouldn't be copyable.
  Mesh(const Mesh& src);
  /// It shouldn't be copyable.
  void operator=(const Mesh& rhs);

public:
  /// Loads in the mesh from a file, and does some post-processing on it.
  /** @param filename - The name of the file to load in.
    * @param flags - The assimp post-process flags. */
  Mesh(const std::string& filename, unsigned int flags)
    : scene_(importer_.ReadFile(
              filename.c_str(),
              flags | aiProcess_Triangulate
            ))
    , filename_(filename)
    , entries_(scene_->mNumMeshes)
    , is_setup_positions_(false)
    , is_setup_normals_(false)
    , is_setup_texcoords_(false) {

    if(!scene_) {
      throw std::runtime_error("Error parsing " + filename_ + " : " + importer_.GetErrorString());
    }
  }

private:
  template <class IdxType>
  /// A template for setting different types (byte/short/int) of indices.
  /** This expect the correct vao to be already bound!
    * @param index - The index of the entry */
  void setIndices(size_t index) {
    const aiMesh* paiMesh = scene_->mMeshes[index];

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

    entries_[index].indices.bind();
    entries_[index].indices.data(indicesVector);
    entries_[index].idxCount = indicesVector.size();
  }

public:
  /// Loads in vertex positions and indices, and uploads the former into an attribute array.
  /** Uploads the vertex positions data to an attribute array, and sets it up for use.
    * Calling this function changes the currently active VAO, ArrayBuffer and IndexBuffer.
    * The mesh cannot be drawn without calling this function.
    * @param attrib - The attribute array to use as destination. */
  void setupPositions(VertexAttribArray attrib) {
    if(is_setup_positions_) {
      throw std::logic_error("Mesh::setup_position is called multiply times on the same object");
    } else {
      is_setup_positions_ = true;
    }

    for(size_t i = 0; i < entries_.size(); i++) {
      const aiMesh* paiMesh = scene_->mMeshes[i];

      // ~~~~~~<{ Load the vertices }>~~~~~~

      std::vector<aiVector3D> vertsVector;
      size_t vertNum = paiMesh->mNumVertices;
      vertsVector.reserve(vertNum);

      for(size_t i = 0; i < vertNum; i++) {
        vertsVector.push_back(paiMesh->mVertices[i]);
      }

      entries_[i].vao.bind();

      entries_[i].verts.bind();
      entries_[i].verts.data(vertsVector);
      attrib.setup<float>(3).enable();

      // ~~~~~~<{ Load the indices }>~~~~~~

      if(paiMesh->mNumFaces * 3 < UCHAR_MAX) {
        entries_[i].idxType = DataType::UnsignedByte;
        setIndices<unsigned char>(i);
      } else if(paiMesh->mNumFaces * 3 < USHRT_MAX) {
        entries_[i].idxType = DataType::UnsignedShort;
        setIndices<unsigned short>(i);
      } else {
        entries_[i].idxType = DataType::UnsignedInt;
        setIndices<unsigned int>(i);
      }
    }

    VertexArray::Unbind();
    ArrayBuffer::Unbind();
  }

  /// Loads in vertex normals, and uploads it to an attribute array.
  /** Uploads the vertex normals data to an attribute array, and sets it up for use.
    * Calling this function changes the currently active VAO and ArrayBuffer.
    * @param attrib - The attribute array to use as destination. */
  void setupNormals(VertexAttribArray attrib) {

    if(is_setup_normals_) {
      throw std::logic_error("Mesh::setupNormals is called multiply times on the same object");
    } else {
      is_setup_normals_ = true;
    }

    for(size_t i = 0; i < entries_.size(); i++) {
      const aiMesh* paiMesh = scene_->mMeshes[i];

      std::vector<aiVector3D> normalsVector;

      size_t vertNum = paiMesh->mNumVertices;
      normalsVector.reserve(vertNum);

      for(size_t i = 0; i < vertNum; i++) {
        normalsVector.push_back(paiMesh->mNormals[i]);
      }

      entries_[i].vao.bind();

      entries_[i].normals.bind();
      entries_[i].normals.data(normalsVector);
      attrib.setup<float>(3).enable();
    }

    VertexArray::Unbind();
    ArrayBuffer::Unbind();
  }

  /// Checks if every mesh in the scene has texcoords
  /** Returns true if all of the meshes in the scene have texture
    * coordinates in the specified texture coordinate set.
    * @param texCoordSet - Specifies the index of the texture coordinate set that should be inspected */
  bool hasTexCoords(unsigned char texCoordSet = 0) {
    for(size_t i = 0; i < entries_.size(); i++) {
      if(!scene_->mMeshes[i]->HasTextureCoords(texCoordSet)) {
        return false;
      }
    }

    return true;
  }

  /// Loads in vertex texture coordinates (the 0th set), and the materials.
  /** Uploads the vertex textures coordinates data to an attribute array,
    * and sets it up for use. Also loads in the materials (textures) for
    * the mesh. May write to the stderr if a material is missing.
    * Calling this function changes the currently active VAO and ArrayBuffer.
    * @param attrib - The attribute array to use as destination.
    * @param texCoordSet - Specifies the index of the texture coordinate set that should be used */
  void setupTexCoords(VertexAttribArray attrib, unsigned char texCoordSet = 0) {

    if(is_setup_texcoords_) {
      throw std::logic_error("Mesh::setupTexCoords is called multiply times on the same object");
    } else {
      is_setup_texcoords_ = true;
    }

    // Initialize TexCoords
    for(size_t i = 0; i < entries_.size(); i++) {
      const aiMesh* paiMesh = scene_->mMeshes[i];
      entries_[i].materialIndex = paiMesh->mMaterialIndex;

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

      entries_[i].vao.bind();

      entries_[i].texCoords.bind();
      entries_[i].texCoords.data(texCoordsVector);
      attrib.setup<float>(2).enable();
    }

    VertexArray::Unbind();
    ArrayBuffer::Unbind();
  }

  template<aiTextureType tex_type>
  /// Sets arbitary type of textures to a specified texture unit.
  /** Changes the currently active texture unit and Texture2D binding.
    * @param texture_unit - Specifies the texture unit to use for the textures. */
  void setupTextures(unsigned short texture_unit) {
    Texture2D::Active(texture_unit);

    materials_[tex_type].active = true;
    materials_[tex_type].texUnit = texture_unit;
    materials_[tex_type].textures.resize(scene_->mNumMaterials);

    if(scene_->mNumMaterials) {

      // Extract the directory part from the file name
      std::string::size_type SlashIndex = filename_.find_last_of("/");
      std::string dir;

      if(SlashIndex == std::string::npos) {
        dir = "./";
      } else if(SlashIndex == 0) {
        dir = "/";
      } else {
        dir = filename_.substr(0, SlashIndex + 1);
      }

      // Initialize the materials
      for(unsigned int i = 0; i < scene_->mNumMaterials; i++) {
        const aiMaterial* pMaterial = scene_->mMaterials[i];

        aiString filepath;
        if(pMaterial->GetTexture(tex_type, 0, &filepath) == AI_SUCCESS) {
          materials_[tex_type].textures[i].bind();
          materials_[tex_type].textures[i].loadTexture(dir + filepath.data);
          materials_[tex_type].textures[i].minFilter(MinFilter::Linear);
          materials_[tex_type].textures[i].magFilter(MagFilter::Linear);
        }
      }
    }

    Texture2D::Unbind();
  }

  /// Sets the diffuse textures up to a specified texture unit.
  /** Changes the currently active texture unit and Texture2D binding.
    * @param texture_unit - Specifies the texture unit to use for the diffuse textures. */
  void setupDiffuseTextures(unsigned short texture_unit) {
    setupTextures<aiTextureType_DIFFUSE>(texture_unit);
  }

  /// Sets the specular textures up to a specified texture unit.
  /** Changes the currently active texture unit and Texture2D binding.
    * @param texture_unit - Specifies the texture unit to use for the specular textures. */
  void setupSpecularTextures(unsigned short texture_unit) {
    setupTextures<aiTextureType_SPECULAR>(texture_unit);
  }

  /// Renders the mesh.
  /** Changes the currently active VAO and may change the Texture2D binding */
  void render() {
    if(!is_setup_positions_) {
      return;
    }
    for(unsigned int i = 0 ; i < entries_.size(); i++) {
      entries_[i].vao.bind();

      const unsigned int materialIndex = entries_[i].materialIndex;
      for(auto iter = materials_.begin(); iter != materials_.end(); iter++) {
        auto material = iter->second;
        if(material.active == true && materialIndex < material.textures.size()) {
          material.textures[materialIndex].active(material.texUnit);
        }
        material.textures[materialIndex].bind();
      }

      gl(DrawElements(
           GL_TRIANGLES,
           entries_[i].idxCount,
           entries_[i].idxType,
           0
         ));
    }

    VertexArray::Unbind();
    Texture2D::Unbind();
  }

  /// Gives information about the mesh's bounding cuboid.
  /** @param center - The vec3 where bounding cuboid's center is to be returned.
    * @param edges - The vec3 where bounding cuboid's edge lengths are to be returned. */
  void bCuboid(glm::vec3& center, glm::vec3& edges) const {
    // Idea: get the minimums and maximums of the vertex positions
    // in each coordinate. Then the average of the mins and maxes
    // will be the center of the cuboid
    glm::vec3 mins, maxes;
    for(size_t entry = 0; entry < entries_.size(); entry++) {
      const aiMesh* paiMesh = scene_->mMeshes[entry];

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
  glm::vec4 bSphere() const {
    glm::vec3 center, edges;
    bCuboid(center, edges);
    return glm::vec4(center, std::max(edges.x, std::max(edges.y, edges.z)) / 2);
  }

  /// Returns the center of the bounding sphere.
  glm::vec3 bSphereCenter() const {
    glm::vec3 center, edges;
    bCuboid(center, edges);
    return center;
  }

  /// Returns the radius of the bounding sphere.
  float bSphereRadius() const {
    glm::vec3 center, edges;
    bCuboid(center, edges);
    return std::max(edges.x, std::max(edges.y, edges.z)) / 2;
  }
}; // Mesh class

} // namespace oglwrap

#endif // OGLWRAP_MESH_MESH_HPP_
