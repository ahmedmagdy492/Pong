#pragma once
#include "Scenes/Scene.h"
#include <vector>

class SceneManager
{
private:
	std::vector<Scene*> scenes;
	Scene* sceneToRender = NULL;

public:
	void AddScene(Scene* scene);
	void SetSceneByName(SceneName sceneName);
	void Render();
};