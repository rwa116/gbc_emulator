#include "cpu.hpp"
#include "emulator.hpp"
#include <iostream>

CPU::CPU() {
    Reset();
}

CPU::~CPU() {
}

void CPU::Init(Emulator* emulator) {
    emu = emulator;
}

void CPU::Reset() {
    registers.a = 0x01;
    registers.f = 0xb0;
    registers.b = 0x00;
    registers.c = 0x13;
    registers.d = 0x00;
    registers.e = 0xd8;
    registers.h = 0x01;
    registers.l = 0x4d;
    registers.sp = 0xfffe;
    registers.pc = 0x0100;

    halted = false;

    interrupt_master_enable = false;
    interrupt_enable = 0x00;
}

void CPU::Step() {
    if(halted) {
        return;
    }
    // Fetch opcode and increment PC
    opcode = emu->bus.Read(ReadRegister(RT_PC));
    WriteRegister(RT_PC, ReadRegister(RT_PC) + 1);

    Execute(opcode);
}

uint8_t CPU::Execute(uint8_t opcode) {
    std::cout << "Executing opcode: " << std::hex << (int)opcode << std::endl;
    switch(opcode) {
        //0x0*
        case 0x00: return NOP();
        case 0x01: return LD_R_N(RT_BC, ReadRegister(RT_PC));
        case 0x02: return LD_BC_A();

        //0x1*

        //0x2*

        //0x3*

        //0x4*
        case 0x40: return LD_R_R(RT_B, RT_B);
        case 0x41: return LD_R_R(RT_B, RT_C);
        case 0x42: return LD_R_R(RT_B, RT_D);
        case 0x43: return LD_R_R(RT_B, RT_E);
        case 0x44: return LD_R_R(RT_B, RT_H);
        case 0x45: return LD_R_R(RT_B, RT_L);
        case 0x46: return LD_R_HL(RT_B);
        case 0x47: return LD_R_R(RT_B, RT_A);
        case 0x48: return LD_R_R(RT_C, RT_B);
        case 0x49: return LD_R_R(RT_C, RT_C);
        case 0x4a: return LD_R_R(RT_C, RT_D);
        case 0x4b: return LD_R_R(RT_C, RT_E);
        case 0x4c: return LD_R_R(RT_C, RT_H);
        case 0x4d: return LD_R_R(RT_C, RT_L);
        case 0x4e: return LD_R_HL(RT_C);
        case 0x4f: return LD_R_R(RT_C, RT_A);

        //0x5*
        case 0x50: return LD_R_R(RT_D, RT_B);
        case 0x51: return LD_R_R(RT_D, RT_C);
        case 0x52: return LD_R_R(RT_D, RT_D);
        case 0x53: return LD_R_R(RT_D, RT_E);
        case 0x54: return LD_R_R(RT_D, RT_H);
        case 0x55: return LD_R_R(RT_D, RT_L);
        case 0x56: return LD_R_HL(RT_D);
        case 0x57: return LD_R_R(RT_D, RT_A);
        case 0x58: return LD_R_R(RT_E, RT_B);
        case 0x59: return LD_R_R(RT_E, RT_C);
        case 0x5a: return LD_R_R(RT_E, RT_D);
        case 0x5b: return LD_R_R(RT_E, RT_E);
        case 0x5c: return LD_R_R(RT_E, RT_H);
        case 0x5d: return LD_R_R(RT_E, RT_L);
        case 0x5e: return LD_R_HL(RT_E);
        case 0x5f: return LD_R_R(RT_E, RT_A);

        //0x6*
        case 0x60: return LD_R_R(RT_H, RT_B);
        case 0x61: return LD_R_R(RT_H, RT_C);
        case 0x62: return LD_R_R(RT_H, RT_D);
        case 0x63: return LD_R_R(RT_H, RT_E);
        case 0x64: return LD_R_R(RT_H, RT_H);
        case 0x65: return LD_R_R(RT_H, RT_L);
        case 0x66: return LD_R_HL(RT_H);
        case 0x67: return LD_R_R(RT_H, RT_A);
        case 0x68: return LD_R_R(RT_L, RT_B);
        case 0x69: return LD_R_R(RT_L, RT_C);
        case 0x6a: return LD_R_R(RT_L, RT_D);
        case 0x6b: return LD_R_R(RT_L, RT_E);
        case 0x6c: return LD_R_R(RT_L, RT_H);
        case 0x6d: return LD_R_R(RT_L, RT_L);
        case 0x6e: return LD_R_HL(RT_L);
        case 0x6f: return LD_R_R(RT_L, RT_A);

        //0x7*
        case 0x70: return LD_HL_R(RT_B);
        case 0x71: return LD_HL_R(RT_C);
        case 0x72: return LD_HL_R(RT_D);
        case 0x73: return LD_HL_R(RT_E);
        case 0x74: return LD_HL_R(RT_H);
        case 0x75: return LD_HL_R(RT_L);

        case 0x77: return LD_HL_R(RT_A);
        case 0x78: return LD_R_R(RT_A, RT_B);
        case 0x79: return LD_R_R(RT_A, RT_C);
        case 0x7a: return LD_R_R(RT_A, RT_D);
        case 0x7b: return LD_R_R(RT_A, RT_E);
        case 0x7c: return LD_R_R(RT_A, RT_H);
        case 0x7d: return LD_R_R(RT_A, RT_L);
        case 0x7e: return LD_R_HL(RT_A);
        case 0x7f: return LD_R_R(RT_A, RT_A);
    }

    return 0;
}

