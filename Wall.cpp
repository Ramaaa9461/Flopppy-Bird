#include "Wall.h"

Wall::Wall()
{
    _color = GREEN;
    _speed = 300;
    rectangle.width = 10;
    rectangle.height = 350;
}

Wall::~Wall()
{

}

Rectangle Wall::GetRectangle()
{
    return rectangle;
}

Color Wall::GetColor()
{
    return _color;
}

int Wall::GetSpeed()
{
    return _speed;
}

void Wall::SetSpeed(int speed)
{
    _speed = speed;
}

void Wall::SetColor(Color color)
{
    _color = color;
}

void Wall::SetRectangle(int width, int height)
{
    rectangle.width = width;
    rectangle.height = height;
}

void Wall::SetRectanglePos(int posX, int posY)
{
    rectangle.x = posX;
    rectangle.y = posY;
}

void Wall::Draw()
{
    DrawRectangleRec(GetRectangle(), GetColor());
}

void Wall::Movement()
{
    rectangle.x -= _speed * GetFrameTime();
}

