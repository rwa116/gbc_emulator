#ifndef EMULATOR_HPP
#define EMULATOR_HPP

#include "graphics.hpp"
#include "cartridge.hpp"

class Emulator {
public:
    Emulator();
    ~Emulator();
    bool Init();
    bool LoadRom(const char* path);
    void Run();
private:
    Graphics graphics;
    Cartridge cartridge;
};

#endif // EMULATOR_HPP