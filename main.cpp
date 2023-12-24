#include <iostream>
#include "emulator.hpp"
#include "SDL.h"

int main(int argc, char** argv) {
    Emulator emulator;
    if(emulator.Init() == false) {
        std::cout << "Failed to initialize emulator." << std::endl;
        return 1;
    }
    if(argc < 2) {
        std::cout << "No ROM file specified." << std::endl;
        return 1;
    }
    emulator.LoadRom(argv[1]);
    emulator.Run();
    SDL_Delay(2000);
    std::cout << "Hello, world!" << std::endl;
    return 0;
}