//
// Created by andrew on 18.01.19.
//

#ifndef PROJECTOR_DRAWABLEENTIY_HPP
#define PROJECTOR_DRAWABLEENTIY_HPP

#include <SFML/Graphics/Drawable.hpp>

class DrawableEntiy : public sf::Drawable
{
public:
    virtual ~DrawableEntiy() override;
protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif //PROJECTOR_DRAWABLEENTIY_HPP
