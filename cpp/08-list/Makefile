CXX = g++

CC = $(CXX)

GXXFLAGS = -Wall -pedantic -Werror -std=c++17

GXXFLAGS+= -Werror

GXXFLAGS+= -g

main : main.o ../01-rational/rational.o

main.o: main.cpp list.inl node.inl ../01-rational/rational.hpp

../01-rational/rational.o: ../01-rational/rational.cpp ../01-rational/rational.hpp

clean:
	rm main *.o ../01-rational/rational.o