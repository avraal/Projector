//
// Created by andrew on 17.01.19.
//

#ifndef PROJECTOR_ENTITY_HPP
#define PROJECTOR_ENTITY_HPP

#include "../Utils/CONST_DEFINITIONS.hpp"
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Entity
{
protected:
    friend class Level;

    ul_int id;
    std::string name;

    static ul_int getNextId();
    static ul_int currentId;

public:
    Entity(std::string name = "");
    Entity() = delete;
    virtual ~Entity();

    ul_int getId() const;
    const std::string &getName() const;

    void setName(const std::string &name);

    virtual void prepare() = 0;
    virtual void update() = 0;
    virtual void exitProcess() = 0;
};

#endif //PROJECTOR_ENTITY_HPP
