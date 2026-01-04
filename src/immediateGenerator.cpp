#include "immediateGenerator.hpp"
#include "instructionDecoder.hpp"

namespace immediateGenerator {
   void signExtend(instruction& instruct, uint32_t sign) {
      if (instructionDecoder::extractBinary(sign,sign,instruct.Imm) == 1) {
         instruct.Imm = (0xFFFFF000 | instruct.Imm);
      }
   }

   void generate(instruction& instruct, uint32_t rawBinary) {
      uint16_t part1 = 0; // offset [1..10]
      uint16_t part2 = 0; // offset [11]
      uint16_t part3 = 0; // offset [12..19]
      uint16_t part4 = 0; // offset [20]

      switch (instruct.Type){
         case enums::IType::I_TYPE:
            instruct.Imm = instructionDecoder::extractBinary(31,20,rawBinary);
            signExtend(instruct, 11);
            break;
         case enums::IType::S_TYPE:
            part1 = instructionDecoder::extractBinary(11,7, rawBinary); // offset [4..0]
            part2 = instructionDecoder::extractBinary(31,25, rawBinary); // offset [11..5]
            instruct.Imm = (part2 << 5 | part1);
            signExtend(instruct, 11);
            break;
         case enums::IType::J_TYPE:
            part1 = instructionDecoder::extractBinary(30,21,rawBinary); // offset [1..10]
            part2 = instructionDecoder::extractBinary(20,20,rawBinary); // offset [11]
            part3 = instructionDecoder::extractBinary(19,12,rawBinary); // offset [12..19]
            part4 = instructionDecoder::extractBinary(31,31,rawBinary); // offset [20]
            instruct.Imm = (part4 << 20) | (part3 << 12) | (part2 << 11) | (part1 << 1);
            signExtend(instruct, 20);
            break;
         case enums::IType::U_TYPE:
            instruct.Imm = instructionDecoder::extractBinary(31,12,rawBinary) << 12;
            break;
         case enums::IType::B_TYPE:
            part1 = instructionDecoder::extractBinary(11,8,rawBinary); // offset [1..4]
            part2 = instructionDecoder::extractBinary(30,25, rawBinary); // offset [5..10]
            part3 = instructionDecoder::extractBinary(7,7,rawBinary); // offset [11]
            part4 = instructionDecoder::extractBinary(31,31,rawBinary); // offset [12]
            instruct.Imm = (part4 << 12) | (part3 << 11) | (part2 << 5) | (part1 << 1);
            signExtend(instruct,12);
         default:
            instruct.Imm  = 0;
            break;
      }
   }
};