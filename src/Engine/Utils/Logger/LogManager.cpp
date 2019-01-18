// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//
// Created by andrew on 15.01.19.
//

#include "LogManager.hpp"
LogManager::LogManager(const std::string &sourceName) : sourceName{sourceName}
{

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
//void LogManager::showLogByType(const ProjectorMessage::Type &type)
//{
//    for (const auto &l : log)
//    {
//        if (l.type == type)
//        {
//            std::cout << sourceName + '/';
//            std::cout << l << std::endl;
//        }
//    }
//}
void LogManager::logging(ProjectorMessage message)
{
    log.push_back(message);
//    std::cout << sourceName << '/' << message << std::endl;
}