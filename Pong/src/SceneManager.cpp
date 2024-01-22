#include "SceneManager.h"

void SceneManager::SetCurrentScene(Scene* newScene) {
	this->currentScene = newScene;
}

void SceneManager::Render() {
	currentScene->Render();
}