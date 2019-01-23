//
// Created by andrew on 17.01.19.
//

#ifndef PROJECTOR_LEVEL_HPP
#define PROJECTOR_LEVEL_HPP

#include <string>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Color.hpp>
#include <TGUI/TGUI.hpp>
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Utils/Logger/LogManager.hpp"
#include "../Entity/DrawableEntity.hpp"

class Level
{
protected:
    sf::Clock clock;
    sf::View *mainCamera;
    sf::Color backgroundColor;

    std::unique_ptr<LogManager> logManager;

    std::vector<std::shared_ptr<DrawableEntity>> DrawableEntities;
    std::vector<std::pair<sf::Vertex, sf::Vertex>> Grid;

    template <typename T>
    static std::shared_ptr<T> CreateEntity(const std::string &name = "")
    {
        auto entity = std::make_shared<T>(name);
        return entity;
    }

    static void DestroyEntity(ul_int id)
    {

    }

    static void DestroyEntity(const std::string &name)
    {

    }

    void addObject(std::string name, sf::Vector2f position = {0.f, 0.f});

    void drawGrid(int gWidth = 10, int gHeight = 10, float tWidth = 64.f, float tHeight = 64.f);
    void zoomViewAt(sf::RenderWindow &window, sf::Vector2i pixel, float zoom);
    float cameraSpeed;
    bool canCameraScroll;
    virtual void readSettings(const std::string &fileName) = 0;

public:
    Level() = delete;
    Level(const std::string &name);
    virtual ~Level() = 0;

    const std::string name;
    float fps;
    tgui::Gui gui;

    virtual void update(sf::RenderWindow &window);
    virtual void prepare();
    virtual void exitProcess();

    void initGui(sf::RenderWindow &window);

    virtual void mouseCallbacks(sf::RenderWindow &window, sf::Event &event);
    virtual void keyboardCallbacks(sf::RenderWindow &window, sf::Event &event) = 0;
    virtual void guiCallbacks(sf::Event &event);

    void setCamera(sf::View &camera);
    void setBackgroundColor(const sf::Color &backgroundColor);
    const sf::Color &getBackgroundColor() const;
    const std::string &getName() const;
};

#endif //PROJECTOR_LEVEL_HPP
