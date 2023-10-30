/*
Copyright (©) 2022-2023  Frosty515

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef _KERNEL_UTIL_H
#define _KERNEL_UTIL_H

#include "stdint.h"
#include "stddef.h"

#define KiB(x) ((uint64_t)x * (uint64_t)1024)
#define MiB(x) (KiB(x) * (uint64_t)1024)
#define GiB(x) (MiB(x) * (uint64_t)1024)

#ifndef KERNEL_STACK_SIZE
// Size of the kernel stack after init
#define KERNEL_STACK_SIZE 16384
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define BCD_TO_BINARY(x) (((x & 0xF0) >> 1) + ((x & 0xF0) >> 3) + (x & 0xF))

#define DIV_ROUNDUP(VALUE, DIV) (VALUE + (DIV - 1)) / DIV

#define DIV_ROUNDUP_ADDRESS(ADDR, DIV) (void*)(((unsigned long)ADDR + (DIV - 1)) / DIV)

#define ALIGN_UP(VALUE, ALIGN) DIV_ROUNDUP(VALUE, ALIGN) * ALIGN

#define ALIGN_DOWN(VALUE, ALIGN) (VALUE / ALIGN) * ALIGN

#define ALIGN_ADDRESS_DOWN(ADDR, ALIGN) (void*)(((unsigned long)ADDR / ALIGN) * ALIGN)

#define ALIGN_ADDRESS_UP(ADDR, ALIGN) (void*)((((unsigned long)ADDR + (ALIGN - 1)) / ALIGN) * ALIGN)

#define PAGE_SIZE 4096

void* memset(void* dst, const uint8_t value, const size_t n);
void* memcpy(void* dst, const void* src, const size_t n);
void* memmove(void* dst, const void* src, const size_t n);

/*
Uses 64-bit operations to quick fill a buffer.
dst is where you write to
value is the value you want to write
n is the amount of times you want to write that value
*/
void fast_memset(void* dst, const uint64_t value, const size_t n);

/*
Uses 64-bit operations to quick copy between buffers.
dst is where you write to
src is the value you want to copy from
n is the amount of data you want to copy, and must be a multiple of 8. If it isn't, it will skip the extra, so it is a multiple of 8.
*/
void* fast_memcpy(void* dst, const void* src, const size_t n);

/*
Uses 64-bit operations to quick copy between buffers.
dst is where you write to
src is the value you want to copy from
n is the amount of data you want to copy, and must be a multiple of 8. If it isn't, it will skip the extra, so it is a multiple of 8.
*/
void* fast_memmove(void* dst, const void* src, const size_t n);

int memcmp(const void* s1, const void* s2, const size_t n);

#define FLAG_SET(x, flag) x |= (flag)
#define FLAG_UNSET(x, flag) x &= ~(flag)

#ifdef __cplusplus
}
#endif

#endif /*_KERNEL_UTIL_H */