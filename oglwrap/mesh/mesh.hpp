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

  /// The transformation that takes the model's world coordinates to the OpenGL style world coordinates.
  glm::mat4 world_transformation_;

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
  Mesh(const std::string& filename, unsigned int flags);

private:
  template <class IdxType>
  /// A template for setting different types (byte/short/int) of indices.
  /** This expect the correct vao to be already bound!
    * @param index - The index of the entry */
  void setIndices(size_t index);

public:
  /// Loads in vertex positions and indices, and uploads the former into an attribute array.
  /** Uploads the vertex positions data to an attribute array, and sets it up for use.
    * Calling this function changes the currently active VAO, ArrayBuffer and IndexBuffer.
    * The mesh cannot be drawn without calling this function.
    * @param attrib - The attribute array to use as destination. */
  void setupPositions(VertexAttribArray attrib);

  /// Loads in vertex normals, and uploads it to an attribute array.
  /** Uploads the vertex normals data to an attribute array, and sets it up for use.
    * Calling this function changes the currently active VAO and ArrayBuffer.
    * @param attrib - The attribute array to use as destination. */
  void setupNormals(VertexAttribArray attrib);

  /// Checks if every mesh in the scene has texcoords
  /** Returns true if all of the meshes in the scene have texture
    * coordinates in the specified texture coordinate set.
    * @param texCoordSet - Specifies the index of the texture coordinate set that should be inspected */
  bool hasTexCoords(unsigned char texCoordSet = 0);

  /// Loads in vertex texture coordinates (the 0th set), and the materials.
  /** Uploads the vertex textures coordinates data to an attribute array,
    * and sets it up for use. Also loads in the materials (textures) for
    * the mesh. May write to the stderr if a material is missing.
    * Calling this function changes the currently active VAO and ArrayBuffer.
    * @param attrib - The attribute array to use as destination.
    * @param texCoordSet - Specifies the index of the texture coordinate set that should be used */
  void setupTexCoords(VertexAttribArray attrib, unsigned char texCoordSet = 0);

  template<aiTextureType tex_type>
  /// Sets arbitrary type of textures to a specified texture unit.
  /** Changes the currently active texture unit and Texture2D binding.
    * @param texture_unit - Specifies the texture unit to use for the textures. */
  void setupTextures(unsigned short texture_unit);

  /// Sets the diffuse textures up to a specified texture unit.
  /** Changes the currently active texture unit and Texture2D binding.
    * @param texture_unit - Specifies the texture unit to use for the diffuse textures. */
  void setupDiffuseTextures(unsigned short texture_unit);

  /// Sets the specular textures up to a specified texture unit.
  /** Changes the currently active texture unit and Texture2D binding.
    * @param texture_unit - Specifies the texture unit to use for the specular textures. */
  void setupSpecularTextures(unsigned short texture_unit);

  /// Renders the mesh.
  /** Changes the currently active VAO and may change the Texture2D binding */
  void render();

  /// Gives information about the mesh's bounding cuboid.
  /** @param center - The vec3 where bounding cuboid's center is to be returned.
    * @param edges - The vec3 where bounding cuboid's edge lengths are to be returned. */
  void bCuboid(glm::vec3& center, glm::vec3& edges) const;

  /// Returns the transformation that takes the model's world coordinates to the OpenGL style world coordinates.
  /** i.e if you see that a character is laying on ground instead of standing, it is probably
    * because the character is defined in a space where Z is up not Y. Right multiplying your
    * model matrix with this matrix will solve that problem. */
  glm::mat4 worldTransform() const;

  /// Returns the center (as xyz) and radius (as w) of the bounding sphere.
  glm::vec4 bSphere() const;

  /// Returns the center offseted by the model matrix (as xyz) and radius (as w) of the bounding sphere.
  glm::vec4 bSphere(glm::mat4 modelMatrix) const;

  /// Returns the center of the bounding sphere.
  glm::vec3 bSphereCenter() const;

  /// Returns the radius of the bounding sphere.
  float bSphereRadius() const;

}; // Mesh class

} // namespace oglwrap

#include "mesh-inl.hpp"

#endif // OGLWRAP_MESH_MESH_HPP_
