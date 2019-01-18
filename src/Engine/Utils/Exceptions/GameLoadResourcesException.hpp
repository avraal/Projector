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
