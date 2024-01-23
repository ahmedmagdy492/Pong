#include <raylib.h>

#include "SceneManager.h"
#include "./Helpers/constants.h"
#include "Scenes/MainMenuScene.h"
#include "Scenes/GameScene.h"


int main(void) {
	const int screenWidth = WIDTH;
	const int screenHeight = HEIGHT;

	InitWindow(screenWidth, screenHeight, "Pong");

	SetTargetFPS(60);

	HideCursor();

	SceneManager sceneManager;
	MainMenuScene* mainMenuScene = new MainMenuScene(&sceneManager, screenWidth, screenHeight);
	sceneManager.AddScene(mainMenuScene);
	GameScene* gameScene = new GameScene(&sceneManager, screenWidth, screenHeight);
	sceneManager.AddScene(gameScene);
	
	sceneManager.SetSceneByName(MainMenu);

	SetExitKey(0);

	while (!WindowShouldClose()) {
		BeginDrawing();

			ClearBackground(BLACK);

			sceneManager.Render();

		EndDrawing();
	}

	delete mainMenuScene;
	delete gameScene;

	CloseWindow();
}