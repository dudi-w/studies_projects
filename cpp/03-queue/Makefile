CXX=g++
CC=g++

CXXFLAGS = -Wall -std=c++17 -Werror -pedantic 

main: main.o queue.o stack.o
#	$(CC) main.o stack.o queue.o -o main

main.o: main.cpp
# $(CC) $(CXXFLAGS) main.cpp -c

stack.o: ../02-stack/stack.cpp ../02-stack/stack.hpp
	$(CC) $(CXXFLAGS) ../02-stack/stack.cpp ../02-stack/stack.hpp -c stack.o

queue.o: queue.cpp queue.hpp
# $(CC) $(CXXFLAGS) stack.cpp stack.hpp -c

run: main
	./main
	make clean

clean: 
	rm *.o main 