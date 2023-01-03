CC =gcc


main : main.o weakGoldbrach.o

main.o : main.c  solution2.h

weakGoldbrach.o :  weakGoldbrach.c solution2.h



run : main
	./main

clean :
	$(RM) main *.o