uint16_t CPU::ReadRegister(register_type reg) {
    switch(reg) {
        case RT_A:
            return registers.a;
        case RT_F:
            return registers.f;
        case RT_B:
            return registers.b;
        case RT_C:
            return registers.c;
        case RT_D:
            return registers.d;
        case RT_E:
            return registers.e;
        case RT_H:
            return registers.h;
        case RT_L:
            return registers.l;
        case RT_AF:
            return (registers.a << 8) | registers.f;
        case RT_BC:
            return (registers.b << 8) | registers.c;
        case RT_DE:
            return (registers.d << 8) | registers.e;
        case RT_HL:
            return (registers.h << 8) | registers.l;
        case RT_SP:
            return registers.sp;
        case RT_PC:
            return registers.pc;
        default:
            return 0x0000;
    }
}

void CPU::WriteRegister(register_type reg, uint16_t value) {
    switch(reg) {
        case RT_A:
            registers.a = value;
            break;
        case RT_F:
            registers.f = value;
            break;
        case RT_B:
            registers.b = value;
            break;
        case RT_C:
            registers.c = value;
            break;
        case RT_D:
            registers.d = value;
            break;
        case RT_E:
            registers.e = value;
            break;
        case RT_H:
            registers.h = value;
            break;
        case RT_L:
            registers.l = value;
            break;
        case RT_AF:
            registers.a = value >> 8;
            registers.f = value & 0xff;
            break;
        case RT_BC:
            registers.b = value >> 8;
            registers.c = value & 0xff;
            break;
        case RT_DE:
            registers.d = value >> 8;
            registers.e = value & 0xff;
            break;
        case RT_HL:
            registers.h = value >> 8;
            registers.l = value & 0xff;
            break;
        case RT_SP:
            registers.sp = value;
            break;
        case RT_PC:
            registers.pc = value;
            break;
    }
}

uint8_t CPU::GetFlag(flag_type flag) {
    switch(flag) {
        case FT_Z:
            return (registers.f & 0x80) >> 7;
        case FT_N:
            return (registers.f & 0x40) >> 6;
        case FT_H:
            return (registers.f & 0x20) >> 5;
        case FT_C:
            return (registers.f & 0x10) >> 4;
        default:
            return 0x00;
    }
}

void CPU::SetFlag(flag_type flag, bool value) {
    switch(flag) {
        case FT_Z:
            if(value) {
                registers.f |= 0x80;
            } else {
                registers.f &= 0x7f;
            }
            break;
        case FT_N:
            if(value) {
                registers.f |= 0x40;
            } else {
                registers.f &= 0xbf;
            }
            break;
        case FT_H:
            if(value) {
                registers.f |= 0x20;
            } else {
                registers.f &= 0xdf;
            }
            break;
        case FT_C:
            if(value) {
                registers.f |= 0x10;
            } else {
                registers.f &= 0xef;
            }
            break;
    }
}