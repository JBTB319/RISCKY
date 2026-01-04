#ifndef INSTRUCTION_DECODER
#define INSTRUCTION_DECODER

#include <cstdint>
#include "instruction.hpp"

namespace instructionDecoder {
   std::uint32_t extractBinary(int R, int L, std::uint32_t binary);
   void extractType(std::uint32_t binary, instruction& instruct);
   uint8_t extractFun3(enums::IType type, uint32_t binary);
   uint8_t extractFun7(enums::IType type, uint32_t binary, uint8_t fun3, uint8_t opCode);
   instruction decode(std::uint32_t binary);

}

#endif