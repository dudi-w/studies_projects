CXX = g++

CC = $(CXX)

CXXFLAGS = -std=c++17 -Wall -pedantic
CXXFLAGS += -Werror
CXXFLAGS += -Wextra

CXXFLAGS += -g3

CPPFLAGS = -I ./includes  -I ./src

LDLIBS += -lcurlpp -lcurl -lgumbo

main : main.o\
			src/simpleRequest.o\
			src/smartRequest.o\
			src/linkParser.o\
			src/wordParser.o\
			src/linkWordParser.o\
			src/searchDatabase.o\
			src/getHTTP.o\
			src/dataLoader.o\
			src/crawler.o\
			src/basePage.o\
			src/analyzPage.o\
			src/result.o\
			src/textUI.o\
			src/multiQueryHandler.o\
			src/simpleQueryHandler.o\
			src/smartQueryHandler.o\
			# src/queryHandlerFactory.o

main.o : main.cpp

src/simpleRequest.o : src/simpleRequest.cpp includes/simpleRequest.hpp

src/smartRequest.o : src/smartRequest.cpp includes/smartRequest.hpp

src/analyzPage.o : src/analyzPage.cpp includes/analyzPage.hpp

src/crawler.o : src/crawler.cpp includes/crawler.hpp

src/dataLoader.o : src/dataLoader.cpp includes/dataLoader.hpp

src/basePage.o :  src/basePage.cpp includes/basePage.hpp

src/linkParser.o : includes/linkParser.hpp src/linkParser.cpp

src/wordParser.o : includes/wordParser.hpp src/wordParser.cpp

src/linkWordParser.o : includes/linkWordParser.hpp src/linkWordParser.cpp

src/getHTTP.o : includes/getHTTP.hpp src/getHTTP.cpp

src/searchDatabase.o : includes/searchDatabase.hpp src/searchDatabase.cpp

src/result.o : includes/result.hpp src/result.cpp

src/textUI.o : includes/textUI.hpp src/textUI.cpp

src/simpleQueryHandler.o : includes/simpleQueryHandler.hpp src/simpleQueryHandler.cpp includes/searchQueryHandler.hpp

src/multiQueryHandler.o : includes/multiQueryHandler.hpp src/multiQueryHandler.cpp includes/searchQueryHandler.hpp

src/smartQueryHandler.o : includes/smartQueryHandler.hpp src/smartQueryHandler.cpp includes/searchQueryHandler.hpp

# src/queryHandlerFactory.o : includes/queryHandlerFactory.hpp src/queryHandlerFactory.cpp includes/searchQueryHandler.hpp

clean :
	$(RM) main *.o */*.o
