add_library(emulator emulator.cpp)
add_library(graphics graphics.cpp)
add_library(cartridge cartridge.cpp)

target_include_directories(emulator PUBLIC ../include)
target_include_directories(graphics PUBLIC ../include)
target_include_directories(cartridge PUBLIC ../include)