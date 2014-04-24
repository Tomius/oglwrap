/** @file context.hpp
    @brief Implements OpenGL context related stuff.
*/

#ifndef OGLWRAP_CONTEXT_HPP_
#define OGLWRAP_CONTEXT_HPP_

#include "context/capabilities.hpp"
#include "context/errors.hpp"
#include "context/viewport_ops.hpp"
#include "context/buffer_selection.hpp"
#include "context/buffer_masking.hpp"
#include "context/buffer_clearing.hpp"
#include "context/rasterization.hpp"
#include "context/drawing.hpp"
#include "context/extensions.hpp"
#include "context/computing.hpp"
#include "context/depth_test.hpp"
#include "context/stencil_test.hpp"

namespace oglwrap {
	class Context
		: public context::Capabilities
		, public context::Errors
		, public context::ViewportOps
		, public context::BufferSelection
		, public context::BufferMasking
		, public context::BufferClearing
		, public context::Rasterization
		, public context::Drawing
		, public context::Extensions
		, public context::Computing
		, public context::DepthTest
		, public context::StencilTest
	{ };
}

#endif // OGLWRAP_CONTEXT_CAPABILITIES_HPP_
