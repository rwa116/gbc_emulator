#include <iostream>
#include "emulator.hpp"
#include "SDL.h"

int main(int argc, char** argv) {
    Emulator emulator;
    // emu.load_rom(argv[1]);
    emulator.Run();
    SDL_Delay(2000);
    std::cout << "Hello, world!" << std::endl;
    return 0;
}