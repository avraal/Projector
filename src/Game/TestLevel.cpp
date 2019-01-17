// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

//
// Created by andrew on 17.01.19.
//

#include <SFML/Window/Event.hpp>
#include "TestLevel.hpp"
TestLevel::TestLevel(const std::string &name) : Level(name)
{
    backgroundColor = sf::Color(42, 76, 61);
}
TestLevel::~TestLevel()
{

}
void TestLevel::update(sf::RenderWindow &window)
{
    Level::update(window);
}
void TestLevel::prepare()
{
    Level::prepare();
}
void TestLevel::exitProcess()
{
    Level::exitProcess();
}
void TestLevel::mouseCallbacks(sf::RenderWindow &window, sf::Event &event)
{

}
void TestLevel::keyboardCallbacks(sf::RenderWindow &window, sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {
            case sf::Keyboard::Escape:
            {
                logManager->logging(ProjectorMessage("Last fps: " + std::to_string(fps), ProjectorMessage::Type::DEBUG));
                window.close();
                break;
            }
        }
    }
}
void TestLevel::guiCallbacks(sf::Event &event)
{

}
