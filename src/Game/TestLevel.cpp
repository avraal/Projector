// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//
// Created by andrew on 17.01.19.
//

#include <SFML/Window/Event.hpp>
#include "TestLevel.hpp"
#include "../Engine/Utils/Exceptions/GameRuntimeException.hpp"
TestLevel::TestLevel(const std::string &name) : Level(name)
{
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
    addObject(std::__cxx11::string(), sf::Vector2f());
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
            case sf::Keyboard::R:
            {
                for (auto d : DrawableEntities)
                {
                    d->rotate(45.f);
                }
                break;
            }
            case sf::Keyboard::Space:
            {
                for (auto d : DrawableEntities)
                {
                    d->toggleCanShowBounds();
                }
                break;
            }
        }
    }
}
void TestLevel::guiCallbacks(sf::Event &event)
{
    Level::guiCallbacks(event);
}
void TestLevel::readSettings(const std::string &fileName)
{

}
