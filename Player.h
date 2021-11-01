#pragma once

#include "raylib.h"

#include "Paralax.h"

class Player
{
private:
	Rectangle rectangle;
	Color color;
	int speed;
	int points;

	Texture2D bird;
	Texture2D animation[3];

	float gravity;
	float velocity;
	float acceleration;

	bool isAlive;
	bool isFalling;
	//=====================================================
	Paralax* parallax;

public:

	Player();
	~Player();

	Rectangle GetRectangle();
	Color GetColor();

	int GetSpeed();
	int GetPoints();

	void SetSpeed(int _speed);
	void SetColor(Color _color);
	void SetWidth(int _width);
	void SetHeight(int _height);
	void SetPoints(int _points);
	void SetRectanglePos(int posX, int posY);
	void AddPoints(int _points);

	void LoadTextures();

	void ResetData();

	void Movement(int key);

	void Draw(bool twoPlayers);

	void SetIsAlive(bool isAlive);
	bool GetIsAlive();

	//========================================================
	Paralax* GetParalax();
};


