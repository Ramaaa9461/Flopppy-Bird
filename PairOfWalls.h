#pragma once
#include "Wall.h"
#include "BlankSpace.h"
class PairOfWalls
{
private:
	Wall* wall1;
	Wall* wall2;
	BlankSpace* blankSpace;

	float posX;
	float posY;
	float _speed;

public:
	PairOfWalls(float x, float y);
	~PairOfWalls();

	Rectangle GetWall1Collider();
	Rectangle GetWall2Collider();
	Rectangle GetBlankCollider();

	void SetWallsPositions();
	void SetPosition(float x, float y);
	void Movement();
	void ConstantMovement();
	void Draw();

};

