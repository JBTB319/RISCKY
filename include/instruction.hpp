#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <cstdint>
#include "enums.hpp"

struct instruction {
   enums::IType Type;
   enums::Instruction Name;
   std::uint8_t Opcode;
   std::uint8_t Fun3;
   std::uint8_t Fun7;
   std::uint8_t r1;
   std::uint8_t r2;
   std::uint8_t rd;
   std::uint32_t Imm;
};

#endif