#include "../includes/mode.hpp"
#include "../includes/creators.hpp"

bool gm::checkValid(char const c)
{
    return isdigit(c) || isalpha(c);
}

void gm::getPlayerNameMODE(sf::RenderWindow& window, gm::Player& player, gm::ResourcesManager& resourcesManager)
{
    sf::Sprite Background(resourcesManager.getTexture(rs::homescreen));
    Background.scale(sf::Vector2f(0.7,1));
    
    gm::TextObject enterName(100, 100);
    enterName.set_font(resourcesManager.getFont(rs::font1));
    enterName.set_character_size(40);
    enterName.setMessage("Welcome to the game!\n\n\tEnter your name :");

    gm::TextObject name(SCREEN_WIDTH/4, SCREEN_HEIGHT*0.6);
    name.set_font(resourcesManager.getFont(rs::font2));
    name.set_character_size(80);
    auto color = sf::Color::Yellow;
    name.set_Color(color);

    int i =0;
    std::string output;
    sf::Event event;
    while(window.isOpen()){
        color = sf::Color((i+50)%255,i%255,(i+200)%255);
        ++i;
        enterName.set_Color(color);
        window.clear(sf::Color::White);
        window.draw(Background);
        window.draw(enterName.getDraw());
        window.draw(name.getDraw());
        window.display();

        while (window.pollEvent(event)){
            if(event.type == sf::Event::TextEntered){
                if(event.text.unicode < 128){
                    char c = static_cast<char>(event.text.unicode);
                    if(checkValid(c)){
                        output.push_back(c);
                        name.setMessage(output);
                    }
                }
            }
            if(event.key.code == sf::Keyboard::Enter && output.size()>3){
                player.setName(output);
                return;
            }
        }
    }
}

void gm::topTenMODE(sf::RenderWindow& window, gm::Player& player, gm::ResourcesManager& resourcesManager)
{
    sf::Sprite Background(resourcesManager.getTexture(rs::top10));
    Background.scale(sf::Vector2f(0.7,1));
    gm::BestPlayers bestPlayers("top10.dat", resourcesManager);
    sf::Event event;
    sf::Clock clock;
    while(window.isOpen() && 0){// clock.getElapsedTime() > sf::milliseconds(5)){
        window.clear(sf::Color::White);
        window.draw(Background);
        window.draw(bestPlayers.getDraw());
        window.display();
    }

    bestPlayers.manageHighScores(player);
    while (window.isOpen()){
        window.clear(sf::Color::White);
        window.draw(Background);
        window.draw(bestPlayers.getDraw());
        window.display();

        while(window.waitEvent(event)){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                return;
            }
        }     
    }
}

void gm::homescreenMODE(sf::RenderWindow& window, gm::Player& player, gm::ResourcesManager& resourcesManager)
{
    sf::Sprite Background(resourcesManager.getTexture(rs::homescreen));
    Background.scale(sf::Vector2f(0.7,1));

    sf::Sprite playIcon(resourcesManager.getTexture(rs::play));
    sf::Sprite exitIcon(resourcesManager.getTexture(rs::exit));
    auto playRect = resourcesManager.getTexture(rs::play).getSize();
    auto exitRect = resourcesManager.getTexture(rs::exit).getSize();

    playIcon.setPosition((SCREEN_WIDTH/4)-(playRect.x/2),(SCREEN_HEIGHT/2)-(playRect.y/2));
    playIcon.setColor(sf::Color::Green);
    exitIcon.setPosition((SCREEN_WIDTH/4)*3-(exitRect.x/2),(SCREEN_HEIGHT/2)-(exitRect.y/2));

    sf::Event event;
    while (window.isOpen()){
        window.clear(sf::Color::White);
        window.draw(Background);
        window.draw(exitIcon);
        window.draw(playIcon);
        window.display();
        

        while(window.waitEvent(event)){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                sf::Vector2i position = sf::Mouse::getPosition(window);
                if(playIcon.getGlobalBounds().contains(position.x, position.y)){
                    return;
                }else if(exitIcon.getGlobalBounds().contains(position.x, position.y)){
                    window.close();
                }
            }
        }        
    }
}

bool gm::levelA_MODE(sf::RenderWindow& window, gm::Player& player, gm::ResourcesManager& resourcesManager)
{
    sf::Sprite Background(resourcesManager.getTexture(rs::background));
    Background.scale(sf::Vector2f(0.7,1));

    auto paddle = createPaddle(resourcesManager);
    auto ball = createBall(resourcesManager, paddle);
    auto bricks = createBricks(3,12,resourcesManager);
    auto score = std::move(createScore(resourcesManager));
    auto life = std::move(createLife(resourcesManager));

    sf::Event event;
    while (window.isOpen() && !player.isKill() && bricks.size()){
        while (window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            if(event.key.code == sf::Keyboard::Escape){
                return false;
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
    return true;
}
