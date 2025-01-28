#include "pch.h"
#include "SceneManager.h"

void* SceneManager::GetCurrentScene() {
	return Scene[CurrentScene];
}

void SceneManager::DrawCurrentScene() {
	Scene[CurrentScene]->draw();
}