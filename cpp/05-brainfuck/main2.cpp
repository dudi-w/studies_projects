#include <iostream>
#include "brainfuck.hpp"
#include "BFcode.hpp"

// #include "Compiler.hpp"
// #include "Code.hpp"
// #include "Errors.hpp"

using namespace bf;

/* Prints Hello World! */
void test1()
{
    std::cout << "\ntest 1:\n\n";
    Brainfuck bf;
    const char sourceCode[] = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
    
    Code commands = compipile(sourceCode);
    Errors status = bf.run(commands);
    
    bf.dump(std::cout);
    std::cout << "status is Succeeded: " << (status == Errors::Succeeded) << std::endl;
}

/* Prints a Christmas tree at the height of the given input 
    from http://brainfuck.org/
*/
void test2()
{
    std::cout << "\ntest 2:\n\n";
    Brainfuck bf(2);
    const char sourceCode[] = ">>>--------<,[<[>++++++++++<-]>>[<------>>-<+]]++>>++<--[<++[+>]>+<<+++<]<<[>>+[[>>+<<-]<<]>>>>[[<<+>.>-]>>]<.<<<+<<-]>>[<.>--]>.>>.";
    Code commands = compipile(sourceCode);
    Errors status = bf.run(commands);
    
    bf.dump(std::cout);
    std::cout << "status is Succeeded: " << (status == Errors::Succeeded) << std::endl;
}

/* Prints Sierpinski Triangle */
void test3()
{
    std::cout << "\ntest 3:\n\n";
    Brainfuck bf;
    const char sourceCode[] = "++++++++[>+>++++<<-]>++>>+<[-[>>+<<-]+>>]>+[    -<<<[        ->[+[-]+>++>>>-<<]<[<]>>++++++[<<+++++>>-]+<<++.[-]<<    ]>.>+[>>]>+]";
    Code commands = compipile(sourceCode);
    Errors status = bf.run(commands);
    bf.dump(std::cout);
    std::cout << "status is Succeeded: " << (status == Errors::Succeeded) << std::endl;
}

/* Prints Sierpinski Triangle 
    from http://brainfuck.org/
*/
void test4()
{
    std::cout << "\ntest 4:\n\n";
    Brainfuck bf(2);
    const char sourceCode[] = ">,>+++++++++,>+++++++++++[<++++++<++++++<+>>>-]<<.>.<<-.>.>.<<.";
    Code commands = compipile(sourceCode);
    Errors status = bf.run(commands);
    bf.dump(std::cout);
    std::cout << "status is Succeeded: " << (status == Errors::Succeeded) << std::endl;
}

/* Goes to cell 30000 and reports from there with a #. 
    (Verifies that the array is big enough.)
    from http://brainfuck.org/
*/
void test5()
{
    std::cout << "\ntest 5:\n\n";
    Brainfuck bf;
    const char sourceCode[] = "++++[>++++++<-]>[>+++++>+++++++<<-]>>++++<[[>[[>>+<<-]<]>>>-]>-[>+>+<<-]>]+++++[>+++++++<<++>-]>.<<.";
    Code commands = compipile(sourceCode);
    Errors status = bf.run(commands);
    bf.dump(std::cout);
    std::cout << "status is Succeeded: " << (status == Errors::Succeeded) << std::endl;
}

/* test the array bounds checking (30000)
    You can change the bounds on the BfMemory.hpp file
    from http://brainfuck.org/
*/
void test6()
{
    std::cout << "\ntest 6:\n\n";
    Brainfuck bf(2);
    const char sourceCode[] = "[]++++++++++[>>+>+>++++++[<<+<+++>>>-]<<<<-]\"A*$\";?@![#>>+<<]>[>>]<<<<[>++<[-]]>.>.";
    Code commands = compipile(sourceCode);
    Errors status = bf.run(commands);
    bf.dump(std::cout);
    std::cout << "status is Succeeded: " << (status == Errors::Succeeded) << std::endl;
}

/* Tests for several obscure problems. Should output an H.
    from http://brainfuck.org/
*/
void test7()
{
    std::cout << "\ntest 7:\n\n";
    Brainfuck bf(2);
    const char sourceCode[] = "+[>+++++++++++++++++++++++++++++++++.]";
    Code commands = compipile(sourceCode);
    Errors status = bf.run(commands);
    bf.dump(std::cout);
    std::cout << "status is Succeeded: " << (status == Errors::Succeeded) << std::endl;
}

/* Should ideally give error message "unmatchedBrackets"
    from http://brainfuck.org/
*/
void test8()
{
    std::cout << "\ntest 8:\n\n";
    Brainfuck bf(2);
    const char sourceCode[] = "+]";//"+++++[>+++++++>++<<-]>.>.[";
    Code commands = compipile(sourceCode);
    Errors status = bf.run(commands);
    bf.dump(std::cout);
    std::cout << "status is Succeeded: " << (status == Errors::Succeeded) << std::endl;
}

