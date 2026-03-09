#pragma once
//===----------------------------------------------------------------------===//
// This file is part of the ArduTurbo project under the MIT license
//===----------------------------------------------------------------------===//
/// @file trans_other.hpp
///
/// @brief __brief__
///
/// @author Saxon Murray <saxonmurray48@gmail.com>
/// @date 2026-03-09
/// @copyright (c) Saxon Murray 2026
//===----------------------------------------------------------------------===//

#include "trans_cv.hpp"
#include "trans_ref.hpp"

namespace tbo::xtd {

    // --- RemoveCVRef ---

    template<typename T>
    struct RemoveCVRef : RemoveCV<RemoveReference_t<T> > {};

    template<typename T>
    using RemoveCVRef_t = typename RemoveCVRef<T>::type;

}
