#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>

#include "instructionDecoder.hpp"
#include "instructionFetcher.hpp"


int main(int argc, char* argv[]) {
   if (argc != 2) {
      std::cout << "Only pass one file\n";
      exit(0);
   }

   instructionFetcher fetcher(argv[1]);
   uint32_t fetched;
   instruction instruct;

   while( fetcher.fetch(fetched)) {
      instruct = instructionDecoder::decode(fetched);
      enums::printEnum(instruct.Name);
      enums::printEnum(instruct.Type);
      std::cout << "\n";
      std::cout << instruct.Imm << "\n--------\n";
   }

}