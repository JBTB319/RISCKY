#ifndef INSTRUCTION_TABLE_HPP
#define INSTRUCTION_TABLE_HPP

#include <unordered_map>
#include <cstdint>
#include <functional>
#include "enums.hpp"

using namespace enums;


struct instructionKey {
   std::uint8_t opCode;
   std::uint8_t fun3;
   std::uint8_t fun7;

   bool operator==(const instructionKey& other) const {
      return opCode == other.opCode && fun3 == other.fun3 && fun7 == other.fun7;
   }
};

struct instructionKeyHash {
   std::size_t operator()(const instructionKey& key) const {
      std::size_t h1 = std::hash<std::uint8_t>{}(key.opCode);
      std::size_t h2 = std::hash<std::uint8_t>{}(key.fun3);
      std::size_t h3 = std::hash<std::uint8_t>{}(key.fun7);

      return  h1 ^ (h2 << 1) ^ h3 << 2;
   }
};


namespace instructionTable {
   const std::unordered_map<instructionKey, Instruction, instructionKeyHash>& getTable() {
      static const std::unordered_map<instructionKey, Instruction, instructionKeyHash> table = {
         {{0x13, 0x0, 0x0}, Instruction::ADDI},
         {{0x13, 0x1, 0x0}, Instruction::SLLI},
         {{0x13, 0x2, 0x0}, Instruction::SLTI},
         {{0x13, 0x3, 0x0}, Instruction::SLTIU},
         {{0x13, 0x4, 0x0}, Instruction::XORI},
         {{0x13, 0x5, 0x0}, Instruction::SRLI},
         {{0x13, 0x5, 0x20}, Instruction::SRAI},
         {{0x13, 0x6, 0x0}, Instruction::ORI},
         {{0x13, 0x7, 0x0}, Instruction::ANDI},
         
         {{0x33, 0x0, 0x0}, Instruction::ADD},
         {{0x33, 0x0, 0x20}, Instruction::SUB},
         {{0x33, 0x1, 0x0}, Instruction::SLL},
         {{0x33, 0x2, 0x0}, Instruction::SLT},
         {{0x33, 0x3, 0x0}, Instruction::SLTU},
         {{0x33, 0x4, 0x0}, Instruction::XOR},
         {{0x33, 0x5, 0x0}, Instruction::SRL},
         {{0x33, 0x5, 0x20}, Instruction::SRA},
         {{0x33, 0x6, 0x0}, Instruction::OR},
         {{0x33, 0x7, 0x0}, Instruction::AND},

         {{0x63, 0x0, 0x0}, Instruction::BEQ},
         {{0x63, 0x1, 0x0}, Instruction::BNE},
         {{0x63, 0x4, 0x0}, Instruction::BLT},
         {{0x63, 0x5, 0x0}, Instruction::BGE},
         {{0x63, 0x6, 0x0}, Instruction::BLTU},
         {{0x63, 0x7, 0x0}, Instruction::BGEU},


         {{0x03, 0x0, 0x0}, Instruction::LB},
         {{0x03, 0x1, 0x0}, Instruction::LH},
         {{0x03, 0x2, 0x0}, Instruction::LW},
         {{0x03, 0x4, 0x0}, Instruction::LBU},
         {{0x03, 0x5, 0x0}, Instruction::LHU},
         {{0x23, 0x0, 0x0}, Instruction::SB},
         {{0x23, 0x1, 0x0}, Instruction::SH},
         {{0x23, 0x2, 0x0}, Instruction::SW},

         {{0x6f, 0x0, 0x0}, Instruction::JAL},
         {{0x67, 0x0, 0x0}, Instruction::JALR},
         {{0x17, 0x0, 0x0}, Instruction::AUIPC},
         {{0x37, 0x0, 0x0}, Instruction::LUI}        
      };

      return table;
   }

   const Instruction lookUpItem(instructionKey key) {
      auto table = getTable();

      return table.at(key);
   }
}

#endif