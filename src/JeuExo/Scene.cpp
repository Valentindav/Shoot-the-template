#include "pch.h"
#include "Scene.h"
#include "Entity.h"
#include <iostream>


void Scene::Update(float dt) {
	// Exemple de logique pour mettre à jour les entités
	for (auto& ent : Entities) {
		ent->Update(0); // Passez le delta temps
		player.Update(dt);
	}
}

void Scene::draw(sf::RenderWindow& window) {
	//player.Draw(window); // Dessinez le joueur principal séparément
	for (const auto& ent : Entities) {
		window.draw(*ent);
		player.Draw(window);
	}
}