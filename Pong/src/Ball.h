#pragma once
#include "Collidable.h"

class Ball : public Collidable
{
private:
	Vector2 speed = { 3.0f, 3.0f };
	bool isMoving = false;
public:
	Ball();
	Ball(float x, float y);
	void Draw() override;
	void Move() override;
	void SetSpeed(const Vector2& newSpeed);
	const Vector2& GetSpeed() const;
	void ToggleMoving();
	void ResetLocation(int screenWidth, int screenHeight);
	bool IsOutOfBoundaries(int xBoundry);
	bool IsMoving();
};

