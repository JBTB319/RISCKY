#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "instruction_memory.hpp"
#include "instruction_decoder.hpp"
#include "instruction.hpp"

int main() {
   instruction_memory mem("instructions.hex");

   for (int i = 0 ; i < mem.getLength();i++ ) {
      instruction_decoder::decode(mem.fetch(i)).print();
   }

}