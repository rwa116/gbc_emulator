#ifndef BUS_HPP
#define BUS_HPP
#pragma once

#include <cstdint>

class Emulator;

class Bus {
public:
    Bus();
    ~Bus();
    void Init(Emulator *emulator);
    uint8_t Read(uint16_t address);
    void Write(uint16_t address, uint8_t data);
    uint16_t Read16(uint16_t address);
    void Write16(uint16_t address, uint16_t data);
private:
    Emulator *emu;
};

#endif // BUS_HPP