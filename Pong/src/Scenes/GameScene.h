#pragma once
#include <iostream>

#include "Scene.h"
#include "../Wall.h"
#include "../Ball.h"
#include "../Player.h"
#include "../UI/Label.h"
#include "../Helpers/Constants.h"
#include "../Helpers/Utils.h"

class GameScene : public Scene
{
private:
	Wall wall1, wall2;
	Ball ball;
	Player p1, p2;
	Label player1ScoreLabel, player2ScoreLabel;
	int screenWidth, screenHeight;

	void ResetScene();

public:
	GameScene(const int screenWidth, const int screenHeight);
	void Render() override;
};

