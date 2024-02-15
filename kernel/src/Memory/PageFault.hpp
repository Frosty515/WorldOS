/*
Copyright (©) 2024  Frosty515

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

#ifndef _PAGE_FAULT_HPP
#define _PAGE_FAULT_HPP

#include <stdint.h>

#include <HAL/hal.hpp>

struct PageFaultErrorCode {
    bool readable;
    bool writable;
    bool user;
    bool reserved_write;
    bool instruction_fetch;
};

void __attribute__((noreturn)) PageFaultHandler(PageFaultErrorCode error_code, void* faulting_address, void* current_address, CPU_Registers* regs, BasicVGA* VGADevice, Colour& background);

#endif /* _PAGE_FAULT_HPP */