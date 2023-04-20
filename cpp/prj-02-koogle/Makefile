CXX = g++

CC = $(CXX)

CXXFLAGS = -std=c++17 -Wall -pedantic
CXXFLAGS += -Werror
CXXFLAGS += -Wextra
CXXFLAGS += -g3

CPPFLAGS = -I ./includes -I ./includes/crawler -I ./includes/parser -I ./includes/queryHandler -I ./src -I ./src/crawler -I ./src/parser -I ./src/queryHandler

LDLIBS += -lcurlpp -lcurl -lgumbo

OBJECTS = mainServer.o src/configuration.o src/tools.o src/simpleRequest.o src/smartRequest.o\
		src/linkParser.o src/wordParser.o src/linkWordParser.o src/matabase.o src/getHTTP.o\
		src/pageFetcher.o src/crawlerQueue.o src/crawler.o src/basePage.o\
		src/analyzPage.o src/result.o src/queryIFfactory.o src/textUI.o src/multiQueryHandler.o\
		src/simpleQueryHandler.o src/smartQueryHandler.o src/searchQueryFacilita.o src/TCPqueryIF.o\
		src/TCPsocketFile.o src/TCPserver.o

OBJECTS_CLIENT = mainClient.o src/clientQueryHandler.o src/textUI.o\
	src/result.o src/searchQueryFacilita.o src/simpleRequest.o src/smartRequest.o\
	src/tools.o src/TCPsocketFile.o src/TCPclient.o

RUNFILES = mainServer mainClient

all : $(RUNFILES)

mainServer : $(OBJECTS)
mainClient : $(OBJECTS_CLIENT)

mainServer.o : mainServer.cpp
mainClient.o : mainClient.cpp

src/simpleRequest.o : src/simpleRequest.cpp includes/simpleRequest.hpp
src/smartRequest.o : src/smartRequest.cpp includes/smartRequest.hpp

src/analyzPage.o : src/analyzPage.cpp includes/analyzPage.hpp includes/basePage.hpp
src/basePage.o :  src/basePage.cpp includes/basePage.hpp includes/basePage.hpp

src/tools.o : src/tools.cpp includes/tools.hpp
src/configuration.o : src/configuration.cpp includes/configuration.hpp includes/tools.hpp
src/crawler.o : src/crawler.cpp includes/crawler.hpp includes/crawlerIF.hpp\
	includes/analyzPage.hpp includes/setDatabase.hpp includes/configuration.hpp\
	includes/analyzPage.hpp includes/linkWordParser.hpp
src/pageFetcher.o : src/pageFetcher.cpp includes/pageFetcher.hpp\
	includes/analyzPage.hpp includes/crawlerIF.hpp
src/linkParser.o : includes/linkParser.hpp includes/parser.hpp src/linkParser.cpp
src/wordParser.o : includes/wordParser.hpp src/wordParser.cpp includes/parser.hpp
src/linkWordParser.o : includes/linkWordParser.hpp src/linkWordParser.cpp includes/parser.hpp
src/getHTTP.o : includes/getHTTP.hpp src/getHTTP.cpp
src/crawlerQueue.o : includes/crawlerQueue.hpp src/crawlerQueue.cpp includes/configuration.hpp\
	includes/analyzPage.hpp includes/myExceptions.hpp includes/getHTTP.hpp includes/linkParser.hpp
src/matabase.o : includes/matabase.hpp includes/getDatabase.hpp includes/setDatabase.hpp src/matabase.cpp 


src/textUI.o : includes/textUI.hpp src/textUI.cpp includes/QueryUI.hpp
src/queryIFfactory.o : includes/queryIFfactory.hpp src/queryIFfactory.cpp includes/QueryUI.hpp includes/textUI.hpp
src/searchQueryFacilita.o : includes/searchQueryFacilita.hpp src/searchQueryFacilita.cpp includes/searchQueryHandler.hpp includes/QueryUI.hpp
src/simpleQueryHandler.o : includes/simpleQueryHandler.hpp\
	src/simpleQueryHandler.cpp includes/searchQueryHandler.hpp
src/multiQueryHandler.o : includes/multiQueryHandler.hpp\
	src/multiQueryHandler.cpp includes/searchQueryHandler.hpp includes/simpleQueryHandler.hpp
src/smartQueryHandler.o : includes/smartQueryHandler.hpp\
	src/smartQueryHandler.cpp includes/searchQueryHandler.hpp\
	includes/simpleQueryHandler.hpp includes/multiQueryHandler.hpp 
src/clientQueryHandler.o : includes/clientQueryHandler.hpp\
	src/clientQueryHandler.cpp includes/searchQueryHandler.hpp
src/result.o : includes/result.hpp src/result.cpp

src/TCPsocketFile.o : includes/TCPsocketFile.hpp src/TCPsocketFile.cpp
src/TCPserver.o : includes/TCPserver.hpp src/TCPserver.cpp includes/TCPsocketFile.hpp
src/TCPclient.o : includes/TCPclient.hpp src/TCPclient.cpp includes/TCPsocketFile.hpp
src/TCPqueryIF.o : includes/TCPqueryIF.hpp src/TCPqueryIF.cpp includes/TCPsocketFile.hpp includes/TCPserver.hpp


clean :
	$(RM) $(RUNFILES) $(OBJECTS) $(OBJECTS_CLIENT)