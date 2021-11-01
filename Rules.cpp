#include "Rules.h"
#include "raylib.h"

const int fontSize = 28;

void Rules::InRules()
{
	CheckInput();
	DrawRules();
}

void Rules::DrawRules()
{
	DrawText("Controls", GetScreenWidth() / 2 - 250, 10, 80, YELLOW);

	DrawText("Player 1 jumps with the \"Space\" key", 10, 150, fontSize, YELLOW);
	DrawText("Player 2 jumps with the \"Up Arrow\"", 10, 200, fontSize, YELLOW);
	DrawText("with the \"p\" key you can pause", 10, 250, fontSize, YELLOW);
	DrawText("with the \"esc\" key and exit the game", 10, 300, fontSize, YELLOW);

	DrawText("Press enter to continue...", 10, 400, fontSize, YELLOW);
}

void Rules::SetSceneManager(SceneManager* sm)
{
	scene = sm;
}

void Rules::ReturnToMenu()
{
	scene->SetSceneManager(Scene::MENU);
}

void Rules::CheckInput()
{
	if (IsKeyReleased(KEY_ENTER))
	{
		ReturnToMenu();
	}
}
