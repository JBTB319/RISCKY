#include "instruction_memory.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <exception>
#include <cstdint>

instruction_memory::instruction_memory(std::string address) {
   std::ifstream instruction_file(address);

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
      std::uint32_t tmpBs(tmp);
      memory.push_back(tmpBs);
   }
   

}

std::uint32_t instruction_memory::fetch(std::uint32_t address) {
   return memory.at(address);
}