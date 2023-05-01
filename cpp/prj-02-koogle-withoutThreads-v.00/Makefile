CXX = g++

CC = $(CXX)

CXXFLAGS = -std=c++17 -Wall -pedantic
CXXFLAGS += -Werror
CXXFLAGS += -Wextra
CXXFLAGS += -g3

CPPFLAGS = -I ./includes -I ./includes/crawler -I ./includes/parsers -I ./includes/queryHandler -I ./src -I ./src/crawler -I ./src/parsers -I ./src/queryHandler

LDLIBS += -lcurlpp -lcurl -lgumbo

OBJECTS = mainServer.o src/configuration.o src/tools.o src/request.o\
		src/parsers/linkParser.o src/parsers/wordParser.o src/parsers/linkWordParser.o src/matabase.o src/getHTTP.o\
		src/pageFetcher.o src/crawler/crawlerQueue.o src/crawler/crawler.o src/basePage.o\
		src/analyzPage.o src/result.o src/queryIFfactory.o src/textUI.o src/queryHandler/multiQueryHandler.o\
		src/queryHandler/simpleQueryHandler.o src/queryHandler/smartQueryHandler.o src/searchQueryFacilita.o src/TCPqueryIF.o\
		src/TCPsocketFile.o src/TCPserver.o

OBJECTS_CLIENT = mainClient.o src/queryHandler/clientQueryHandler.o src/textUI.o\
	src/result.o src/searchQueryFacilita.o src/request.o\
	src/tools.o src/TCPsocketFile.o src/TCPclient.o

RUNFILES = mainServer mainClient

all : $(RUNFILES)

mainServer : $(OBJECTS)
mainClient : $(OBJECTS_CLIENT)

mainServer.o : mainServer.cpp
mainClient.o : mainClient.cpp

src/request.o : src/request.cpp includes/request.hpp includes/requestIF.hpp

src/analyzPage.o : src/analyzPage.cpp includes/analyzPage.hpp includes/basePage.hpp
src/basePage.o :  src/basePage.cpp includes/basePage.hpp includes/basePage.hpp

src/tools.o : src/tools.cpp includes/tools.hpp
src/configuration.o : src/configuration.cpp includes/configuration.hpp includes/tools.hpp
src/crawler/crawler.o : src/crawler/crawler.cpp includes/crawler/crawler.hpp includes/crawler/crawlerIF.hpp\
	includes/analyzPage.hpp includes/setDatabase.hpp includes/configuration.hpp\
	includes/analyzPage.hpp includes/parsers/linkWordParser.hpp
src/pageFetcher.o : src/pageFetcher.cpp includes/pageFetcher.hpp\
	includes/analyzPage.hpp includes/crawler/crawlerIF.hpp
src/parsers/linkParser.o : includes/parsers/linkParser.hpp includes/crawler/crawlerQueue.hpp src/parsers/linkParser.cpp
src/parsers/wordParser.o : includes/parsers/wordParser.hpp src/parsers/wordParser.cpp includes/crawler/crawlerQueue.hpp
src/parsers/linkWordParser.o : includes/parsers/linkWordParser.hpp src/parsers/linkWordParser.cpp includes/crawler/crawlerQueue.hpp
src/getHTTP.o : includes/getHTTP.hpp src/getHTTP.cpp
src/crawler/crawlerQueue.o : includes/crawler/crawlerQueue.hpp src/crawler/crawlerQueue.cpp includes/configuration.hpp\
	includes/analyzPage.hpp includes/myExceptions.hpp includes/getHTTP.hpp includes/parsers/linkParser.hpp
src/matabase.o : includes/matabase.hpp includes/getDatabase.hpp includes/setDatabase.hpp src/matabase.cpp 


src/textUI.o : includes/textUI.hpp src/textUI.cpp includes/QueryBuilderIF.hpp
src/queryIFfactory.o : includes/queryBuilderFactory.hpp src/queryIFfactory.cpp\
	includes/QueryBuilderIF.hpp includes/textUI.hpp
src/searchQueryFacilita.o : includes/searchQueryFacilita.hpp src/searchQueryFacilita.cpp\
	includes/queryHandler/searchQueryHandler.hpp includes/QueryBuilderIF.hpp
src/queryHandler/simpleQueryHandler.o : includes/queryHandler/simpleQueryHandler.hpp\
	src/queryHandler/simpleQueryHandler.cpp includes/queryHandler/searchQueryHandler.hpp
src/queryHandler/multiQueryHandler.o : includes/queryHandler/multiQueryHandler.hpp\
	src/queryHandler/multiQueryHandler.cpp includes/queryHandler/searchQueryHandler.hpp\
	includes/queryHandler/simpleQueryHandler.hpp
src/queryHandler/smartQueryHandler.o : includes/queryHandler/smartQueryHandler.hpp\
	src/queryHandler/smartQueryHandler.cpp includes/queryHandler/searchQueryHandler.hpp\
	includes/queryHandler/simpleQueryHandler.hpp includes/queryHandler/multiQueryHandler.hpp 
src/queryHandler/clientQueryHandler.o : includes/queryHandler/clientQueryHandler.hpp\
	src/queryHandler/clientQueryHandler.cpp includes/queryHandler/searchQueryHandler.hpp
src/result.o : includes/result.hpp src/result.cpp

src/TCPsocketFile.o : includes/TCPsocketFile.hpp src/TCPsocketFile.cpp includes/tools.hpp includes/myExceptions.hpp
src/TCPserver.o : includes/TCPserver.hpp src/TCPserver.cpp includes/TCPsocketFile.hpp
src/TCPclient.o : includes/TCPclient.hpp src/TCPclient.cpp includes/TCPsocketFile.hpp
src/TCPqueryIF.o : includes/TCPqueryIF.hpp src/TCPqueryIF.cpp includes/TCPsocketFile.hpp includes/TCPserver.hpp


clean :
	$(RM) $(RUNFILES) $(OBJECTS) $(OBJECTS_CLIENT)