#include "SceneManager.h"

void SceneManager::AddScene(Scene* scene) {
	scenes.push_back(scene);
}

void SceneManager::SetSceneByName(SceneName sceneName) {
	int i, size = scenes.size();

	for (i = 0; i < size; ++i) {
		if (scenes[i]->sceneName == sceneName) {
			sceneToRender = scenes[i];
			break;
		}
	}
}

void SceneManager::Render() {
	if (sceneToRender != NULL) {
		sceneToRender->Render();
	}
}