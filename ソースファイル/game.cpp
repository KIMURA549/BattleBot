#include"main.h"
#include"manager.h"
#include"game.h"
#include"title.h"
#include"input.h"

#include"camera.h"
#include"field.h"
#include"player.h"
#include"enemy.h"
#include"fade.h"
#include"hpGauge.h"
#include"audio.h"
#include"fightWord.h"
void Game::Init()
{

	Scene::AddGameObject<Camera>(0);
	Scene::AddGameObject<Field>(1);
	Scene::AddGameObject<Player>(1);
	Scene::AddGameObject<Enemy>(1);
	Scene::AddGameObject<HpGauge>(2);


	m_fade = Scene::AddGameObject<Fade>(4);
	m_fade->Init();
	m_fade->StartFadeIn();

	m_delay = 30.0f;

	m_BGM = AddGameObject<GameObject>(0)->AddComponent<Audio>();
	m_BGM->Load("asset\\audio\\bgm00.wav");
	m_BGM->Play(true);

	m_word = Scene::AddGameObject<Word>(2);
	m_word->Init();
	m_word->SetWordTexture(FIGHT_WORD);
	m_word->SetUse(false);

	m_state = START;
	m_voice = true;
	m_noinput = true;
}

void Game::Uninit()
{
	Scene::Uninit();
}

void Game::Update()
{
	static float fcnt = 0.0f;

	Enemy* enemy = GetGameObject<Enemy>();
	Player* player = GetGameObject<Player>();


	switch (m_state)
	{
	case START:
		Scene::Update();
		m_fade->Update();
		if (m_fade->GetFadeEnd()) {
			m_delay -= 1.0f;
			if (m_voice == true) {
				if (m_delay <= 0.0f) {
					//ï∂éöï\é¶
					m_word->SetUse(true);
					//âπñ¬ÇÁÇ∑
					m_voice = false;
					m_word->Voice();
					m_delay = 60.0f;
				}
			}
			//ÇQïbå„äJén
			if (m_delay <= 0.0f) {
				m_word->SetUse(false);
				m_state = FIGHT;
				m_delay = 180.0f;
				m_noinput = false;
			}
		}
		break;
	case FIGHT:
		Scene::Update();

		if (player->GetHp() <= 0.0f) {
			m_word->SetWordTexture(KO_WORD);
			m_word->SetUse(true);
			//âπñ¬ÇÁÇ∑
			m_word->Voice();
			m_noinput = true;
			m_state = LOSE;
		}
		else if (enemy->GetHp() <= 0.0f) {
			m_word->SetWordTexture(KO_WORD);
			m_word->SetUse(true);
			//âπñ¬ÇÁÇ∑
			m_word->Voice();
			m_noinput = true;
			m_state = WIN;
		}
		break;
	case WIN:
		fcnt += 1.0f;
		if (fcnt >= 5.0f) {
			fcnt = 0.0f;
			Scene::Update();
		}
		m_delay -= 1.0f;
		if (m_delay <= 0.0f) {
			m_word->SetWordTexture(WIN_WORD);
			m_word->SetUse(true);
			m_word->Voice();
			m_state = GameState::END;
		}
		break;
	case LOSE:
		fcnt += 1.0f;
		if (fcnt >= 5.0f) {
			fcnt = 0.0f;
			Scene::Update();
		}
		m_delay -= 1.0f;
		if (m_delay <= 0.0f) {
			m_word->SetWordTexture(LOSE_WORD);
			m_word->SetUse(true);
			m_word->Voice();
			m_state = END;
		}

		break;
	case END:
		Scene::Update();

		if (m_next == false) {
			if (Input::GetKeyPress('J') || Input::GetKeyPress('K') ||
				Input::GetKeyPress('L') || Input::GetKeyPress('I')) {
				m_next = true;
				m_fade->StartFadeOut();
			}
		}

		if (m_fade->GetFadeEnd() == true && m_next == true) {
			Manager::SetScene<Title>();
		}
		break;
	default:
		break;
	}

}
