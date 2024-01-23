#include "Label.h"

Label::Label() {
	location = { 0 };
	color = WHITE;
	fontSize = 30;
	font = LoadFontEx(FONT_PATH, fontSize, 0, 250);
}

Label::~Label() {
	UnloadFont(font);
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