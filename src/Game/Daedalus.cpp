// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//
// Created by andrew on 22.01.19.
//

#include "Daedalus.hpp"
#include "../Engine/Utils/Ini/INIReader.hpp"
#include "../Engine/Utils/Exceptions/GameLoadResourcesException.hpp"

Daedalus::Daedalus(const std::string &name) : Level(name)
{
    setPositionByGrid = true;
    canCreateOrEdit = true;
    cellSize = {64.f, 64.f};
    currentEditorMode = EditorMode::ADD;
}

void Daedalus::update(sf::RenderWindow &window)
{
    Level::update(window);
    infoFPSLabel->setText("FPS: " + std::to_string((us_int) fps));
    infoObjCountLabel->setText("Object count: " + std::to_string(DrawableEntities.size()));
}

void Daedalus::prepare()
{
    Level::prepare();

    initGui();
    drawGrid(10, 10, cellSize.x, cellSize.y);
}

void Daedalus::exitProcess()
{
    Level::exitProcess();
}

void Daedalus::mouseCallbacks(sf::RenderWindow &window, sf::Event &event)
{
    Level::mouseCallbacks(window, event);

    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if (canCreateOrEdit)
            {
                sf::Vector2f mouseGlobalPosition{window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y})};
                switch (currentEditorMode)
                {
                    case EditorMode::ADD:
                    {
                        unselectedAllEntities();
                        sf::Vector2f position{0.f, 0.f};
                        if (setPositionByGrid)
                        {
                            position.x = std::trunc(mouseGlobalPosition.x / cellSize.x) * cellSize.x;
                            position.y = std::trunc(mouseGlobalPosition.y / cellSize.y) * cellSize.y;
                        } else
                        {
                            position.x = mouseGlobalPosition.x - cellSize.x / 2;
                            position.y = mouseGlobalPosition.y - cellSize.y / 2;
                        }
                        addObject("", position);
                        break;
                    }
                    case EditorMode::SELECT:
                    {
                        unselectedAllEntities();
                        for (auto e : DrawableEntities)
                        {
                            if (onClickOnEntity(e, mouseGlobalPosition))
                            {
                                std::cout << e->getName() << std::endl;
                                std::cout << e->getPosition().x << " : " << e->getPosition().y << std::endl;
                                selectEntity(e);
                                break;
                            }
                        }
                        break;
                    }
                    case EditorMode::MULTISELECT:
                    {
                        for (auto e : DrawableEntities)
                        {
                            if (onClickOnEntity(e, mouseGlobalPosition))
                            {
                                std::cout << e->getName() << std::endl;
                                std::cout << e->getPosition().x << " : " << e->getPosition().y << std::endl;
                                selectEntity(e);
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
}

void Daedalus::keyboardCallbacks(sf::RenderWindow &window, sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {
            case sf::Keyboard::F3:
            {
                infoPanel->setVisible(!infoPanel->isVisible());
                break;
            }
            case sf::Keyboard::Up:
            {
                mainCamera->move(0.0f, -cameraSpeed);
                break;
            }
            case sf::Keyboard::Down:
            {
                mainCamera->move(0.0f, cameraSpeed);
                break;
            }
            case sf::Keyboard::Right:
            {
                mainCamera->move(cameraSpeed, 0.0f);
                break;
            }
            case sf::Keyboard::Left:
            {
                mainCamera->move(-cameraSpeed, 0.0f);
                break;
            }
            case sf::Keyboard::Space:
            {
                for (const auto &e : DrawableEntities)
                {
                    std::cout << e->getName() << std::endl;
                }
                break;
            }
            case sf::Keyboard::LShift:
            {
                if (currentEditorMode == EditorMode::ADD)
                {
                    currentEditorMode = EditorMode::SELECT;
                } else if (currentEditorMode == EditorMode::SELECT)
                {
                    currentEditorMode = EditorMode::MULTISELECT;
                } else
                {
                    currentEditorMode = EditorMode::ADD;
                }
                std::cout << "currentEditorMode: " << currentEditorMode << std::endl;
                break;
            }
        }
    }
}

void Daedalus::guiCallbacks(sf::Event &event)
{
    Level::guiCallbacks(event);
}

Daedalus::~Daedalus()
{

}

void Daedalus::initGui()
{
    infoPanel = tgui::Panel::create({200, 100});
    infoPanel->getRenderer()->setBackgroundColor(sf::Color(0, 0, 0, 128));
    infoPanel->setVisible(true);

    infoFPSLabel = tgui::Label::create();
    infoFPSLabel->getRenderer()->setTextColor(infoTextColor);
    infoFPSLabel->setTextSize(infoTextSize);
    infoFPSLabel->setText("FPS");
    infoFPSLabel->setPosition({0.f, 0.f});

    infoObjCountLabel = tgui::Label::copy(infoFPSLabel);
    infoObjCountLabel->setPosition(0, infoTextSize + infoTextMargin);
    infoObjCountLabel->setText("Object count");

    infoPanel->add(infoFPSLabel);
    infoPanel->add(infoObjCountLabel);
    gui.add(infoPanel);
}

void Daedalus::readSettings(const std::string &fileName)
{
    auto reader = std::make_unique<INIReader>(fileName);
    if (reader->ParseError() < 0)
    {
        throw GameLoadResourcesException(fileName + " not found");
    }
    infoTextSize = reader->GetInteger("infoPanel", "textSize", 12);
    infoTextColor.r = reader->GetInteger("infoPanel", "textColorR", 255);
    infoTextColor.g = reader->GetInteger("infoPanel", "textColorG", 255);
    infoTextColor.b = reader->GetInteger("infoPanel", "textColorB", 255);
    infoTextMargin = reader->GetReal("infoPanel", "margin", 2);
}

bool Daedalus::onClickOnEntity(std::shared_ptr<DrawableEntity> e, const sf::Vector2f &mousePosition) const
{
    return
            mousePosition.x > e->getPosition().x &&
            mousePosition.y > e->getPosition().y &&
            mousePosition.x < e->getPosition().x + e->getBoundingBox().width &&
            mousePosition.y < e->getPosition().y + e->getBoundingBox().height;
}

void Daedalus::selectEntity(std::shared_ptr<DrawableEntity> e)
{
    e->setCanShowBounds(true);
    selectedEntities.emplace_back(e);
}

void Daedalus::unselectedAllEntities()
{
    for (auto e : DrawableEntities)
    {
        e->setCanShowBounds(false);
    }
    selectedEntities.clear();
}
