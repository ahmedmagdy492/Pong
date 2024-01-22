#pragma once

#include <iostream>

#include <raylib.h>

class Label
{
private:
	std::string text;
	Vector2 location;
	Color color;
	Font font;
	int fontSize;

public:
	Label();

	void SetLocation(const Vector2& newLocation);
	const Vector2& GetLocation() const;

	void SetText(const std::string newText);
	const std::string& GetText() const;

	void SetColor(Color newColor);
	Color GetColor() const;

	int GetFontSize();
	void SetFontSize(int fontSize);

	void Draw();
	Vector2 GetTextDimensions();
};