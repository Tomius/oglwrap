// Copyright (c) 2014, Tamas Csala

#ifndef OGLWRAP_CONTEXT_CAPABILITIES_H_
#define OGLWRAP_CONTEXT_CAPABILITIES_H_

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

#include "../config.h"
#include "../enums/capability.h"

#include "../define_internal_macros.h"

namespace OGLWRAP_NAMESPACE_NAME {

/// Enables a capability.
/** @see glEnable */
inline void Enable(Capability capability) {
  gl(Enable(GLenum(capability)));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(glEnablei)
/// Enables a capability for an index target.
/** @see glEnablei */
inline void Enable(Capability capability, GLuint index) {
	gl(Enablei(GLenum(capability), index));
}
#endif

/// Disables a capability.
/** @see glDisable */
inline void Disable(Capability capability) {
	gl(Disable(GLenum(capability)));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(glDisablei)
/// Disables a capability for an index target.
/** @see glDisablei */
inline void Disable(Capability capability, GLuint index) {
	gl(Disablei(GLenum(capability), index));
}
#endif

/// Checks if a capability is enabled.
/** @see glIsEnabled */
inline bool IsEnabled(Capability capability) {
	return gl(IsEnabled(GLenum(capability)));
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(glIsEnabledi)
/// Checks if a capability is enabled for an index target.
/** @see glIsEnabledi */
inline bool IsEnabled(Capability capability, GLuint index) {
	return gl(IsEnabledi(GLenum(capability), index));
}
#endif

/// Enables or disables a capability.
/** @see glEnable, glDisable */
inline void SetCapability(Capability capability, bool value) {
	if (value) {
		Enable(capability);
	} else {
		Disable(capability);
	}
}

#if OGLWRAP_DEFINE_EVERYTHING || defined(glEnablei) && defined(glDisablei)
/// Enables or disables a capability for an indexet target.
/** @see glEnable, glDisable */
inline void SetCapability(Capability capability, GLuint index, bool value) {
	if (value) {
		Enable(capability, index);
	} else {
		Disable(capability, index);
	}
}
#endif

/// Enables a capability, and creates a variable. When the variable goes
/// out of the scope, sets the capability back to its old value.
class TemporaryEnable {
	Capability cap_;
	bool was_enabled_;

public:
	TemporaryEnable(Capability capability) : cap_(capability) {
		was_enabled_ = IsEnabled(cap_);
		if (!was_enabled_) {
			Enable(cap_);
		}
	}

	~TemporaryEnable() {
		if (!was_enabled_) {
			Disable(cap_);
		}
	}
};

/// Disables a capability, and creates a variable. When the variable goes
/// out of the scope, sets the capability back to its old value.
class TemporaryDisable {
	Capability cap_;
	bool was_enabled_;

public:
	TemporaryDisable(Capability capability) : cap_(capability) {
		was_enabled_ = IsEnabled(cap_);
		if (was_enabled_) {
			Disable(cap_);
		}
	}

	~TemporaryDisable() {
		if (was_enabled_) {
			Enable(cap_);
		}
	}
};

/// Temporary sets a list of Capabilities to the specified value.
/// When the created variable goes out of scope, these variables are set back
/// to their old values.
class TemporarySet {
	std::vector<std::pair<Capability, bool>> cap_;

public:
	TemporarySet(std::vector<std::pair<Capability, bool>> capabilites) {
		for (auto i : capabilites) {
			bool current_state = IsEnabled(i.first);
			if (i.second != current_state) {
				cap_.push_back({i.first, i.second});
				if (current_state) {
					Disable(i.first);
				} else {
					Enable(i.first);
				}
			}
		}
	}

	~TemporarySet() {
		for (auto i : cap_) {
			if (i.second) {
				Disable(i.first);
			} else {
				Enable(i.first);
			}
		}
	}
};

} // namespace oglwrap

#include "../undefine_internal_macros.h"
#endif  // OGLWRAP_CONTEXT_CAPABILITIES_H_
