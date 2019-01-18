// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//
// Created by andrew on 17.01.19.
//

#include "LevelException.hpp"
const char *LevelException::what() const throw()
{
    return message.c_str();
}
LevelException::LevelException(const std::string &message) : message{message}
{

}
LevelException::LevelException(std::shared_ptr<Level> level, std::string message) : message{message}
{
    if (!level)
    {
        message += "; this level is nullptr";
    } else
    {
        message += "; levelName = " + level->name;
    }
}
