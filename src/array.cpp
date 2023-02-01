#include "array.h"

#include <cassert>
#include <iostream>

namespace my {
template<class T, std::size_t N>
CONSTEXPR_M const T&
array<T, N>::operator[](std::size_t idx) const
{
    assert(idx < N);
    return arr[idx];
}

template<class T, std::size_t N>
CONSTEXPR_M T&
array<T, N>::operator[](std::size_t idx)
{
    assert(idx < N);
    return arr[idx];
}

template<class T, std::size_t N>
void
array<T, N>::print() const
{
    for (auto const xi : arr) {
        std::cout << xi << ' ';
    }
}

} // namespace my

// Compiles with MSVC
// template my::array<int, 3>;
// template my::array<double, 4>;

template class my::array<int, 3>;
template class my::array<double, 4>;