#include "Gameplay.h"
#include <iostream>
#include <string>

const int screenWidth = 800;
const int screenHeight = 450;
const int fontSize = 40;
const int pointsToWin = 10;

int offset = 60;

int timeElapsed = 0;

const int totalPairs = 4;

bool alreadyAddedPoint[totalPairs] = { false };

Gameplay::Gameplay()
{
	player = new Player();
	hud = new HUD();
	pause = new InGamePause();

	float offset = 200;

	for (int i = 0; i < totalPairs; i++)
	{
		pair[i] = new PairOfWalls(screenWidth + offset * i, GetRandomValue(0, screenHeight - offset));
	}

	inPause = false;
}

Gameplay::~Gameplay()
{
	delete player;
	delete hud;
	delete pause;

	for (int i = 0; i < totalPairs; i++)
	{
		delete pair[i];
	}
}

void Gameplay::InGame()
{
	Input();
	if (!pause->GetInPause())
	{
		Update();
	}
	else
	{
		pause->InPause();
		if (scene->GetScene() == Scene::MENU)
		{
			ResetData(player);
		}
	}
	audioManager->PlayGameMusic();
	Draw();
}

bool Gameplay::GetInPause()
{
	return inPause;
}

void Gameplay::SetInPause(bool pause)
{
	inPause = pause;
}

void Gameplay::Input()
{
	if (IsKeyReleased(KEY_P))
	{
		pause->SetInPause(!pause->GetInPause());
	}
}

void Gameplay::Update()
{
	for (int i = 0; i < totalPairs; i++)
	{
		pair[i]->Movement();
	}

	player->Movement();


	Collision();
}

void Gameplay::Draw()
{
	player->Draw();

	for (int i = 0; i < totalPairs; i++)
	{
		pair[i]->Draw();
	}

	DrawPlayerPoints(player, 300, 50);
}

void Gameplay::SetSceneManager(SceneManager* sc)
{
	scene = sc;
}

void Gameplay::DrawPlayerPoints(Player* player, int x, int y)
{
	hud->DrawPoints(player->GetPoints(), x, y, fontSize, BLACK);
}


void Gameplay::ResetData(Player* player)
{
	ResetPlayerData(player);
}

void Gameplay::Collision()
{
	for (int i = 0; i < totalPairs; i++)
	{
		if (CheckCollisionRecs(player->GetRectangle(), pair[i]->GetWall1Collider()))
		{
			player->ResetData();
			ResetNumberCounter();
			ResetWallsPositions();
		}
		else if (CheckCollisionRecs(player->GetRectangle(), pair[i]->GetWall2Collider()))
		{
			player->ResetData();
			ResetNumberCounter();
			ResetWallsPositions();
		}
		else if (CheckCollisionRecs(player->GetRectangle(), pair[i]->GetBlankCollider()) && !alreadyAddedPoint[i])
		{
			player->AddPoints(1);
			alreadyAddedPoint[i] = true;
		}
	}

	for (int i = 0; i < totalPairs; i++)
	{
		if (alreadyAddedPoint[i])
		{
			if (i == 0)
			{
				alreadyAddedPoint[3] = false;
			}
			else
			{
				alreadyAddedPoint[i - 1] = false;
			}
		}
	}
	
}

void Gameplay::ResetNumberCounter()
{
	for (int i = 0; i < totalPairs; i++)
	{
		alreadyAddedPoint[i] = false;
	}
}

void Gameplay::ResetWallsPositions()
{
	float offset = 200;

	for (int i = 0; i < totalPairs; i++)
	{
		pair[i]->SetPosition(screenWidth + offset * i, GetRandomValue(0, screenHeight - offset));
	}
}

void Gameplay::ResetPlayerData(Player* player)
{
	player->SetPoints(0);
	player->SetHeight(30);
}

void Gameplay::InitGameplay()
{
	player->ResetData();

	SetInGamePauseData();

	pause->SetSceneManager(scene);
}

void Gameplay::SetEndGameScreen(EndGameScreen* eg)
{
	endGameScreen = eg;
}

void Gameplay::SetInGamePauseData()
{
	pause->InitInPauseData();
	pause->SetSceneManager(scene);
}

void Gameplay::SetAudioManager(AudioManager* am)
{
	audioManager = am;
}

void Gameplay::SetPlayerData(Player* player, int posX, int posY)
{
	SetPlayerPosition(player, posX, posY);
}

void Gameplay::SetPlayerPosition(Player* player, int posX, int posY)
{
	player->SetRectanglePos(posX, posY);
}


