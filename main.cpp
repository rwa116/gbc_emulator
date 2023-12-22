#include <iostream>
#include "emulator.hpp"
#include "SDL.h"

int main(int argc, char** argv) {
    Emulator emulator;
    emulator.LoadRom(argv[1]);
    emulator.Run();
    SDL_Delay(2000);
    std::cout << "Hello, world!" << std::endl;
    return 0;
}