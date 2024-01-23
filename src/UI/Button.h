#pragma once

#include <iostream>

#include <raylib.h>

#include "../Helpers/Constants.h"

class Button
{
private:
	Vector2 location;
	Vector2 dim;
	bool isActive;
	std::string text;
	Font font;
	int fontSize;
	Vector2 padding;

public:
	Button();
	~Button();

	Vector2 MeasureTextDimensions() const;

	void SetLocation(const Vector2& newLocation);
	const Vector2& GetLocation() const;

	void SetDim(const Vector2& newDim);
	const Vector2& GetDim() const;

	void SetIsActive(bool isActive);
	bool IsActive() const;

	void SetText(std::string text);
	const std::string& GetText() const;

	void SetPadding(const Vector2& padding);
	const Vector2& GetPadding() const;

	void Draw();
};