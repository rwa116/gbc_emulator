cmake_minimum_required(VERSION 3.22.1)
project(gbc)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.cpp)

add_compile_options(-g)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} emulator graphics cartridge cpu bus opcodes)

add_subdirectory(src)