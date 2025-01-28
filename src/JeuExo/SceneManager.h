#pragma once
#include <vector>
#include "Scene.h" // Inclure la d�finition de Scene
#include <SFML/Graphics.hpp>

class SceneManager {
private:
    int NumberOfscene;
    int CurrentScene; // Index de la sc�ne active
    std::vector<Scene*> Scenes; // Liste des sc�nes

public:
    SceneManager();

    Scene* GetCurrentScene(); // Retourne la sc�ne actuelle
    void DrawCurrentScene(sf::RenderWindow& window); // Dessine la sc�ne actuelle
    void AddScene(Scene* scene); // Ajoute une sc�ne
};
