//
// Created by andrew on 17.01.19.
//

#ifndef PROJECTOR_TESTLEVEL_HPP
#define PROJECTOR_TESTLEVEL_HPP

#include "../Engine/Level/Level.hpp"
#include <SFML/Graphics.hpp>
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
protected:
    virtual void readSettings(const std::string &fileName) override;
};

#endif //PROJECTOR_TESTLEVEL_HPP
