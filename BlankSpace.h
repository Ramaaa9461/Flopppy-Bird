#pragma once
#include "raylib.h"

class BlankSpace
{
private:
	int _speed;
	Rectangle rectangle;
	Color _color;

public:
	BlankSpace();
	~BlankSpace();

	Rectangle GetRectangle();
	Color GetColor();

	int GetSpeed();
	void SetSpeed(int speed);
	void SetColor(Color color);
	void SetRectangle(int width, int height);
	void SetRectanglePos(int posX, int posY);
	void Movement();
};

