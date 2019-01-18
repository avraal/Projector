// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com


//
// Created by andrew on 15.01.19.
//

#include "ProjectorMessage.hpp"
ProjectorMessage::ProjectorMessage(const std::string &desc, ProjectorMessage::Type type) : description{desc}, type{type}
{

}
ProjectorMessage::~ProjectorMessage()
{

}
