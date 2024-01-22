#pragma once
#include <iostream>
#include "Collidable.h"
#include "Wall.h"
#include "./Helpers/Constants.h"

#define PARTS_LEN 3

enum Direction {
	RIGHT,
	LEFT
};

class Player : public Collidable
{
private:
	Vector2 speed;
	const int SPEED = 4;
	int boundaryX = 0, boundaryY = 0;
	Collidable* parts[PARTS_LEN];
	unsigned int score = 0;
	Direction direction;

public:
	Player();
	Player(float x, float y);
	~Player();

	void SetSpeed(const Vector2& newSpeed);
	const Vector2& GetSpeed() const;

	void Draw() override;
	void Move() override;

	int GetConstantSpeed();
	void SetBoundary(int boundaryX, int boundaryY);
	
	void SetLocation(Vector2& newLocation) override;
	const Vector2& GetLocation() const override;

	const Collidable** GetParts() const;

	void IncreamentScore();
	unsigned int GetScore() const;

	Direction GetPlayerDirection() const;
	void SetPlayerDirection(Direction direction);
};