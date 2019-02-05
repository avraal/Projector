//
// Created by andrew on 15.01.19.
//

#ifndef PROJECTOR_PROJECTORMESSAGE_HPP
#define PROJECTOR_PROJECTORMESSAGE_HPP

#include <string>
#include <iostream>

class ProjectorMessage
{
public:
    enum class Type
    {
        ALL = 0,
        MESSAGE = 1,
        DEBUG = 2,
        WARNING = 3,
        ERROR = 4
    };

private:
    std::string description;
public:
    ProjectorMessage(const std::string &desc, Type type);
    ProjectorMessage(const std::exception &ex, Type type);
    virtual ~ProjectorMessage();
    Type type;

    const std::string toString() const;

    friend std::ostream &operator<<(std::ostream &os, ProjectorMessage message)
    {
        os << message.toString();
        return os;
    }

};

#endif //PROJECTOR_PROJECTORMESSAGE_HPP
