#include "instruction_decoder.hpp"

#include <iostream>


void instruction_decoder::extractRegister(std::uint32_t rawBinary, instruction& instruct) {
   std::uint32_t regA = extractBinary(19,15, rawBinary);
   std::uint32_t regB = extractBinary(24,20, rawBinary);
   std::uint32_t dst = extractBinary(11,7, rawBinary);
   
   instruct.setRegisterA(regA);
   instruct.setRegisterB(regB);
   instruct.setDst(dst);
}

void instruction_decoder::extractFunction(std::uint32_t rawBinary,instruction& instruct) {
   std::uint32_t fun3 = extractBinary(14,12,rawBinary);
   std::uint32_t fun7 = extractBinary(31,27, rawBinary);

   instruct.setFun3(fun3);
   instruct.setFun7(fun7);
}

void instruction_decoder::extractOpcode(std::uint32_t rawBinary, instruction& instruct) {
   std::uint32_t opcode = extractBinary(6,0, rawBinary);
   instruct.setOpcode(opcode);
}

void instruction_decoder::extractType(instruction& instruct) {
   switch (instruct.getOpcode())
   {
      case 0x13: instruct.setType(Global::instructionType::I_TYPE); break;
      case 0x67: instruct.setType(Global::instructionType::I_TYPE_JALR); break;
      case 0x03: instruct.setType(Global::instructionType::I_TYPE_LOAD); break;
      case 0x33: instruct.setType(Global::instructionType::R_TYPE); break;
      case 0x63: instruct.setType(Global::instructionType::B_TYPE); break;
      case 0x17: instruct.setType(Global::instructionType::U_TYPE_AUIPC); break;
      case 0x37: instruct.setType(Global::instructionType::U_TYPE_LUI); break;
      case 0x6f: instruct.setType(Global::instructionType::J_TYPE); break;
      case 0x23: instruct.setType(Global::instructionType::S_TYPE); break;
      default: instruct.setType(Global::instructionType::NONE_TYPE); break;
   }
}

std::uint32_t instruction_decoder::extractBinary(int L, int R, std::uint32_t binary) {   
   binary <<= (32 - (L+1));
   binary >>= ((32 - (L+1)) + R);
   return binary;
}

