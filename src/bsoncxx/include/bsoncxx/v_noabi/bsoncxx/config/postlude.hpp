// Copyright 2014 MongoDB Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// compiler.hpp
#undef BSONCXX_INLINE
#pragma pop_macro("BSONCXX_INLINE")
BSONCXX_POP_WARNINGS();
#undef BSONCXX_CALL
#pragma pop_macro("BSONCXX_CALL")

// config.hpp (generated by CMake)
#undef BSONCXX_INLINE_NAMESPACE_BEGIN
#pragma pop_macro("BSONCXX_INLINE_NAMESPACE_BEGIN")
#undef BSONCXX_INLINE_NAMESPACE_END
#pragma pop_macro("BSONCXX_INLINE_NAMESPACE_END")
#undef BSONCXX_POLY_USE_MNMLSTC
#pragma pop_macro("BSONCXX_POLY_USE_MNMLSTC")
#undef BSONCXX_POLY_USE_STD_EXPERIMENTAL
#pragma pop_macro("BSONCXX_POLY_USE_STD_EXPERIMENTAL")
#undef BSONCXX_POLY_USE_SYSTEM_MNMLSTC
#pragma pop_macro("BSONCXX_POLY_USE_SYSTEM_MNMLSTC")
#undef BSONCXX_POLY_USE_BOOST
#pragma pop_macro("BSONCXX_POLY_USE_BOOST")

// version.hpp (generated by CMake)
#undef BSONCXX_VERSION_EXTRA
#pragma pop_macro("BSONCXX_VERSION_EXTRA")
#undef BSONCXX_VERSION_MAJOR
#pragma pop_macro("BSONCXX_VERSION_MAJOR")
#undef BSONCXX_VERSION_MINOR
#pragma pop_macro("BSONCXX_VERSION_MINOR")
#undef BSONCXX_VERSION_PATCH
#pragma pop_macro("BSONCXX_VERSION_PATCH")

// export.hpp (generated by CMake)
#undef BSONCXX_API_H
#pragma pop_macro("BSONCXX_API_H")
#undef BSONCXX_API
#pragma pop_macro("BSONCXX_API")
#undef BSONCXX_PRIVATE
#pragma pop_macro("BSONCXX_PRIVATE")
#undef BSONCXX_DEPRECATED
#pragma pop_macro("BSONCXX_DEPRECATED")
#undef BSONCXX_DEPRECATED_EXPORT
#pragma pop_macro("BSONCXX_DEPRECATED_EXPORT")
#undef BSONCXX_DEPRECATED_NO_EXPORT
#pragma pop_macro("BSONCXX_DEPRECATED_NO_EXPORT")
#undef DEFINE_NO_DEPRECATED
#pragma pop_macro("DEFINE_NO_DEPRECATED")
#undef BSONCXX_NO_DEPRECATED
#pragma pop_macro("BSONCXX_NO_DEPRECATED")

// prelude.hpp
#undef BSONCXX_UNREACHABLE
#pragma pop_macro("BSONCXX_UNREACHABLE")

#pragma pop_macro("bsoncxx_cxx14_constexpr")
#pragma pop_macro("BSONCXX_RETURNS")

// CXX-2769: out-of-place, but remains for backward compatibility.
#ifdef BSONCXX_ENUM
static_assert(false, "BSONCXX_ENUM must be undef'ed");
#endif
#pragma pop_macro("BSONCXX_ENUM")

// util.hpp
#pragma pop_macro("BSONCXX_PUSH_WARNINGS")
#pragma pop_macro("BSONCXX_POP_WARNINGS")
#pragma pop_macro("BSONCXX_DISABLE_WARNING")

#pragma pop_macro("_bsoncxxDisableWarningImpl_for_MSVC")
#pragma pop_macro("_bsoncxxDisableWarningImpl_for_GCC")
#pragma pop_macro("_bsoncxxDisableWarningImpl_for_GNU")
#pragma pop_macro("_bsoncxxDisableWarningImpl_for_Clang")

#pragma pop_macro("BSONCXX_CONCAT")
#pragma pop_macro("BSONCXX_CONCAT_IMPL")

#pragma pop_macro("BSONCXX_PRAGMA")
#pragma pop_macro("_bsoncxxPragma")
#pragma pop_macro("BSONCXX_STRINGIFY_IMPL")
#pragma pop_macro("BSONCXX_STRINGIFY")
#pragma pop_macro("BSONCXX_FORCE_SEMICOLON")

#pragma pop_macro("BSONCXX_IF_MSVC")
#pragma pop_macro("BSONCXX_IF_GCC")
#pragma pop_macro("BSONCXX_IF_CLANG")
#pragma pop_macro("BSONCXX_IF_GNU_LIKE")

#pragma pop_macro("BSONCXX_FWD")
