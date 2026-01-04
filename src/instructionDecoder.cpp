#include "instructionDecoder.hpp"
#include "InstructionTable.hpp"
#include "immediateGenerator.hpp"
#include <iostream>
#include <bitset>

namespace instructionDecoder {
   std::uint32_t extractBinary(int L, int R, std::uint32_t binary) {
      binary <<= (32 - (L+1));
      binary >>= ((32 - (L+1)) + R);
      return binary;
   }

   void extractType(uint32_t opCode, instruction& instruct){
      switch (opCode){
         case 0x13: 
         case 0x03:
         case 0x67:
            instruct.Type = (enums::IType::I_TYPE); 
            break;
         case 0x17:
         case 0x37:
            instruct.Type = (enums::IType::U_TYPE);
            break;
         case 0x33: instruct.Type = (enums::IType::R_TYPE); break;
         case 0x63: instruct.Type = (enums::IType::B_TYPE); break;
         case 0x6f: instruct.Type = (enums::IType::J_TYPE); break;
         case 0x23: instruct.Type = (enums::IType::S_TYPE); break;
      }
   }

   uint8_t extractFun3(enums::IType type, uint32_t binary) {
      switch (type){
         case enums::IType::I_TYPE:
         case enums::IType::R_TYPE:
         case enums::IType::B_TYPE:
         case enums::IType::S_TYPE:
            return extractBinary(14,12,binary);
            break;
         default:
            return 0;
            break;
      }
   }

   uint8_t extractFun7(enums::IType type, uint32_t binary, uint8_t fun3, uint8_t opCode) {
      if (type == enums::IType::R_TYPE || (type == enums::IType::I_TYPE &&  (fun3 == 1 || fun3 == 5)) ) {
         if(opCode == 0x03)
            return 0;
         return extractBinary(31,25, binary);
      }

      return 0;
   }

   instruction decode(std::uint32_t binary) {
      instruction instruct;

      std::uint8_t regA = extractBinary(19,15, binary);
      std::uint8_t regB = extractBinary(24,20, binary);
      std::uint8_t regC = extractBinary(11,7, binary);
      std::uint8_t opCode = extractBinary(6,0, binary);
      std::uint8_t fun3 = 0x0;
      std::uint8_t fun7 = 0x0;

      extractType(opCode, instruct);

      fun3 = extractFun3(instruct.Type,binary);
      fun7 = extractFun7(instruct.Type,binary, fun3,opCode);

      instructionKey key;

      key.opCode = opCode;
      key.fun3 = fun3;
      key.fun7 = fun7;
      
      //std::cout << (uint16_t)opCode << "\n" << (uint16_t)fun3 << "\n" << (uint16_t)fun7 << "\n";

      enums::Instruction name = instructionTable::lookUpItem(key);

      instruct.RegA = regA;
      instruct.RegB = regB;
      instruct.RegC = regC;
      instruct.Name = name;

      immediateGenerator::generate(instruct,binary);

      return instruct;
   }

}