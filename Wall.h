#pragma once
#include "raylib.h"
class Wall
{
private:
	int _speed;
	Rectangle rectangle;
	Color _color;

public:
	Wall();
	~Wall();

	Rectangle GetRectangle();
	Color GetColor();

	int GetSpeed();
	void SetSpeed(int speed);
	void SetColor(Color color);
	void SetRectangle(int width, int height);
	void SetRectanglePos(int posX, int posY);

	void Draw();
	void Movement();
};

