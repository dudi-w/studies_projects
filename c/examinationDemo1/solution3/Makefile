CC =gcc


main : main.o str_dis.o

main.o : main.c  solution3.h

str_dis.o :  str_dis.c solution3.h



run : main
	./main

clean :
	$(RM) main *.o