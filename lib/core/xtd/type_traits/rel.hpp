#pragma once
//===----------------------------------------------------------------------===//
// This file is part of the ArduTurbo project under the MIT license
//===----------------------------------------------------------------------===//
/// @file rel.hpp
///
/// @brief __brief__
///
/// @author Saxon Murray <saxonmurray48@gmail.com>
/// @date 2026-03-09
/// @copyright (c) Saxon Murray 2026
//===----------------------------------------------------------------------===//

#include "meta.hpp"
#include "logical.hpp"

namespace tbo::xtd {

    // --- IsSame ---

    template<typename T, typename U>
    struct IsSame : FalseType {};

    template<typename T>
    struct IsSame<T, T> : TrueType {};

    template<typename T, typename U>
    inline constexpr bool is_same_v = IsSame<T, U>::value;

    template<typename T, typename U>
    concept SameAs = is_same_v<T, U> && is_same_v<U, T>;

    // --- IsAnyOf ---

    template<typename T, typename ...Ts>
    struct IsAnyOf : Disjunction<IsSame<T, Ts>...> {};

    template<typename T, typename ...Ts>
    inline constexpr bool is_any_of_v = IsAnyOf<T, Ts...>::value;

    template<typename T, typename ...Ts>
    concept AnyOf = is_any_of_v<T, Ts...>;

}
