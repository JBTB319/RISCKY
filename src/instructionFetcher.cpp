#include "instructionFetcher.hpp"

instructionFetcher::instructionFetcher(const std::string& address) {
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
      memory.push_back(tmp);
   }

   pc = 0;
}

const bool instructionFetcher::fetch(uint32_t& instruct) {
   if (pc >= memory.size()) {
      return false;
   }

   instruct = memory.at(pc);

   pc++;

   return true;
}

const bool instructionFetcher::fetch(uint32_t& instruct, uint32_t offset) {
   if (pc >= memory.size()) {
      return 0;
   }

   instruct = memory.at(pc);

   pc++;

   return instruct;
}

