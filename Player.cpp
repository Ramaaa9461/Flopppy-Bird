#include "Player.h"

const int screenWidth = 800;
const int screenHeight = 450;

float timeElapsed = 0.5f;

Player::Player()
{
	rectangle.width = 10;
	rectangle.height = 30;

	
	color = BLACK;
	speed = 300;
	points = 0;
	isFalling = true;
	gravity = 0.0001;
	velocity = 0;
	upForce = 800;
	acceleration = 0;

	isFalling = true;
}

Player::~Player()
{

}

Rectangle Player::GetRectangle()
{
	return rectangle;
}

Color Player::GetColor()
{
	return color;
}

int Player::GetSpeed()
{
	return speed;
}

int Player::GetPoints()
{
	return points;
}

void Player::SetSpeed(int _speed)
{
	speed = _speed;
}

void Player::SetColor(Color _color)
{
	color = _color;
}

void Player::SetWidth(int _width)
{
	rectangle.width = _width;
}

void Player::SetHeight(int _height)
{
	rectangle.height = _height;
}

void Player::SetPoints(int _points)
{
	points = _points;
}

void Player::SetRectanglePos(int posX, int posY)
{
	rectangle.x = posX;
	rectangle.y = posY;
}

void Player::AddPoints(int _points)
{
	points += _points;
}

void Player::SetData()
{
	int offsetX = 200;

	rectangle.x = screenWidth / 2 - offsetX;
	rectangle.y = screenHeight / 2;
}

void Player::Movement()
{
	timeElapsed += GetFrameTime();

	if ((IsKeyDown(KEY_SPACE) && velocity >= gravity))
	{
		timeElapsed = 0.5f;
		acceleration = 0;
		velocity = -gravity * upForce;
	}
	else
		acceleration += gravity * timeElapsed;

	if (acceleration > gravity)
		acceleration = gravity;

	velocity += acceleration * timeElapsed;

	if (rectangle.y <= screenHeight - rectangle.height)
	{
		rectangle.y += velocity * timeElapsed;
	}
}

void Player::Draw()
{
	DrawRectangleRec(GetRectangle(), GetColor());
}
