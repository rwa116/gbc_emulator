#include "emulator.hpp"

Emulator::Emulator() {
    Graphics graphics;
    Cartridge cartridge;
    CPU cpu;
    Bus bus;
}

Emulator::~Emulator() {
}

bool Emulator::Init() {
    if(graphics.Init() == false) {
        return false;
    }

    bus.Init(this);
    cpu.Init(this);
    cpu.Reset();
    
    return true;
}

bool Emulator::LoadRom(const char* path) {
    if(cartridge.Load(path) == false) {
        return false;
    }
    return true;
}

void Emulator::Run() {
    while(true) {
        SDL_Delay(200);
        Tick();
    }
}

void Emulator::Tick() {
    cpu.Step();
}