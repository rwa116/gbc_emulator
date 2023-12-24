#ifndef CPU_HPP
#define CPU_HPP

#include <cstdint>
#include "types.hpp"
#include "bus.hpp"

class Emulator;

typedef struct {
    uint8_t a;
    uint8_t f;
    uint8_t b;
    uint8_t c;
    uint8_t d;
    uint8_t e;
    uint8_t h;
    uint8_t l;
    uint16_t sp;
    uint16_t pc;
} Registers;

class CPU {
public:
    CPU();
    ~CPU();
    void Init(Emulator* emulator);
    void Reset();
    void Step();
    void Interrupt(uint8_t interrupt);

    uint16_t ReadRegister(register_type reg);
    void WriteRegister(register_type reg, uint16_t value);
private:
    uint8_t Execute(uint8_t opcode);
    uint8_t GetFlag(flag_type flag);
    void SetFlag(flag_type flag, bool value);
    Emulator* emu;
    Registers registers;
    uint16_t fetched_data;
    uint8_t opcode;

    bool halted;

    bool interrupt_master_enable;
    uint8_t interrupt_enable;

    // NOP
    uint8_t NOP();

    // LD
    uint8_t LD_R_R(register_type reg1, register_type reg2);
    uint8_t LD_R_N(register_type reg, uint8_t value);
    uint8_t LD_R_HL(register_type reg);
    uint8_t LD_HL_R(register_type reg);
    uint8_t LD_HL_N(uint8_t value);
    uint8_t LD_A_BC();
    uint8_t LD_A_DE();
    uint8_t LD_A_NN(uint16_t address);
    uint8_t LD_BC_A();
    uint8_t LD_DE_A();
    uint8_t LD_NN_A(uint16_t address);
    uint8_t LD_A_FF00_N(uint8_t value);
    uint8_t LD_FF00_N_A(uint8_t value);
    uint8_t LD_A_FF00_C();
    uint8_t LD_FF00_C_A();

    // LDI / LDD
    uint8_t LDI_HL_A();
    uint8_t LDI_A_HL();
    uint8_t LDD_HL_A();
    uint8_t LDD_A_HL();

    // LD 16 bit
    uint8_t LD_RR_NN(register_type reg, uint16_t value);
    uint8_t LD_NN_SP(uint16_t address);
    uint8_t LD_SP_HL();
    uint8_t LD_PUSH_RR(register_type reg);
    uint8_t LD_POP_RR(register_type reg);


    uint8_t INC(register_type reg);
    uint8_t DEC(register_type reg);
};


#endif // CPU_HPP