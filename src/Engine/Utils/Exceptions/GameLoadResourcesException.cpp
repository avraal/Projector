// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

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
