CC =gcc


main : main.o calculator.o stackList.o

main.o : main.c  solution2.h

calculator.o :  stackList.c 

stackList.o : stackList.c



run : main
	./main "18/"

clean :
	$(RM) main *.o