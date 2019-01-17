//
// Created by andrew on 15.01.19.
//

#include "GameLoadException.hpp"
const char *GameLoadException::what() const throw()
{
    return message.c_str();
}
GameLoadException::GameLoadException(const std::string &message) : message{message}
{
}
