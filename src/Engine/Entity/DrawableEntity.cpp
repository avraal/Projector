// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//
// Created by andrew on 18.01.19.
//

#include <iostream>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include "DrawableEntity.hpp"
#include "../Utils/Exceptions/GameLoadResourcesException.hpp"
DrawableEntity::~DrawableEntity()
{

}
DrawableEntity::DrawableEntity(std::string name) : Entity(name)
{
    canShowBounds = false;
    canRenderer = true;
}
void DrawableEntity::prepare()
{
    if (!texture.loadFromFile("Resources/1.png"))
    {
        sf::RenderTexture newTexture;
        newTexture.create(16, 16);
        newTexture.clear(sf::Color::Transparent);
        texture = newTexture.getTexture();
    }

    sprite.setTexture(texture);

    setPosition({100.f, 100.f});
}
void DrawableEntity::update()
{
}
void DrawableEntity::exitProcess()
{

}
void DrawableEntity::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (canRenderer)
    {
        target.draw(sprite, getTransform());
        if (canShowBounds)
        {
            target.draw(rect, getTransform());
        }
    }
}
void DrawableEntity::initBounds()
{
    sf::FloatRect boundingBox = sprite.getGlobalBounds();

    rect.setSize({boundingBox.height, boundingBox.width});
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineThickness(2.2f);
    rect.setOutlineColor(sf::Color::Red);
}
void DrawableEntity::toggleCanShowBounds()
{
    setCanShowBounds(!canShowBounds);
}
bool DrawableEntity::isCanShowBounds() const
{
    return canShowBounds;
}
void DrawableEntity::setCanShowBounds(bool canShowBounds)
{
    this->canShowBounds = canShowBounds;
    initBounds();
}
const sf::FloatRect DrawableEntity::getBoundingBox() const
{
    return sprite.getGlobalBounds();
}
