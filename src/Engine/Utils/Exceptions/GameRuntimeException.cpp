// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//
// Created by andrew on 15.01.19.
//

#include "GameRuntimeException.hpp"
GameRuntimeException::GameRuntimeException(const std::string &message)
{
//    this->message = message;
    this->message = "Not realize exception";
}
const char *GameRuntimeException::what() const throw()
{
    return message.c_str();
}
