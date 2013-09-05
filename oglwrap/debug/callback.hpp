/** @file callback.hpp
    @brief A callback function for oglwrap errors
*/

#pragma once

#if OGLWRAP_DEBUG

/// A callback function that will be called everytime an oglwrap error happens.
/** You can find out where the error happened inside your code, by setting a
  * breakpoint here, and repeatedly stepping out until you get out into your code. */
inline void ErrorCallback() {
    std::cerr << std::flush; // Just to avoid optimization
}

#endif // OGLWRAP_DEBUG
