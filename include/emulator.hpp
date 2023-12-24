#ifndef EMULATOR_HPP
#define EMULATOR_HPP
#pragma once

#include "graphics.hpp"
#include "cartridge.hpp"
#include "cpu.hpp"
#include "bus.hpp"

class Emulator {
public:
    Emulator();
    ~Emulator();
    bool Init();
    bool LoadRom(const char* path);
    void Run();
    void Tick();
private:
    Graphics graphics;
    Cartridge cartridge;
    CPU cpu;
    friend class CPU;
    Bus bus;
    friend class Bus;
};

#endif // EMULATOR_HPP