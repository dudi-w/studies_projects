CXX = g++
CC = $(CXX)

CCXXFLAGS = -std=c++17 -Well -pedantic 
CCXXFLAGS += -Werror
CCXXFLAGS += -g

main: main.o tokens/numToken.o tokens/operatorToken.o tokens/token.hpp

main.o: main.cpp 

tokens/numToken.o : tokens/numToken.cpp tokens/numToken.hpp

tokens/operatorToken.o : tokens/operatorToken.cpp tokens/operatorToken.hpp

clean:
	$(RM) -r *.o ./main */*.o