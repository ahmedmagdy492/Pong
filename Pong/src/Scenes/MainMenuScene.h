#pragma once
#include "Scene.h"

#include "../Helpers/Constants.h"

#include "../UI/Button.h"
#include "../UI/Label.h"
#include "../SceneManager.h"
#include "../Scenes/GameScene.h"

class MainMenuScene : public Scene
{
private:
	Button btnStart, btnExit;
	Label bannerLabel;
	SceneManager* sceneManager;
	GameScene *gameScene;

public:
	MainMenuScene(SceneManager* sceneManager, const int screenWidth, const int screenHeight);
	~MainMenuScene();
	void Render() override;
};

