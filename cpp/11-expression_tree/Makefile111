CXX = g++
CC = $(CXX)

CCXXFLAGS = -std=c++17 -Well -pedantic 
CCXXFLAGS += -Werror
CCXXFLAGS += -g

main: main.o numNode.o addNode.o subNode.o mulNode.o divNode.o

main.o: main.cpp 

numNode.o : numNode.cpp numNode.hpp

addNode.o : addNode.cpp addNode.hpp

subNode.o : subNode.cpp subNode.hpp

mulNode.o : mulNode.cpp mulNode.hpp

divNode.o : divNode.cpp divNode.hpp

clean:
	$(RM) -r *.o ./main