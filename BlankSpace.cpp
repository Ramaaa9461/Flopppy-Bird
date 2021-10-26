#include "BlankSpace.h"

BlankSpace::BlankSpace()
{
    _color = GREEN;
    _speed = 300;

    rectangle.width = 10;
    rectangle.height = 200;
}

BlankSpace::~BlankSpace()
{

}

Rectangle BlankSpace::GetRectangle()
{
    return rectangle;
}

Color BlankSpace::GetColor()
{
    return _color;
}

int BlankSpace::GetSpeed()
{
    return _speed;
}

void BlankSpace::SetSpeed(int speed)
{
    _speed = speed;
}

void BlankSpace::SetColor(Color color)
{
    _color = color;
}

void BlankSpace::SetRectangle(int width, int height)
{
    rectangle.width = width;
    rectangle.height = height;
}

void BlankSpace::SetRectanglePos(int posX, int posY)
{
    rectangle.x = posX;
    rectangle.y = posY;
}

void BlankSpace::Movement()
{
    rectangle.x -= _speed * GetFrameTime();
}

