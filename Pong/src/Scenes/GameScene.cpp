#include "GameScene.h"

GameScene::GameScene(const int screenWidth, const int screenHeight) {
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;

	Vector2 wall1Location = { 0, 0 };
	wall1.SetLocation(wall1Location);
	Vector2 wall1Dim = { screenWidth, 20 };
	wall1.SetDim(wall1Dim);

	Vector2 wall2Dim = { screenWidth, 20 };
	wall2.SetDim(wall2Dim);
	Vector2 wall2Location = { wall2.GetLocation().x, screenHeight - wall2.GetDim().y };
	wall2.SetLocation(wall2Location);

	Vector2 ballLocation = { (screenWidth / 2) - 40, (screenHeight - ball.GetDim().y) / 2 };
	ball.SetLocation(ballLocation);

	// player 1 location
	Vector2 p1Location = { (screenWidth / 2 - p1.GetDim().x) / 2, (screenHeight - p1.GetDim().y) / 2 };
	p1.SetLocation(p1Location);
	p1.SetBoundary(screenWidth, screenHeight - wall1.GetDim().y);

	// other player location
	Vector2 p2Location = { (screenWidth / 2 + screenWidth / 2 / 2), (screenHeight - p2.GetDim().y) / 2 };
	p2.SetLocation(p2Location);
	p2.SetBoundary(screenWidth, screenHeight-wall1.GetDim().y);
}

void GameScene::Render() {
	wall1.Draw();
	wall2.Draw();
	ball.Draw();
	p1.Draw();
	p2.Draw();
	Vector2 p1Speed = p1.GetSpeed();

	if (IsKeyDown(KEY_UP)) {
		Vector2 newSpeed = {0, p1.GetConstantSpeed()*-1};
		p1.SetSpeed(newSpeed);
		p1.Move();
	}
	else if (IsKeyDown(KEY_DOWN)) {
		Vector2 newSpeed = { 0, p1.GetConstantSpeed() };
		p1.SetSpeed(newSpeed);
		p1.Move();
	}
	else if (IsKeyDown(KEY_LEFT)) {
		Vector2 newSpeed = { p1.GetConstantSpeed()*-1, 0};
		p1.SetSpeed(newSpeed);
		p1.Move();
	}
	else if (IsKeyDown(KEY_RIGHT)) {
		Vector2 newSpeed = { p1.GetConstantSpeed(), 0};
		p1.SetSpeed(newSpeed);
		p1.Move();
	}

	if (ball.IsCollidingWith(wall1) || ball.IsCollidingWith(wall2)) {
		Vector2 oldSpeed = ball.GetSpeed();
		Vector2 newSpeed = { oldSpeed.x, oldSpeed.y * -1 };
		ball.SetSpeed(newSpeed);
	}

	if (ball.IsOutOfBoundaries(screenWidth)) {
		ball.ResetLocation(screenWidth, screenHeight);
		ball.ToggleMoving();
		// TODO: increament the current player score
	}

	ball.Move();

	if (ball.IsCollidingWith(p1)) {
		if (!ball.IsMoving()) {
			ball.ToggleMoving();
		}
		Vector2 oldSpeed = ball.GetSpeed();
		Vector2 newSpeed = { abs(oldSpeed.x), oldSpeed.y };
		ball.SetSpeed(newSpeed);
	}

	if (ball.IsCollidingWith(p2)) {
		if (!ball.IsMoving()) {
			ball.ToggleMoving();
		}
		Vector2 oldSpeed = ball.GetSpeed();
		Vector2 newSpeed = { abs(oldSpeed.x), oldSpeed.y };
		ball.SetSpeed(newSpeed);
	}
}