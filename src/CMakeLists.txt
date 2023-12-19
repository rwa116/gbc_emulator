add_library(emulator emulator.cpp)
add_library(graphics graphics.cpp)

target_include_directories(emulator PUBLIC ../include)
target_include_directories(graphics PUBLIC ../include)