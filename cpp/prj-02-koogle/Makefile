CXX = g++

CC = $(CXX)

CXXFLAGS = -std=c++17 -Wall -pedantic
# CXXFLAGS += -Werror
# CXXFLAGS += -Wextra

# CXXFLAGS += -g3

CPPFLAGS = -I ./includes  -I ./src

LDLIBS += -lcurlpp -lcurl -lgumbo

main : main.o\
			src/linkParser.o\
			src/wordParser.o\
			src/linkWordParser.o\
			src/searchDatabase.o\
			src/getHTTP2.o\
			src/dataLoader.o\
			src/crawler.o\
			src/basePage.o\
			src/analyzPage.o

main.o : main.cpp

src/analyzPage.o : src/analyzPage.cpp includes/analyzPage.hpp

src/crawler.o : src/crawler.cpp includes/crawler.hpp

src/dataLoader.o : src/dataLoader.cpp includes/dataLoader.hpp

src/basePage.o :  src/basePage.cpp includes/basePage.hpp

src/linkParser.o : includes/linkParser.hpp src/linkParser.cpp

src/wordParser.o : includes/wordParser.hpp src/wordParser.cpp

src/linkWordParser.o : includes/linkWordParser.hpp src/linkWordParser.cpp

src/getHTTP2.o : includes/getHTTP2.hpp src/getHTTP2.cpp

src/searchDatabase.o : includes/searchDatabase.hpp src/searchDatabase.cpp

clean :
	$(RM) main *.o */*.o