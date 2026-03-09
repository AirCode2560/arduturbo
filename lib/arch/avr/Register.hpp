#pragma once
//===----------------------------------------------------------------------===//
// This file is part of the ArduTurbo project under the MIT license
//===----------------------------------------------------------------------===//
/// @file Register.hpp
///
/// @brief __brief__
///
/// @author Saxon Murray <saxonmurray48@gmail.com>
/// @date 2026-03-07
/// @copyright (c) Saxon Murray 2026
//===----------------------------------------------------------------------===//

#include <stdint.h>
#include "../../core/xtd/type_traits.hpp"

namespace tbo::reg {

    // --- Address ---

    struct Address {
        const uintptr_t value;
        constexpr Address(uintptr_t v) : value{v} {}
    };

    // --- Register ---

    template<xtd::Integral T, Address addr>
    struct Register {
        using value_type = T;
        using ref_type = volatile T&;
        using ptr_type = volatile T*;

        static constexpr Address address = addr;

        [[nodiscard]]
        [[gnu::always_inline]]
        static inline ref_type ref() {
            return *reinterpret_cast<ptr_type>(address.value);
        }

        [[nodiscard]]
        [[gnu::always_inline]]
        static inline ptr_type ptr() {
            return reinterpret_cast<ptr_type>(address.value);
        }

        [[nodiscard]]
        [[gnu::always_inline]]
        static inline value_type read() {
            return ref();
        }

        [[gnu::always_inline]]
        static inline void write(value_type value) {
            ref() = value;
        }

        [[gnu::always_inline]]
        static inline void set(value_type mask) {
            ref() |= mask;
        }

        [[gnu::always_inline]]
        static inline void clear(value_type mask) {
            ref() &= ~mask;
        }

        [[gnu::always_inline]]
        static inline void toggle(value_type mask) {
            ref() ^= mask;
        }
    };

    template<typename T, typename U = void>
    struct IsRegister : xtd::FalseType {};

    template<xtd::Integral T, Address addr>
    struct IsRegister<Register<T, addr>, void> : xtd::TrueType {};

    template<xtd::Integral T, Address addr>
    struct IsRegister<Register<T, addr>, T> : xtd::TrueType {};

    template<typename T, typename U = void>
    inline constexpr bool is_register_v = IsRegister<T, U>::value;

    template<typename T, typename U = void>
    concept RegisterType = is_register_v<T, U>;

    // --- Bit ---

    template<RegisterType Reg, uint8_t idx>
    struct Bit {
        using reg_type = Reg;
        using value_type = typename Reg::value_type;

        static_assert(idx < sizeof(value_type) * 8, "bit index out of range");

        static constexpr uint8_t index = idx;
        static constexpr value_type bit_mask = value_type{1} << index;

        [[nodiscard]]
        [[gnu::always_inline]]
        static inline bool read() {
            return (reg_type::read() & bit_mask) != 0;
        }

        [[gnu::always_inline]]
        static inline void write(bool value) {
            if (value) set();
            else clear();
        }

        [[gnu::always_inline]]
        static inline void set() {
            reg_type::set(bit_mask);
        }

        [[gnu::always_inline]]
        static inline void clear() {
            reg_type::clear(bit_mask);
        }

        [[gnu::always_inline]]
        static inline void toggle() {
            reg_type::toggle(bit_mask);
        }
    };

    template<typename T>
    struct IsBit : xtd::FalseType {};

    template<RegisterType Reg, uint8_t idx>
    struct IsBit<Bit<Reg, idx> > : xtd::TrueType {};

    template<typename T>
    inline constexpr bool is_bit_v = IsBit<T>::value;

    template<typename T>
    concept BitType = is_bit_v<T>;

}
