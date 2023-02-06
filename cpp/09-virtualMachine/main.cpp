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
    code.push_back(static_cast<int32_t>(vm::OpCode::Push));
    code.push_back(0);
    code.push_back( static_cast<int32_t>(vm::OpCode::Jnz));
    code.push_back(0);
    code.push_back(static_cast<int32_t>(vm::OpCode::Halt));
    myMachine.run(code);
    std::cout<<'\n';
}

void test_print_ABC(){
    vm::VirtualMachine myMachine;
    std::vector<int32_t> code;
    code.push_back(static_cast<int32_t>(vm::OpCode::Push));
    code.push_back(64);
    code.push_back(static_cast<int32_t>(vm::OpCode::Inc));
    code.push_back(static_cast<int32_t>(vm::OpCode::Dup));
    code.push_back(static_cast<int32_t>(vm::OpCode::PrintC));
    code.push_back(static_cast<int32_t>(vm::OpCode::Dup));
    code.push_back(static_cast<int32_t>(vm::OpCode::Push));
    code.push_back(70);
    code.push_back(static_cast<int32_t>(vm::OpCode::Sub));
    code.push_back(static_cast<int32_t>(vm::OpCode::Jnz));
    code.push_back(2);
    code.push_back(static_cast<int32_t>(vm::OpCode::Halt));
    myMachine.run(code);
    std::cout<<'\n';
}
int main(){
    test_1();
    test_print_ABC();
    return 0;
}