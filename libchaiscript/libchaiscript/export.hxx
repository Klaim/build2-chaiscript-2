#pragma once

// Normally we don't export class templates (but do complete specializations),
// inline functions, and classes with only inline member functions. Exporting
// classes that inherit from non-exported/imported bases (e.g., std::string)
// will end up badly. The only known workarounds are to not inherit or to not
// export. Also, MinGW GCC doesn't like seeing non-exported functions being
// used before their inline definition. The workaround is to reorder code. In
// the end it's all trial and error.

#if defined(LIBCHAISCRIPT_STATIC)         // Using static.
#  define LIBCHAISCRIPT_SYMEXPORT
#elif defined(LIBCHAISCRIPT_STATIC_BUILD) // Building static.
#  define LIBCHAISCRIPT_SYMEXPORT
#elif defined(LIBCHAISCRIPT_SHARED)       // Using shared.
#  ifdef _WIN32
#    define LIBCHAISCRIPT_SYMEXPORT __declspec(dllimport)
#  else
#    define LIBCHAISCRIPT_SYMEXPORT
#  endif
#elif defined(LIBCHAISCRIPT_SHARED_BUILD) // Building shared.
#  ifdef _WIN32
#    define LIBCHAISCRIPT_SYMEXPORT __declspec(dllexport)
#  else
#    define LIBCHAISCRIPT_SYMEXPORT
#  endif
#else
// If none of the above macros are defined, then we assume we are being used
// by some third-party build system that cannot/doesn't signal the library
// type. Note that this fallback works for both static and shared but in case
// of shared will be sub-optimal compared to having dllimport.
//
#  define LIBCHAISCRIPT_SYMEXPORT         // Using static or shared.
#endif
