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
	twoPlayers = true;

	player = new Player();
	player2 = new Player();

	hud = new HUD();
	hud2 = new HUD();

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
	delete player2;
	delete hud;
	delete hud2;
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
		Draw();
	}
	else
	{
		Draw();
		pause->InPause();
		if (scene->GetScene() == Scene::MENU)
		{
			ResetData(player);
			if (twoPlayers)
			{
				ResetData(player2);
			}
		}
	}
	audioManager->PlayGameMusic();
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

	player->Movement(KEY_A);
	if (twoPlayers)
	{
		player2->Movement(KEY_L);
	}

	Collision();
}

void Gameplay::Draw()
{
	player->Draw();
	if (twoPlayers)
	{
		player2->Draw();
	}

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

	if (twoPlayers)
	{
		hud2->DrawPoints(player2->GetPoints(), x, y + 50, fontSize, BLACK);
	}
}


void Gameplay::ResetData(Player* player)
{
	ResetPlayerData(player);
	if (twoPlayers)
	{
		ResetPlayerData(player2);
	}
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

	ResetCounterBooleans();
	if (twoPlayers)
	{
		for (int i = 0; i < totalPairs; i++)
		{
			if (CheckCollisionRecs(player2->GetRectangle(), pair[i]->GetWall1Collider()))
			{
				player2->ResetData();
				ResetNumberCounter();
				ResetWallsPositions();
			}
			else if (CheckCollisionRecs(player2->GetRectangle(), pair[i]->GetWall2Collider()))
			{
				player2->ResetData();
				ResetNumberCounter();
				ResetWallsPositions();
			}
			else if (CheckCollisionRecs(player2->GetRectangle(), pair[i]->GetBlankCollider()) && !alreadyAddedPoint[i])
			{
				player2->AddPoints(1);
				alreadyAddedPoint[i] = true;
			}
		}
		ResetCounterBooleans();

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

void Gameplay::ResetCounterBooleans()
{
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

void Gameplay::ResetPlayerData(Player* player)
{
	player->SetPoints(0);
	player->SetHeight(30);

	if (twoPlayers)
	{
		player2->SetPoints(0);
		player2->SetHeight(30);
	}
}

void Gameplay::InitGameplay()
{
	player->LoadTextures();
	player->ResetData();

	if (twoPlayers)
	{
		player2->LoadTextures();
		player2->ResetData();
	}

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
	SetPlayerPosition(player, posX + 10, posY);

	if (twoPlayers)
	{
		SetPlayerPosition(player2, posX - 10 , posY);

	}
}

void Gameplay::SetPlayerPosition(Player* player, int posX, int posY)
{
	player->SetRectanglePos(posX, posY);
}

bool Gameplay::GetTwoPlayers()
{
	return twoPlayers;
}

void Gameplay::SetTwoPlayers(bool twoPlayers)
{

	this->twoPlayers = twoPlayers;
}