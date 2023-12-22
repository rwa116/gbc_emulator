#ifndef CARTRIDGE_HPP
#define CARTRIDGE_HPP

#include <cstdint>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>

typedef struct {
    uint8_t entry[0x4];
    uint8_t logo[0x30];
    char title[0x10];
    // uint16_t manufacturer;
    // uint8_t cgb_flag;
    uint16_t new_licensee_code;
    uint8_t sgb_flag;
    uint8_t cartridge_type;
    uint8_t rom_size;
    uint8_t ram_size;
    uint8_t destination_code;
    uint8_t old_licensee_code;
    uint8_t mask_rom_version_number;
    uint8_t header_checksum;
    uint16_t global_checksum;
} CartridgeHeader;

class Cartridge {
public:
    Cartridge();
    ~Cartridge();
    bool Load(const char* path);
    uint8_t Read(uint16_t address);
    void Write(uint16_t address, uint8_t value);
private:
    std::string file_path;
    CartridgeHeader header;
    uint8_t* rom;
    uint8_t* ram;
    std::string LicenseeCode();
    std::string CartridgeType();
};


#endif // CARTRIDGE_HPP