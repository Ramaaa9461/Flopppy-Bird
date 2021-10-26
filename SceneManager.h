#pragma once

enum class Scene { MENU = 1, GAME, RULES, CREDITS, EXIT, CHOOSEMODE, ENDGAME };


class SceneManager
{
private:
	Scene scene;
	bool twoPlayers;
public:
	SceneManager();
	~SceneManager();

	Scene GetScene();

	void SetSceneManager(Scene _scene);
};

