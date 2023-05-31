CXX=g++
CC=g++

# CFLAGS = -Wall -pedantic -Werror -g3

main: dublePointers.o

	$(CC)  dublePointers.o -o main

dublePointers.o: dublePointers.cpp

	$(CC) $(CFLAGS) dublePointers.cpp -c 

clean:
	rm main *.o
