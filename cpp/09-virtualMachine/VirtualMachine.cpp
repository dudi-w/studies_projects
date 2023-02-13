#include <assert.h>
#include "VirtualMachine.hpp"

bool checkOpration(int32_t opNum, std::unordered_map<vm::OpCode, std::function<vm::Log (vm::VirtualMachine &)>> functions , vm::Log log);
bool checkAddres(size_t index , const std::vector<int32_t>& code , vm::Log& log);


vm::VirtualMachine::VirtualMachine()
: m_index(0)
, m_functions(
    {
        { vm::OpCode::Pop ,&VirtualMachine::pop },
        { vm::OpCode::Push ,[](VirtualMachine&){return vm::Log::MakePush;} },
        { vm::OpCode::Add ,&VirtualMachine::add },
        { vm::OpCode::Sub ,&VirtualMachine::sub },
        { vm::OpCode::Mul ,&VirtualMachine::mul },
        { vm::OpCode::Div ,&VirtualMachine::div },
        { vm::OpCode::Inc ,&VirtualMachine::inc },
        { vm::OpCode::Dec ,&VirtualMachine::dec },
        { vm::OpCode::Dup ,&VirtualMachine::dup },
        { vm::OpCode::Swap ,&VirtualMachine::swap },
        { vm::OpCode::Print ,&VirtualMachine::print },
        { vm::OpCode::PrintC ,&VirtualMachine::printC },
        { vm::OpCode::Jmp ,[](VirtualMachine&){return vm::Log::MakeJump;} },
        { vm::OpCode::Jz ,&VirtualMachine::jz },
        { vm::OpCode::Jnz ,&VirtualMachine::jnz },
        { vm::OpCode::Halt ,[](VirtualMachine&){return vm::Log::Halt;} },
        { vm::OpCode::Call ,[](VirtualMachine&){return vm::Log::MakeCall;} },
        { vm::OpCode::Ret ,&VirtualMachine::ret },
        { vm::OpCode::Nop ,[](VirtualMachine&){return vm::Log::Success;} }
    }
)
{}

vm::Report vm::VirtualMachine::run( std::vector <int32_t> const& code)
{
    cleanMem();

    vm::Log log  = vm::Log::Start;
    
    while(true){
        if(!checkOpration(code[m_index], m_functions ,log)) {break;} 
        if(!checkAddres(m_index ,code ,log)) {break;}
        log = m_functions[static_cast<vm::OpCode>(code[m_index])](*this);

        if(log == vm::Log::MakeCall){
            m_callStack.push(m_index+2);
            log = vm::Log::MakeJump;
        }

        if(log == vm::Log::MakeJump){
            ++m_index;
            if(!checkAddres(m_index ,code ,log)) {break;}
            m_index = code[m_index];
            continue;
        }

        if(log == vm::Log::MakePush){
            if(!checkAddres(m_index ,code ,log)) {break;}
            m_memStack.push(code[++m_index]);
        }else if(log != vm::Log::Success){
            break;
        };
        ++m_index;
    }
    return vm::Report(m_index ,static_cast<vm::OpCode>(code[m_index]), log , m_memStack.empty() , m_callStack.empty());
}


void vm::VirtualMachine::cleanMem()
{
    while(!m_memStack.empty()){
        m_memStack.pop();
    }
    m_index= 0;
}

vm::Log vm::VirtualMachine::add()
{   
    if(m_memStack.size() < 2){
        return vm::Log::TooFewArguments;
    }
    int32_t data = m_memStack.top();
    pop();
    m_memStack.top() = m_memStack.top() + data;
    return vm::Log::Success;
}

vm::Log vm::VirtualMachine::sub()
{
    if(m_memStack.size() < 2){
        return vm::Log::TooFewArguments;
    }
    int32_t data = m_memStack.top();
    pop();
    m_memStack.top() = m_memStack.top() - data;
    return vm::Log::Success;
}

