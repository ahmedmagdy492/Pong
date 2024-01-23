#include "Player.h"

Player::Player() {
	speed = { 0 };
	dim = { PLAYER_WIDTH, PLAYER_HEIGHT };

	int i = 0;

	for (; i < PARTS_LEN; ++i) {
		parts[i] = new Wall(location.x, location.y+(i*(dim.y/3)), dim.x, dim.y / 3);
	}
}

Player::Player(float x, float y) : Player() {
	location.x = x;
	location.y = y;
}

Player::~Player() {
	int i = 0;
	for (; i < PARTS_LEN; ++i) {
		delete parts[i];
	}
}

void Player::SetLocation(Vector2& newLocation) {
	int i = 0;

	for (; i < PARTS_LEN; ++i) {
		Vector2 tempLocation = { newLocation.x, newLocation.y+((dim.y/3)*i)};
		parts[i]->SetLocation(tempLocation);
	}
}

const Vector2& Player::GetLocation() const {
	return parts[0]->GetLocation();
}

void Player::Draw() {
	int i = 0;

	for (; i < PARTS_LEN; ++i) {
		parts[i]->Draw();
	}
}

void Player::SetBoundary(int boundaryX, int boundaryY) {
	this->boundaryX = boundaryX;
	this->boundaryY = boundaryY;
}

void Player::Move() {
	Vector2 curLocation = parts[0]->GetLocation();

	if (direction == Direction::LEFT) {
		if ((curLocation.x + speed.x) > 0 && ((curLocation.x + dim.x) + speed.x) < ((boundaryX - dim.x) / 2)) {
			Vector2 newLocation = { curLocation.x + speed.x, curLocation.y };
			SetLocation(newLocation);
		}
	}
	else {
		if ((curLocation.x + speed.x) > (boundaryX/2/2) && ((curLocation.x + dim.x) + speed.x) < ((boundaryX - dim.x) / 2)) {
			Vector2 newLocation = { curLocation.x + speed.x, curLocation.y };
			SetLocation(newLocation);
		}
	}

	curLocation = parts[0]->GetLocation();

	if ((curLocation.y + speed.y) > WALL_HEIGHT && ((curLocation.y + dim.y) + speed.y) < boundaryY) {
		Vector2 newLocation = { curLocation.x, curLocation.y + speed.y };
		SetLocation(newLocation);
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

const Collidable** Player::GetParts() const {
	return (const Collidable**)parts;
}

void Player::IncreamentScore() {
	++score;
}

unsigned int Player::GetScore() const {
	return score;
}

Direction Player::GetPlayerDirection() const {
	return direction;
}

void Player::SetPlayerDirection(Direction direction) {
	this->direction = direction;
}