#pragma once

#include <cstddef>

// clang does not allow explicitly instantiated constexpr member functions
// of class templates
#if !defined(__clang__) &&                                                     \
  (__cpp_constexpr >= 201304 || (defined(_MSC_VER) && _MSC_VER >= 1910))
#define CONSTEXPR_M constexpr
#else
#define CONSTEXPR_M
#endif

// NOTE to export explicitly instantiated member functions, prefix with
// appropriate dllexport/dllimport for clang/llvm w/ msvc frontend;
// msvc does not need this
#include "core_export.h"

namespace my {
template<typename T, std::size_t N>
class array
{
public:
    T arr[N];

    CORE_EXPORT CONSTEXPR_M const T& operator[](std::size_t idx) const;
    CORE_EXPORT CONSTEXPR_M T& operator[](std::size_t idx);

    CORE_EXPORT void print() const;
};
} // namespace my