void instruction_decoder::extractName(instruction& instruct) {
   Global::fun3 fun3 = static_cast<Global::fun3>(instruct.getFun3());
   Global::fun7 fun7 = static_cast<Global::fun7>(instruct.getFun7());
   Global::instructionType type = instruct.getType();

   switch (type)
   {
      case Global::instructionType::I_TYPE:
         switch (fun3)
         {
            case Global::fun3::ADDI_ADD_SUB_BEQ_LB_SB: instruct.setName(Global::instructionName::ADDI); break;
            case Global::fun3::SLLI_SLL_BNE_LH_SH: instruct.setName(Global::instructionName::SLLI); break;
            case Global::fun3::SLTI_SLT_LW_SW: instruct.setName(Global::instructionName::SLTI); break;
            case Global::fun3::SLTIU: instruct.setName(Global::instructionName::SLTIU); break;
            case Global::fun3::XORI_XOR_BLT_LBU: instruct.setName(Global::instructionName::XORI); break;
            case Global::fun3::SRLI_SRAI_SRA_SRL_BGE_LHU: 
               if (fun7 == Global::fun7::SRAI_SUB_SRA) {
                  instruct.setName(Global::instructionName::SRAI);
               }
               else {
                  instruct.setName(Global::instructionName::SRLI);
               }
               break;
            case Global::fun3::ORI_OR_BLTU: instruct.setName(Global::instructionName::ORI); break;
            case Global::fun3::ANDI_AND_BGEU: instruct.setName(Global::instructionName::ANDI); break;
            default: break;
         }
         break;
      case Global::instructionType::I_TYPE_LOAD:
         switch (fun3)
         {
            case Global::fun3::ADDI_ADD_SUB_BEQ_LB_SB: instruct.setName(Global::instructionName::LB); break;
            case Global::fun3::SLLI_SLL_BNE_LH_SH: instruct.setName(Global::instructionName::LH); break;
            case Global::fun3::SLTI_SLT_LW_SW: instruct.setName(Global::instructionName::LW); break;
            case Global::fun3::XORI_XOR_BLT_LBU: instruct.setName(Global::instructionName::LBU); break;
            case Global::fun3::SRLI_SRAI_SRA_SRL_BGE_LHU: instruct.setName(Global::instructionName::LHU); break;
            default: break;
         }
         break;
      case Global::instructionType::S_TYPE:
         switch (fun3)
         {
            case Global::fun3::ADDI_ADD_SUB_BEQ_LB_SB: instruct.setName(Global::instructionName::SB); break;
            case Global::fun3::SLLI_SLL_BNE_LH_SH: instruct.setName(Global::instructionName::SH); break;
            case Global::fun3::SLTI_SLT_LW_SW: instruct.setName(Global::instructionName::SW); break;
            default: break;
         }
         break;
      case Global::instructionType::B_TYPE:
         switch (fun3)
         {
            case Global::fun3::ADDI_ADD_SUB_BEQ_LB_SB: instruct.setName(Global::instructionName::BEQ); break;
            case Global::fun3::SLLI_SLL_BNE_LH_SH: instruct.setName(Global::instructionName::BNE); break;
            case Global::fun3::XORI_XOR_BLT_LBU: instruct.setName(Global::instructionName::BLT); break;
            case Global::fun3::SRLI_SRAI_SRA_SRL_BGE_LHU: instruct.setName(Global::instructionName::BGE); break;
            case Global::fun3::ORI_OR_BLTU: instruct.setName(Global::instructionName::BLTU); break;
            case Global::fun3::ANDI_AND_BGEU: instruct.setName(Global::instructionName::BGEU); break;
            default: break;
         }
         break;
      case Global::instructionType::R_TYPE:
         switch (fun3)
         {
            case Global::fun3::ADDI_ADD_SUB_BEQ_LB_SB:
               if(fun7 == Global::fun7::SRAI_SUB_SRA){
                  instruct.setName(Global::instructionName::SUB);
               }
               else {
                  instruct.setName(Global::instructionName::ADD);
               }
               break;
            case Global::fun3::SLLI_SLL_BNE_LH_SH: instruct.setName(Global::instructionName::SLL); break;
            case Global::fun3::SLTI_SLT_LW_SW: instruct.setName(Global::instructionName::SLT); break;
            case Global::fun3::XORI_XOR_BLT_LBU: instruct.setName(Global::instructionName::XOR); break;
            case Global::fun3::SRLI_SRAI_SRA_SRL_BGE_LHU: 
               if (fun7 == Global::fun7::SRAI_SUB_SRA) {
                  instruct.setName(Global::instructionName::SRA);
               }
               else {
                  instruct.setName(Global::instructionName::SRL);
               }
               break;
            case Global::fun3::ORI_OR_BLTU: instruct.setName(Global::instructionName::OR); break;
            case Global::fun3::ANDI_AND_BGEU: instruct.setName(Global::instructionName::AND); break;
            default: break;
         }
         break;
      case Global::instructionType::I_TYPE_JALR: instruct.setName(Global::instructionName(Global::instructionName::JALR)); break;
      case Global::instructionType::J_TYPE: instruct.setName(Global::instructionName(Global::instructionName::JAL)); break;
      case Global::instructionType::U_TYPE_AUIPC: instruct.setName(Global::instructionName(Global::instructionName::AUIPC));  break;
      case Global::instructionType::U_TYPE_LUI: instruct.setName(Global::instructionName(Global::instructionName::LUI)); break;
      default:
         break;
   }
   
   /*
   if(type == Global::instructionType::I_TYPE) {
      switch (fun3)
      {
         case Global::fun3::ADDI_ADD_SUB_BEQ_LB_SB: 
            instruct.setName(Global::instructionName::ADDI); 
            break;
         case Global::fun3::SLLI_SLL_BNE_LH_SH: instruct.setName(Global::instructionName::SLLI); break;
         case Global::fun3::SLTI_SLT_LW_SW: instruct.setName(Global::instructionName::SLTI); break;
         case Global::fun3::SLTIU: instruct.setName(Global::instructionName::SLTIU); break;
         case Global::fun3::XORI_XOR_BLT_LBU: instruct.setName(Global::instructionName::XORI); break;
         case Global::fun3::SRLI_SRAI_SRA_SRL_BGE_LHU: 
            if (fun7 == Global::fun7::SRAI_SUB_SRA) {
               instruct.setName(Global::instructionName::SRAI);
            }
            else {
               instruct.setName(Global::instructionName::SRLI);
            }
            break;
         case Global::fun3::ORI_OR_BLTU: instruct.setName(Global::instructionName::ORI); break;
         case Global::fun3::ANDI_AND_BGEU: instruct.setName(Global::instructionName::ANDI); break;
         default: break;
      }
   }

   if (type == Global::instructionType::R_TYPE) {
      switch (fun3)
      {
         case Global::fun3::ADDI_ADD_SUB_BEQ_LB_SB:
            if(fun7 == Global::fun7::SRAI_SUB_SRA){
               instruct.setName(Global::instructionName::SUB);
            }
            else {
               instruct.setName(Global::instructionName::ADD);
            }
            break;
         case Global::fun3::SLLI_SLL_BNE_LH_SH: instruct.setName(Global::instructionName::SLL); break;
         case Global::fun3::SLTI_SLT_LW_SW: instruct.setName(Global::instructionName::SLT); break;
         case Global::fun3::XORI_XOR_BLT_LBU: instruct.setName(Global::instructionName::XOR); break;
         case Global::fun3::SRLI_SRAI_SRA_SRL_BGE_LHU: 
            if (fun7 == Global::fun7::SRAI_SUB_SRA) {
               instruct.setName(Global::instructionName::SRA);
            }
            else {
               instruct.setName(Global::instructionName::SRL);
            }
            break;
         case Global::fun3::ORI_OR_BLTU: instruct.setName(Global::instructionName::OR); break;
         case Global::fun3::ANDI_AND_BGEU: instruct.setName(Global::instructionName::AND); break;
         default: break;
      }
   }

   if (type == Global::instructionType::B_TYPE) {
      switch (fun3)
      {
         case Global::fun3::ADDI_ADD_SUB_BEQ_LB_SB: instruct.setName(Global::instructionName::BEQ); break;
         case Global::fun3::SLLI_SLL_BNE_LH_SH: instruct.setName(Global::instructionName::BNE); break;
         case Global::fun3::XORI_XOR_BLT_LBU: instruct.setName(Global::instructionName::BLT); break;
         case Global::fun3::SRLI_SRAI_SRA_SRL_BGE_LHU: instruct.setName(Global::instructionName::BGE); break;
         case Global::fun3::ORI_OR_BLTU: instruct.setName(Global::instructionName::BLTU); break;
         case Global::fun3::ANDI_AND_BGEU: instruct.setName(Global::instructionName::BGEU); break;
         default: break;
      }
   }

   if (type == Global::instructionType::I_TYPE_LOAD) {
      switch (fun3)
      {
         case Global::fun3::ADDI_ADD_SUB_BEQ_LB_SB: instruct.setName(Global::instructionName::LB); break;
         case Global::fun3::SLLI_SLL_BNE_LH_SH: instruct.setName(Global::instructionName::LH); break;
         case Global::fun3::SLTI_SLT_LW_SW: instruct.setName(Global::instructionName::LW); break;
         case Global::fun3::XORI_XOR_BLT_LBU: instruct.setName(Global::instructionName::LBU); break;
         case Global::fun3::SRLI_SRAI_SRA_SRL_BGE_LHU: instruct.setName(Global::instructionName::LBU); break;
         default:break;
      }
   }

   switch (type)
   {
      case Global::instructionType::I_TYPE_JALR: instruct.setName(Global::instructionName(Global::instructionName::JALR)); break;
      case Global::instructionType::J_TYPE: instruct.setName(Global::instructionName(Global::instructionName::JAL)); break;
      case Global::instructionType::U_TYPE_AUIPC: instruct.setName(Global::instructionName(Global::instructionName::AUIPC));  break;
      case Global::instructionType::U_TYPE_LUI: instruct.setName(Global::instructionName(Global::instructionName::LUI)); break;
      default: break;
   }

   if (type == Global::instructionType::S_TYPE) {
      switch (fun3)
      {
         case Global::fun3::ADDI_ADD_SUB_BEQ_LB_SB: instruct.setName(Global::instructionName::SB); break;
         case Global::fun3::SLLI_SLL_BNE_LH_SH: instruct.setName(Global::instructionName::SH); break;
         case Global::fun3::SLTI_SLT_LW_SW: instruct.setName(Global::instructionName::SW); break;
         default: break;
      }
   }
   */
}

instruction instruction_decoder::decode(std::uint32_t rawBinary) {
   instruction decoded(0,0,0,0, Global::instructionName::NONE, Global::instructionType::NONE_TYPE);

   extractOpcode(rawBinary, decoded);
   extractRegister(rawBinary, decoded);
   extractFunction(rawBinary, decoded);
   extractType(decoded);
   extractName(decoded);


   return decoded;

}