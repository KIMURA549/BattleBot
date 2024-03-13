#pragma once
#include"scene.h"

enum GameState {
	START,
	FIGHT,
	WIN,
	LOSE,
	END,

	NONE,
};

class Game :public Scene {
private:
	class Fade* m_fade;
	bool m_next = false;
	class Audio* m_BGM;
	float m_delay = 0.0f;
	GameState m_state = START;
	bool m_voice = true;
	class Word* m_word;
public:
	void Init()override;
	void Uninit()override;
	void Update()override;
};