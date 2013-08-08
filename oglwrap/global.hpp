#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <string>
#include "error.hpp"
#include "shader.hpp"
#include "vertexAttrib.hpp"

/// A global operator for the lazy. But (prog | "Position")
/// does look better than VertexAttribArray(prog, "Position")
inline oglwrap::VertexAttribArray operator|(oglwrap::Program& prog, const std::string& file) {
    return oglwrap::VertexAttribArray(prog, file);
}

#endif

