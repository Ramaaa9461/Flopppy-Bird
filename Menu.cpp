#include "Menu.h"

const int screenWidth = 800;
const int screenHeight = 450;

const int fontSize = 40;

int rectangleWidth = 250;
int rectangleHeight = 250;

int txtSize = 50;

int PlayButton1Position = 150;
int PlayButton2Position = 200;
int OptionsButtonPosition = 250;
int CreditsButtonPosition = 300;
int ExitButtonPosition = 350;


int releaseButtonOffSet = 50;
int releaseButtonPosition = screenHeight - releaseButtonOffSet;

int optionButtonHeight = 20;
int optionButtonWidth = 20;

Menu::Menu()
{
	menuScene = MenuScene::PLAY;

	for (int i = 0; i < totalButtons; i++)
		_button[i] = new Button();

	releaseVersion = new Button();
}

Menu::~Menu()
{
	for (int i = 0; i < totalButtons; i++)
		delete _button[i];
	UnloadTextures();
}

void Menu::SetAudioManager(AudioManager* am)
{
	audioManager = am;
}

void Menu::SetSceneManager(SceneManager* sm)
{
	sceneManager = sm;
}

void Menu::InMenu()
{
	Input();
	Update();
	Draw();
}

void Menu::Input()
{
	Menu::CheckOptionState();
	Menu::CheckInput();
}

void Menu::Update()
{
	audioManager->PlayMenuMusic();
	Menu::SetMenuOption();
}

void Menu::Draw()
{
	DrawText("Flappy Birds", GetScreenWidth() / 2 - 250 , 10,80, YELLOW);
	
	DrawRectangle(295, PlayButton1Position, 245, 45, DARKBLUE);
	DrawButton(_button[0], "1 PLAYER");
	
	DrawRectangle(295, PlayButton2Position, 260, 45, DARKBLUE);
	DrawButton(_button[1], "2 PLAYER");

	DrawRectangle(295, OptionsButtonPosition, 285, 45, DARKBLUE);
	DrawButton(_button[2], "CONTROLS");

	DrawRectangle(295, CreditsButtonPosition, 240, 45, DARKBLUE);
	DrawButton(_button[3], "CREDITS");

	DrawRectangle(295, ExitButtonPosition, 135, 45, DARKBLUE);
	DrawButton(_button[4], "EXIT");

	DrawButton(releaseVersion, "version 1.0");

	DrawLogo();
}

void Menu::InitMenuData()
{
	LoadTextures();

	SetButtonsData(_button[0], screenWidth * 0.5 - 100, PlayButton1Position, 250, 300);
	SetButtonsData(_button[1], screenWidth * 0.5 - 100, PlayButton2Position, 250, 300);
	SetButtonsData(_button[2], screenWidth * 0.5 - 100, OptionsButtonPosition, 250, 300);
	SetButtonsData(_button[3], screenWidth * 0.5 - 100, CreditsButtonPosition, 250, 300);
	SetButtonsData(_button[4], screenWidth * 0.5 - 100, ExitButtonPosition, 250, 300);

	SetButtonsData(releaseVersion, screenWidth * 0.65, releaseButtonPosition, 200, 300);
}

void Menu::DrawLogo()
{
	DrawTexture(logo, 0, GetScreenHeight() - logo.height, WHITE);
	//DrawTextureEx(logo, { screenWidth - 200,screenHeight - 170 }, 0, 0.4, WHITE);
}

void Menu::SetButtonsData(Button _button[], int posX, int posY, int height, int width)
{
	_button->SetRectanglePos(posX, posY);

	_button->SetHeight(height);
	_button->SetWidth(width);

	_button->SetColor(YELLOW);
}

void Menu::LoadTextures()
{
	logo = LoadTexture("res/assets/Cachuflito.png");
	logo.width *= 0.1;
	logo.height *= 0.1;
}

void Menu::UnloadTextures()
{
	UnloadTexture(logo);
}

void Menu::DrawButton(Button _button[], const char text[])
{
	_button->DrawButton(_button->GetRectangle(), text);
}

void Menu::CheckOptionState()
{
	if (IsKeyReleased(KEY_DOWN))
	{
		switch (menuScene)
		{
		case MenuScene::PLAY:
			menuScene = MenuScene::PLAY_2J;
			break;
		case MenuScene::PLAY_2J:
			menuScene = MenuScene::OPTIONS;
			break;
		case MenuScene::OPTIONS:
			menuScene = MenuScene::CREDITS;
			break;
		case MenuScene::CREDITS:
			menuScene = MenuScene::EXIT;
			break;
		case MenuScene::EXIT:
			menuScene = MenuScene::PLAY;
			break;
		default:
			break;
		}
	}
	else if (IsKeyReleased(KEY_UP))
	{
		switch (menuScene)
		{
		case MenuScene::PLAY:
			menuScene = MenuScene::EXIT;
			break;
		case MenuScene::PLAY_2J:
			menuScene = MenuScene::PLAY;
			break;
		case MenuScene::OPTIONS:
			menuScene = MenuScene::PLAY_2J;
			break;
		case MenuScene::CREDITS:
			menuScene = MenuScene::OPTIONS;
			break;
		case MenuScene::EXIT:
			menuScene = MenuScene::CREDITS;
			break;
		default:
			break;
		}
	}
}

void Menu::CheckInput()
{
	if (IsKeyReleased(KEY_ENTER))
	{
		switch (menuScene)
		{
		case MenuScene::PLAY:
			twoPlayers = false;
			sceneManager->SetSceneManager(Scene::GAME);
			break;
		case MenuScene::PLAY_2J:
			twoPlayers = true;
			sceneManager->SetSceneManager(Scene::GAME);
			break;
		case MenuScene::OPTIONS:
			sceneManager->SetSceneManager(Scene::RULES);
			break;
		case MenuScene::CREDITS:
			sceneManager->SetSceneManager(Scene::CREDITS);
			break;
		case MenuScene::EXIT:
			sceneManager->SetSceneManager(Scene::EXIT);
			break;
		default:
			break;
		}
		audioManager->PlayOptionSound();
	}
}

void Menu::SetMenuOption()
{
	switch (menuScene)
	{
	case MenuScene::PLAY:

		_button[(int)MenuScene::PLAY]->SetActive(true);
		break;
	case MenuScene::PLAY_2J:

		_button[(int)MenuScene::PLAY_2J]->SetActive(true);
		break;
	case MenuScene::OPTIONS:

		_button[(int)MenuScene::OPTIONS]->SetActive(true);
		break;
	case MenuScene::CREDITS:

		_button[(int)MenuScene::CREDITS]->SetActive(true);
		break;
	case MenuScene::EXIT:

		_button[(int)MenuScene::EXIT]->SetActive(true);
		break;
	}

	SetButtonsToFalse();
}

void Menu::SetButtonsToFalse()
{
	for (int i = 0; i < totalButtons; i++)
	{
		if (i != (int)menuScene)
		{
			_button[i]->SetActive(false);
		}
	}
}

bool Menu::GetTwoPlayers()
{
	return twoPlayers;
}

