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
	Font font = GetFontDefault();
	DrawText("Player 1 jumps with the \"Space\" key", 10, 10, fontSize, BLACK);
	DrawText("Player 2 jumps with the \"Up Arrow\"", 10, 60, fontSize, BLACK);
	DrawText("with the \"p\" key you can pause", 10, 110, fontSize, BLACK);
	DrawText("with the \"esc\" key and exit the game", 10, 160, fontSize, BLACK);
	/*DrawText("Take care if both players reach 7 points!", 10, 210, fontSize, BLACK);
	DrawText("Press |P| to pause the game while playing", 10, 260, fontSize, BLACK);*/
	DrawText("Press enter to continue...", 10, 400, fontSize, BLACK);
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
