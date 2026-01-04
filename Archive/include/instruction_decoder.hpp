#ifndef INSTRUCTION_DECODER_H
#define INSTRUCTION_DECODER_H

#include "instruction.hpp"
#include <cstdint>

class instruction_decoder {
   private:
      static std::uint32_t extractBinary(int R, int L, std::uint32_t binary);
      static void extractRegister(std::uint32_t rawBinary, instruction& instruct);
      static void extractFunction(std::uint32_t rawBinary, instruction& instruct);
      static void extractOpcode(std::uint32_t rawBinary, instruction& instruct);
      static void extractType(instruction& instruct);
      static void extractName(instruction& instruct);
   public:
      static instruction decode(std::uint32_t rawBinary);
};

#endif