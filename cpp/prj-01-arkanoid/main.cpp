#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "includes/creators.hpp"

void levelA(sf::RenderWindow& window, gm::Player& player, gm::TextureManager& textureManager)
{
        sf::Sprite Background(textureManager.m_background);
    Background.scale(sf::Vector2f(0.7,1));


    auto paddle = createPaddle(textureManager);

    auto ball = createBall(textureManager, paddle);
    
    auto  bricks = createBricks(3,5,textureManager);

    auto score = createScore(textureManager);

    auto life = createLife(textureManager);

    sf::Event event;

    while (window.isOpen() && !player.isKill()){
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.key.code == sf::Keyboard::Escape){
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
        window.draw(paddle->getDraw());
        window.draw(ball->getDraw());
        window.draw(*score);
        window.draw(*life);

        for(auto brick : bricks){
            if(!brick->isKill()){
                window.draw(brick->getDraw());
            }
        }

        window.display();
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML first game");
    window.setFramerateLimit(30);

    gm::Player player1("myPlayer",3);
    
    gm::TextureManager textureManager("./resources/2x1_NSwitch_ArkanoidEternalBattle.jpg",\
                                    "./resources/ball2.png",\
                                    "./resources/paddle.png",\
                                    "./resources/bricks1.jpg",\
                                    "./resources/SwipeRaceDemo.ttf"
    );
    
    levelA(window, player1, textureManager);

    return EXIT_SUCCESS;
}
