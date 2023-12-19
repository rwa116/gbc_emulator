#ifndef CARTRIDGE_HPP
#define CARTRIDGE_HPP

#include <cstdint>

typedef struct {
    uint8_t entry[0x4];
    uint8_t logo[0x30];
    char title[0x10];
    uint8_t manufacturer[0x4];
    uint8_t cgb_flag;
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
    CartridgeHeader header;
    uint8_t* rom;
    uint8_t* ram;
};


#endif // CARTRIDGE_HPP