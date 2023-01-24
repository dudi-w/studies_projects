CXX=g++
CC=g++

CFLAGS = -Wall -pedantic -Werror -g

main: main.o rational.o

	$(CC)  main.o rational.o -o main

main.o: main.cpp rational.hpp

	$(CC) $(CFLAGS) main.cpp -c 

rational.o: rational.cpp rational.hpp

	$(CC) $(CFLAGS) rational.cpp -c 

run: main
	echo "\033[3;35mmain"
	./main
	echo "\033[0m"
	make clean

clean:
	echo "\033[1;33mclean\033[0m"
	rm main *.o
