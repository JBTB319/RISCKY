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

const std::uint32_t instructionFetcher::fetch() {
   if (pc == memory.size()) {
      exit(0);
   }

   std::uint32_t instruct = memory.at(pc);

   pc++;

   return instruct;
}

const std::uint32_t instructionFetcher::fetch(uint32_t offset) {
   if (pc == memory.size()) {
      exit(0);
   }

   std::uint32_t instruct = memory.at(pc);

   pc++;

   return instruct;
}

