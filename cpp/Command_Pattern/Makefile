CXX = g++

CC = $(CXX)

CXXFLAGS = -std=c++17 -Wall -pedantic
CXXFLAGS += -Werror
CXXFLAGS += -Wextra

CXXFLAGS += -g3

LDLIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

main : main.o includes/command.hpp\
				includes/light.hpp\
				includes/greenLight.hpp\
				includes/redLight.hpp\
				includes/LightCommand.hpp\
				includes/remote.hpp\
				includes/ShabatClock.hpp\
				includes/TV.hpp\
				includes/TVCommand.hpp\
				includes/windowCloseCommand.hpp


clean :
	$(RM) main *.o