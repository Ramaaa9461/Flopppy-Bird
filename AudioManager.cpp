#include "AudioManager.h"

const float standardVolume = 0.3f;

AudioManager::AudioManager()
{
	InitAudioDevice();

	musicInited = false;
}

AudioManager::~AudioManager()
{

}

void AudioManager::InitMenuMusic(Music music)
{
	if (!menuMusicInited)
	{
		menuMusic = music;
		menuMusicInited = true;
	}
}
void AudioManager::InitGameMusic(Music music)
{
	if (!gameMusicInited)
	{
		gameMusic = music;
		gameMusicInited = true;
	}
}

Music AudioManager::GetMenuMusic()
{
	return menuMusic;
}

void AudioManager::StopAllMusics()
{
	StopMusicStream(gameMusic);
	StopMusicStream(menuMusic);

}

void AudioManager::PlayMenuMusic()
{
	//if (menuMusicInited)
	//{
	//	PlayMusicStream(menuMusic);
	//	StopMusicStream(gameMusic);
	//	SetMusicVolume(menuMusic, standardVolume);
	//	UpdateMusicStream(menuMusic);
	//}
}

void AudioManager::PlayGameMusic()
{
	//if (gameMusicInited)
	//{
	//	PlayMusicStream(gameMusic);
	//	StopMusicStream(menuMusic);
	//	SetMusicVolume(gameMusic, standardVolume);
	//	UpdateMusicStream(gameMusic);
	//}
}

void AudioManager::PlayOptionSound()
{

}


