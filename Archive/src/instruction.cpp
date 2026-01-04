#include "instruction.hpp"
#include <iostream>
#include "global_enums.hpp"

instruction::instruction(uint32_t op, uint32_t A, uint32_t B, uint32_t D, Global::instructionName Name, Global::instructionType Type)
{
   opcode = op;
   registerA = A;
   registerB = B;
   dst = D;
   name = Name; 
   type = Type;
}

void instruction::printTypeI() {
   std::cout << "INSTRUCTION {\n";
   std::cout << "    NAME: ";
   Global::printEnum(name);
   std::cout << "\n";
   std::cout << "    TYPE: ";
   Global::printEnum(type);
   std::cout << "\n";
   std::cout << "    OPCODE: " << opcode << "\n";
   std::cout << "    DEST: " << dst << "\n";
   std::cout << "    REG_A: " << registerA << "\n";
   std::cout << "    IMM: " << val << "\n";
   std::cout << "}\n";
}

void::instruction::printTypeB () {
   std::cout << "INSTRUCTION {\n";
   std::cout << "    NAME: ";
   Global::printEnum(name);
   std::cout << "\n";
   std::cout << "    TYPE: ";
   Global::printEnum(type);
   std::cout << "\n";
   std::cout << "    OPCODE: " << opcode << "\n";
   std::cout << "    REG_A: " << registerA << "\n";
   std::cout << "    REG_B: " << registerB << "\n";
   std::cout << "    OFFSET: " << val << "\n";
   std::cout << "}\n";
}


void instruction::printTypeR() {
   std::cout << "INSTRUCTION {\n";
   std::cout << "    NAME: ";
   Global::printEnum(name);
   std::cout << "\n";
   std::cout << "    TYPE: ";
   Global::printEnum(type);
   std::cout << "\n";
   std::cout << "    OPCODE: " << opcode << "\n";
   std::cout << "    DEST: " << dst << "\n";
   std::cout << "    REG_A: " << registerA << "\n";
   std::cout << "    REG_B: " << registerB << "\n";
   std::cout << "}\n";
}

void instruction::printTypeS() {
   std::cout << "INSTRUCTION {\n";
   std::cout << "    NAME: ";
   Global::printEnum(name);
   std::cout << "\n";
   std::cout << "    TYPE: ";
   Global::printEnum(type);
   std::cout << "\n";
   std::cout << "    OPCODE: " << opcode << "\n";
   std::cout << "    DEST: " << dst << "\n";
   std::cout << "    REG_A: " << registerA << "\n";
   std::cout << "    REG_B: " << registerB << "\n";
   std::cout << "}\n";
}

void instruction::printTypeU() {
    std::cout << "INSTRUCTION {\n";
   std::cout << "    NAME: ";
   Global::printEnum(name);
   std::cout << "\n";
   std::cout << "    TYPE: ";
   Global::printEnum(type);
   std::cout << "\n";
   std::cout << "    OPCODE: " << opcode << "\n";
   std::cout << "    DEST: " << dst << "\n";
   std::cout << "    IMM: " << val << "\n";
   std::cout << "}\n";
}

void instruction::printTypeJ() {
   std::cout << "INSTRUCTION {\n";
   std::cout << "    NAME: ";
   Global::printEnum(name);
   std::cout << "\n";
   std::cout << "    TYPE: ";
   Global::printEnum(type);
   std::cout << "\n";
   std::cout << "    OPCODE: " << opcode << "\n";
   std::cout << "    DEST: " << dst << "\n";
   std::cout << "    IMM: " << val << "\n";
   std::cout << "}\n";
}

void instruction::print() {
   switch (type)
   {
      case Global::instructionType::I_TYPE:
      case Global::instructionType::I_TYPE_JALR:
      case Global::instructionType::I_TYPE_LOAD:
         printTypeI();
         break;
      case Global::instructionType::J_TYPE: 
         printTypeJ();
         break;
      case Global::instructionType::R_TYPE:
         printTypeR();
         break;
      case Global::instructionType::S_TYPE:
         printTypeS();
         break;
      case Global::instructionType::U_TYPE_AUIPC:
      case Global::instructionType::U_TYPE_LUI:
         printTypeU();
         break;
      default:
         break;
   }
}
