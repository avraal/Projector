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

    void showLog(const ProjectorMessage::Type &type = ProjectorMessage::Type::ALL);
    void logging(ProjectorMessage message);

    static bool canPrintInTerminal;
};

#endif //PROJECTOR_LOGERMANAGER_HPP
