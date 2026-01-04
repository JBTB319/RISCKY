#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>

#include "instructionDecoder.hpp"


int main() {
   std::vector<uint32_t> memory;

   std::ifstream instruction_file("tests/All.hex");

   if(!instruction_file) {
      throw std::invalid_argument("File does not exist!");
   }

   std::uint32_t tmp;
   std::string tmpString;
   

   while (instruction_file >> tmpString)
   {
      std::stringstream ss;
      ss << std::hex << tmpString.substr(2);
      ss >> tmp;
      memory.push_back(tmp);
   }

   instruction instruct; 

   for (int i = 0; i < memory.size(); i++) {
      //std::cout << std::hex << memory.at(i) << "\n";
      instruct = instructionDecoder::decode(memory.at(i));
      enums::printEnum(instruct.Name);
      enums::printEnum(instruct.Type);
      std::cout << "\n";
      std::cout << instruct.Imm << "\n--------\n";
   }

}