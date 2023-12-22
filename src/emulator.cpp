#include "emulator.hpp"

Emulator::Emulator() {
    Graphics graphics;
    Cartridge cartridge;
}

Emulator::~Emulator() {
}

bool Emulator::Init() {
    if(graphics.Init() == false) {
        return false;
    }
    return true;
}

bool Emulator::LoadRom(const char* path) {
    if(cartridge.Load(path) == false) {
        return false;
    }
    return true;
}

void Emulator::Run() {
}