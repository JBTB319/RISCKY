#ifndef ENUMS_H
#define ENUMS_H

#include <iostream>
#include <cstdint>

namespace enums {
   enum class Instruction {
      UNKNOWN, // For testing
      // Immediate Types
      ADDI, SLTI, SLTIU, XORI, ORI, ANDI, SLLI, SRLI, SRAI,
      // Register Type
      ADD, SUB, SLL, SLTU, XOR, XRL, SRL, SRA, OR, AND, SLT,
      // Load
      LB,LH,LW,LBU,LHU,
      // STORE
      SB, SW,SH,
      // JUMP
      JAL, JALR,
      // BRANCH
      BEQ, BNE, BLT, BGE, BLTU, BGEU,
      // UPPER IMEDIATE
      LUI, AUIPC
   };

   enum class IType : uint8_t {
      I_TYPE,
      R_TYPE,
      B_TYPE,
      S_TYPE,
      J_TYPE,
      U_TYPE,
      UNKNOWN
   };

   void printEnum(IType type);
   void printEnum(Instruction name);
   const char* getName(Instruction name);
}


#endif