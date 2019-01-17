// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

//
// Created by andrew on 17.01.19.
//

#ifndef PROJECTOR_GAMESETTINGS_HPP
#define PROJECTOR_GAMESETTINGS_HPP

#include <string>
#include "CONST_DEFINITIONS.hpp"

class GameSettings final
{
public:
    void loadSettings(const std::string &fileName);
    void saveSettings(const std::string &fileName);

    us_int windowWidth;
    us_int windowHeight;
    float maxFPS;
    bool useVSync;
    bool useLimitFPS;
};

#endif //PROJECTOR_GAMESETTINGS_HPP
