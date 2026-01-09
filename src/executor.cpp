#include "executor.hpp"

using name = enums::Instruction;

void executor::execute_alu_i_group(cpu& target, instruction& instruct) {
   uint8_t& rd = instruct.rd;
   uint32_t r1 =  target.getRegister(instruct.r1);
   uint32_t& imm = instruct.Imm;

   switch (instruct.Name) {
      case name::ADDI: 
         target.setRegister(rd, r1 + imm);
         break;
      case name::SLTI: 
         target.setRegister(rd, r1 < (int32_t)imm);
         break;
      case name::SLTIU:
         target.setRegister(rd, r1 < imm);
      case name::XORI: 
         target.setRegister(rd, r1 ^ imm);
         break;
      case name::ORI: 
         target.setRegister(rd, r1 | imm);
         break;
      case name::ANDI: 
         target.setRegister(rd, r1 & imm);
         break;
      case name::SLLI: 
         target.setRegister(rd, r1 << imm);
         break;
      case name::SRLI:
         target.setRegister(rd, r1 >> imm);
         break;
      case name::SRAI: 
         target.setRegister(rd, r1 >> (int32_t) imm);
         break;
      default:
         break;
   }
}

void executor::execute(){

}