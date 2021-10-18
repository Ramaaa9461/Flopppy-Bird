#include "Player.h"

const int screenWidth = 800;
const int screenHeight = 450;

float timeElapsed = 0.5f;
float timeElapsedForAnim = 0;

const int anims = 3;

int actualAnimation = 0;


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

void Player::LoadTextures()
{
	animation[0] = LoadTexture("res/assets/AguilaPose1.png");
	animation[1] = LoadTexture("res/assets/AguilaPose2.png");
	animation[2] = LoadTexture("res/assets/AguilaPose3.png");
}

void Player::ResetData()
{
	int offsetX = 200;

	rectangle.x = screenWidth / 2 - offsetX;
	rectangle.y = screenHeight / 2;

	velocity = 0;

	timeElapsed = 0.5f;

	points = 0;
}

void Player::Movement()
{
	timeElapsed += GetFrameTime();

	if ((IsKeyDown(KEY_SPACE)))
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
	else
	{
		//Evita que no se pueda saltar en el piso de la pantalla
		rectangle.y = rectangle.y - 1;
		timeElapsed = 0.5f;
	}
}

void Player::Draw()
{
	float offsetX = 70;
	float offsetY = 40;
	bird = animation[actualAnimation];

	timeElapsedForAnim += GetFrameTime();

	if (timeElapsedForAnim < 0.1)
	{
		actualAnimation = 0;
	}
	else if (timeElapsedForAnim < 0.2)
	{
		actualAnimation = 1;
	}
	else if (timeElapsedForAnim < 0.3)
	{
		actualAnimation = 2;
	}
	else if (timeElapsedForAnim < 0.4)
	{
		actualAnimation = 0;
		timeElapsedForAnim = 0;
	}

	DrawTexture(bird, rectangle.x - offsetX, rectangle.y - offsetY, WHITE);
	//DrawRectangleRec(GetRectangle(), GetColor());
}
