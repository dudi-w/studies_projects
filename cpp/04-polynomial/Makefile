CC=g++

CXX=$(CC)

CXXFLAGS = -Wall -std=c++17 -Werror -pedantic -g

main: main.o arrRational.o ../01-rational/rational.o  polynomial.o

main.o: main.cpp dataStructure.hpp

polynomial.o : polynomial.cpp polynomial.hpp

arrRational.o: arrRational.cpp dataStructure.hpp 

../01-rational/rational.o: ../01-rational/rational.cpp ../01-rational/rational.hpp

run: main
	echo "\033[3;33m"
	./main
	echo "\033[3;35m"
	make clean

clean: 
	rm *.o main ../01-rational/rational.o