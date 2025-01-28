#include "pch.h"
#include "GameManager.h"
#include "SFML/Graphics.hpp"
#include "Scene.h"
#include "SceneManager.h"
#include "Entity.h"

void GameManager::Init() {
    
}

void GameManager::Update(float dt) {
    player.Input(dt);
    player.Update(dt);
}

void GameManager::Draw(sf::RenderWindow& window) {
    
        window.clear();
        player.Draw(window);
    
        window.display();
}

void GameManager::PlayGame() {
    sf::Clock clock;
    Scene* scene = new Scene;
    Init();
    sf::RenderWindow window(sf::VideoMode(800, 800), "littleGame");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        float dt = clock.restart().asSeconds();
        player.Input(dt);
        scene->draw(window);
        Update(dt);
        Draw(window);
  
    }
}