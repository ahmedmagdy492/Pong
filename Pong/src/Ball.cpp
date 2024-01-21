#include "Ball.h"

Ball::Ball() {
	location = { 0 };
	dim = { 25, 25 };
}

Ball::Ball(float x, float y) {
	location = { x, y };
	dim = { 25, 25 };
}

void Ball::Draw() {
	DrawRectangle(location.x, location.y, dim.x, dim.y, DARKGREEN);
}

void Ball::ToggleMoving() {
	isMoving = !isMoving;
}

void Ball::Move() {
	if (isMoving) {
		location.x += speed.x;
		location.y += speed.y;
	}
}

void Ball::SetSpeed(const Vector2& newSpeed) {
	speed.x = newSpeed.x;
	speed.y = newSpeed.y;
}

const Vector2& Ball::GetSpeed() const {
	return speed;
}

void Ball::ResetLocation(int screenWidth, int screenHeight) {
	Vector2 newBallLocation = { (screenWidth / 2) - 40, (screenHeight - GetDim().y) / 2 };
	SetLocation(newBallLocation);
}

bool Ball::IsOutOfBoundaries(int xBoundry) {
	return (location.x > xBoundry) || (location.x < 0) || 
		((location.x + dim.x) > xBoundry);
}

bool Ball::IsMoving() {
	return isMoving;
}