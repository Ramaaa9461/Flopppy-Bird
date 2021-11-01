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

	gravity = 10.0f;
	velocity = 0.0f;
	acceleration = 0.0f;

	isFalling = true;
	isAlive = true;

	//===========================================================
	parallax = new Paralax();
}

Player::~Player()
{
	delete parallax;
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

	parallax->LoadTextures();
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

void Player::Movement(int key)
{
	//FORMA ANTIGUA DE CALCULAR EL SALTO

	//timeElapsed += GetFrameTime(); 

	//if ((IsKeyDown(key)))
	//{
	//	timeElapsed = 0.5f;
	//	acceleration = 0;
	//	velocity = (-gravity * upForce) * GetFrameTime();
	//}
	//else
	//{
	//	acceleration += (gravity * timeElapsed) * GetFrameTime();
	//}

	//if (acceleration > gravity)
	//{
	//	acceleration = gravity;
	//}

	//velocity += acceleration * timeElapsed;

	//if (rectangle.y <= screenHeight - rectangle.height)
	//{
	//	rectangle.y += velocity * timeElapsed;
	//}
	//else
	//{
	//	//Evita que no se pueda saltar en el piso de la pantalla
	//	rectangle.y = rectangle.y - 1;
	//	timeElapsed = 0.5f;
	//}
	 
	//======================================================================

	//FORMA NUEVA DE CALCULAR EL SALTO :D (independiente del FrameTime)

	if (IsKeyPressed(key)) 
	{
		acceleration = 0;
		velocity = -gravity / 4;
	}

	acceleration -= (gravity * GetFrameTime());

	if (acceleration >= gravity)
	{
		acceleration = gravity;
	}
	velocity -= (acceleration * GetFrameTime());

	rectangle.y += velocity;

	if (rectangle.y > GetScreenHeight() - rectangle.height)
	{
		rectangle.y = GetScreenHeight() - rectangle.height;
	}
	if (rectangle.y < 0)
	{
		rectangle.y = 0;
	}
}


void Player::Draw(bool twoPlayers)
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
	if (!twoPlayers)
	{
		DrawText("P1", rectangle.x, rectangle.y - 10, 20, BLACK);
		DrawTexture(bird, rectangle.x - offsetX, rectangle.y - offsetY, WHITE);
	}
	else
	{
		DrawText("P2", rectangle.x - offsetX, rectangle.y, 20, BLACK);
		DrawTexture(bird, rectangle.x - offsetX, rectangle.y - offsetY, SKYBLUE);
	}
	//DrawRectangleRec(GetRectangle(), GetColor());
//=========================================================================

}
Paralax* Player::GetParalax()
{
	return parallax;
}

void Player::SetIsAlive(bool isAlive)
{
	this->isAlive = isAlive;
}
bool Player::GetIsAlive()
{
	return isAlive;
}