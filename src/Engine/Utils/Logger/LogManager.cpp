//
// Created by andrew on 15.01.19.
//

#include "LogManager.hpp"
LogManager::LogManager(const std::string &sourceName) : sourceName{sourceName}
{

}
void LogManager::showLog()
{
    for (const auto &l : log)
    {
        std::cout << sourceName + '/';
        std::cout << l << std::endl;
    }
}
void LogManager::showLogByType(const ProjectorMessage::Type &type)
{
    for (const auto &l : log)
    {
        if (l.type == type)
        {
            std::cout << sourceName + '/';
            std::cout << l << std::endl;
        }
    }
}
void LogManager::logging(ProjectorMessage message)
{
    log.push_back(message);
}