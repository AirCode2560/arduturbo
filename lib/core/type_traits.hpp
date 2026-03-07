#pragma once
//===----------------------------------------------------------------------===//
// This file is part of the ArduTurbo project under the MIT license
//===----------------------------------------------------------------------===//
/// @file type_traits.hpp
///
/// @brief __brief__
///
/// @author Saxon Murray <saxonmurray48@gmail.com>
/// @date 2026-03-07
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

    // --- IsSame ---

    template<typename T, typename U>
    struct IsSame : FalseType {};

    template<typename T>
    struct IsSame<T, T> : TrueType {};

    template<typename T, typename U>
    inline constexpr bool is_same_v = IsSame<T, U>::value;

    // --- RemoveConst ---

    template<typename T>
    struct RemoveConst : TypeIdentity<T> {};

    template<typename T>
    struct RemoveConst<const T> : TypeIdentity<T> {};

    template<typename T>
    using RemoveConst_t = typename RemoveConst<T>::type;

    // --- RemoveVolatile ---

    template<typename T>
    struct RemoveVolatile : TypeIdentity<T> {};

    template<typename T>
    struct RemoveVolatile<volatile T> : TypeIdentity<T> {};

    template<typename T>
    using RemoveVolatile_t = typename RemoveVolatile<T>::type;

    // --- RemoveCV ---

    template<typename T>
    struct RemoveCV : TypeIdentity<T> {};

    template<typename T> struct RemoveCV<const T>          : TypeIdentity<T> {};
    template<typename T> struct RemoveCV<volatile T>       : TypeIdentity<T> {};
    template<typename T> struct RemoveCV<const volatile T> : TypeIdentity<T> {};

    template<typename T>
    using RemoveCV_t = typename RemoveCV<T>::type;

    // --- AddConst ---

    template<typename T>
    struct AddConst : TypeIdentity<const T> {};

    template<typename T>
    using AddConst_t = typename AddConst<T>::type;

    // --- AddVolatile ---

    template<typename T>
    struct AddVolatile : TypeIdentity<volatile T> {};

    template<typename T>
    using AddVolatile_t = typename AddVolatile<T>::type;

    // --- AddCV ---

    template<typename T>
    struct AddCV : TypeIdentity<const volatile T> {};

    template<typename T>
    using AddCV_t = typename AddCV<T>::type;

    // --- RemoveReference ---

    template<typename T>
    struct RemoveReference : TypeIdentity<T> {};

    template<typename T> struct RemoveReference<T&>  : TypeIdentity<T> {};
    template<typename T> struct RemoveReference<T&&> : TypeIdentity<T> {};

    template<typename T>
    using RemoveReference_t = typename RemoveReference<T>::type;

    // --- AddLvalueReference ---

    template<typename T>
    struct AddLvalueReference : TypeIdentity<T&> {};

    template<> struct AddLvalueReference<void>                : TypeIdentity<void> {};
    template<> struct AddLvalueReference<const void>          : TypeIdentity<const void> {};
    template<> struct AddLvalueReference<volatile void>       : TypeIdentity<volatile void> {};
    template<> struct AddLvalueReference<const volatile void> : TypeIdentity<const volatile void> {};

    template<typename T>
    using AddLvalueReference_t = typename AddLvalueReference<T>::type;

    // --- AddRvalueReference ---

    template<typename T>
    struct AddRvalueReference : TypeIdentity<T&&> {};

    template<> struct AddRvalueReference<void>                : TypeIdentity<void> {};
    template<> struct AddRvalueReference<const void>          : TypeIdentity<const void> {};
    template<> struct AddRvalueReference<volatile void>       : TypeIdentity<volatile void> {};
    template<> struct AddRvalueReference<const volatile void> : TypeIdentity<const volatile void> {};

    template<typename T>
    using AddRvalueReference_t = typename AddRvalueReference<T>::type;

}
