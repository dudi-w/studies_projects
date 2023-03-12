#include <regex>
#include <memory>
#include "../includes/mode.hpp"
#include "../includes/creators.hpp"

uint indestructBrickCount(std::unordered_set<std::shared_ptr<gm::ConstObject>> bricks)
{
    uint count = 0;
    auto it = bricks.cbegin();
    while(it != bricks.cend()){
        if(auto ptr = std::dynamic_pointer_cast<gm::IndestructBrick>(*it)){
            ++count;
        }
        ++it;
    }
    return count;
}

bool checkValid(std::string const& input)
{
    int count = 0;
    for(auto c : input){
        if(c!= 32){
            ++count;
        }
        if(count>3){
            return true;
        }
    }
    return false;
}

bool is_input_valid(const char input)
{
    return std::regex_match(std::string(1,input), std::regex("[!-+--~]"));
}

void gm::restartGame(gm::Player& player, gm::ResourcesManager& resourcesManager)
{
    player.restart();
    resourcesManager.restartQeueu();
}

bool gm::runGame(sf::RenderWindow& window, gm::Player& player, gm::ResourcesManager& resourcesManager){
    while(!resourcesManager.isEndGame()){
        if(!gameMODE(window, player, resourcesManager)){
            return false;
        }
    }
    return !topTenMODE(window, player, resourcesManager);

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

    uint i =0;
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
                    if(is_input_valid(c)){
                        output.push_back(c);
                        name.setMessage(output);
                    }
                }
            }
            if(event.key.code == sf::Keyboard::Enter && checkValid(output)){
                player.setName(output);
                return;
            }
        }
    }
}

bool gm::topTenMODE(sf::RenderWindow& window, gm::Player& player, gm::ResourcesManager& resourcesManager)
{
    sf::Sprite Background(resourcesManager.getTexture(rs::top10));
    Background.scale(sf::Vector2f(0.7,1));
    gm::BestPlayers bestPlayers("./resources/top10.dat", resourcesManager);
    sf::Sprite sandClock(resourcesManager.getTexture(rs::sandClock));
    sandClock.setOrigin(sandClock.getTextureRect().width/2, sandClock.getTextureRect().height/2);
    sandClock.setPosition(SCREEN_WIDTH/2 ,SCREEN_HEIGHT/2);
    
    sf::Event event;
    sf::Clock clock;
    clock.restart();
    while(window.isOpen() && clock.getElapsedTime() < sf::seconds(2.5)){
        sandClock.rotate(5);
        window.clear(sf::Color::White);
        window.draw(Background);
        window.draw(sandClock);
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
            if(event.type == sf::Event::KeyPressed){
                return true;
            }
        }     
    }
    return false;
}

void gm::homescreenMODE(sf::RenderWindow& window, gm::ResourcesManager& resourcesManager)
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
                    return;
                }
            }
        }        
    }
}

bool gm::gameMODE(sf::RenderWindow& window, gm::Player& player, gm::ResourcesManager& resourcesManager)
{
    sf::Sprite Background(resourcesManager.getTexture(rs::background));
    Background.scale(sf::Vector2f(0.7,1));

    auto paddle = createPaddle(resourcesManager);
    auto ball = createBall(resourcesManager, paddle);
    auto bricks = createBricks(resourcesManager);
    auto score = std::move(createScore(resourcesManager));
    auto life = std::move(createLife(resourcesManager));
    
    uint indestructBricks = indestructBrickCount(bricks);
    sf::Event event;
    while (window.isOpen() && !player.isKill() && bricks.size() - indestructBricks){
        while (window.pollEvent(event)){
            if(event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed){
                return false;
            }
            if(event.key.code == sf::Keyboard::Add){
                while(window.waitEvent(event)){
                    if(event.key.code == sf::Keyboard::Subtract){
                        return true;
                    }
                }
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
