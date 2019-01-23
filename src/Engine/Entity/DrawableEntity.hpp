//
// Created by andrew on 18.01.19.
//

#ifndef PROJECTOR_DRAWABLEENTIY_HPP
#define PROJECTOR_DRAWABLEENTIY_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "Entity.hpp"

class DrawableEntity : public Entity, public sf::Drawable, public sf::Transformable
{
protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    sf::Texture texture;
    sf::Sprite sprite;
    sf::RectangleShape rect;
    sf::Vector2f position;
    bool canShowBounds;
    bool canRenderer;

    void initBounds();
public:
    DrawableEntity(std::string name = "");
    virtual ~DrawableEntity() override;
    virtual void prepare() override;
    virtual void update() override;
    virtual void exitProcess() override;

    void toggleCanShowBounds();
    void setCanShowBounds(bool canShowBounds);

    bool isCanShowBounds() const;
    const sf::FloatRect getBoundingBox() const;
};

#endif //PROJECTOR_DRAWABLEENTIY_HPP
