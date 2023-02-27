#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "includes/creators.hpp"

void levelA(sf::RenderWindow& window, gm::Player& player, gm::ResourcesManager& resourcesManager)
{
    sf::Sprite Background(resourcesManager.m_background);
    Background.scale(sf::Vector2f(0.7,1));

    auto paddle = createPaddle(resourcesManager);
    auto ball = createBall(resourcesManager, paddle);
    auto bricks = createBricks(3,12,resourcesManager);
    auto score = std::move(createScore(resourcesManager));
    auto life = std::move(createLife(resourcesManager));

    sf::Event event;
    while (window.isOpen() && !player.isKill()){
        while (window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            if(event.key.code == sf::Keyboard::Escape){
                window.close();
            }
        }

        gm::keystrokeManager(paddle ,ball);
        gm::collisionsManager(paddle ,ball ,bricks ,player);

        score->setString(score->getString().substring(0,16) + std::to_string(player.getScore()));
        life->setString(life->getString().substring(0,7) + std::to_string(player.getLife()));
        paddle->move();
        ball->move();
        
        window.clear(sf::Color::White);
        window.draw(Background);
        window.draw(*score);
        window.draw(*life);
        window.draw(paddle->getDraw());
        window.draw(ball->getDraw());
        for(auto brick : bricks){
            window.draw(brick->getDraw());
        }
        window.display();
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML first game");
    window.setFramerateLimit(30);

    gm::Player player1("myPlayer",3);
    
    gm::ResourcesManager resourcesManager("./resources/2x1_NSwitch_ArkanoidEternalBattle.jpg",\
                                    "./resources/ball2.png",\
                                    "./resources/paddle.png",\
                                    "./resources/bricks1.jpg",\
                                    "./resources/SwipeRaceDemo.ttf"
    );
    
    levelA(window, player1, resourcesManager);

    return EXIT_SUCCESS;
}
