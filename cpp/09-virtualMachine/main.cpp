#include "VirtualMachine.hpp"

int main(){
    vm::VirtualMachine myMachine;
    std::vector<vm::VMdata> code;
    code.at(0) = vm::VMdata::OpCode::Push ;
    code.at(1)=10;
    code.at(2)=5;
    code.at(3)=20;
    code.at(4)=0;
    code.at(5)=8;
    // myMachine.run(code);
    return 0;
}