CXX = g++

CC = $(CXX)

GXXFLAGS = -Wall -pedantic -g -std=c++17

GXXFLAGS+= -Werror

main: main.o

main.o: main.cpp templateFunction.hpp

clean:
	rm main *.o
