#include "pch.h"
#include "Scene.h"
#include "Entity.h"


template <typename T>
 inline T* Scene::Add() {
	 T* pushed = new T;
	 Entities.push_back(pushed);
	 return pushed;
}

template <typename T>
  T* Scene::Gets() {
	 std::vector<T*> Got;
	 /*for (Entity* ent : Entities) {
		 if (T* found == dynamic_cast<T*>(Entity) { 
			 Got.push_back(ent); 
		 }
	 }
	 return found;*/
}

template <typename T>
const T& Scene::RemoveType() {
	for (int i = 0; i < Entities.size(); i++) {
		delete Entities[i];
	}
}

void Scene::Update() {
	player.Spawn();
}

void Scene::draw(sf::RenderWindow Window)  {
	Update();
	Player* p = Add<Player>();
	player.Draw(Window);
	for (Entity* ent : Entities) Window.draw(*ent);
}