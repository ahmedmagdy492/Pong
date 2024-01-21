#pragma once
#include "Collidable.h"


class Player : public Collidable
{
private:
	Vector2 speed;
	const int SPEED = 4;
	int boundaryX = 0, boundaryY = 0;

public:
	Player();
	Player(float x, float y);

	void SetSpeed(const Vector2& newSpeed);
	const Vector2& GetSpeed() const;

	void Draw() override;
	void Move() override;

	int GetConstantSpeed();
	void SetBoundary(int boundaryX, int boundaryY);
};

