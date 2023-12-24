#include "cartridge.hpp"
#include <unordered_map>


static std::unordered_map<int, std::string>  ROM_TYPES = {
    {0x00, "ROM ONLY"},
    {0x01, "MBC1"},
    {0x02, "MBC1+RAM"},
    {0x03, "MBC1+RAM+BATTERY"},
    {0x04, "0x04 ???"},
    {0x05, "MBC2"},
    {0x06, "MBC2+BATTERY"},
    {0x07, "0x07 ???"},
    {0x08, "ROM+RAM 1"},
    {0x09, "ROM+RAM+BATTERY 1"},
    {0x0A, "0x0A ???"},
    {0x0B, "MMM01"},
    {0x0C, "MMM01+RAM"},
    {0x0D, "MMM01+RAM+BATTERY"},
    {0x0E, "0x0E ???"},
    {0x0F, "MBC3+TIMER+BATTERY"},
    {0x10, "MBC3+TIMER+RAM+BATTERY 2"},
    {0x11, "MBC3"},
    {0x12, "MBC3+RAM 2"},
    {0x13, "MBC3+RAM+BATTERY 2"},
    {0x14, "0x14 ???"},
    {0x15, "0x15 ???"},
    {0x16, "0x16 ???"},
    {0x17, "0x17 ???"},
    {0x18, "0x18 ???"},
    {0x19, "MBC5"},
    {0x1A, "MBC5+RAM"},
    {0x1B, "MBC5+RAM+BATTERY"},
    {0x1C, "MBC5+RUMBLE"},
    {0x1D, "MBC5+RUMBLE+RAM"},
    {0x1E, "MBC5+RUMBLE+RAM+BATTERY"},
    {0x1F, "0x1F ???"},
    {0x20, "MBC6"},
    {0x21, "0x21 ???"},
    {0x22, "MBC7+SENSOR+RUMBLE+RAM+BATTERY"}
};

static std::unordered_map<int, std::string> NEW_LIC_CODE = {
    {0x00, "None"},
    {0x01, "Nintendo R&D1"},
    {0x08, "Capcom"},
    {0x13, "Electronic Arts"},
    {0x18, "Hudson Soft"},
    {0x19, "b-ai"},
    {0x20, "kss"},
    {0x22, "pow"},
    {0x24, "PCM Complete"},
    {0x25, "san-x"},
    {0x28, "Kemco Japan"},
    {0x29, "seta"},
    {0x30, "Viacom"},
    {0x31, "Nintendo"},
    {0x32, "Bandai"},
    {0x33, "Ocean/Acclaim"},
    {0x34, "Konami"},
    {0x35, "Hector"},
    {0x37, "Taito"},
    {0x38, "Hudson"},
    {0x39, "Banpresto"},
    {0x41, "Ubi Soft"},
    {0x42, "Atlus"},
    {0x44, "Malibu"},
    {0x46, "angel"},
    {0x47, "Bullet-Proof"},
    {0x49, "irem"},
    {0x50, "Absolute"},
    {0x51, "Acclaim"},
    {0x52, "Activision"},
    {0x53, "American sammy"},
    {0x54, "Konami"},
    {0x55, "Hi tech entertainment"},
    {0x56, "LJN"},
    {0x57, "Matchbox"},
    {0x58, "Mattel"},
    {0x59, "Milton Bradley"},
    {0x60, "Titus"},
    {0x61, "Virgin"},
    {0x64, "LucasArts"},
    {0x67, "Ocean"},
    {0x69, "Electronic Arts"},
    {0x70, "Infogrames"},
    {0x71, "Interplay"},
    {0x72, "Broderbund"},
    {0x73, "sculptured"},
    {0x75, "sci"},
    {0x78, "THQ"},
    {0x79, "Accolade"},
    {0x80, "misawa"},
    {0x83, "lozc"},
    {0x86, "Tokuma Shoten Intermedia"},
    {0x87, "Tsukuda Original"},
    {0x91, "Chunsoft"},
    {0x92, "Video system"},
    {0x93, "Ocean/Acclaim"},
    {0x95, "Varie"},
    {0x96, "Yonezawa/s’pal"},
    {0x97, "Kaneko"},
    {0x99, "Pack in soft"},
    {0xA4, "Konami (Yu-Gi-Oh!)"}
};

