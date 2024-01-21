#include "Player.h"

Player::Player() {
	speed = { 0 };
	location = {0};
	dim = { 20, 100 };
}

Player::Player(float x, float y) {
	speed = {0};
	location.x = x;
	location.y = y;
	dim = { 20, 100 };
}

void Player::Draw() {
	DrawRectangle(location.x, location.y, dim.x, dim.y, GRAY);
}

void Player::SetBoundary(int boundaryX, int boundaryY) {
	this->boundaryX = boundaryX;
	this->boundaryY = boundaryY;
}

void Player::Move() {
	if ((location.x + speed.x) > 0 && ((location.x + dim.x) + speed.x) < ((boundaryX-dim.x)/2)) {
		location.x += speed.x;
	}
	if ((location.y + speed.y) > 0 && ((location.y + dim.y) + speed.y) < boundaryY) {
		location.y += speed.y;
	}
}

void Player::SetSpeed(const Vector2& newSpeed) {
	speed.x = newSpeed.x;
	speed.y = newSpeed.y;
}

const Vector2& Player::GetSpeed() const {
	return speed;
}

int Player::GetConstantSpeed()
{
	return SPEED;
}