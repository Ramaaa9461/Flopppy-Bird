#include "Credits.h"
#include "raylib.h"

void Credits::InCredits()
{
	CheckInput();
	DrawCredits();
}

void Credits::DrawCredits()
{
	Font font = GetFontDefault();
	DrawText("Credits:", 10, 10, 40, BLACK);
	DrawText("Created by pablo Goldman", 10, 60, 40, BLACK);
	DrawText("continued by Ramiro Guzman", 10, 110, 40, BLACK);

	DrawText("created with Raylib library", 10, 160, 40, BLACK);
	DrawText("It was programmed in the IDE Visual Studio 2019", 10, 210, 30, BLACK);
	DrawText("Library Creator: Raysan", 10, 260, 40, BLACK);


	DrawText("V0.3", GetScreenWidth() - 50 , GetScreenHeight() - 25, 20, BLACK);
	DrawText("Press enter to continue...", 10, 400, 40, BLACK);
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
