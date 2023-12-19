#include "emulator.hpp"

Emulator::Emulator() {
    Graphics graphics;
}

Emulator::~Emulator() {
}

bool Emulator::Init() {
    if(graphics.Init() == false) {
        return false;
    }
}

void Emulator::LoadRom(const char* path) {
}

void Emulator::Run() {
}