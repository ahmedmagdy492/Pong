#include "SceneManager.h"

SceneManager::SceneManager(Scene* currentScene) {
	this->currentScene = currentScene;
}

void SceneManager::SetCurrentScene(Scene* newScene) {
	this->currentScene = newScene;
}

void SceneManager::Render() {
	currentScene->Render();
}