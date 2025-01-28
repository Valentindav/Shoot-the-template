#include "pch.h"
#include "SceneManager.h"
#include <iostream>

SceneManager::SceneManager() : CurrentScene(0) {}

// Retourne la scène active
Scene* SceneManager::GetCurrentScene() {
    if (CurrentScene >= 0 && CurrentScene < Scenes.size()) {
        return Scenes[CurrentScene];
    }
    return nullptr;
}

// Dessine la scène active
void SceneManager::DrawCurrentScene(sf::RenderWindow& window) {
    Scene* currentScene = GetCurrentScene();
    if (currentScene) {
        currentScene->draw(window);
    }
    else {
        std::cout << "Aucune scène active !\n";
    }
}

// Ajoute une scène au gestionnaire
void SceneManager::AddScene(Scene* scene) {
    Scenes.push_back(scene);
}