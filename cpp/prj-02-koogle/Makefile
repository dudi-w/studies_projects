CXX = g++

CC = $(CXX)

CXXFLAGS = -std=c++17 -Wall -pedantic
CXXFLAGS += -Werror
CXXFLAGS += -Wextra
CXXFLAGS += -g3

CPPFLAGS = -I ./includes  -I ./src

LDLIBS += -lcurlpp -lcurl -lgumbo

OBJECTS = main.o src/configuration.o src/simpleRequest.o src/smartRequest.o src/linkParser.o \
		src/wordParser.o src/linkWordParser.o src/matabase.o 	src/getHTTP.o \
		src/dataLoader.o src/crawler.o src/basePage.o src/analyzPage.o 	src/result.o \
		src/textUI.o src/multiQueryHandler.o src/simpleQueryHandler.o src/smartQueryHandler.o\
		src/server.o

main : $(OBJECTS)

main.o : main.cpp

src/simpleRequest.o : src/simpleRequest.cpp includes/simpleRequest.hpp
src/smartRequest.o : src/smartRequest.cpp includes/smartRequest.hpp

src/analyzPage.o : src/analyzPage.cpp includes/analyzPage.hpp includes/basePage.hpp
src/basePage.o :  src/basePage.cpp includes/basePage.hpp includes/basePage.hpp

src/configuration.o : src/configuration.cpp includes/configuration.hpp
src/crawler.o : src/crawler.cpp includes/crawler.hpp includes/crawlerIF.hpp\
	includes/analyzPage.hpp includes/dataLoader.hpp
src/dataLoader.o : src/dataLoader.cpp includes/dataLoader.hpp includes/setDatabase.hpp\
	includes/configuration.hpp includes/analyzPage.hpp includes/linkWordParser.hpp includes/crawlerIF.hpp
src/linkParser.o : includes/linkParser.hpp includes/parser.hpp src/linkParser.cpp
src/wordParser.o : includes/wordParser.hpp src/wordParser.cpp includes/parser.hpp
src/linkWordParser.o : includes/linkWordParser.hpp src/linkWordParser.cpp includes/parser.hpp
src/getHTTP.o : includes/getHTTP.hpp src/getHTTP.cpp

src/matabase.o : includes/matabase.hpp includes/getDatabase.hpp includes/setDatabase.hpp src/matabase.cpp 

src/textUI.o : includes/textUI.hpp src/textUI.cpp
src/server.o : includes/server.hpp src/server.cpp includes/searchQueryHandler.hpp includes/textUI.hpp
src/simpleQueryHandler.o : includes/simpleQueryHandler.hpp\
	src/simpleQueryHandler.cpp includes/searchQueryHandler.hpp
src/multiQueryHandler.o : includes/multiQueryHandler.hpp\
	src/multiQueryHandler.cpp includes/searchQueryHandler.hpp includes/simpleQueryHandler.hpp
src/smartQueryHandler.o : includes/smartQueryHandler.hpp\
	src/smartQueryHandler.cpp includes/searchQueryHandler.hpp\
	includes/simpleQueryHandler.hpp includes/multiQueryHandler.hpp 
src/result.o : includes/result.hpp src/result.cpp

clean :
	$(RM) $(OBJECTS) main
