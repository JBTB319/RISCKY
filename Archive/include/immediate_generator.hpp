#ifndef IMMEDIATE_GENERATOR_H
#define IMMEDIATE_GENERATOR_H

#include "instruction.hpp"
#include <cstdint>

class immediate_generator {
   private:
      static std::uint32_t extractImm(std::uint32_t rawBinary, Global::instructionType type);
      static std::uint32_t signExtend(std::uint32_t rawBinary);
      static std::uint32_t zeroExtend(std::uint32_t rawBinary);
   public:
      static std::uint32_t generateImmediate(instruction& instruct);
};

#endif