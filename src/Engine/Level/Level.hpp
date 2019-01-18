// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

//
// Created by andrew on 17.01.19.
//

#ifndef PROJECTOR_LEVEL_HPP
#define PROJECTOR_LEVEL_HPP

#include <string>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Color.hpp>

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Utils/Logger/LogManager.hpp"

class Level
{
protected:
    sf::Clock clock;
    sf::View *mainCamera;
    sf::Color backgroundColor;

    std::unique_ptr<LogManager> logManager;

public:
    Level() = delete;
    Level(const std::string &name);
    virtual ~Level() = 0;

    const std::string name;
    float fps;

    virtual void update(sf::RenderWindow &window);
    virtual void prepare();
    virtual void exitProcess();

    virtual void mouseCallbacks(sf::RenderWindow &window, sf::Event &event) = 0;
    virtual void keyboardCallbacks(sf::RenderWindow &window, sf::Event &event) = 0;
    virtual void guiCallbacks(sf::Event &event) = 0;

    void setCamera(sf::View &camera);
    void setBackgroundColor(const sf::Color &backgroundColor);
    const sf::Color &getBackgroundColor() const;
};

#endif //PROJECTOR_LEVEL_HPP