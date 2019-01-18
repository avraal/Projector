//
// Created by andrew on 17.01.19.
//

#ifndef PROJECTOR_LEVELMANAGER_HPP
#define PROJECTOR_LEVELMANAGER_HPP

#include <map>
#include <memory>
#include "Level.hpp"

class LevelManager final
{
private:
    std::map<std::string, std::shared_ptr<Level>> levels;

public:
    void registerLevel(std::shared_ptr<Level> level);
    std::shared_ptr<Level> loadLevel(const std::string &name);
};

#endif //PROJECTOR_LEVELMANAGER_HPP
