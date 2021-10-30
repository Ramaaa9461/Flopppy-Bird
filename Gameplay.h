#pragma once
#include "Player.h"
#include "HUD.h"
#include "InGamePause.h"
#include "AudioManager.h"
#include "EndGameScreen.h"
#include "PairOfWalls.h"
#include "Paralax.h"

class Gameplay
{
private:

	EndGameScreen* endGameScreen;
	AudioManager* audioManager;
	SceneManager* scene;
	InGamePause* pause;

	Paralax* paralax;

	Player* player;
	HUD* hud;
	Player* player2;

	PairOfWalls* pair[4];

	bool inPause;
	bool twoPlayers;

	void Input();
	void Update();
	void Draw();
	void SetPlayerData(Player* player, int posX, int posY);
	void SetPlayerPosition(Player* player, int posX, int posY);
	void DrawPlayerPoints(Player* player, int x, int y);
	void ResetPlayerData(Player* player);
	void ResetData(Player* player);

	void Collision();
	void ResetNumberCounter();
	void ResetWallsPositions();
	void ResetCounterBooleans();

public:
	Gameplay();
	~Gameplay();

	bool GetInPause();
	bool GetTwoPlayers();

	void SetInPause(bool pause);
	void SetTwoPlayers(bool twoPlayers);

	void SetEndGameScreen(EndGameScreen* eg);
	void SetInGamePauseData();
	void SetAudioManager(AudioManager* am);
	void SetSceneManager(SceneManager* sc);
	void InGame();
	void InitGameplay();
};

