CC =gcc


main : main.o stackArray.o stackList.o

main.o : main.c 

stackArray.o : stackArray.c

stackList.o : stackList.c

run : main
	./main

clean :
	$(RM) main *.o