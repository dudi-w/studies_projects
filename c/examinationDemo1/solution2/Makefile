CC =gcc


main : main.o goldbrach.o

main.o : main.c  solution2.h

goldbrach.o :  goldbrach.c solution2.h



run : main
	./main

clean :
	$(RM) main *.o