/* Should ideally give error message "unmatchedBrackets"
    from http://brainfuck.org/
*/
void test9()
{
    std::cout << "\ntest 9:\n\n";
    Brainfuck bf(2);
    const char sourceCode[] = "+++++[>+++++++>++<<-]>.>.][";
    Code commands = compipile(sourceCode);
    Errors status = bf.run(commands);
    bf.dump(std::cout);
    std::cout << "status is ok: " << (status == Errors::Succeeded) << std::endl;
}

/* 
    TheSucceededrainfuck to C interpretor:
    NOTE: It does not take well to any characters of input besides
    the 8 standard brainfuck operators and newline and EOF.

    from BrainFuck Programming Tutorial by: Katie
    https://gist.github.com/roachhd/dce54bec8ba55fb17d3a

*/
void test10()
{
    std::cout << "\ntest 10:\n\n";
    Brainfuck bf(2);
    const char sourceCode[] = ">+++++[>+++++++<-]>.<<++[>+++++[>+++++++<-]<-]>>.+++++.<++[>-----<-]>-.<++[>++++<-]>+.<++[>++++<-]>+.[>+>+>+<<<-]>>>[<<<+>>>-]<<<<<++[>+++[>---<-]<-]>>+.+.<+++++++[>----------<-]>+.<++++[>+++++++<-]>.>.-------.-----.<<++[>>+++++<<-]>>.+.----------------.<<++[>-------<-]>.>++++.<<++[>++++++++<-]>.<++++++++++[>>>-----------<<<-]>>>+++.<-----.+++++.-------.<<++[>>++++++++<<-]>>+.<<+++[>----------<-]>.<++[>>--------<<-]>>-.------.<<++[>++++++++<-]>+++.---....>++.<----.--.<++[>>+++++++++<<-]>>+.<<++[>+++++++++<-]>+.<++[>>-------<<-]>>-.<--.>>.<<<+++[>>++++<<-]>>.<<+++[>>----<<-]>>.++++++++.+++++.<<++[>---------<-]>-.+.>>.<<<++[>>+++++++<<-]>>-.>.>>>[-]>>[-]<+[<<[-],[>>>>>>>>>>>>>+>+<<<<<<<<<<<<<<-]>>>>>>>>>>>>>>[<<<<<<<<<<<<<<+>>>>>>>>>>>>>>-]<<+>[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[-[<->[-]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]<[<<<<<<<<<<<<[-]>>>>>>>>>>>>[-]]<<<<<<<<<<<<[<+++++[>---------<-]>++[>]>>[>+++++[>+++++++++<-]>--..-.<+++++++[>++++++++++<-]>.<+++++++++++[>-----<-]>++.<<<<<<.>>>>>>[-]<]<<<[-[>]>>[>++++++[>+++[>++++++<-]<-]>>++++++.-------------.----.+++.<++++++[>----------<-]>.++++++++.----.<++++[>+++++++++++++++++<-]>.<++++[>-----------------<-]>.+++++.--------.<++[>+++++++++<-]>.[-]<<<<<<<.>>>>>]<<<[-[>]>>[>+++++[>+++++++++<-]>..---.<+++++++[>++++++++++<-]>.<+++++++++++[>-----<-]>++.<<<<<<.>>>>>>[-]<]<<<[-[>]>>[>+++[>++++[>++++++++++<-]<-]>>-.-----.---------.<++[>++++++<-]>-.<+++[>-----<-]>.<++++++[>----------<-]>-.<+++[>+++<-]>.-----.<++++[>+++++++++++++++++<-]>.<++++[>-----------------<-]>.+++++.--------.<++[>+++++++++<-]>.[-]<<<<<<<.>>>>>]<<<[<+++[>-----<-]>+[>]>>[>+++++[>+++++++++<-]>..<+++++++[>++++++++++<-]>---.<+++++[>----------<-]>---.<<<<<<.>>>>>>[-]<]<<<[--[>]>>[>+++++[>+++++++++<-]>--..<+++++++[>++++++++++<-]>-.<+++++[>----------<-]>---.[-]<<<<<<.>>>>>]<<<[<+++[>----------<-]>+[>]>>[>+++[>++++[>++++++++++<-]<-]>>-.<+++[>-----<-]>.+.+++.-------.<++++++[>----------<-]>-.++.<+++++++[>++++++++++<-]>.<+++++++[>----------<-]>-.<++++++++[>++++++++++<-]>++.[-]<<<<<<<.>>>>>]<<<[--[>]>>[>+++++[>+++++[>+++++<-]<-]>>.[-]<<<<<<<.>>>>>]<<<[<++++++++++[>----------------<-]>--[>]>>[<<<<[-]]]]]]]]]]]>>]<++[>+++++[>++++++++++<-]<-]>>+.<+++[>++++++<-]>+.<+++[>-----<-]>.+++++++++++.<+++++++[>----------<-]>------.++++++++.-------.<+++[>++++++<-]>.<++++++[>+++++++++++<-]>.<++++++++++.";
    Code commands = compipile(sourceCode);
    Errors status = bf.run(commands);
    bf.dump(std::cout);
    std::cout << "status is ok: " << (status == Errors::Succeeded) << std::endl;
}


int main ()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
}