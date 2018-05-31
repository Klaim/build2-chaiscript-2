#pragma once

#include <iosfwd>
#include <string>

#include <libchaiscript/export.hxx>

namespace chaiscript
{
  // Print a greeting for the specified name into the specified
  // stream. Throw std::invalid_argument if the name is empty.
  //
  LIBCHAISCRIPT_SYMEXPORT void
  say_hello (std::ostream&, const std::string& name);
}
