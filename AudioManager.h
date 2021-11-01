#pragma once
#include "raylib.h"

class AudioManager
{
private:
	Music menuMusic;
	Music gameMusic;
	Sound optionSound;

	bool menuMusicInited;
	bool gameMusicInited;
	bool optionSoundInited;

	bool musicInited;

public:
	AudioManager();
	~AudioManager();

	void InitMenuMusic(Music music);
	void InitGameMusic(Music music);

	Music GetMenuMusic();
	void StopAllMusics();
	void PlayMenuMusic();
	void PlayGameMusic();
	void PlayOptionSound();

};



