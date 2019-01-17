// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

//
// Created by andrew on 17.01.19.
//

#ifndef PROJECTOR_TESTLEVEL_HPP
#define PROJECTOR_TESTLEVEL_HPP

#include "../Engine/Level/Level.hpp"

class TestLevel : public Level
{
public:
    TestLevel(const std::string &name);
    virtual ~TestLevel();
    virtual void update(sf::RenderWindow &window) override;
    virtual void prepare() override;
    virtual void exitProcess() override;

    virtual void mouseCallbacks(sf::RenderWindow &window, sf::Event &event) override;
    virtual void keyboardCallbacks(sf::RenderWindow &window, sf::Event &event) override;
    virtual void guiCallbacks(sf::Event &event) override;
};

#endif //PROJECTOR_TESTLEVEL_HPP
