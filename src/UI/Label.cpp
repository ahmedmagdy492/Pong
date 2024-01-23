#include "Label.h"

Label::Label() {
	location = { 0 };
	color = WHITE;
	font = GetFontDefault();
	fontSize = 30;
}

void Label::SetLocation(const Vector2& newLocation) {
	location.x = newLocation.x;
	location.y = newLocation.y;
}

const Vector2& Label::GetLocation() const {
	return location;
}

void Label::SetText(const std::string newText) {
	text = newText;
}

const std::string& Label::GetText() const {
	return text;
}

void Label::SetColor(Color newColor) {
	color = newColor;
}

Color Label::GetColor() const {
	return color;
}

int Label::GetFontSize() {
	return fontSize;
}

void Label::SetFontSize(int fontSize) {
	this->fontSize = fontSize;
}

void Label::Draw() {
	DrawTextEx(font, text.c_str(), location, fontSize, 0, color);
}

Vector2 Label::GetTextDimensions() {
	return MeasureTextEx(font, text.c_str(), fontSize, 0);
}