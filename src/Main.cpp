#include <raylib.h>

#include "SceneManager.h"
#include "./Helpers/constants.h"
#include "Scenes/MainMenuScene.h"


int main(void) {
	const int screenWidth = WIDTH;
	const int screenHeight = HEIGHT;

	InitWindow(screenWidth, screenHeight, "Pong");

	SetTargetFPS(60);

	SceneManager sceneManager;
	MainMenuScene mainMenuScene(&sceneManager, screenWidth, screenHeight);
	sceneManager.SetCurrentScene(&mainMenuScene);

	SetExitKey(0);

	while (!WindowShouldClose()) {
		BeginDrawing();

			ClearBackground(BLACK);

			sceneManager.Render();

		EndDrawing();
	}

	CloseWindow();
}