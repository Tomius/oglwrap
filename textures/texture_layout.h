// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_TEXTURES_TEXUTRE_LAYOUT_H_
#define OGLWRAP_TEXTURES_TEXUTRE_LAYOUT_H_

#include "./texture_base.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

class TextureLayout {
 public:
  TextureLayout() : top_idx_(-1) {
    GLint texture_units;
    gl(GetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &texture_units));
    textures_.resize(texture_units, nullptr);
  }

  int add(TextureBase& tex) {
    assert(++top_idx_ < textures_.size());
    textures_[top_idx_] = &tex;
    return top_idx_;
  }

  int top_idx() const { return top_idx_; }

  void bind() {
    for (int i = 0; i <= top_idx_; ++i) {
      gl(ActiveTexture(GL_TEXTURE0+i));
      gl(BindTexture(GLenum(textures_[i]->target), textures_[i]->handle));
    }
  }

  void unbind() {
    for (int i = top_idx_; i >= 0; --i) {
      gl(ActiveTexture(GL_TEXTURE0+i));
      gl(BindTexture(GLenum(textures_[i]->target), 0));
    }
  }
 private:
  std::vector<TextureBase*> textures_;
  int top_idx_;
};

}  // namespace oglwrap

#include "../undefine_internal_macros.h"

#endif
