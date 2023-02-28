CXX = g++

CC = $(CXX)

CXXFLAGS = -std=c++17 -Wall -pedantic
# CXXFLAGS += -Werror
CXXFLAGS += -Wextra

CXXFLAGS += -g3

# CPPFLAGS = -I ./includes  -I ./src

LDLIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

main : main.o\
		src/resourcesManager.o\
		src/player.o\
		src/creators.o\
		src/spriteObject.o\
		src/textObject.o\
		src/life.o\
		src/platform.o\
		src/ball.o\
		src/moveObject.o\
		src/constObject.o\
		src/ballBrickCollision.o\
		src/ballPaddleCollision.o\
		src/collisionsManager.o\
		src/eventManager.o\
		includes/definitions.hpp

main.o : main.cpp includes/definitions.hpp

src/life.o : src/life.cpp includes/life.hpp

src/player.o : src/player.cpp includes/player.hpp includes/life.hpp

src/creators.o : includes/creators.hpp src/creators.cpp

src/spriteObject.o : src/spriteObject.cpp includes/spriteObject.hpp includes/object.hpp

src/platform.o : src/platform.cpp\
				includes/platform.hpp\
				includes/object.hpp\
				includes/spriteObject.hpp\
				includes/moveObject.hpp

src/ballBrickCollision.o : src/ballBrickCollision.cpp includes/ballBrickCollision.hpp

src/ballPaddleCollision.o : src/ballPaddleCollision.cpp includes/ballPaddleCollision.hpp

src/collisionsManager.o : src/collisionsManager.cpp includes/collisionsManager.hpp

src/eventManager.o : src/eventManager.cpp includes/eventManager.hpp

src/resourcesManager.o : includes/resourcesManager.hpp src/resourcesManager.cpp

src/textObject.o : src/textObject.cpp includes/textObject.hpp 


clean :
	$(RM) main *.o */*.o