#pragma once
//===----------------------------------------------------------------------===//
// This file is part of the AvrTurbo project under the MIT license
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

    // --- IsArray ---

    template<typename T>
    struct IsArray : FalseType {};

    template<typename T>           struct IsArray<T[]>  : TrueType {};
    template<typename T, size_t n> struct IsArray<T[n]> : TrueType {};

    template<typename T>
    inline constexpr bool is_array_v = IsArray<T>::value;

    // --- IsEnum ---

    template<typename T>
    struct IsEnum : BoolConstant<__is_enum(T)> {};

    template<typename T>
    inline constexpr bool is_enum_v = IsEnum<T>::value;

    // --- IsUnion ---

    template<typename T>
    struct IsUnion : BoolConstant<__is_union(T)> {};

    template<typename T>
    inline constexpr bool is_union_v = IsUnion<T>::value;

    // --- IsClass ---

    template<typename T>
    struct IsClass : BoolConstant<__is_class(T)> {};

    template<typename T>
    inline constexpr bool is_class_v = IsClass<T>::value;

    // --- IsFunction ---

    template<typename T>
    struct IsFunction : BoolConstant<__is_function(T)> {};

    template<typename T>
    inline constexpr bool is_function_v = IsFunction<T>::value;

    // --- IsPointer ---

    template<typename T>
    struct IsPointer : FalseType {};

    template<typename T>
    struct IsPointer<T*> : TrueType {};

    template<typename T>
    inline constexpr bool is_pointer_v = IsPointer<T>::value;

    // --- IsLvalueReference ---

    template<typename T>
    struct IsLvalueReference : FalseType {};

    template<typename T>
    struct IsLvalueReference<T&> : TrueType {};

    template<typename T>
    inline constexpr bool is_lvalue_reference_v = IsLvalueReference<T>::value;

    // --- IsRvalueReference ---

    template<typename T>
    struct IsRvalueReference : FalseType {};

    template<typename T>
    struct IsRvalueReference<T&&> : TrueType {};

    template<typename T>
    inline constexpr bool is_rvalue_reference_v = IsRvalueReference<T>::value;

    // --- IsMemberObjectPointer ---


    template<typename T>
    struct IsMemberObjectPointer
        : BoolConstant<__is_member_object_pointer(T)> {};

    template<typename T>
    inline constexpr bool is_member_object_pointer_v =
        IsMemberObjectPointer<T>::value;

    // --- IsMemberFunctionPointer ---

    template<typename T>
    struct IsMemberFunctionPointer
        : BoolConstant<__is_member_function_pointer(T)> {};

    template<typename T>
    inline constexpr bool is_member_function_pointer_v =
        IsMemberFunctionPointer<T>::value;

}
