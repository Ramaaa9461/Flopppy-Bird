#include "Credits.h"
#include "raylib.h"

void Credits::InCredits()
{
	CheckInput();
	DrawCredits();
}

Font font = GetFontDefault();	
int fontSize = 25;

void Credits::DrawCredits()
{
	DrawText("Credits", GetScreenWidth() / 2 - 250, 10, 80, YELLOW);

	DrawText("Created by pablo Goldman", 10, 100, fontSize, RED);
	DrawText("continued by Ramiro Guzman", 10, 130, fontSize, RED);

	DrawText("created with Raylib library", 10, 160, fontSize, RED);
	DrawText("It was programmed in the IDE Visual Studio 2019", 10, 190, fontSize, RED);
	DrawText("Library Creator: Raysan", 10, 220, fontSize, RED);

	DrawText("ART", 10, 250, fontSize + 10, BLUE);

	DrawText("Industrial Parallax Background , ansimuz: https://opengameart.org/content/industrial-parallax-background", 10, 290, fontSize-10, RED);
	
	DrawText("MUSIC", 10, 310, fontSize+10, BLUE);

	DrawText("Menu Music , mrpoly: https://opengameart.org/content/menu-music", 10, 350, fontSize - 10, RED);
	DrawText("Chiptune Exploration , ansimuz: https://opengameart.org/content/chiptune-exploration", 10, 370, fontSize - 10, RED);

	DrawText("V1.0", GetScreenWidth() - 50 , GetScreenHeight() - 25, 20, YELLOW);
	DrawText("Press enter to continue...", 10, GetScreenHeight() - fontSize-10, fontSize+10, YELLOW);
}

void Credits::SetSceneManager(SceneManager* sm)
{
	scene = sm;
}

void Credits::ReturnToMenu()
{
	scene->SetSceneManager(Scene::MENU);
}

void Credits::CheckInput()
{
	if (IsKeyReleased(KEY_ENTER))
	{
		ReturnToMenu();
	}
}
