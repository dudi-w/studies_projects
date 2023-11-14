CC = g++

CXX = $(CC)

GXXFLAGS = -Wall -pedantic -g3 -std=c++17
GXXFLAGS+= -Werror

main: main.o 

main.o: main.cpp templateFunction2.hpp templateFunction2.inl

clean:
	rm main *.o