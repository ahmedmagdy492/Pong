#pragma once

#include "../Helpers/Constants.h"

#include "Scene.h"
#include "../UI/Button.h"
#include "../UI/Label.h"
#include "../SceneManager.h"

class MainMenuScene : public Scene
{
private:
	Button btnStart, btnExit;
	Label bannerLabel;
	SceneManager* sceneManager;

public:
	MainMenuScene(SceneManager* sceneManager, const int screenWidth, const int screenHeight);
	void Render() override;
};

