#include "VirtualMachine.hpp"


void test_1(vm::VirtualMachine& myMachine)
{
    std::vector<int32_t> code;
    code.push_back(static_cast<int32_t>(vm::OpCode::Push));
    code.push_back(10);
    code.push_back(static_cast<int32_t>(vm::OpCode::Push));
    code.push_back(20);
    code.push_back(static_cast<int32_t>(vm::OpCode::Swap));
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
    vm::Report report = myMachine.run(code);
    std::cout<<report<<'\n';
}

void test_print_ABC(vm::VirtualMachine& myMachine){
    std::vector<int32_t> code;
    code.push_back(static_cast<int32_t>(vm::OpCode::Nop));
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
    code.push_back(3);
    code.push_back(static_cast<int32_t>(vm::OpCode::Halt));
    vm::Report report = myMachine.run(code);
    std::cout<<report<<'\n';
}

void test_print_AB_Phase3(vm::VirtualMachine& myMachine){
    std::vector<int32_t> code;
    code.push_back(static_cast<int32_t>(vm::OpCode::Push));
    code.push_back(64);
    code.push_back(static_cast<int32_t>(vm::OpCode::Call));
    code.push_back(12);
    code.push_back(static_cast<int32_t>(vm::OpCode::Nop));
    code.push_back(static_cast<int32_t>(vm::OpCode::Call));
    code.push_back(12);
    code.push_back(static_cast<int32_t>(vm::OpCode::Nop));
    code.push_back(static_cast<int32_t>(vm::OpCode::Call));
    code.push_back(12);
    code.push_back(static_cast<int32_t>(vm::OpCode::Nop));
    code.push_back(static_cast<int32_t>(vm::OpCode::Halt));
    code.push_back(static_cast<int32_t>(vm::OpCode::Nop));
    code.push_back(static_cast<int32_t>(vm::OpCode::Inc));
    code.push_back(static_cast<int32_t>(vm::OpCode::Dup));
    code.push_back(static_cast<int32_t>(vm::OpCode::PrintC));
    code.push_back(static_cast<int32_t>(vm::OpCode::Ret));
    vm::Report report = myMachine.run(code);
    std::cout<<report<<'\n';
}

void test_error_program(vm::VirtualMachine& myMachine){
    std::vector<int32_t> code;
    code.push_back(static_cast<int32_t>(vm::OpCode::Push));
    code.push_back(64);
    code.push_back(static_cast<int32_t>(vm::OpCode::Pop));
    code.push_back(static_cast<int32_t>(vm::OpCode::Pop));

    vm::Report report = myMachine.run(code);
    std::cout<<report<<'\n';
}

void test_factorial(vm::VirtualMachine& myMachine)
{
    int n = 5;
    std::cout << "test_factorial:\nresulte for "<<n<<" = ";

    std::vector<int32_t> code = {
        static_cast<int32_t>(vm::OpCode::Push), 
        n, 
        static_cast<int32_t>(vm::OpCode::Call),
        8,
        static_cast<int32_t>(vm::OpCode::Nop),
        static_cast<int32_t>(vm::OpCode::Print),
        static_cast<int32_t>(vm::OpCode::Halt),
        static_cast<int32_t>(vm::OpCode::Nop),
        static_cast<int32_t>(vm::OpCode::Dup),//8
        static_cast<int32_t>(vm::OpCode::Jz),
        15,
        static_cast<int32_t>(vm::OpCode::Dup),
        static_cast<int32_t>(vm::OpCode::Dec),
        static_cast<int32_t>(vm::OpCode::Call),
        8,
        static_cast<int32_t>(vm::OpCode::Dup),//15
        static_cast<int32_t>(vm::OpCode::Jnz),
        21,
        static_cast<int32_t>(vm::OpCode::Inc),
        static_cast<int32_t>(vm::OpCode::Push),
        1,
        static_cast<int32_t>(vm::OpCode::Mul),//21 
        static_cast<int32_t>(vm::OpCode::Ret),
    };
    vm::Report report = myMachine.run(code);
    std::cout<<report<<'\n';
}

int main(){
    vm::VirtualMachine myMachine;
    test_1(myMachine);
    test_print_ABC(myMachine);
    test_print_AB_Phase3(myMachine);
    test_error_program(myMachine);
    test_factorial(myMachine);

    return 0;
}