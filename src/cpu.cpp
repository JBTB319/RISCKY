#include "cpu.hpp"

uint32_t cpu::getMemory(uint32_t address){
   return memory[address];
}

uint32_t cpu::getRegister(uint32_t address){
   return reg[address];
}


void cpu::setRegister(uint32_t address, uint32_t value) {
   reg[address] = value;
}


void cpu::setMemory(uint32_t address, uint32_t value) {
   memory[address] = value;
}