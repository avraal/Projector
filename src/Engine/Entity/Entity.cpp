// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//
// Created by andrew on 17.01.19.
//

#include <iostream>
#include "Entity.hpp"
#include "../Utils/Exceptions/GameLoadResourcesException.hpp"

ul_int Entity::currentId = 0;

Entity::Entity(const std::string &name) : id{getNextId()}, name{name}
{

}
Entity::~Entity()
{

}
ul_int Entity::getNextId()
{
    return currentId++;
}
