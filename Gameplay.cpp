#include "Gameplay.h"

#include <iostream>

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
	player->GetParalax()->Update();

	for (int i = 0; i < totalPairs; i++)
	{
		pair[i]->Movement();
	}

	player->Movement(KEY_SPACE);

	if (twoPlayers)
	{
		player2->Movement(KEY_UP);
	}

	Collision();
	
	if (twoPlayers)
	{
		if (!player->GetIsAlive() || !player2->GetIsAlive())
		{
			Winner();
		}
	}
}

void Gameplay::Draw()
{
	player->GetParalax()->Draw();
	player->Draw(false);

	if (twoPlayers)
	{
		player2->Draw(true);
	}

	for (int i = 0; i < totalPairs; i++)
	{
		pair[i]->Draw();
	}

	if (!twoPlayers)
	{
	DrawPlayerPoints(player, 200, 30);
	}
}

void Gameplay::SetSceneManager(SceneManager* sc)
{
	scene = sc;
}

void Gameplay::DrawPlayerPoints(Player* player, int x, int y)
{
	hud->DrawPoints(player->GetPoints(), x, y, fontSize, YELLOW);
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
	float time = 0;
	float maxTime = 3;

	for (int i = 0; i < totalPairs; i++)
	{
		if (CheckCollisionRecs(player->GetRectangle(), pair[i]->GetWall1Collider()))
		{
			player->ResetData();
			endGameScreen->ResetWinners();
			ResetNumberCounter();
			ResetWallsPositions();
			player->SetIsAlive(false);
			
		}
		else if (CheckCollisionRecs(player->GetRectangle(), pair[i]->GetWall2Collider()))
		{
			player->ResetData();
			endGameScreen->ResetWinners();
			ResetNumberCounter();
			ResetWallsPositions();
			player->SetIsAlive(false);
		}
		else if (CheckCollisionRecs(player->GetRectangle(), pair[i]->GetBlankCollider()) && !alreadyAddedPoint[i])
		{
			player->AddPoints(1);
			alreadyAddedPoint[i] = true;
		}
	}

	if (twoPlayers)
	{
		for (int i = 0; i < totalPairs; i++)
		{
			if (CheckCollisionRecs(player2->GetRectangle(), pair[i]->GetWall1Collider()))
			{
				player2->ResetData();
				endGameScreen->ResetWinners();
				ResetNumberCounter();
				ResetWallsPositions();
				player2->SetIsAlive(false);
			}
			else if (CheckCollisionRecs(player2->GetRectangle(), pair[i]->GetWall2Collider()))
			{
				player2->ResetData();
				endGameScreen->ResetWinners();
				ResetNumberCounter();
				ResetWallsPositions();
				player2->SetIsAlive(false);
			}
			else if (CheckCollisionRecs(player2->GetRectangle(), pair[i]->GetBlankCollider()) && !alreadyAddedPoint[i])
			{
				player2->AddPoints(1);
				alreadyAddedPoint[i] = true;
			}
		}

	}
		ResetCounterBooleans();
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

void Gameplay::Winner()
{
	if (!player->GetIsAlive() && !player2->GetIsAlive())
	{
		player->SetIsAlive(true);
		player2->SetIsAlive(true);
		endGameScreen->SetTie(true);

	}
	else if(!player->GetIsAlive())
	{
		player->SetIsAlive(true);
		endGameScreen->SetWinPlayer2(true);
	}
	else if (!player2->GetIsAlive())
	{
		player2->SetIsAlive(true);
		endGameScreen->SetWinPlayer1(true);
	}

	scene->SetSceneManager(Scene::ENDGAME);
}

void Gameplay::ResetPlayerData(Player* player)
{
	player->SetPoints(0);
	player->SetHeight(30);
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
	SetPlayerPosition(player, posX, posY);

	if (twoPlayers)
	{
		SetPlayerPosition(player2, posX , posY);
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