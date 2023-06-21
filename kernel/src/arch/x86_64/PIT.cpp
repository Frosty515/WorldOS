#include "PIT.hpp"
#include "io.h"

#include <stdio.hpp>

#include <Scheduling/Scheduler.hpp>

#include "interrupts/pic.hpp"
#include "interrupts/IRQ.hpp"

#include "Scheduling/taskutil.hpp"

uint64_t g_Divisor = 0;
uint64_t g_Frequency = 0;
uint64_t g_ticks = 0;

#define DATA_0  0x40
#define DATA_1  0x41
#define DATA_2  0x42
#define COMMAND 0x43

#define BASE_FREQUENCY 1193182

void x86_64_PIT_Handler(x86_64_Interrupt_Registers* iregs) {
    g_ticks += 10;
    if (!NewDeleteInitialised())
        return;
    x86_64_Registers* regs = new x86_64_Registers;
    if (regs != nullptr)
        x86_64_ConvertToStandardRegisters(regs, iregs);
    x86_64_Registers* rregs = Scheduling::Scheduler::TimerTick(regs);
    if (rregs != nullptr)
        x86_64_PrepareNewRegisters(iregs, rregs);
    if (regs != nullptr)
        delete regs;
}

void x86_64_PIT_Init() {
    x86_64_outb(COMMAND, 0b00110110 /* Channel 0, lobyte/hibyte, Mode 3 (Square wave generator), 16-bit binary*/);

    x86_64_outb(DATA_0, g_Divisor & 0xFF);
    x86_64_outb(DATA_0, (g_Divisor >> 8) & 0xFF);

    x86_64_PIC_Unmask(0);
    x86_64_IRQ_RegisterHandler(0, (x86_64_IRQHandler_t)x86_64_PIT_Handler);

    g_Divisor = 0;
    g_Frequency = 0;
    g_ticks = 0;
}

void x86_64_PIT_SetDivisor(uint64_t div) {
    g_Divisor = div;
    g_Frequency = BASE_FREQUENCY / div;
    x86_64_outb(DATA_0, g_Divisor & 0xFF);
    x86_64_outb(DATA_0, (g_Divisor >> 8) & 0xFF);
}

uint64_t x86_64_PIT_GetTicks() {
    return g_ticks;
}

void x86_64_PIT_SetTicks(uint64_t t) {
    g_ticks = t;
}
