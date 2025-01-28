#pragma once
#include "Scene.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class SceneManager
{
	int NumberOfScene;
	int CurrentScene;
	std::vector<Scene*> Scene;
public : 
	SceneManager();

	void* GetCurrentScene();

	void DrawCurrentScene();
};

