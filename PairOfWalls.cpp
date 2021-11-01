#include "PairOfWalls.h"

const int screenWidth = 800;
const int screenHeight = 450;

PairOfWalls::PairOfWalls(float x, float y)
{
	wall1 = new Wall();
	wall2 = new Wall();
	blankSpace = new BlankSpace();

	posX = x;
	posY = y;
	_speed = 200;
}

PairOfWalls::~PairOfWalls()
{
	delete wall1;
	delete wall2;
	delete blankSpace;
}

Rectangle PairOfWalls::GetWall1Collider()
{
	return wall1->GetRectangle();
}

Rectangle PairOfWalls::GetWall2Collider()
{
	return wall2->GetRectangle();
}

Rectangle PairOfWalls::GetBlankCollider()
{
	return blankSpace->GetRectangle();
}

void PairOfWalls::SetWallsPositions()
{
	float offset = 30;
	wall1->SetRectanglePos(posX, posY - blankSpace->GetRectangle().height - offset);
	wall2->SetRectanglePos(posX, posY + blankSpace->GetRectangle().height + offset);
	blankSpace->SetRectanglePos(posX, posY);
}

void PairOfWalls::SetPosition(float x, float y)
{
	posX = x;
	posY = y;
}

void PairOfWalls::Movement()
{
	SetWallsPositions();

	ConstantMovement();

	if (posX <= 0)
	{
		int offset = 40;
		SetPosition(screenWidth, GetRandomValue(-10, screenHeight - blankSpace->GetRectangle().height - offset));
	}
}

void PairOfWalls::ConstantMovement()
{
	posX -= _speed * GetFrameTime();
}

void PairOfWalls::Draw()
{
	wall1->Draw();
	wall2->Draw();
}
