#include "bus.hpp"
#include "emulator.hpp"

Bus::Bus() {
}

Bus::~Bus() {
}

void Bus::Init(Emulator *emulator) {
    emu = emulator;
}

uint8_t Bus::Read(uint16_t address) {
    switch(address) {
        case 0x0000 ... 0x7fff:
            return emu->cartridge.Read(address);
        case 0x8000 ... 0x9fff:
            return 0x00;
        case 0xa000 ... 0xbfff:
            return 0x00;
        case 0xc000 ... 0xdfff:
            return 0x00;
        case 0xe000 ... 0xfdff:
            return 0x00;
        case 0xfe00 ... 0xfe9f:
            return 0x00;
        case 0xfea0 ... 0xfeff:
            return 0x00;
        case 0xff00 ... 0xff7f:
            return 0x00;
        case 0xff80 ... 0xfffe:
            return 0x00;
        case 0xffff:
            return 0x00;
    }
}

void Bus::Write(uint16_t address, uint8_t data) {
    switch(address) {
        case 0x0000 ... 0x7fff:
            emu->cartridge.Write(address, data);
            break;
        case 0x8000 ... 0x9fff:
            break;
        case 0xa000 ... 0xbfff:
            break;
        case 0xc000 ... 0xdfff:
            break;
        case 0xe000 ... 0xfdff:
            break;
        case 0xfe00 ... 0xfe9f:
            break;
        case 0xfea0 ... 0xfeff:
            break;
        case 0xff00 ... 0xff7f:
            break;
        case 0xff80 ... 0xfffe:
            break;
        case 0xffff:
            break;
    }
}

uint16_t Bus::Read16(uint16_t address) {
    return (Read(address) << 8) | Read(address + 1);
}

void Bus::Write16(uint16_t address, uint16_t data) {
    Write(address, data >> 8);
    Write(address + 1, data & 0xff);
}
