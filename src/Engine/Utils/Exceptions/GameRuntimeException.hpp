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
