#ifndef IMMEDIATE_GENERATOR_HPP
#define IMMEDIATE_GENERATOR_HPP

#include "instruction.hpp"
#include <cstdint>

namespace immediateGenerator {
   void signExtend(uint32_t rawBinary);
   void generate(instruction& instruct, uint32_t rawBinary);
};

#endif