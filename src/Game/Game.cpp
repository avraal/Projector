// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//
// Created by andrew on 15.01.19.
//

#include "Game.hpp"
#include <SFML/Window/Event.hpp>
#include "../Engine/Utils/getClassName.hpp"
#include "../Engine/Utils/Exceptions/GameLoadResourcesException.hpp"
#include "../Engine/Utils/Exceptions/GameRuntimeException.hpp"
#include "TestLevel.hpp"
#include "Daedalus.hpp"
Game::Game(const std::string &title) : title{title}
{
    logManager = std::make_unique<LogManager>(getClassName<Game>());
    levelManager = std::make_unique<LevelManager>();
    gameSettings = std::make_unique<GameSettings>();
    gameCanRun = true;
}
void Game::prepare()
{
    logManager->logging(ProjectorMessage("prepare", ProjectorMessage::Type::MESSAGE));
    const std::string fileName = "Resources/Settings/test.ini";
    logManager->logging(ProjectorMessage("load settings from " + fileName, ProjectorMessage::Type::DEBUG));
    gameSettings->loadSettings(fileName);

    auto testLevel = std::make_shared<TestLevel>("TestLevel");
    auto daedalus = std::make_shared<Daedalus>("Daedalus");
    levelManager->registerLevel(testLevel);
    levelManager->registerLevel(daedalus);
    daedalus->prepare();
}
void Game::run()
{
    logManager->logging(ProjectorMessage("start game", ProjectorMessage::Type::MESSAGE));

    window.create(sf::VideoMode(gameSettings->windowWidth, gameSettings->windowHeight), title);
    mainCamera = window.getView();
    mainCamera.setCenter(gameSettings->windowWidth / 2, gameSettings->windowHeight / 2);

    window.setKeyRepeatEnabled(true);
    window.setVerticalSyncEnabled(gameSettings->useVSync);
    if (gameSettings->useLimitFPS)
    {
        window.setFramerateLimit(gameSettings->maxFPS);
    }
    currentLevel = levelManager->loadLevel("Daedalus");
    currentLevel->initGui(window);
    currentLevel->setCamera(mainCamera);

    while (gameCanRun && window.isOpen())
    {
        try
        {
            sf::Event event;
            window.clear(currentLevel->getBackgroundColor());

            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                    gameCanRun = false;
                }

                currentLevel->mouseCallbacks(window, event);
                currentLevel->keyboardCallbacks(window, event);
                currentLevel->guiCallbacks(event);
            }
            window.setView(mainCamera);
            currentLevel->update(window);
            currentLevel->gui.draw();
            window.display();
        } catch (const GameRuntimeException &ex)
        {
            logManager->logging(ProjectorMessage(ex.what(), ProjectorMessage::Type::ERROR));
            gameCanRun = false;
        } catch (const GameLoadResourcesException &ex)
        {
            logManager->logging(ProjectorMessage(ex.what(), ProjectorMessage::Type::ERROR));
        }
    }

    logManager->logging(ProjectorMessage("end \"run\"", ProjectorMessage::Type::MESSAGE));
}
void Game::exitProcess()
{
    currentLevel->exitProcess();
    logManager->logging(ProjectorMessage("exiting...", ProjectorMessage::Type::DEBUG));
    logManager->showLog();
}
Game::~Game()
{

}
