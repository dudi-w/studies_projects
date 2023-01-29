CXX=g++
CC=g++

CXXFLAGS = -Wall -pedantic -Werror -g -std=c++17

main: main.o brainfuck.o BFcode.o arrByte.o BFmemory.o

main.o: main.cpp brainfuck.hpp dataStructure.hpp

brainfuck.o: brainfuck.cpp brainfuck.hpp BFenum.hpp BFcode.hpp BFmemory.hpp

BFmemory.o: BFmemory.cpp BFmemory.hpp arrByte.cpp dataStructure.hpp

BFcode.o: BFcode.cpp BFcode.hpp arrByte.cpp dataStructure.hpp


run: main
	echo "\033[3;35mmain"
	./main
	echo "\033[0m"
	make clean

clean:
	echo "\033[1;33mclean\033[0m"
	rm main *.o