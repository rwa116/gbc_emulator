add_library(emulator emulator.cpp)
add_library(graphics graphics.cpp)
add_library(cartridge cartridge.cpp)
add_library(cpu cpu.cpp)
add_library(bus bus.cpp)
add_library(opcodes opcodes.cpp)

target_include_directories(emulator PUBLIC ../include)
target_include_directories(graphics PUBLIC ../include)
target_include_directories(cartridge PUBLIC ../include)
target_include_directories(cpu PUBLIC ../include)
target_include_directories(bus PUBLIC ../include)
target_include_directories(opcodes PUBLIC ../include)