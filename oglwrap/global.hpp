/** @file global.hpp
    @brief Global operator overloads.
*/

#pragma once
#include "vertexAttrib.hpp"

/// A global operator that is a VertexArray constructor with nicer syntax.
/** I think (prog | "Position") does look better than VertexAttribArray(prog, "Position") */
inline oglwrap::LazyVertexAttribArray operator|(oglwrap::Program& prog, const std::string& file) {
    return oglwrap::LazyVertexAttribArray(prog, file);
}


