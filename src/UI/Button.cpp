#include "Button.h"

Button::Button() {
	location = { 0 };
	dim = { 0 };
	fontSize = 35;
	font = LoadFontEx(FONT_PATH, fontSize, 0, 250);
	isActive = false;
	padding = { 20, 20 };
}

Button::~Button() {
	UnloadFont(font);
}

Vector2 Button::MeasureTextDimensions() const {
	return MeasureTextEx(font, text.c_str(), fontSize, 0);
}

void Button::SetLocation(const Vector2& newLocation) {
	location.x = newLocation.x;
	location.y = newLocation.y;
}

const Vector2& Button::GetLocation() const {
	return location;
}

void Button::SetDim(const Vector2& newDim) {
	dim.x = newDim.x;
	dim.y = newDim.y;
}

const Vector2& Button::GetDim() const {
	return dim;
}

void Button::SetIsActive(bool isActive) {
	this->isActive = isActive;
}

bool Button::IsActive() const {
	return isActive;
}

void Button::SetText(std::string text) {
	this->text = text;
}

const std::string& Button::GetText() const {
	return text;
}

void Button::SetPadding(const Vector2& padding) {
	this->padding.x = padding.x;
	this->padding.y = padding.y;
}

const Vector2& Button::GetPadding() const {
	return padding;
}

void Button::Draw() {
	Vector2 textDim = MeasureTextDimensions();
	Vector2 newLocation = { location.x + (dim.x-textDim.x)/2, location.y + (dim.y-fontSize)/2 };

	if (isActive) {
		Rectangle rect;
		rect.x = location.x-padding.x;
		rect.y = location.y-padding.y;
		rect.width = dim.x+padding.x+20;
		rect.height = dim.y+padding.y+10;
		DrawRectangleRoundedLines(rect, 10, 80, 2, GRAY);
		DrawTextEx(font, text.c_str(), newLocation, fontSize, 0, GRAY);
	}
	else {
		DrawTextEx(font, text.c_str(), newLocation, fontSize, 0, GRAY);
	}
}