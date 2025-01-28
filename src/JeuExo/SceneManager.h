#pragma once
#include <vector>
#include "Scene.h" // Inclure la définition de Scene
#include <SFML/Graphics.hpp>

class SceneManager {
private:
    int NumberOfscene;
    int CurrentScene; // Index de la scène active
    std::vector<Scene*> Scenes; // Liste des scènes

public:
    SceneManager();

    Scene* GetCurrentScene(); // Retourne la scène actuelle
    void DrawCurrentScene(sf::RenderWindow& window); // Dessine la scène actuelle
    void AddScene(Scene* scene); // Ajoute une scène
};
