// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

//
// Created by andrew on 15.01.19.
//

#ifndef PROJECTOR_GAMERUNTIMEEXCEPTION_HPP
#define PROJECTOR_GAMERUNTIMEEXCEPTION_HPP

#include <exception>
#include <string>

class GameRuntimeException : public std::exception
{
private:
    std::string message;

public:
    GameRuntimeException(const std::string &message);
    virtual const char *what() const throw() override;
    virtual ~GameRuntimeException() {}
};

#endif //PROJECTOR_GAMERUNTIMEEXCEPTION_HPP
