#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "includes/creators.hpp"
#include "includes/mode.hpp"

int main()
{
    gm::Player player1(3);
    gm::ResourcesManager resourcesManager;

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Arkanoid game");
    window.setFramerateLimit(30);

    getPlayerNameMODE(window, player1, resourcesManager);
    do{
        homescreenMODE(window, resourcesManager);
        restartGame(player1, resourcesManager);
    }while(window.isOpen() && !runGame(window, player1, resourcesManager));
    window.close();

    return EXIT_SUCCESS;
}

