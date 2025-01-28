#pragma once
#include <SFML/Graphics.hpp>



class Entity : public sf::Drawable, sf::Transformable
{
    int health;
    sf::FloatRect hitbox;
public : 
    Entity() {

    }
    virtual void Update(float dt) = 0;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual const sf::FloatRect& GetHitbox() const = 0;
};

