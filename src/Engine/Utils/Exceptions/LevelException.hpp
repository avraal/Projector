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
