CXX = g++
CC= $(CXX)

CCXXFLAGS = -std=c++17 -Well -pedantic 
CCXXFLAGS += -Werror
CCXXFLAGS += -g

main: main.o lowercase.o uppercase.o change_case.o shiftEncryption.o

main.o: main.cpp lowercase.hpp uppercase.hpp change_case.hpp

lowercase.o: lowercase.hpp lowercase.cpp

uppercase.o: uppercase.hpp uppercase.cpp

shiftEncryption.o: shiftEncryption.hpp shiftEncryption.cpp

change_case.o: change_case.hpp change_case.cpp



clean:
	$(RM) -r *.o ./main
