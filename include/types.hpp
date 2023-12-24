#ifndef TYPES_HPP
#define TYPES_HPP

typedef enum {
    OT_IMP,
    OT_REG_REG,
    OT_REG,
    OT_REG_D8,
    OT_REG_D16,
    OT_REG_A8,
    OT_REG_A16,
    OT_A8_REG,
    OT_A16_REG,
} operand_type;

typedef enum {
    RT_NONE,
    RT_A,
    RT_F,
    RT_B,
    RT_C,
    RT_D,
    RT_E,
    RT_H,
    RT_L,
    RT_AF,
    RT_BC,
    RT_DE,
    RT_HL,
    RT_SP,
    RT_PC
} register_type;

typedef enum {
    IT_NONE,
    IT_NOP,
    IT_LD,
    IT_INC,
    IT_DEC,
    IT_RLCA,
    IT_ADD,
    IT_RRCA,
    IT_STOP,
    IT_RLA,
    IT_JR,
    IT_RRA,
    IT_DAA,
    IT_CPL,
    IT_SCF,
    IT_CCF,
    IT_HALT,
    IT_ADC,
    IT_SUB,
    IT_SBC,
    IT_AND,
    IT_XOR,
    IT_OR,
    IT_CP,
    IT_POP,
    IT_JP,
    IT_PUSH,
    IT_RET,
    IT_CB,
    IT_CALL,
    IT_RETI,
    IT_LDH,
    IT_JPHL,
    IT_DI,
    IT_EI,
    IT_RST,
    IT_ERR
} instruction_type;

typedef enum {
    FT_Z,
    FT_N,
    FT_H,
    FT_C
} flag_type;

typedef struct {
    operand_type ot;
    instruction_type it;
    register_type reg1;
    register_type reg2;
    uint8_t param;
} instruction;

#endif // TYPES_HPP