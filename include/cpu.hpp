#ifndef CPU_H
#define CPU_H

#include <vector>
#include <cstdint>

#define R_SIZE 32
#define M_SIZE 1024

class cpu {
   private:
      uint32_t reg[R_SIZE];
      uint32_t memory[M_SIZE];
   public:
      cpu(): reg{}, memory{} {

      }
      void setRegister(std::uint32_t address, std::uint32_t value);
      void setMemory(std::uint32_t address, std::uint32_t value);
      std::uint32_t getRegister(std::uint32_t address);
      std::uint32_t getMemory(std::uint32_t address);

};

#endif