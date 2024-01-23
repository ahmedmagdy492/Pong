#pragma once
#include "Collidable.h"

class Wall : public Collidable
{
public:
	Wall();
	Wall(float x, float y, float w, float h);
	void Draw() override;
	void Move() override;
};

