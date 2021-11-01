#include "Paralax.h"



Paralax::Paralax()
{
	scrollingBack = 0.0f;
	scrollingMid = 0.0f;
	scrollingFore = 0.0f;

}

Paralax::~Paralax()
{
	UnloadTexture(front);
	UnloadTexture(middle);
	UnloadTexture(back);
}

void Paralax::LoadTextures()
{
	 front = LoadTexture("parallax/front.png");

	 middle = LoadTexture("parallax/middle.png");

	 back = LoadTexture("parallax/back.png");

	float scale = 1.6f;
	back.height *= scale;
	back.width *= scale;

	middle.height *= scale;
	middle.width *= scale;

	front.height *= scale;
	front.width *= scale;
}

void Paralax::Update()
{
	scrollingBack -= 200.0f * GetFrameTime();
	scrollingMid -= 350.0f * GetFrameTime();
	scrollingFore -= 400.0f * GetFrameTime();

	if (scrollingBack <= -back.width * 2)
	{
		scrollingBack = 0;
	}
	if (scrollingMid <= -middle.width * 2)
	{
		scrollingMid = 0;
	}
	if (scrollingFore <= -front.width * 2)
	{
		scrollingFore = 0;
	}
}

void Paralax::Draw()
{

	DrawTextureEx(back, { scrollingBack, 0 }, 0.0f, 2.0f, WHITE);
	DrawTextureEx(back, { back.width * 2 + scrollingBack, 0 }, 0.0f, 2.0f, WHITE);

	DrawTextureEx(middle, { scrollingMid, 0 }, 0.0f, 2.0f, WHITE);
	DrawTextureEx(middle, { middle.width * 2 + scrollingMid, 0 }, 0.0f, 2.0f, WHITE);

	DrawTextureEx(front, { scrollingFore, 115 }, 0.0f, 2.0f, WHITE);
	DrawTextureEx(front, { front.width * 2 + scrollingFore, 115 }, 0.0f, 2.0f, WHITE);

}



//Musica : https://opengameart.org/content/chiptune-exploration