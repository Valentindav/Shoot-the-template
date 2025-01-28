#include "pch.h"
#include "GameManager.h"
#include "SFML/Graphics.hpp"
#include "Scene.h"
#include "SceneManager.h"
#include "Entity.h"

void GameManager::Init() {
    // Ajouter une sc�ne au gestionnaire
    Scene* scene = new Scene();
    Player* player = scene->Add<Player>();
    sceneManager.AddScene(scene); // Utilisez AddScene pour ajouter une sc�ne
}


void GameManager::Update(float dt) {
    // Exemple d'acc�s � la sc�ne active via GetCurrentScene
    Scene* currentScene = sceneManager.GetCurrentScene();
    if (currentScene) {
        currentScene->Update(dt);
    }
}

void GameManager::Draw(sf::RenderWindow& window) {
    sceneManager.DrawCurrentScene(window); // Dessiner la sc�ne active
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

        // Mettre � jour la sc�ne actuelle
        Update(dt);

        // Dessiner la sc�ne actuelle
        window.clear();
        Draw(window);
        window.display();
    }
}