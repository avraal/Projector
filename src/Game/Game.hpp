// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

//
// Created by andrew on 15.01.19.
//

#ifndef PROJECTOR_GAME_HPP
#define PROJECTOR_GAME_HPP

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Engine/Utils/ProjectorMessage.hpp"
#include "../Engine/Utils/Logger/LogManager.hpp"
#include "../Engine/Utils/GameSettings.hpp"
#include "../Engine/Level/LevelManager.hpp"

class Game final
{
private:
    std::string title;
    sf::RenderWindow window;
    sf::View mainCamera;
    std::unique_ptr<LogManager> logManager;
    std::unique_ptr<GameSettings> gameSettings;
    std::unique_ptr<LevelManager> levelManager;
    std::shared_ptr<Level> currentLevel;
    bool gameCanRun;

public:
    Game() = delete;
    explicit Game(const std::string &title);
    ~Game();

    void prepare(); //load default values and resources
    void run(); //start game
    void exitProcess(); //precessing results after game (show errors etc)

};

#endif //PROJECTOR_GAME_HPP
