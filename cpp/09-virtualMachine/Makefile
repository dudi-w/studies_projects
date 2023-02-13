CXX = g++

CC = $(CXX)

CXXFLAGS = -Wall -pedantic -std=c++17

CXXFLAGS+= -Werror

CXXFLAGS+= -g

main : main.o VirtualMachine.o report.o VMenum.hpp

main.o: main.cpp VirtualMachine.hpp

VirtualMachine.o: VirtualMachine.cpp VirtualMachine.hpp

report.o: report.cpp report.hpp

clean: 
	rm *.o main