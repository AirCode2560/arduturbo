#pragma once
//===----------------------------------------------------------------------===//
// This file is part of the ArduTurbo project under the MIT license
//===----------------------------------------------------------------------===//
/// @file meta.hpp
///
/// @brief __brief__
///
/// @author Saxon Murray <saxonmurray48@gmail.com>
/// @date 2026-03-09
/// @copyright (c) Saxon Murray 2026
//===----------------------------------------------------------------------===//

namespace tbo::xtd {

    // --- IntegralConstant ---

    template<typename T, T v>
    struct IntegralConstant {
        using value_type = T;
        using type = IntegralConstant<T, v>;

        inline static constexpr value_type value = v;

        constexpr operator value_type () const {
            return value;
        }

        constexpr value_type operator()() const {
            return value;
        }
    };

    template<bool b>
    using BoolConstant = IntegralConstant<bool, b>;

    using TrueType = BoolConstant<true>;
    using FalseType = BoolConstant<false>;

    // --- TypeIdentity ---

    template<typename T>
    struct TypeIdentity {
        using type = T;
    };

    template<typename T>
    using TypeIdentity_t = typename TypeIdentity<T>::type;

    // --- Void_t ---

    template<typename ...>
    using Void_t = void;

    // --- EnableIf ---

    template<bool b, typename T = void>
    struct EnableIf {};

    template<typename T>
    struct EnableIf<true, T> : TypeIdentity<T> {};

    template<bool b, typename T = void>
    using EnableIf_t = typename EnableIf<b, T>::type;

    // --- Conditional ---

    template<bool b, typename T, typename F>
    struct Conditional : TypeIdentity<F> {};

    template<typename T, typename F>
    struct Conditional<true, T, F> : TypeIdentity<T> {};

    template<bool b, typename T, typename F>
    using Conditional_t = typename Conditional<b, T, F>::type;

}
