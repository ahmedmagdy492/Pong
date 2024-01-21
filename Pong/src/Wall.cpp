#include "Wall.h"

Wall::Wall() {

}

Wall::Wall(float x, float y, float w, float h) {
	location.x = x;
	location.y = y;
	dim.x = w;
	dim.y = h;
}

void Wall::Draw() {
	DrawRectangle((int)location.x, (int)location.y, (int)dim.x, (int)dim.y, GRAY);
}

void Wall::Move() {

}