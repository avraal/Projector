// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

//
// Created by andrew on 15.01.19.
//

#ifndef PROJECTOR_GAMELOADEXCEPTION_HPP
#define PROJECTOR_GAMELOADEXCEPTION_HPP

#include <exception>
#include <string>

class GameLoadException : public std::exception
{
private:
    std::string message;
public:
    GameLoadException(const std::string &message);
    virtual const char *what() const throw() override;
    virtual ~GameLoadException() {}
};

#endif //PROJECTOR_GAMELOADEXCEPTION_HPP
