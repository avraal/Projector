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
