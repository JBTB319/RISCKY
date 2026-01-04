#include "enums.hpp"

void enums::printEnum(Instruction inst)
{
   const char *name;
   switch (inst)
   {
      // NONE
      case Instruction::NONE: name = "NONE"; break;
      // IMMEDIATE TYPES (I-Type)
      case Instruction::ADDI:name = "ADDI";break;
      case Instruction::SLTI: name = "SLTI"; break;
      case Instruction::SLTIU: name = "SLTIU"; break;
      case Instruction::XORI: name = "XORI"; break;
      case Instruction::ORI: name = "ORI"; break;
      case Instruction::ANDI: name = "ANDI"; break;
      case Instruction::SLLI: name = "SLLI"; break;
      case Instruction::SRLI: name = "SRLI"; break;
      case Instruction::SRAI: name = "SRAI"; break;
      case Instruction::ADD: name = "ADD"; break;
      // REGISTER TYPE (R-Type)
      case Instruction::SUB: name = "SUB"; break;
      case Instruction::SLL: name = "SLL"; break;
      case Instruction::SLTU: name = "SLTU"; break;
      case Instruction::XOR: name = "XOR"; break;
      case Instruction::XRL: name = "XRL"; break;
      case Instruction::SRL: name = "SRL"; break;
      case Instruction::SRA: name = "SRA"; break;
      case Instruction::OR: name = "OR"; break;
      case Instruction::AND: name = "AND"; break;
      case Instruction::SLT: name = "SLT"; break;
      // LOAD (I-Type)
      case Instruction::LB: name = "LB"; break;
      case Instruction::LH: name = "LH"; break;
      case Instruction::LW: name = "LW"; break;
      case Instruction::LBU: name = "LBU"; break;
      case Instruction::LHU: name = "LHU"; break;
      // STORE (S-Type)
      case Instruction::SB: name = "SB"; break;
      case Instruction::SH: name = "SH"; break;
      case Instruction::SW: name = "SW"; break;
      // JUMP (J-Type and I-Type)
      case Instruction::JAL: name = "JAL"; break;
      case Instruction::JALR: name = "JALR"; break;
      // BRANCH (B-Type)
      case Instruction::BEQ: name = "BEQ"; break;
      case Instruction::BNE: name = "BNE"; break;
      case Instruction::BLT: name = "BLT"; break;
      case Instruction::BGE: name = "BGE"; break;
      case Instruction::BLTU: name = "BLTU"; break;
      case Instruction::BGEU: name = "BGEU"; break;
      // UPPER IMMEDIATE (U-Type)
      case Instruction::LUI: name = "LUI"; break;
      case Instruction::AUIPC: name = "AUIPC"; break;
         }
   std::cout << name << " ";
}

void enums::printEnum(IType type)
{
   const char *name;
   
   switch (type)
   {
      case IType::I_TYPE: name = "I_TYPE"; break;
      case IType::U_TYPE: name = "U_TYPE"; break;
      case IType::S_TYPE: name = "S_TYPE"; break;
      case IType::B_TYPE: name = "B_TYPE"; break;
      case IType::J_TYPE: name = "J_TYPE"; break;
      case IType::R_TYPE: name = "R_TYPE"; break;
      default:
         name = "ERROR";
         break;
   }
   
   std::cout << name << " ";
}