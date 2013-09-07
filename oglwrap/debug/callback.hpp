/** @file callback.hpp
    @brief A callback function for oglwrap errors
*/

#pragma once

#if OGLWRAP_DEBUG

namespace oglwrap {

/// The default callback function for errors. It prints the error to stderr.
inline void default_error_callback(std::string error_message) {
    std::cerr << error_message << std::endl;
}

/// A pointer to the callback function that will be called everytime an oglwrap error happens.
/** By default it prints to stderr, but you can assign any void(*)(std::string) type function to it.
  * Note: you can find out where the error happened inside your code, by setting a
  * breakpoint into this function, and repeatedly stepping out until you get out
  * into your code. It's INCREDIBLY useful! */
static void (*error_callback)(std::string) = default_error_callback;

} // namespace oglwrap

#endif // OGLWRAP_DEBUG

