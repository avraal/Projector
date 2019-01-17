//
// Created by andrew on 15.01.19.
//

#include "Game.hpp"
#include <SFML/Window/Event.hpp>
#include "../Engine/Utils/getClassName.hpp"
#include "../Engine/Utils/Exceptions/GameLoadException.hpp"
#include "../Engine/Utils/Exceptions/GameRuntimeException.hpp"
#include "TestLevel.hpp"
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

    std::shared_ptr<TestLevel> testLevel = std::make_shared<TestLevel>("TestLevel");
    testLevel->prepare();
    levelManager->registerLevel(testLevel);
}
void Game::run()
{
    logManager->logging(ProjectorMessage("start game", ProjectorMessage::Type::MESSAGE));

    window.create(sf::VideoMode(gameSettings->windowWidth, gameSettings->windowHeight), title);
    mainCamera = window.getView();
    mainCamera.setCenter(gameSettings->windowWidth / 4, gameSettings->windowHeight / 4);

    window.setKeyRepeatEnabled(true);
    window.setVerticalSyncEnabled(gameSettings->useVSync);
    if (gameSettings->useLimitFPS)
    {
        window.setFramerateLimit(gameSettings->maxFPS);
    }

    currentLevel = levelManager->loadLevel("TestLevel");

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
            window.display();
            currentLevel->update(window);
        } catch (const GameRuntimeException &ex)
        {
            logManager->logging(ProjectorMessage(ex.what(), ProjectorMessage::Type::ERROR));
            gameCanRun = false;
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
