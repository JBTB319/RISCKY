#ifndef INSTRUCTION_FETCHER_HPP
#define INSTRUCTION_FETCHER_HPP


#include <cstdint>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>


class instructionFetcher {
   private:
      std::vector<std::uint32_t> memory;
      std::uint32_t pc;
   public:
      instructionFetcher(const std::string& address);
      const std::uint32_t fetch();
      const std::uint32_t fetch(uint32_t offset);
};
/*
namespace instructionFetcher {
   const std::vector<uint32_t>& loadFile(std::string address) {
      static std::vector<uint32_t> memory;

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

      return memory;
   }

   const std::uint32_t fetch(uint32_t pc) {
      return loadFile().at
   }
}
*/
#endif