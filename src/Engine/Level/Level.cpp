// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//
// Created by andrew on 17.01.19.
//

#include "Level.hpp"
#include "../Utils/getClassName.hpp"
Level::Level(const std::string &name) : name{name}, backgroundColor{sf::Color::Black}
{
    logManager = std::make_unique<LogManager>(getClassName<Level>());
}
Level::~Level()
{
}
const sf::Color &Level::getBackgroundColor() const
{
    return backgroundColor;
}
void Level::setBackgroundColor(const sf::Color &backgroundColor)
{
    this->backgroundColor = backgroundColor;
}
void Level::update(sf::RenderWindow &window)
{
    float currentTime = clock.restart().asSeconds();
    fps = 1.f / currentTime;
    for (auto e : Entities)
    {
        e->update();
    }

    for (auto e : DrawableEntities)
    {
        window.draw(*e);
    }
}
void Level::prepare()
{
    logManager->logging(ProjectorMessage("load level " + name, ProjectorMessage::Type::DEBUG));
    for (auto e : Entities)
    {
        e->prepare();
    }

}
void Level::exitProcess()
{
    logManager->logging(ProjectorMessage("exit level " + name, ProjectorMessage::Type::DEBUG));
    logManager->showLog();
}
void Level::setCamera(sf::View &camera)
{
    mainCamera = &camera;
}
