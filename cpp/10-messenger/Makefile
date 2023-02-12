CXX = g++
CC= $(CXX)

CCXXFLAGS = -std=c++17 -Well -pedantic 
CCXXFLAGS += -Werror
CCXXFLAGS += -g

main: main.o lowercase.o uppercase.o change_case.o shiftEncryption.o a_zEncryption.o

main.o: main.cpp lowercase.hpp uppercase.hpp a_zEncryption.hpp change_case.hpp

lowercase.o: lowercase.hpp lowercase.cpp

uppercase.o: uppercase.hpp uppercase.cpp

shiftEncryption.o: shiftEncryption.hpp shiftEncryption.cpp

a_zEncryption.o: a_zEncryption.hpp a_zEncryption.cpp 

change_case.o: change_case.hpp change_case.cpp



clean:
	$(RM) -r *.o ./main
