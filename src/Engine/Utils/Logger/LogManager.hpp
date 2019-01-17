// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

//
// Created by andrew on 15.01.19.
//

#ifndef PROJECTOR_LOGMANAGER_HPP
#define PROJECTOR_LOGMANAGER_HPP

#include <string>
#include <list>
#include "../ProjectorMessage.hpp"

class LogManager
{
private:
    const std::string sourceName;
    std::list<ProjectorMessage> log;

public:
    explicit LogManager(const std::string &sourceName);
    LogManager() = delete;

    void showLog();
    void showLogByType(const ProjectorMessage::Type &type);
    void logging(ProjectorMessage message);
};

#endif //PROJECTOR_LOGERMANAGER_HPP
