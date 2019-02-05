//
// Created by andrew on 15.01.19.
//

#ifndef PROJECTOR_LOGMANAGER_HPP
#define PROJECTOR_LOGMANAGER_HPP

#include <string>
#include <list>
#include <mutex>
#include <fstream>
#include "../ProjectorMessage.hpp"

class LogManager
{
private:
    const std::string sourceName;
    std::list<ProjectorMessage> log;
    bool canWriteToFile;
    std::mutex writeMutex;
    std::ofstream toFile;

    void saveToFile(const std::string &message);

public:
    explicit LogManager(const std::string &sourceName);
    LogManager() = delete;

    void showLog(const ProjectorMessage::Type &type = ProjectorMessage::Type::ALL);
    void logging(ProjectorMessage message);
    void setCanWriteToFile(bool canWriteToFile);

    bool isCanWriteToFile() const;
    static bool canPrintInTerminal;
    static std::string fileName;
};

#endif //PROJECTOR_LOGERMANAGER_HPP
