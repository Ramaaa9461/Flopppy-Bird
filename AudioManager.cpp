#include "AudioManager.h"
const float standardVolume = 0.4f;

AudioManager::AudioManager()
{
	InitAudioDevice();
	InitMusic();

	musicInited = false;
}

AudioManager::~AudioManager()
{

}

void AudioManager::InitMusic()
{
	menuMusic = LoadMusicStream("res/assets/Music/awesomeness.wav");
	gameMusic = LoadMusicStream("res/assets/Music/exploration.wav");
	optionSound = LoadSound("res/assets/Music/sound.ogg");
}

Music AudioManager::GetMenuMusic()
{
	return menuMusic;
}

void AudioManager::StopAllMusics()
{
	StopMusicStream(menuMusic);
	StopMusicStream(gameMusic);
}

void AudioManager::PlayMenuMusic()
{
	StopMusicStream(gameMusic);
	PlayMusicStream(menuMusic);
	SetMusicVolume(menuMusic, standardVolume);
	UpdateMusicStream(menuMusic);
}

void AudioManager::PlayGameMusic()
{
	PlayMusicStream(gameMusic);
	StopMusicStream(menuMusic);
	SetMusicVolume(gameMusic, standardVolume);
	UpdateMusicStream(gameMusic);
}

void AudioManager::PlayOptionSound()
{
	SetSoundVolume(optionSound, standardVolume + 0.4f);
	PlaySound(optionSound);
}
