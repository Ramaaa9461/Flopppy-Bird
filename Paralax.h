#pragma once

#include "raylib.h"

class Paralax
{
private:

	Texture2D front;
	Texture2D middle;
	Texture2D back;

	float scrollingBack;
	float scrollingMid;
	float scrollingFore;

public:

	Paralax();
	~Paralax();
	void loadTexture();
	void update();
	 void draw();
};

