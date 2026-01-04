#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <cstdint>
#include "enums.hpp"

struct instruction {
   enums::IType Type;
   enums::Instruction Name;
   std::uint8_t RegA;
   std::uint8_t RegB;
   std::uint8_t RegC;
   std::uint32_t Imm;
};

#endif