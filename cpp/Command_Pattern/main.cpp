#include "includes/greenLight.hpp"
#include "includes/redLight.hpp"
#include "includes/TV.hpp"
#include "includes/LightCommand.hpp"
#include "includes/TVCommand.hpp"
#include "includes/windowCloseCommand.hpp"
#include "includes/remote.hpp"
#include "includes/ShabatClock.hpp"

void eventMenegar(sf::Event const& event, RemoteControl& remote,sf::RenderWindow& window ,GreenLight& greenLight, RedLight& redLight,[[maybe_unused]] TV& tv)
{
    if(event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed){
        remote.setCommand(std::make_shared<WindowCloseCommand>(window));
    }
    if(event.key.code == sf::Keyboard::Add){
        remote.setCommand(std::make_shared<LightOnCommand>(greenLight));
        remote.setCommand(std::make_shared<LightOnCommand>(redLight));
    }
    if(event.key.code == sf::Keyboard::Subtract){
        remote.setCommand(std::make_shared<LightOffCommand>(greenLight));
        remote.setCommand(std::make_shared<LightOffCommand>(redLight));
    }
    if(event.key.code == sf::Keyboard::Up){
        remote.setCommand(std::make_shared<TVplayCommand>(tv));
        remote.setCommand(std::make_shared<LightOffCommand>(greenLight));
    }
    if(event.key.code == sf::Keyboard::Down){
        remote.setCommand(std::make_shared<TVstopPlayCommand>(tv));
    }
}

void exmple1()
{
    sf::RenderWindow window(sf::VideoMode(1300, 800),"");
    window.setFramerateLimit(30);

    GreenLight greenLight(20,20);
    RedLight redLight(1000,20);
    TV tv(500,500);

    sf::Event event;
    while (window.isOpen()){
        while (window.pollEvent(event)){
            if(event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed){
                window.close();
            }
            if(event.key.code == sf::Keyboard::Add){
                greenLight.turnOn();
                redLight.turnOn();
            }
            if(event.key.code == sf::Keyboard::Subtract){
                redLight.turnOff();
                greenLight.turnOff();
            }
        }

        window.clear(sf::Color::Black);
        
        window.draw(greenLight.getDrow());
        window.draw(redLight.getDrow());
        window.draw(tv.getDrow());

        window.display();
    }
    window.close();

    return;
}

void exmple2()
{
    sf::RenderWindow window(sf::VideoMode(1300, 800),"");
    window.setFramerateLimit(30);

    GreenLight greenLight(100,50);
    RedLight redLight(1000,50);
    TV tv(500,500);

    ShabatClock shabatClock;
    RemoteControl remote;

    sf::Event event;
    while (window.isOpen()){
        while (window.pollEvent(event)){
           eventMenegar(event, remote, window, greenLight, redLight, tv);
        }
        
        shabatClock.checkTime(tv, remote);
        remote.buttonWasPressed();

        window.clear(sf::Color::Black);
        window.draw(greenLight.getDrow());
        window.draw(redLight.getDrow());
        window.draw(tv.getDrow());

        window.display();
    }
    window.close();
    return;
}

int main()
{
    // exmple1();
    exmple2();
    return EXIT_SUCCESS;
}
