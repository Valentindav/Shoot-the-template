#pragma once
#include "Entity.h"
#include "SFML/Graphics.hpp"

class Player : public Entity
{
	float x, y;
	float spawnX, spawnY;
	int Health = 100;
	int currentHealth = Health;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::FloatRect hitbox;
public : 
	Player();
	void Move(float offsetX, float offsetY);
	void Input(float dt);
	float GetX() const;
	float GetY() const;
	void Update(float dt) override;
	const sf::FloatRect& GetHitbox() const override;
	void TakeDamage(int damage);
	void Heal(int amount);
	void Spawn();
	void Draw(sf::RenderWindow& window);
};

