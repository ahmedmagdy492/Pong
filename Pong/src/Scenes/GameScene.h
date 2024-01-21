#pragma once
#include <iostream>

#include "Scene.h"
#include "../Wall.h"
#include "../Ball.h"
#include "../Player.h"

class GameScene : public Scene
{
private:
	Wall wall1, wall2;
	Ball ball;
	Player p1, p2;
	int screenWidth, screenHeight;

public:
	GameScene(const int screenWidth, const int screenHeight);
	void Render() override;
};

