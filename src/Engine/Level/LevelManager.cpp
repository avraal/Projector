// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

//
// Created by andrew on 17.01.19.
//

#include "LevelManager.hpp"
#include "../Utils/Exceptions/LevelException.hpp"
void LevelManager::registerLevel(std::shared_ptr<Level> level)
{
    if (level)
    {
        levels.insert({level->name, level});
    } else
    {
        throw LevelException("level is nullptr");
    }
}
std::shared_ptr<Level> LevelManager::loadLevel(const std::string &name)
{
    if (levels.find(name) == levels.end())
    {
        throw LevelException("level " + name + " not found");
    }
    return levels.find(name)->second;
}
