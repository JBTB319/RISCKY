#include "global_enums.hpp"

void  Global::printEnum(instructionName inst)
{
   const char *name;
   switch (inst)
   {
      // NONE
      case instructionName::NONE: name = "NONE"; break;
      // IMMEDIATE TYPES (I-Type)
      case instructionName::ADDI:name = "ADDI";break;
      case instructionName::SLTI: name = "SLTI"; break;
      case instructionName::SLTIU: name = "SLTIU"; break;
      case instructionName::XORI: name = "XORI"; break;
      case instructionName::ORI: name = "ORI"; break;
      case instructionName::ANDI: name = "ANDI"; break;
      case instructionName::SLLI: name = "SLLI"; break;
      case instructionName::SRLI: name = "SRLI"; break;
      case instructionName::SRAI: name = "SRAI"; break;
      case instructionName::ADD: name = "ADD"; break;
      // REGISTER TYPE (R-Type)
      case instructionName::SUB: name = "SUB"; break;
      case instructionName::SLL: name = "SLL"; break;
      case instructionName::SLTU: name = "SLTU"; break;
      case instructionName::XOR: name = "XOR"; break;
      case instructionName::XRL: name = "XRL"; break;
      case instructionName::SRL: name = "SRL"; break;
      case instructionName::SRA: name = "SRA"; break;
      case instructionName::OR: name = "OR"; break;
      case instructionName::AND: name = "AND"; break;
      case instructionName::SLT: name = "SLT"; break;
      // LOAD (I-Type)
      case instructionName::LB: name = "LB"; break;
      case instructionName::LH: name = "LH"; break;
      case instructionName::LW: name = "LW"; break;
      case instructionName::LBU: name = "LBU"; break;
      case instructionName::LHU: name = "LHU"; break;
      // STORE (S-Type)
      case instructionName::SB: name = "SB"; break;
      case instructionName::SH: name = "SH"; break;
      case instructionName::SW: name = "SW"; break;
      // JUMP (J-Type and I-Type)
      case instructionName::JAL: name = "JAL"; break;
      case instructionName::JALR: name = "JALR"; break;
      // BRANCH (B-Type)
      case instructionName::BEQ: name = "BEQ"; break;
      case instructionName::BNE: name = "BNE"; break;
      case instructionName::BLT: name = "BLT"; break;
      case instructionName::BGE: name = "BGE"; break;
      case instructionName::BLTU: name = "BLTU"; break;
      case instructionName::BGEU: name = "BGEU"; break;
      // UPPER IMMEDIATE (U-Type)
      case instructionName::LUI: name = "LUI"; break;
      case instructionName::AUIPC: name = "AUIPC"; break;
         }
   std::cout << name << " ";
}

void Global::printEnum(instructionType type)
{
   const char *name;
   
   switch (type)
   {
      case instructionType::NONE_TYPE: name = "NONE_TYPE"; break;
      case instructionType::I_TYPE: name = "I_TYPE"; break;
      case instructionType::I_TYPE_JALR: name = "I_TYPE_JALR"; break;
      case instructionType::I_TYPE_LOAD: name = "I_TYPE_LOAD"; break;
      case instructionType::U_TYPE_AUIPC: name = "U_TYPE_AUIPC"; break;
      case instructionType::U_TYPE_LUI: name = "U_TYPE_LUI"; break;
      case instructionType::S_TYPE: name = "S_TYPE"; break;
      case instructionType::B_TYPE: name = "B_TYPE"; break;
      case instructionType::J_TYPE: name = "J_TYPE"; break;
      case instructionType::R_TYPE: name = "R_TYPE"; break;
   }
   
   std::cout << name << " ";
}