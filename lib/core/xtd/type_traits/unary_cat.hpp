#pragma once
//===----------------------------------------------------------------------===//
// This file is part of the ArduTurbo project under the MIT license
//===----------------------------------------------------------------------===//
/// @file unary_cat.hpp
///
/// @brief __brief__
///
/// @author Saxon Murray <saxonmurray48@gmail.com>
/// @date 2026-03-09
/// @copyright (c) Saxon Murray 2026
//===----------------------------------------------------------------------===//

#include <stddef.h>
#include "trans_cv.hpp"
#include "rel.hpp"

namespace tbo::xtd {

    // --- IsVoid ---

    template<typename T>
    struct IsVoid : IsSame<RemoveCV_t<T>, void> {};

    template<typename T>
    inline constexpr bool is_void_v = IsVoid<T>::value;

    // --- IsNullPointer ---

    template<typename T>
    struct IsNullPointer : IsSame<RemoveCV_t<T>, nullptr_t> {};

    template<typename T>
    inline constexpr bool is_null_pointer_v = IsNullPointer<T>::value;

    // --- IsIntegral ---

    template<typename T>
    struct IsIntegral : IsAnyOf<RemoveCV_t<T>,
            bool,
            char, signed char, unsigned char,
            short, unsigned short,
            int, unsigned int,
            long, unsigned long,
            long long, unsigned long long> {};

    template<typename T>
    inline constexpr bool is_integral_v = IsIntegral<T>::value;

    template<typename T>
    concept Integral = is_integral_v<T>;

    // --- IsFloatingPoint ---

    template<typename T>
    struct IsFloatingPoint : IsAnyOf<RemoveCV_t<T>,
            float, double, long double> {};

    template<typename T>
    inline constexpr bool is_floating_point_v = IsFloatingPoint<T>::value;

    template<typename T>
    concept FloatingPoint = is_floating_point_v<T>;

}
