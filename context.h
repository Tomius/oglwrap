/** @file context.hpp
    @brief Implements OpenGL context related stuff.
*/

#ifndef OGLWRAP_CONTEXT_H_
#define OGLWRAP_CONTEXT_H_

#include "context/capabilities.h"
#include "context/errors.h"
#include "context/viewport_ops.h"
#include "context/buffer_selection.h"
#include "context/buffer_masking.h"
#include "context/buffer_clearing.h"
#include "context/rasterization.h"
#include "context/drawing.h"
#include "context/extensions.h"
#include "context/computing.h"
#include "context/depth_test.h"
#include "context/stencil_test.h"
#include "context/scissor_test.h"
#include "context/logical_ops.h"
#include "context/pixel_ops.h"

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
		, public context::ScissorTest
		, public context::LogicalOps
		, public context::PixelOps
	{ };
}

#endif // OGLWRAP_CONTEXT_CAPABILITIES_H_
