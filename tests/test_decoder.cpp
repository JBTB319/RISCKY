#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"
#include <string>
#include "instructionDecoder.hpp"

using names = enums::Instruction;
using types = enums::IType;

struct decodeTest {
   uint32_t rawBinary;
   names name;
   types expectedType;
   uint8_t r1;
   uint8_t r2;
   uint8_t rd;
   uint32_t imm;
};

void compare(decodeTest& actual, instruction& decoded) {

   std::string name = enums::getName(actual.name);
   
   CHECK_MESSAGE(actual.expectedType == decoded.Type, "Type Mismatch: " << name);
   CHECK_MESSAGE(actual.name == decoded.Name, "Name Mismatch:" << name);

   switch (actual.expectedType)
   {
      case types::R_TYPE:
         CHECK_MESSAGE(actual.r1 == decoded.r1, "Register 1 Mismatch:" << name);
         CHECK_MESSAGE(actual.r2 == decoded.r2, "Register 2 Mismatch:" << name);
         CHECK_MESSAGE(actual.rd == decoded.rd, "Register d Mismatch:" << name);
         break;
      case types::I_TYPE:
         CHECK_MESSAGE(actual.r1 == decoded.r1, "Register 1 Mismatch:" << name);
         CHECK_MESSAGE(actual.rd == decoded.rd, "Register d Mismatch:" << name);
         CHECK_MESSAGE(actual.imm == decoded.Imm, "Immediate Mismatch:" << name);
         break;
      case types::S_TYPE:
      case types::B_TYPE:
         CHECK_MESSAGE(actual.r1 == decoded.r1, "Register 1 Mismatch:" << name);
         CHECK_MESSAGE(actual.r2 == decoded.r2, "Register 2 Mismatch:" << name);
         CHECK_MESSAGE(actual.imm == decoded.Imm, "Immediate Mismatch:" << name);
         break;
      case types::U_TYPE:
      case types::J_TYPE:
         CHECK_MESSAGE(actual.rd == decoded.rd, "Register 1 Mismatch:" << name);
         CHECK_MESSAGE(actual.imm == decoded.Imm, "Immediate Mismatch:" << name);
         break;
      case types::UNKNOWN:
         FAIL("ERROR, TYPE UNKNOWN");
         break;
   }
}


TEST_CASE("Testing Decoder") {
   decodeTest table[] = {
      {0x06400093, names::ADDI, types::I_TYPE, 0, 0, 1, 100},
      {0x000000B3, names::ADD, types::R_TYPE, 0, 0, 1, 0},
      {0x00064137, names::LUI, types::U_TYPE, 0, 0, 2, (100 << 12)}
   };

   for (auto& i : table) {
      CAPTURE(i);
      instruction iDecoded = instructionDecoder::decode(i.rawBinary);
      compare(i, iDecoded);
   } 
}
