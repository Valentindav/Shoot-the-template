#pragma once
#include <vector>
#include "Player.h" // Inclure le joueur si nécessaire
#include <SFML/Graphics.hpp>

class Scene
{
	int SceneNumber;
	Player player;
	std::vector<Entity*> Entities;
public : 
	template <typename T>
	 T* Add();
	template <typename T>
	 T* Gets();
	template <typename T>
	const T& RemoveType();
	void Update(float dt);
	void draw(sf::RenderWindow& Window);
};

template <typename T>
T* Scene::Add() {
	auto entity = new T();
	Entities.push_back(entity);
	return entity;
}

template <typename T>
T* Scene::Gets() {
	for (Entity* ent : Entities) {
		if (T* casted = dynamic_cast<T*>(ent)) {
			return casted; // Retourne le premier objet du type demandé
		}
	}
	return nullptr; // Si aucun objet n'est trouvé
}

template <typename T>
const T& Scene::RemoveType() {
	for (size_t i = 0; i < Entities.size(); ++i) {
		if (dynamic_cast<T*>(Entities[i]) != nullptr) {
			delete Entities[i];
			Entities.erase(Entities.begin() + i);
			--i;
		}
	}
}