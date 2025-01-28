#pragma once
#include "Entity.h"
#include "Player.h"
#include "SFML/Graphics.hpp"

class Entity;
class Scene
{
	int SceneNumber;
	Player player;
	std::vector<Entity*> Entities;
public : 
	 void draw(sf::RenderWindow Window);
	template <typename T>
	 T* Add();
	template <typename T>
	 T* Gets();
	template <typename T>
	const T& RemoveType();
	void Update();
};

