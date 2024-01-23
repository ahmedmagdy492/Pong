#pragma once
#include "./Scenes/Scene.h"

class SceneManager
{
private:
	Scene* currentScene;

public:
	void Render();
	void SetCurrentScene(Scene* newScene);
};

