#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class GameManager
{
	 //sf::RenderWindow window;
	 Player player;
	 static GameManager* Minstance;
public : 
	static GameManager* Getinstance();
	void Init();
	void Update(float dt);
	void Draw(sf::RenderWindow& window);
	void PlayGame();
};

