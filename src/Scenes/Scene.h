#pragma once

#include "SceneName.h"

class Scene
{
public:
	SceneName sceneName;

	virtual void Render() = 0;
};

