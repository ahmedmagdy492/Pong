#include <raylib.h>


#include "SceneManager.h"
#include "Scenes/GameScene.h"

int main(void) {
	const int screenWidth = 1600;
	const int screenHeight = 900;

	InitWindow(screenWidth, screenHeight, "Pong");

	SetTargetFPS(60);

	GameScene gameScene(screenWidth, screenHeight);
	SceneManager sceneManager(&gameScene);

	while (!WindowShouldClose()) {
		BeginDrawing();

			ClearBackground(BLACK);

			sceneManager.Render();

		EndDrawing();
	}

	CloseWindow();
}