static std::unordered_map<int, std::string> OLD_LIC_CODE = {
    {0x00, "None"},
    {0x01, "Nintendo R&D1"},
    {0x08, "Capcom"},
    {0x13, "Electronic Arts"},
    {0x18, "Hudson Soft"},
    {0x19, "b-ai"},
    {0x20, "kss"},
    {0x22, "pow"},
    {0x24, "PCM Complete"},
    {0x25, "san-x"},
    {0x28, "Kemco Japan"},
    {0x29, "seta"},
    {0x30, "Viacom"},
    {0x31, "Nintendo"},
    {0x32, "Bandai"},
    {0x33, "Ocean/Acclaim"},
    {0x34, "Konami"},
    {0x35, "Hector"},
    {0x37, "Taito"},
    {0x38, "Hudson"},
    {0x39, "Banpresto"},
    {0x41, "Ubi Soft"},
    {0x42, "Atlus"},
    {0x44, "Malibu"},
    {0x46, "angel"},
    {0x47, "Bullet-Proof"},
    {0x49, "irem"},
    {0x50, "Absolute"},
    {0x51, "Acclaim"},
    {0x52, "Activision"},
    {0x53, "American sammy"},
    {0x54, "Konami"},
    {0x55, "Hi tech entertainment"},
    {0x56, "LJN"},
    {0x57, "Matchbox"},
    {0x58, "Mattel"},
    {0x59, "Milton Bradley"},
    {0x60, "Titus"},
    {0x61, "Virgin"},
    {0x64, "LucasArts"},
    {0x67, "Ocean"},
    {0x69, "Electronic Arts"},
    {0x70, "Infogrames"},
    {0x71, "Interplay"},
    {0x72, "Broderbund"},
    {0x73, "sculptured"},
    {0x75, "sci"},
    {0x78, "THQ"},
    {0x79, "Accolade"},
    {0x80, "misawa"},
    {0x83, "lozc"},
    {0x86, "Tokuma Shoten Intermedia"},
    {0x87, "Tsukuda Original"},
    {0x91, "Chunsoft"},
    {0x92, "Video system"},
    {0x93, "Ocean/Acclaim"},
    {0x95, "Varie"},
    {0x96, "Yonezawa/s’pal"},
    {0x97, "Kaneko"},
    {0x99, "Pack in soft"},
    {0xA4, "Konami (Yu-Gi-Oh!)"}
};

Cartridge::Cartridge() {
    rom = NULL;
    ram = NULL;
}

Cartridge::~Cartridge() {
    // delete[] rom;
    // delete[] ram;
}

bool Cartridge::Load(const char* path) {
    file_path = path;

    // Open file
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << path << std::endl;
        return false;
    }

    // Read rom size
    uint64_t fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // Allocate memory
    std::cout << "Allocating " << fileSize << " bytes for rom" << std::endl;
    rom = new uint8_t[fileSize];

    // Read rom into memory
    if (file.read(reinterpret_cast<char*>(rom), fileSize)) {
        std::cout << rom[0x13F] << rom[0x140] << rom[0x141] << rom[0x142] << std::endl;
        std::cout << "Read " << fileSize << " bytes from " << path << std::endl;
    } else {
        std::cerr << "Failed to read file: " << path << std::endl;
        return false;
    }
    file.close();

    // Read header
    std::memcpy(&header, rom + 0x100, sizeof(CartridgeHeader));
    header.title[0x10] = '\0'; // null terminate title

    std::cout << "Cartridge loaded:" << std::endl;
    std::cout << "Title: " << header.title << std::endl;
    std::cout << "Manufacturer Code: " << LicenseeCode() << std::endl;
    std::cout << "Cartridge Type: " << CartridgeType() << std::endl;
    std::cout << "ROM Size: " << (32 << header.rom_size) << " kB" << std::endl;
    std::cout << "RAM Size: " << (header.ram_size == 0 ? "None" : std::to_string(2048 << header.ram_size) + " bytes") << std::endl;

    uint16_t checksum = 0;
    for (int i = 0x134; i <= 0x14C; i++) {
        checksum = checksum - rom[i] - 1;
    }

    if ((checksum & 0xFF) == (header.header_checksum)) {
        std::cout << "Checksum: OK" << std::endl;
    } else {
        std::cerr << "Checksum: FAIL" << std::endl;
        return false;
    }

    return true;
}  

uint8_t Cartridge::Read(uint16_t address) {
    std::cout << "Size of rom: " << sizeof(rom) << std::endl;
    std::cout << "Reading from ROM: " << std::hex << address << std::endl;
    // for now ROM ONLY, TODO: MBC
    return rom[address];
}

void Cartridge::Write(uint16_t address, uint8_t value) {
    // for now ROM ONLY, TODO: MBC
    std::cout << "Writing to ROM: " << std::hex << address << " " << (int)value << std::endl;
    rom[address] = value;
}

std::string Cartridge::LicenseeCode() {
    if (header.old_licensee_code == 0x33) {
        return NEW_LIC_CODE[header.new_licensee_code];
    } else {
        return OLD_LIC_CODE[header.old_licensee_code];
    }
}

std::string Cartridge::CartridgeType() {
    return ROM_TYPES[header.cartridge_type];
}