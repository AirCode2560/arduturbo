#pragma once
//===----------------------------------------------------------------------===//
// This file is part of the ArduTurbo project under the MIT license
//===----------------------------------------------------------------------===//
/// @file trans_ref.hpp
///
/// @brief __brief__
///
/// @author Saxon Murray <saxonmurray48@gmail.com>
/// @date 2026-03-09
/// @copyright (c) Saxon Murray 2026
//===----------------------------------------------------------------------===//

#include "meta.hpp"

namespace tbo::xtd {

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
