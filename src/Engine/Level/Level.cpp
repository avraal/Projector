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
    backgroundColor = sf::Color(42, 76, 61);
    cameraSpeed = 4.f;
    canCameraScroll = true;
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

    for (auto e : DrawableEntities)
    {
        e->update();
        window.draw(*e);
    }

    for (const auto &g : Grid)
    {
        sf::Vertex line[] = {g.first, g.second};
        window.draw(line, 2, sf::Lines);
    }
}
void Level::prepare()
{
    logManager->logging(ProjectorMessage("load level " + name, ProjectorMessage::Type::DEBUG));
    const std::string settingsFileName = "Resources/Settings/" + name + ".ini";
    readSettings(settingsFileName);
    logManager->logging(ProjectorMessage("level load settings from " + settingsFileName, ProjectorMessage::Type::DEBUG));
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
void Level::guiCallbacks(sf::Event &event)
{
    gui.handleEvent(event);
}
void Level::initGui(sf::RenderWindow &window)
{
    gui.setTarget(window);
}
void Level::drawGrid(int gWidth, int gHeight, float tWidth, float tHeight)
{
    sf::Color lineColor = sf::Color::White;
    for (int i = 0; i <= gWidth; i++)
    {
        sf::Vertex line[] =
                {
                    sf::Vertex({0, i * tHeight}, lineColor),
                    sf::Vertex({gHeight * tWidth, i * tHeight}, lineColor)
                };
        Grid.emplace_back(std::pair<sf::Vertex, sf::Vertex>(line[0], line[1]));
    }

    for (int j = 0; j <= gHeight; j++)
    {
        sf::Vertex line[] =
                {
                    sf::Vertex({j * tWidth, 0}, lineColor),
                    sf::Vertex({j * tWidth, gWidth * tHeight}, lineColor)
                };
        Grid.emplace_back(std::pair<sf::Vertex, sf::Vertex>(line[0], line[1]));
    }
}
void Level::zoomViewAt(sf::RenderWindow &window, sf::Vector2i pixel, float zoom)
{
    const sf::Vector2f beforeCoord{window.mapPixelToCoords(pixel)};
    mainCamera->zoom(zoom);
    const sf::Vector2f afterCoord{window.mapPixelToCoords(pixel)};
    const sf::Vector2f offsetCoord{beforeCoord - afterCoord};
    mainCamera->move(offsetCoord);
}
void Level::mouseCallbacks(sf::RenderWindow &window, sf::Event &event)
{
    if (event.type == sf::Event::MouseWheelScrolled)
    {
        if (canCameraScroll)
        {
            zoomViewAt(window, {event.mouseWheelScroll.x, event.mouseWheelScroll.y}, event.mouseWheelScroll.delta > 0 ? (1.0f / 1.1f) : 1.1f);
        }
    }
}

void Level::addObject(std::string name, sf::Vector2f position)
{
    ul_int count = 0;
    if (name.empty())
    {
        name = "obj";
    }
    std::string _t_name = name;
    for (const auto &e : DrawableEntities)
    {
        if (e->getName() == _t_name)
        {
            _t_name = name + "(" + std::to_string(++count) + ")";
        }
    }

    auto entity = CreateEntity<DrawableEntity>(_t_name);
    entity->prepare();
    entity->setPosition(position);
    DrawableEntities.push_back(entity);
}
const std::string &Level::getName() const
{
    return name;
}
