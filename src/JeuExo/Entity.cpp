#include "pch.h"
#include "Entity.h"

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.combine(this->getTransform());
} 