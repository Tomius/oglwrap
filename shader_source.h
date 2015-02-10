// Copyright (c) 2014, Tamas Csala

/** @file shader_source.h
    @brief Implements GLSL shader source loading and manipulating facilities.
*/

#ifndef OGLWRAP_SHADER_SOURCE_H_
#define OGLWRAP_SHADER_SOURCE_H_

#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "./config.h"

#include "./define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

/**
 * @brief A class that can load shader sources in from files, and do some
 *        preprocessing on them.
 */
class ShaderSource {
  std::string src_, filename_;

 public:
  /// Default constructor.
  ShaderSource() : filename_("Unnamed shader") { }

  /// Loads in the shader from a file.
  /** @param file - The path to the file. */
  explicit ShaderSource(const std::string& file) {
    loadFromFile(file);
  }

  /// Returns the source.
  std::string const& source() const { return src_; }

  /// Returns the source.
  std::string& source() { return src_; }

  /// Adds a string as the shader source.
  /** @param source_string - The source string. */
  void set_source(const std::string& source_string) {
    src_ = source_string;
  }

  /// Loads in the shader from a file.
  /** @param file - The path to the file. */
  void loadFromFile(const std::string& file) {
    filename_ = file;
    std::ifstream shader_file((OGLWRAP_DEFAULT_SHADER_PATH + file).c_str());
    if (!shader_file.is_open()) {
      throw std::runtime_error("Shader file '" + file + "' not found.");
    }
    std::stringstream shader_string;
    shader_string << shader_file.rdbuf();

    // Remove the EOF from the end of the string.
    src_ = shader_string.str();
    if (src_[src_.length() - 1] == EOF) {
      src_.pop_back();
    }
  }

  /// Returns the file's name that was loaded in.
  const std::string& source_file() const { return filename_; }

  void set_source_file(const std::string& file) {
    filename_ = file;
  }

  template<typename T>
  /// Inserts a value for a defined preprocessor in the shader.
  /** @param macro_name - The name of the macro.
    * @param value - The value to insert. */
  void insertMacroValue(const std::string& macro_name, const T& value) {
    size_t macro_pos = src_.find("#define " + macro_name);
  #if OGLWRAP_DEBUG
    if (macro_pos == std::string::npos) {
      throw std::invalid_argument(
        "ShaderSource::insert_macro_value is called for '" + filename_ +
        "', but the shader doesn't have any macro named " + macro_name);
    }
  #endif

    size_t macro_end = src_.find('\n', macro_pos);

    std::stringstream sstream;
    sstream << src_.substr(0, macro_pos+strlen("#define ")+macro_name.length());
    sstream << ' ' << value << src_.substr(macro_end);
    src_ = sstream.str();
  }
};

}  // namespace oglwrap

#include "./undefine_internal_macros.h"

#endif  // OGLWRAP_SHADER_SOURCE_H_
