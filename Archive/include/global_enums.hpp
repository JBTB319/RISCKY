#ifndef GLOBAL_ENUMS_H
#define GLOBAL_ENUMS_H

#include <iostream>
#include <cstdint>

namespace Global {
   enum class instructionName {
      NONE, // For testing
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

   enum class instructionType {
      NONE_TYPE,
      I_TYPE,
      I_TYPE_LOAD,
      I_TYPE_JALR,
      U_TYPE_LUI,
      U_TYPE_AUIPC,
      S_TYPE,
      B_TYPE,
      J_TYPE,
      R_TYPE
   };

   enum class fun3 : uint32_t{
      ADDI_ADD_SUB_BEQ_LB_SB = 0x0,
      SLLI_SLL_BNE_LH_SH = 0x1,
      SLTI_SLT_LW_SW = 0x2,
      SLTIU = 0x3,
      XORI_XOR_BLT_LBU = 0x4,
      SRLI_SRAI_SRA_SRL_BGE_LHU = 0x5,
      ORI_OR_BLTU = 0x6,
      ANDI_AND_BGEU = 0x7
   };

   enum class fun7 : uint32_t {
      SRAI_SUB_SRA = 0x20
   };

   void printEnum(instructionType type);
   void printEnum(instructionName name);
}


#endif