#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "includes/creators.hpp"
#include "includes/mode.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML first game");
    window.setFramerateLimit(30);

    gm::Player player1(3);
    
    gm::ResourcesManager resourcesManager;
    resourcesManager.insertTexture("./resources/2x1_NSwitch_ArkanoidEternalBattle.jpg", rs::background);
    resourcesManager.insertTexture("./resources/opening_screen.jpg", rs::homescreen);
    resourcesManager.insertTexture("./resources/ball2.png", rs::ball);
    resourcesManager.insertTexture("./resources/paddle.png", rs::paddle);
    resourcesManager.insertTexture("./resources/bricks1.jpg",rs::brick);
    resourcesManager.insertTexture("./resources/exit.png", rs::exit);
    resourcesManager.insertTexture("./resources/play.png", rs::play);
    resourcesManager.insertTexture("./resources/colorful-balloons-flying-sky.jpg", rs::top10);
    resourcesManager.insertTexture("./resources/sand.png", rs::sandClock);
    resourcesManager.insertFunt("./resources/SwipeRaceDemo.ttf", rs::font1);
    resourcesManager.insertFunt("./resources/Sportfield_Varsity-Outline2.otf", rs::font2);
    resourcesManager.insertFunt("./resources/Famouse.ttf", rs::font3);
    resourcesManager.insertFunt("./resources/MiracleFairway.otf", rs::font4);
    
    getPlayerNameMODE(window, player1, resourcesManager);
    do{
        homescreenMODE(window, resourcesManager);
        player1.restart();
    }while(!levelA_MODE(window, player1, resourcesManager));
    topTenMODE(window, player1, resourcesManager);
    window.close();

    return EXIT_SUCCESS;
}
