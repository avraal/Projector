// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//
// Created by andrew on 15.01.19.
//

#include <thread>
#include "LogManager.hpp"

bool LogManager::canPrintInTerminal = true;
std::string LogManager::fileName = "";

LogManager::LogManager(const std::string &sourceName) : sourceName{sourceName}
{
    canWriteToFile = false;
}
void LogManager::showLog(const ProjectorMessage::Type &type)
{
    for (const auto &l : log)
    {
        if (l.type == type)
        {
            if (type == ProjectorMessage::Type::ERROR || type == ProjectorMessage::Type::WARNING)
            {
                std::cerr << sourceName << '/' << l << std::endl;
            } else
            {
                std::cout << sourceName << '/' << l << std::endl;
            }
        }
    }
}
void LogManager::logging(ProjectorMessage message)
{
    log.push_back(message);
    if (LogManager::canPrintInTerminal)
    {
        std::cout << sourceName << '/' << message << std::endl;
    }

    if (canWriteToFile)
    {
        std::thread saveThr(&LogManager::saveToFile, this, sourceName + "/" + message.toString());
        saveThr.detach();
//        saveToFile("", sourceName + "/" + message.toString());
    }
}

bool LogManager::isCanWriteToFile() const
{
    return canWriteToFile;
}

void LogManager::setCanWriteToFile(bool canWriteToFile)
{
    this->canWriteToFile = canWriteToFile;
}

void LogManager::saveToFile(const std::string &message)
{
    try
    {
        toFile.open(LogManager::fileName, std::ios_base::app | std::ios_base::binary);
        std::lock_guard<std::mutex> lock(writeMutex);
        toFile << message << std::endl;
        toFile.close();
    } catch (const std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }

}
