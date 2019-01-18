// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

//
// Created by andrew on 17.01.19.
//

#ifndef PROJECTOR_ENTITY_HPP
#define PROJECTOR_ENTITY_HPP

#include "Utils/CONST_DEFINITIONS.hpp"
#include <string>
#include <memory>

class Entity
{
protected:
    const ul_int id;
    std::string name;

    Entity(ul_int, const std::string &name);
    virtual ~Entity();
public:

};

#endif //PROJECTOR_ENTITY_HPP
