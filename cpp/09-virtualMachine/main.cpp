#include "VirtualMachine.hpp"
void test_1()
{
    vm::VirtualMachine myMachine;
    std::vector<int32_t> code (5);
    code.at(0) = static_cast<int32_t>(vm::OpCode::Push);
    code.at(1) = 10;
    code.at(2) = static_cast<int32_t>(vm::OpCode::Push);
    code.at(3) = 20;
    code.at(4) = static_cast<int32_t>(vm::OpCode::Swap);
    code.push_back(static_cast<int32_t>(vm::OpCode::Mul));
    code.push_back(static_cast<int32_t>(vm::OpCode::Inc));
    code.push_back(static_cast<int32_t>(vm::OpCode::Inc));
    code.push_back(static_cast<int32_t>(vm::OpCode::Dec));
    code.push_back( static_cast<int32_t>(vm::OpCode::Print));
    code.push_back(static_cast<int32_t>(vm::OpCode::Halt));
    myMachine.run(code);
}
int main(){
    test_1();
    return 0;
}