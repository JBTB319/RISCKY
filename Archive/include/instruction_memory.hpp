#ifndef INSTRUCTION_MEMORY_H
#define INSTRUCTION_MEMORY_H

#include <vector>
#include <string>
#include <cstdint>

class instruction_memory {
   private:
      std::vector<std::uint32_t> memory;
   public:
      instruction_memory(std::string address);
      std::uint32_t fetch(std::uint32_t address);
      std::uint32_t getLength() { return memory.size();}
};

#endif