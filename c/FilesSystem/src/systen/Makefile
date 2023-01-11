GCC=gcc

simplefs: shell.o fs.o disk.o
	$(GCC) shell.o fs.o disk.o -o simplefs

shell.o: shell.c
	$(GCC) -Wall -pedantic shell.c -c -o shell.o -g

fs.o: fs.c fs.h
	$(GCC) -Wall -pedantic fs.c -c -o fs.o -g

disk.o: disk.c disk.h
	$(GCC) -Wall -pedantic disk.c -c -o disk.o -g

run : simplefs
	./simplefs image.20 20

clean:
	rm simplefs disk.o fs.o shell.o