vm::Log vm::VirtualMachine::mul()
{
    if(m_memStack.size() < 2){
        return vm::Log::TooFewArguments;
    }
    int32_t data = m_memStack.top();
    pop();
    m_memStack.top() = m_memStack.top() * data;
    return vm::Log::Success;
}

vm::Log vm::VirtualMachine::div()
{
    if(m_memStack.size() < 2){
        return vm::Log::TooFewArguments;
    }
    int32_t data = m_memStack.top();
    pop();
    if(m_memStack.top()==0){
        return vm::Log::DivisionByZero;
    }
    m_memStack.top() = m_memStack.top() / data;
    return vm::Log::Success;
}

vm::Log vm::VirtualMachine::pop()
{
    if(m_memStack.empty()){
        return vm::Log::Empty_stack;
    }
    m_memStack.pop();
    return vm::Log::Success;
}

vm::Log vm::VirtualMachine::dup()
{
    if(m_memStack.empty()){
        return vm::Log::Empty_stack;
    }
    m_memStack.push(m_memStack.top());
    return vm::Log::Success;
}

vm::Log vm::VirtualMachine::swap()
{
    if(m_memStack.size() < 2){
        return vm::Log::TooFewArguments;
    }
    int32_t data1 = m_memStack.top();
    m_memStack.pop();
    int32_t data2 = m_memStack.top();
    m_memStack.pop();
    m_memStack.push(data1);
    m_memStack.push(data2);
    return vm::Log::Success;
}

vm::Log vm::VirtualMachine::print()
{
    if(m_memStack.empty()){
        return vm::Log::Empty_stack;
    }
    std::cout<<m_memStack.top()<<std::flush;
    m_memStack.pop();
    return vm::Log::Success;
}

vm::Log vm::VirtualMachine::printC()
{
    if(m_memStack.empty()){
        return vm::Log::Empty_stack;
    }
    std::cout<<static_cast<char>(m_memStack.top())<<std::flush;
    m_memStack.pop();
    return vm::Log::Success;
}

vm::Log vm::VirtualMachine::inc()
{
    if(m_memStack.empty()){
        return vm::Log::Empty_stack;
    }
    int32_t data = m_memStack.top();
    m_memStack.pop();
    m_memStack.push(++data);
    return vm::Log::Success;
}

vm::Log vm::VirtualMachine::dec()
{
    if(m_memStack.empty()){
        return vm::Log::Empty_stack;
    }
    int32_t data = m_memStack.top();
    m_memStack.pop();
    m_memStack.push(--data);
    return vm::Log::Success;
}

vm::Log vm::VirtualMachine::jz()
{
    if(m_memStack.empty()){
        return vm::Log::Empty_stack;
    }
    if(!m_memStack.top()){
        m_memStack.pop();
        return vm::Log::MakeJump;

    }
    else{
        pop();
        ++m_index;
        return vm::Log::Success;
    }

}

vm::Log vm::VirtualMachine::jnz()
{    if(m_memStack.empty()){
        return vm::Log::Empty_stack;
    }
    if(m_memStack.top()){
        m_memStack.pop();
        return vm::Log::MakeJump;
    }
    else{
        pop();
        ++m_index;
        return vm::Log::Success;
    }
}

vm::Log vm::VirtualMachine::ret()
{    if(m_callStack.empty()){
        return vm::Log::Empty_stack;
    }
    m_index = m_callStack.top()-1;//Because the external loop increase the pointer
    m_callStack.pop();
    return vm::Log::Success;
}

bool checkAddres(size_t index , const std::vector<int32_t>& code , vm::Log& log){
    if(index >= code.size()){
        log= vm::Log::Out_of_renge;
        return false;
    }
    return true;
}

bool checkOpration(int32_t opNum, std::unordered_map<vm::OpCode, std::function<vm::Log (vm::VirtualMachine &)>> functions , vm::Log log){
    if(opNum>= static_cast <int32_t> (functions.size())){
        log = vm::Log::Invalid_program;
        return false;
    }
    return true;
}