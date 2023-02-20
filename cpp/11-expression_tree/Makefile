CXX = g++
CC = $(CXX)

CXXFLAGS = -std=c++17 -Wall -pedantic 
CXXFLAGS += -Werror
CXXFLAGS += -Wextra
CXXFLAGS += -g3

main: main.o expressionTree/expressionTree.o\
	map_bild_functions.o\
	storingToExpressionTree.o\
	tokens/token-implementation/numToken.o\
	tokens/token-implementation/operatorToken.o\
	node/numNode/numNode.o\
	node/binaryOperatorNode/binaryOperatorNode-implementation/addNode.o\
	node/binaryOperatorNode/binaryOperatorNode-implementation/subNode.o\
	node/binaryOperatorNode/binaryOperatorNode-implementation/mulNode.o \
	node/binaryOperatorNode/binaryOperatorNode-implementation/divNode.o


main.o: main.cpp

expressionTree/expressionTree.o : expressionTree/expressionTree.cpp expressionTree/expressionTree.hpp

map_bild_functions.o : map_bild_functions.cpp map_bild_functions.hpp

storingToExpressionTree.o : storingToExpressionTree.cpp storingToExpressionTree.hpp

tokens/token-implementation/numToken.o : tokens/token-implementation/numToken.cpp\
										tokens/token-implementation/numToken.hpp\
										tokens/token.hpp

tokens/token-implementation/operatorToken.o : tokens/token-implementation/operatorToken.cpp\
											tokens/token-implementation/operatorToken.hpp\
											tokens/token.hpp

node/numNode/numNode.o : node/numNode/numNode.cpp node/numNode/numNode.hpp node/expressionNode.hpp


node/binaryOperatorNode/binaryOperatorNode-implementation/addNode.o : node/binaryOperatorNode/binaryOperatorNode-implementation/addNode.cpp\
																node/binaryOperatorNode/binaryOperatorNode-implementation/addNode.hpp\
																node/binaryOperatorNode/binaryOperatorNode.hpp\
																node/expressionNode.hpp

node/binaryOperatorNode/binaryOperatorNode-implementation/subNode.o : node/binaryOperatorNode/binaryOperatorNode-implementation/subNode.cpp\
																node/binaryOperatorNode/binaryOperatorNode-implementation/subNode.hpp\
																node/binaryOperatorNode/binaryOperatorNode.hpp\
																node/expressionNode.hpp

node/binaryOperatorNode/binaryOperatorNode-implementation/mulNode.o : node/binaryOperatorNode/binaryOperatorNode-implementation/mulNode.cpp\
																node/binaryOperatorNode/binaryOperatorNode-implementation/mulNode.hpp\
																node/binaryOperatorNode/binaryOperatorNode.hpp\
																node/expressionNode.hpp

node/binaryOperatorNode/binaryOperatorNode-implementation/divNode.o : node/binaryOperatorNode/binaryOperatorNode-implementation/divNode.cpp\
																node/binaryOperatorNode/binaryOperatorNode-implementation/divNode.hpp\
																node/binaryOperatorNode/binaryOperatorNode.hpp\
																node/expressionNode.hpp

clean:
	$(RM) -r ./main *.o */*.o */*/*.o */*/*/*.o
