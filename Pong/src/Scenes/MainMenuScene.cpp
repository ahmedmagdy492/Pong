#include "MainMenuScene.h"

MainMenuScene::MainMenuScene(SceneManager* sceneManager, const int screenWidth, const int screenHeight) {

	gameScene = NULL;

	this->sceneManager = sceneManager;

	btnStart.SetText("Start Game");
	btnExit.SetText("Exit");

	btnStart.SetIsActive(true);

	Vector2 btnStartTextDims = btnStart.MeasureTextDimensions();
	Vector2 btnStartLocation = { 
		(screenWidth - btnStartTextDims.x) / 2,
		(screenHeight - btnStartTextDims.y) / 2
	};
	btnStart.SetLocation(btnStartLocation);
	Vector2 btnStartDim = { btnStartTextDims.x, btnStartTextDims.y };
	btnStart.SetDim(btnStartDim);

	// exit button
	Vector2 btnExitTextDims = btnExit.MeasureTextDimensions();
	Vector2 btnExitLocation = {
		(screenWidth - btnExitTextDims.x) / 2,
		btnStartLocation.y + btnStartDim.y + btnExit.GetPadding().y
	};
	btnExit.SetLocation(btnExitLocation);
	Vector2 btnExitDim = { btnExitTextDims.x, btnExitTextDims.y };
	btnExit.SetDim(btnExitDim);

	// banner text
	bannerLabel.SetText("Pong Game");
	bannerLabel.SetFontSize(55);
	Vector2 bannerTxtDims = bannerLabel.GetTextDimensions();
	Vector2 newBannerLocation = { (screenWidth-bannerTxtDims.x)/2, WALL_HEIGHT+40 };
	bannerLabel.SetLocation(newBannerLocation);
}

MainMenuScene::~MainMenuScene() {
	if (gameScene != NULL) {
		delete gameScene;
	}
}

void MainMenuScene::Render() {
	bannerLabel.Draw();
	btnStart.Draw();
	btnExit.Draw();

	if (IsKeyPressed(KEY_UP)) {
		if (btnStart.IsActive()) {
			btnStart.SetIsActive(false);
			btnExit.SetIsActive(true);
		}
		else {
			btnExit.SetIsActive(false);
			btnStart.SetIsActive(true);
		}
	}
	else if (IsKeyPressed(KEY_DOWN)) {
		if (btnStart.IsActive()) {
			btnStart.SetIsActive(false);
			btnExit.SetIsActive(true);
		}
		else {
			btnExit.SetIsActive(false);
			btnStart.SetIsActive(true);
		}
	}

	if (IsKeyPressed(KEY_ENTER)) {
		if (btnStart.IsActive()) {
			gameScene = new GameScene(WIDTH, HEIGHT);
			sceneManager->SetCurrentScene(gameScene);
		}
		else if(btnExit.IsActive()) {
			exit(0);
		}
	}
}