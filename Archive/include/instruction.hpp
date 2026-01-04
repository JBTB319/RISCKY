#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <cstdint>
#include "global_enums.hpp"

class instruction {
   private:
      uint32_t opcode;
      uint32_t registerA;
      uint32_t registerB;
      uint32_t dst;
      uint32_t fun3;
      uint32_t fun7;
      uint32_t val;
      Global::instructionName name;
      Global::instructionType type;
      void printTypeI();
      void printTypeR();
      void printTypeJ();
      void printTypeS();
      void printTypeU();
      void printTypeB();
   public:
      instruction(uint32_t op, uint32_t A, uint32_t B, uint32_t D, Global::instructionName Name, Global::instructionType Type);
      uint32_t getOpcode() {return opcode;}
      uint32_t getRegisterA () {return registerA;}
      uint32_t getRegisterB () {return registerB;}
      uint32_t getDst () {return dst;}
      uint32_t getFun3 () {return fun3;}
      uint32_t getFun7 () {return fun7;}
      Global::instructionName getName () {return name;}
      Global::instructionType getType () {return type;}
      void setOpcode (uint32_t Opcode) { opcode = Opcode;}
      void setRegisterA (uint32_t A) { registerA = A;}
      void setRegisterB (uint32_t B) { registerB = B;}
      void setDst (uint32_t Dst) {dst = Dst;}
      void setFun3 (uint32_t Fun3) {fun3 = Fun3;}
      void setFun7 (uint32_t Fun7) {fun7 = Fun7;}
      void setName (Global::instructionName Name) {name = Name;}
      void setType (Global::instructionType Type) {type = Type;}
      void print();

      
};

#endif