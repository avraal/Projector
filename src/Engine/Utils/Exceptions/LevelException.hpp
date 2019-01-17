// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

//
// Created by andrew on 17.01.19.
//

#ifndef PROJECTOR_LEVELEXCEPTION_HPP
#define PROJECTOR_LEVELEXCEPTION_HPP

#include <exception>
#include <string>
#include "../../Level/Level.hpp"

class LevelException : public std::exception
{
private:
    std::string message;
public:
    explicit LevelException(const std::string &message);
    LevelException(std::shared_ptr<Level> level, std::string message);

    virtual const char *what() const throw() override;
    virtual ~LevelException() {}
};

#endif //PROJECTOR_LEVELEXCEPTION_HPP
