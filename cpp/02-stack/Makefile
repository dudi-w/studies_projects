CXX=g++
CC=g++

CXXFLAGS = -Wall -Werror -pedantic  -g 

main: main.o stack.o
# $(CC) main.o stack.o -o main

main.o: main.cpp stack.hpp
# $(CC) $(CXXFLAGS) main.cpp -c

stack.o: stack.cpp stack.hpp
# $(CC) $(CXXFLAGS) stack.cpp stack.hpp -c

run: main
	./main
	make clean

clean: 
	rm *.o main 