#ifndef EMULATOR_HPP
#define EMULATOR_HPP

#include "graphics.hpp"

class Emulator {
public:
    Emulator();
    ~Emulator();
    bool Init();
    void LoadRom(const char* path);
    void Run();
private:
    Graphics graphics;
};

#endif // EMULATOR_HPP