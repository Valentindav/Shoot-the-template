#include "pch.h"
#include "Scene.h"
#include "Entity.h"
#include <iostream>


void Scene::Update(float dt) {
	// Exemple de logique pour mettre � jour les entit�s
	for (auto& ent : Entities) {
		ent->Update(0); // Passez le delta temps
		player.Update(dt);
	}
}

void Scene::draw(sf::RenderWindow& window) {
	//player.Draw(window); // Dessinez le joueur principal s�par�ment
	for (const auto& ent : Entities) {
		window.draw(*ent);
		player.Draw(window);
	}
}