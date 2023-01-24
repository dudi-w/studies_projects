CXX=g++
CC=g++

CFLAGS = -Wall -pedantic -Werror -g -std=c++17

main: main.o brainfuck.o

main.o: main.cpp brainfuck.hpp

brainfuck.o: brainfuck.cpp brainfuck.hpp

run: main
	echo "\033[3;35mmain"
	./main
	echo "\033[0m"
	make clean

clean:
	echo "\033[1;33mclean\033[0m"
	rm main *.o