implement a brain fuck interpeter

see:
https://en.wikipedia.org/wiki/Brainfuck#Commands
https://brainfuck-visualizer.herokuapp.com/


class BrainFuckInterpreter {
public:
    BrainFuckInterpreter(size_t n);
    void run(const char* program);

    enum class OpCode { NoOp, Right, Left, Increment, Decrement, Write, Read, LoopBegin, LoopEnd };
    OpCode translate(char c);
    void execute(OpCode code);

// bellow here: use your imagination
    void dump(); // print the memory

private:
    char* mem;
    char* ptr;
};

void BrainFuckInterpreter::run(const char* program)
{
    while(...){
        char c = program[i];
        OpCode operation = translate(c); // + --> OpCode::Increment;  a..z 0..9 -> OpCode::NoOp
        execute(operation);
    }
}

void test(){
    BrainFuckInterpreter bfi(100);
    bfi.run("+++++++>[>++++<-]>.");
}
