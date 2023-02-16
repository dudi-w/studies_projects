CXX = g++
CC = $(CXX)

CCXXFLAGS = -std=c++17 -Well -pedantic 
CCXXFLAGS += -Werror
CCXXFLAGS += -g3

# CPPFLEGS = I ./

main: main.o storingToExpressionTree.o\
	tokens/token-implementation/numToken.o\
	tokens/token-implementation/operatorToken.o\
	map_bild_functions.o\
	tokens/token.hpp\
	

main.o: main.cpp 

map_bild_functions.o : map_bild_functions.cpp map_bild_functions.hpp

storingToExpressionTree.o : storingToExpressionTree.cpp storingToExpressionTree.hpp

tokens/token-implementation/numToken.o : tokens/token-implementation/numToken.cpp tokens/token-implementation/numToken.hpp

tokens/token-implementation/operatorToken.o : tokens/token-implementation/operatorToken.cpp tokens/token-implementation/operatorToken.hpp


clean:
	$(RM) -r *.o ./main */*.o */*/*.o