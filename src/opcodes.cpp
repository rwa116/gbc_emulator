#include "cpu.hpp"
#include "bus.hpp"
#include "emulator.hpp"

uint8_t CPU::NOP() {
    return 4;
}

// 8-bit load instructions

uint8_t CPU::LD_R_R(register_type reg1, register_type reg2) {
    uint16_t value = ReadRegister(reg2);
    WriteRegister(reg1, value);
    return 4;
}

uint8_t CPU::LD_R_N(register_type reg, uint8_t value) {
    WriteRegister(reg, value);
    return 8;
}

uint8_t CPU::LD_R_HL(register_type reg) {
    uint16_t value = emu->bus.Read(ReadRegister(RT_HL));
    WriteRegister(reg, value);
    return 8;
}

uint8_t CPU::LD_HL_R(register_type reg) {
    uint16_t address = ReadRegister(RT_HL);
    uint8_t value = ReadRegister(reg);
    emu->bus.Write(address, value);
    return 8;
}

uint8_t CPU::LD_HL_N(uint8_t value) {
    uint16_t address = ReadRegister(RT_HL);
    emu->bus.Write(address, value);
    return 12;
}

uint8_t CPU::LD_A_BC() {
    uint16_t address = ReadRegister(RT_BC);
    uint8_t value = emu->bus.Read(address);
    WriteRegister(RT_A, value);
    return 8;
}

uint8_t CPU::LD_A_DE() {
    uint16_t address = ReadRegister(RT_DE);
    uint8_t value = emu->bus.Read(address);
    WriteRegister(RT_A, value);
    return 8;
}

uint8_t CPU::LD_A_NN(uint16_t address) {
    uint8_t value = emu->bus.Read(address);
    WriteRegister(RT_A, value);
    return 16;
}

uint8_t CPU::LD_BC_A() {
    uint16_t address = ReadRegister(RT_BC);
    uint8_t value = ReadRegister(RT_A);
    emu->bus.Write(address, value);
    return 8;
}

uint8_t CPU::LD_DE_A() {
    uint16_t address = ReadRegister(RT_DE);
    uint8_t value = ReadRegister(RT_A);
    emu->bus.Write(address, value);
    return 8;
}

uint8_t CPU::LD_NN_A(uint16_t address) {
    uint8_t value = ReadRegister(RT_A);
    emu->bus.Write(address, value);
    return 16;
}

uint8_t CPU::LD_A_FF00_N(uint8_t value) {
    uint16_t address = 0xff00 | value;
    uint8_t data = emu->bus.Read(address);
    WriteRegister(RT_A, data);
    return 12;
}

uint8_t CPU::LD_FF00_N_A(uint8_t value) {
    uint16_t address = 0xff00 | value;
    uint8_t data = ReadRegister(RT_A);
    emu->bus.Write(address, data);
    return 12;
}

uint8_t CPU::LD_A_FF00_C() {
    uint16_t address = 0xff00 | ReadRegister(RT_C);
    uint8_t data = emu->bus.Read(address);
    WriteRegister(RT_A, data);
    return 8;
}

uint8_t CPU::LD_FF00_C_A() {
    uint16_t address = 0xff00 | ReadRegister(RT_C);
    uint8_t data = ReadRegister(RT_A);
    emu->bus.Write(address, data);
    return 8;
}

uint8_t CPU::LDI_HL_A() {
    uint16_t address = ReadRegister(RT_HL);
    uint8_t data = ReadRegister(RT_A);
    emu->bus.Write(address, data);
    WriteRegister(RT_HL, address + 1);
    return 8;
}

uint8_t CPU::LDI_A_HL() {
    uint16_t address = ReadRegister(RT_HL);
    uint8_t data = emu->bus.Read(address);
    WriteRegister(RT_A, data);
    WriteRegister(RT_HL, address + 1);
    return 8;
}

uint8_t CPU::LDD_HL_A() {
    uint16_t address = ReadRegister(RT_HL);
    uint8_t data = ReadRegister(RT_A);
    emu->bus.Write(address, data);
    WriteRegister(RT_HL, address - 1);
    return 8;
}

uint8_t CPU::LDD_A_HL() {
    uint16_t address = ReadRegister(RT_HL);
    uint8_t data = emu->bus.Read(address);
    WriteRegister(RT_A, data);
    WriteRegister(RT_HL, address - 1);
    return 8;
}

// 16-bit load instructions

uint8_t CPU::LD_RR_NN(register_type reg, uint16_t value) {
    WriteRegister(reg, value);
    return 12;
}

uint8_t CPU::LD_NN_SP(uint16_t address) {
    uint16_t value = ReadRegister(RT_SP);
    emu->bus.Write(address, value & 0xff);
    emu->bus.Write(address + 1, value >> 8);
    return 20;
}

uint8_t CPU::LD_SP_HL() {
    uint16_t value = ReadRegister(RT_HL);
    WriteRegister(RT_SP, value);
    return 8;
}

uint8_t CPU::LD_PUSH_RR(register_type reg) {
    uint16_t value = ReadRegister(reg);
    WriteRegister(RT_SP, ReadRegister(RT_SP) - 2);
    emu->bus.Write16(ReadRegister(RT_SP), value);
    return 16;
}

uint8_t CPU::LD_POP_RR(register_type reg) {
    uint16_t value = emu->bus.Read16(ReadRegister(RT_SP));
    WriteRegister(reg, value);
    WriteRegister(RT_SP, ReadRegister(RT_SP) + 2);
    return 12;
}