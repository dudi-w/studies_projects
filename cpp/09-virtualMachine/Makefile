CXX = g++

CC = $(CXX)

CXXFLAGS = -Wall -pedantic -std=c++17
CXXFLAGS+= -Werror
CXXFLAGS+= -g

main : main.o VirtualMachine.o

main.o: main.cpp VirtualMachine.hpp

VirtualMachine.o: VirtualMachine.cpp VirtualMachine.hpp

clean: 
	rm *.o main