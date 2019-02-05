// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com


//
// Created by andrew on 15.01.19.
//

#include "ProjectorMessage.hpp"

ProjectorMessage::ProjectorMessage(const std::string &desc, ProjectorMessage::Type type)
{
    this->description = desc;
    this->type = type;
}

ProjectorMessage::~ProjectorMessage()
{

}

ProjectorMessage::ProjectorMessage(const std::exception &ex, ProjectorMessage::Type type)
{
    this->description = ex.what();
    this->type = type;
}

const std::string ProjectorMessage::toString() const
{
    std::string strType = "";
    switch (type)
    {
        case ProjectorMessage::Type::MESSAGE:
        {
            strType = "MESSAGE";
            break;
        }
        case ProjectorMessage::Type::DEBUG:
        {
            strType = "DEBUG";
            break;
        }
        case ProjectorMessage::Type::WARNING:
        {
            strType = "WARNING";
            break;
        }
        case ProjectorMessage::Type::ERROR:
        {
            strType = "ERROR";
            break;
        }
        default:
        {
            strType = "UNDEFINED";
        }
    }
    return "[" + strType + "]: " + description;
}

