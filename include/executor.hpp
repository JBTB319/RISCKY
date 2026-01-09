#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "cpu.hpp"
#include "instruction.hpp"
#include "instructionFetcher.hpp"

class executor {
   private:
      void execute_branch_group(cpu& target, instruction& instruct);
      void execute_alu_r_group(cpu& target, instruction& instruct);
      void execute_alu_i_group(cpu& target, instruction& instruct);
      void execute_storage_group(cpu& target, instruction& instruct);
      void execute_jump_group(cpu& target, instruction& instruct, instructionFetcher& fetcher);
   public:
      void execute();
};

#endif