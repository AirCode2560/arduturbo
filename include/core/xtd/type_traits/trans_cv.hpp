#pragma once
//===----------------------------------------------------------------------===//
// This file is part of the AvrTurbo project under the MIT license
//===----------------------------------------------------------------------===//
/// @file trans_cv.hpp
///
/// @brief __brief__
///
/// @author Saxon Murray <saxonmurray48@gmail.com>
/// @date 2026-03-09
/// @copyright (c) Saxon Murray 2026
//===----------------------------------------------------------------------===//

#include "meta.hpp"

namespace tbo::xtd {

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

}
