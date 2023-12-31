#include "brainfuck.hpp"
#include "assert.h"

/*declaration*/
bf::Log translate(bf::Code& code , const char* const program);
size_t checkValid(const char* const program);


bf::Brainfuck::Brainfuck(size_t size)
:m_runMem(size)
{}


bf::Log bf::Brainfuck::run(bf::Code& code)
{
    m_runMem.cleanMem();
    while(code.getIndex()>0){
        code<<1;
    }
    
    OpCode op;
    while(( op = code.getCurrentOp() ) != OpCode::EndOp){
        
        bf::Log log = execute(op);
        
        if(log == bf::Log::gumpEnd){
            code.jumpToEndLoop();
        }
        
        if(log== bf::Log::gumpHead){
            code.jumpToHeadLoop();
        };
        code>>1;
    }
    return Log::success;
}

bf::Log bf::Brainfuck::execute(bf::OpCode const code)
{
    switch(code){

        case bf::OpCode::Right:
            m_runMem>>1;
            break;

        case bf::OpCode::Left:
            m_runMem<<1;
            break;

        case bf::OpCode::Read:
            m_runMem.read();
            break;

        case bf::OpCode::Write:
            m_runMem.write();
            break;

        case bf::OpCode::Increment:
            ++m_runMem;
            break;

        case bf::OpCode::Decrement:
            --m_runMem;
            break;

        case bf::OpCode::LoopBegin:
            if(m_runMem.getValue()){
                break;
            }
            else{
                return bf::Log::gumpEnd;
                break;
            }

        case bf::OpCode::LoopEnd:
            if(m_runMem.getValue()){
                return bf::Log::gumpHead;
                break;
            }
            else{break;}

        default:
            break;
    }
    return bf::Log::success;
}


bf::Code bf::compiler(const char* const program)
{
    size_t size = checkValid(program);
    
    if(!size){
        assert(!"invalid code");
    }
    
    bf::Code code(size);
    translate(code , program);
    return code;
}

size_t checkValid(const char* const program)
{
    size_t count, headLoop, endLoop;
    count = headLoop = endLoop = 0;
    
    for(size_t i=0 ; program[i]!='\0' ; ++i){
        if( program[i]== '<' || program[i]== '>' ||
            program[i]== '.' || program[i]== ',' ||
            program[i]== '+' || program[i]== '-'){
            ++count;
        }
        if(program[i]== '['){
            ++headLoop;
            ++count;
        }
        if(program[i]== ']'){
            ++endLoop;
            ++count;
        }
        if(endLoop > headLoop){
            return 0;
        }
    }
    return (headLoop==endLoop) ? count +1 : 0;
}

bf::Log translate(bf::Code& code , const char* const program)
{
    size_t i = 0;

    while(program[i]!= '\0'){
        switch(program[i++]){

            case '>':
                code.setOp(bf::OpCode::Right);
                break;

            case '<':
                code.setOp(bf::OpCode::Left);
                break;

            case '.':
                code.setOp(bf::OpCode::Read);
                break;

            case ',':
                code.setOp(bf::OpCode::Write);
                break;

            case '+':
                code.setOp(bf::OpCode::Increment);
                break;

            case '-':
                code.setOp(bf::OpCode::Decrement);
                break;

            case '[':
                code.setOp(bf::OpCode::LoopBegin);
                break;

            case ']':
                code.setOp(bf::OpCode::LoopEnd);
                break;

            default:
            code<<1;                    //In order to stay the same place in memory
                break;
        }
        code>>1;               
    }
    code.setOp(bf::OpCode::EndOp);      //To indicate the end of the program
    return bf::Log::success;
}