#include "pch.h"
#include "Player.h"
#include <iostream>

Player::Player() {
	spawnX = x = 425;
	spawnY = y = 725;
	const std::string& texturePath = "..\\..\\..\\res\\kenney_space-shooter-extension\\PNG\\Sprites\\Ships\\spaceShips_003.png";
	if (!texture.loadFromFile(texturePath)) {
		throw std::runtime_error("Erreur de chargement de la texture !");
	}
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
	sprite.setRotation(180);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	hitbox = sprite.getGlobalBounds();
}

void Player::Move(float offsetX, float offsetY) {
	sprite.move(offsetX, offsetY);
	hitbox = sprite.getGlobalBounds(); // Mise � jour de la hitbox
}

void Player::Spawn() {
    sprite.setPosition(spawnX, spawnY);
}

void Player::Heal(int amount) {
    currentHealth += amount;
    if (currentHealth > Health) currentHealth = Health; // Cap la vie � 100
}

void Player::Input(float dt) {
    float speed = 200.f;
    float diagonalFactor = 1.f;

    bool isMovingHorizontally = sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    bool isMovingVertically = sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    // Si le joueur se déplace à la fois horizontalement et verticalement, réduire la vitesse
    if (isMovingHorizontally && isMovingVertically) {
        diagonalFactor = 1.f / std::sqrt(2.f); // ≈ 0.707
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        Move(0.f, -speed * diagonalFactor * dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        Move(0.f, speed * diagonalFactor * dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        Move(-speed * diagonalFactor * dt, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        Move(speed * diagonalFactor * dt, 0.f);
    }
   /* if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        GameManager::Getinstance()->SpawnBullet();
    }*/

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
        TakeDamage(10); // Inflige 10 points de d�g�ts
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
        Heal(10); // Soigne 10 points de vie
    }
}

float Player::GetX() const { return x; }
float Player::GetY() const { return y; }

void Player::Update(float dt) {
	Input(dt);
}

const sf::FloatRect& Player::GetHitbox() const {
	return hitbox;
}

void Player::TakeDamage(int damage) {
	currentHealth -= damage;
	std::cout << "you have" << currentHealth << " " << Health;
	if (currentHealth <= 0) {
		currentHealth = 0;
		std::cout << "Game Over! Player is dead.\n";
	}
}


void Player::Draw(sf::RenderWindow& window) {
	window.draw(sprite);
}