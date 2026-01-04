#ifndef CPU_H
#define CPU_H

#include <vector>
#include <cstdint>

class cpu {
   private:
      std::vector<std::uint32_t> registers;
      std::vector<std::uint32_t> memory;
   public:
      cpu();
      void setRegister(std::uint32_t address, std::uint32_t);
      void setMemory(std::uint32_t address, std::uint32_t value);
      std::uint32_t getRegister(std::uint32_t address);
      std::uint32_t getMemory(std::uint32_t address);

};

#endif