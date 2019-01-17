// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

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
        MESSAGE = 0,
        DEBUG = 1,
        WARNING = 2,
        ERROR = 3
    };

private:
    std::string description;
public:
    explicit ProjectorMessage(const std::string &desc, Type type);
    virtual ~ProjectorMessage();
    Type type;

    friend std::ostream &operator<<(std::ostream &os, ProjectorMessage message)
    {
        std::string type = "";
        switch (message.type)
        {
            case ProjectorMessage::Type::MESSAGE:
            {
                type = "MESSAGE";
                break;
            }
            case ProjectorMessage::Type::DEBUG:
            {
                type = "DEBUG";
                break;
            }
            case ProjectorMessage::Type::WARNING:
            {
                type = "WARNING";
                break;
            }
            case ProjectorMessage::Type::ERROR:
            {
                type = "ERROR";
                break;
            }
            default:
            {
                type = "UNDEFINED";
            }
        }
        os << "[" << type << "]: ";
        os << message.description;
        return os;
    }

};

#endif //PROJECTOR_PROJECTORMESSAGE_HPP
