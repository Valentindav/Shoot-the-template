#include "pch.h"
#include "GameManager.h"
#include "SFML/Graphics.hpp"
#include "Scene.h"
#include "SceneManager.h"
#include "Entity.h"

void GameManager::Init() {
    // Ajouter une scène au gestionnaire
    Scene* scene = new Scene();
    Player* player = scene->Add<Player>();
    sceneManager.AddScene(scene); // Utilisez AddScene pour ajouter une scène
}


void GameManager::Update(float dt) {
    // Exemple d'accès à la scène active via GetCurrentScene
    Scene* currentScene = sceneManager.GetCurrentScene();
    if (currentScene) {
        currentScene->Update(dt);
    }
}

void GameManager::Draw(sf::RenderWindow& window) {
    sceneManager.DrawCurrentScene(window); // Dessiner la scène active
}

void GameManager::PlayGame() {
    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(800, 800), "littleGame");

    Init();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float dt = clock.restart().asSeconds();

        // Mettre à jour la scène actuelle
        Update(dt);

        // Dessiner la scène actuelle
        window.clear();
        Draw(window);
        window.display();
    }
}