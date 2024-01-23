#pragma once

#include <raylib.h>
#include <assert.h>

class Collidable
{
protected:
	Vector2 location;
	Vector2 dim;

public:
	Collidable();

	virtual const Vector2& GetLocation() const;

	virtual void SetLocation(Vector2& newLocation);

	const Vector2& GetDim() const;

	void SetDim(Vector2& newDim);

	bool IsCollidingWith(const Collidable& other);

	virtual void Draw() = 0;

	virtual void Move() = 0;
};

