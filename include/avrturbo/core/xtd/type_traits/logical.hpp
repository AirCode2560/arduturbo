#pragma once
//===----------------------------------------------------------------------===//
// This file is part of the AvrTurbo project under the MIT license
//===----------------------------------------------------------------------===//
/// @file logical.hpp
///
/// @brief __brief__
///
/// @author Saxon Murray <saxonmurray48@gmail.com>
/// @date 2026-03-09
/// @copyright (c) Saxon Murray 2026
//===----------------------------------------------------------------------===//

#include "meta.hpp"

namespace tbo::xtd {

    // --- Conjunction ---

    template<typename ...>
    struct Conjunction : TrueType {};

    template<typename B1>
    struct Conjunction<B1> : B1 {};

    template<typename B1, typename ... Bn>
    struct Conjunction<B1, Bn ...>
        : Conditional_t<B1::value, Conjunction<Bn...>, B1> {};

    template<typename ... B>
    inline constexpr bool conjunction_v = Conjunction<B...>::value;

    // --- Disjunction ---

    template<typename ...>
    struct Disjunction : FalseType {};

    template<typename B1>
    struct Disjunction<B1> : B1 {};

    template<typename B1, typename ... Bn>
    struct Disjunction<B1, Bn ...>
        : Conditional_t<B1::value, B1, Disjunction<Bn...> > {};

    template<typename ... B>
    inline constexpr bool disjunction_v = Disjunction<B...>::value;

    // --- Negation ---

    template< typename B>
    struct Negation : BoolConstant<!bool(B::value)> {};

    template<typename B>
    inline constexpr bool negation_v = Negation<B>::value;

}
