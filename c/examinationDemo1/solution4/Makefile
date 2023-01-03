CC =gcc


main : main.o robot.o

main.o : main.c  solution4.h

robot.o :  robot.c solution4.h



run : main
	./main

clean :
	$(RM) main *.o