#include "Collidable.h"

Collidable::Collidable() {
	location = { 0 };
	dim = { 0 };
}

const Vector2& Collidable::GetLocation() const {
	return location;
}

void Collidable::SetLocation(Vector2& newLocation) {
	location.x = newLocation.x;
	location.y = newLocation.y;
}

const Vector2& Collidable::GetDim() const {
	return dim;
}

void Collidable::SetDim(Vector2& newDim) {
	dim.x = newDim.x;
	dim.y = newDim.y;
}

bool Collidable::IsCollidingWith(const Collidable& other) {
	bool firstXPointCheck = location.x >= other.location.x && location.x <= (other.location.x + other.dim.x);
	bool firstYPointCheck = location.y <= (other.location.y + other.dim.y) && location.y >= other.location.y;

	bool secondXPointCheck = (location.x + dim.x) >= other.location.x && (location.x + dim.x) <= (other.location.x + other.dim.x);
	bool secondYPointCheck = location.y <= (other.location.y + other.dim.y) && location.y >= other.location.y;

	bool thirdXPointCheck = location.x >= other.location.x && location.x <= (other.location.x + other.dim.x);
	bool thirdYPointCheck = (location.y + dim.y) >= other.location.y && (location.y + dim.y) <= (other.location.y + other.dim.y);

	bool fourthXPointCheck = (location.x + dim.x) >= other.location.x && (location.x + dim.x) <= (other.location.x + other.dim.x);
	bool fourthYPointCheck = (location.y + dim.y) >= other.location.y && (location.y + dim.y) <= (other.location.y + other.dim.y);

	return (firstXPointCheck && firstYPointCheck) || (secondXPointCheck && secondYPointCheck) || (thirdXPointCheck && thirdYPointCheck) || (fourthXPointCheck && fourthYPointCheck);
}