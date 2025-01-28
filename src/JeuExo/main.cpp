#include "pch.h"
#include "main.h"
#include <SFML/Graphics.hpp>
#include "GameManager.h"

GameManager* GameManager::Minstance = nullptr;

GameManager* GameManager::Getinstance() {
    if (Minstance == nullptr) {
        Minstance = new GameManager();
    }
    return Minstance;
}

int main()
{
    GameManager* gameManager = GameManager::Getinstance();
    gameManager->PlayGame();
    return 0;
}
