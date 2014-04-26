#ifndef OGLWRAP_MESH_MESH_INL_HPP
#define OGLWRAP_MESH_MESH_INL_HPP

#include "mesh.hpp"
#include "../context.hpp"

#include "../define_internal_macros.hpp"

namespace oglwrap {

/// Loads in the mesh from a file, and does some post-processing on it.
/** @param filename - The name of the file to load in.
  * @param flags - The assimp post-process flags. */
inline Mesh::Mesh(const std::string& filename, Bitfield<aiPostProcessSteps> flags)
  : scene_(importer_.ReadFile(
             filename.c_str(),
             flags | aiProcess_Triangulate
           ))
  , filename_(filename)
  , entries_(scene_->mNumMeshes)
  , is_setup_positions_(false)
  , is_setup_normals_(false)
  , is_setup_texcoords_(false)
  , textures_enabled_(true) {

  if(!scene_) {
    throw std::runtime_error(
      "Error parsing " + filename_ + " : " + importer_.GetErrorString()
    );
  }

  // The world transform is the transform that takes the root node to it's
  // parent's space, which is the OpenGL style world space. The inverse of this
  // is stored as an attribute of the scene's root node.
  world_transformation_ = glm::inverse(convertMatrix(scene_->mRootNode->mTransformation));
}

template <class IdxType>
/// A template for setting different types (byte/short/int) of indices.
/** This expect the correct vao to be already bound!
  * @param index - The index of the entry */
void Mesh::setIndices(size_t index) {
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

/// Loads in vertex positions and indices, and uploads the former into an attribute array.
/** Uploads the vertex positions data to an attribute array, and sets it up for use.
  * Calling this function changes the currently active VAO, ArrayBuffer and IndexBuffer.
  * The mesh cannot be drawn without calling this function.
  * @param attrib - The attribute array to use as destination. */
inline void Mesh::setupPositions(VertexAttribArray attrib) {
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
      entries_[i].idxType = IndexType::UnsignedByte;
      setIndices<unsigned char>(i);
    } else if(paiMesh->mNumFaces * 3 < USHRT_MAX) {
      entries_[i].idxType = IndexType::UnsignedShort;
      setIndices<unsigned short>(i);
    } else {
      entries_[i].idxType = IndexType::UnsignedInt;
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
inline void Mesh::setupNormals(VertexAttribArray attrib) {

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
inline bool Mesh::hasTexCoords(unsigned char texCoordSet) {
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
inline void Mesh::setupTexCoords(VertexAttribArray attrib, unsigned char texCoordSet) {

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

#if OGLWRAP_USE_IMAGEMAGICK
template<aiTextureType tex_type>
/// Sets arbitrary type of textures to a specified texture unit.
/** Changes the currently active texture unit and Texture2D binding.
  * @param texture_unit - Specifies the texture unit to use for the textures. */
void Mesh::setupTextures(unsigned short texture_unit) {
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
#endif

/// Sets the diffuse textures up to a specified texture unit.
/** Changes the currently active texture unit and Texture2D binding.
  * @param texture_unit - Specifies the texture unit to use for the diffuse textures. */
inline void Mesh::setupDiffuseTextures(unsigned short texture_unit) {
  setupTextures<aiTextureType_DIFFUSE>(texture_unit);
}

/// Sets the specular textures up to a specified texture unit.
/** Changes the currently active texture unit and Texture2D binding.
  * @param texture_unit - Specifies the texture unit to use for the specular textures. */
inline void Mesh::setupSpecularTextures(unsigned short texture_unit) {
  setupTextures<aiTextureType_SPECULAR>(texture_unit);
}

/// Renders the mesh.
/** Changes the currently active VAO and may change the Texture2D binding */
inline void Mesh::render() {
  if(!is_setup_positions_) {
    return;
  }
  for(size_t i = 0 ; i < entries_.size(); i++) {
    entries_[i].vao.bind();

    const size_t materialIndex = entries_[i].materialIndex;

    if(textures_enabled_) {
      for(auto iter = materials_.begin(); iter != materials_.end(); iter++) {
        auto material = iter->second;
        if(material.active == true && materialIndex < material.textures.size()) {
          material.textures[materialIndex].active(material.texUnit);
        }
        material.textures[materialIndex].bind();
      }
    }

    Context::DrawElements(
      PrimType::Triangles,
      entries_[i].idxCount,
      entries_[i].idxType
    );

    if(textures_enabled_) {
      for(auto iter = materials_.begin(); iter != materials_.end(); iter++) {
        auto material = iter->second;
        if(material.active == true && materialIndex < material.textures.size()) {
          material.textures[materialIndex].active(material.texUnit);
        }
        material.textures[materialIndex].unbind();
      }
    }
  }

  VertexArray::Unbind();
}

/// The transformation that takes the model's world coordinates to the OpenGL style world coordinates.
/** i.e if you see that a character is laying on ground instead of standing, it is probably
  * because the character is defined in a space where XY is flat, and Z is up. Right
  * multiplying your model matrix with this matrix will solve that problem. */
inline glm::mat4 Mesh::worldTransform() const {
  return world_transformation_;
}

/// Gives information about the mesh's bounding cuboid.
/** @param center - The vec3 where bounding cuboid's center is to be returned.
  * @param edges - The vec3 where bounding cuboid's edge lengths are to be returned. */
inline void Mesh::bCuboid(glm::vec3& center, glm::vec3& edges) const {
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
inline glm::vec4 Mesh::bSphere() const {
  glm::vec3 center, edges;
  bCuboid(center, edges);
  return glm::vec4(center, sqrt(glm::dot(edges, edges)) / 2); // Pythagoras.
}

/// Returns the center offseted by the model matrix (as xyz) and radius (as w) of the bounding sphere.
/** @param modelMatrix - The matrix to use to offset the center of the bounding sphere. */
inline glm::vec4 Mesh::bSphere(glm::mat4 modelMatrix) const {
  glm::vec4 m_bSphere = bSphere();
  return glm::vec4(glm::vec3(modelMatrix * glm::vec4(glm::vec3(m_bSphere), 1)), m_bSphere.w);
}

/// Returns the center of the bounding sphere.
inline glm::vec3 Mesh::bSphereCenter() const {
  glm::vec3 center, edges;
  bCuboid(center, edges);
  return center;
}

/// Returns the radius of the bounding sphere.
inline float Mesh::bSphereRadius() const {
  glm::vec3 center, edges;
  bCuboid(center, edges);
  return sqrt(glm::dot(edges, edges)) / 2; // Pythagoras.
}

} // namespace oglwrap

#include "../undefine_internal_macros.hpp"

#endif // OGLWRAP_MESH_MESH_INL_HPP
