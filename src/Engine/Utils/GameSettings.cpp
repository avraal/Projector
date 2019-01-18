// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

//
// Created by andrew on 17.01.19.
//

#include "GameSettings.hpp"
#include "Ini/INIReader.hpp"
#include "Exceptions/GameLoadException.hpp"
#include <memory>
#include <iostream>

void GameSettings::loadSettings(const std::string &fileName)
{
    std::unique_ptr<INIReader> reader = std::make_unique<INIReader>(fileName);
    if (reader->ParseError() < 0)
    {
        throw GameLoadException(fileName + " not found");
    }
    windowWidth = reader->GetInteger("window", "width", 1280);
    windowHeight = reader->GetInteger("window", "height", 720);
    maxFPS = reader->GetReal("window", "maxFPS", 60);
    useVSync = reader->GetBoolean("window", "vsync", true);
    useLimitFPS = reader->GetBoolean("window", "limitedFPS", true);
}
void GameSettings::saveSettings(const std::string &fileName)
{

}