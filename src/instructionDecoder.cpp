#include "instructionDecoder.hpp"
#include "InstructionTable.hpp"
#include "immediateGenerator.hpp"
#include <iostream>
#include <bitset>

#define FUN3(bin) extractBinary(14,12,bin)
#define FUN7(bin) extractBinary(31,25,bin)
#define R1(bin) extractBinary(19,15,bin)
#define R2(bin) extractBinary(24,20,bin)
#define RD(bin) extractBinary(11, 7,bin)

namespace instructionDecoder {
   std::uint32_t extractBinary(int L, int R, std::uint32_t binary) {
      binary <<= (32 - (L+1));
      binary >>= ((32 - (L+1)) + R);
      return binary;
   }

   void extractIdentity(uint32_t binary, instruction& instruct) {
      instruct.Opcode = extractBinary(6,0, binary);

      switch (instruct.Opcode){
         case 0x13: 
         case 0x67:
            instruct.Type = (enums::IType::I_TYPE);
            instruct.Fun3 = FUN3(binary);
            instruct.Fun7 = (instruct.Fun3 == 5 || instruct.Fun3 == 1 ) ? FUN7(binary) : 0;
            break;
         case 0x03:
            instruct.Type = (enums::IType::I_TYPE);
            instruct.Fun3 = FUN3(binary);
            break;
         case 0x33: 
            instruct.Type = (enums::IType::R_TYPE); 
            instruct.Fun3 = FUN3(binary);
            instruct.Fun7 = FUN7(binary);
            break;
         case 0x63: 
            instruct.Type = (enums::IType::B_TYPE); 
            instruct.Fun3 = FUN3(binary);
            break;
         case 0x23: 
            instruct.Type = (enums::IType::S_TYPE);
            instruct.Fun3 = FUN3(binary);
            break;
         case 0x17:
         case 0x37:
            instruct.Type = (enums::IType::U_TYPE);
            break;
         case 0x6f: instruct.Type = (enums::IType::J_TYPE); break;
         default:
            instruct.Type = enums::IType::UNKNOWN;
      }

   }

   instruction decode(std::uint32_t binary) {
      instruction instruct = {};

      extractIdentity(binary, instruct);
      instructionKey key = {instruct.Opcode, instruct.Fun3, instruct.Fun7};

      instruct.Name = instructionTable::lookUpItem(key);
      instruct.r1 = R1(binary);
      instruct.r2 = R2(binary);
      instruct.rd = RD(binary);

      immediateGenerator::generate(instruct,binary);

      return instruct;
   }

}

#undef R1
#undef R2
#undef RD
