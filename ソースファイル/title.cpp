#include"main.h"
#include"manager.h"
#include "title.h"
#include"explanation.h"
#include"input.h"

#include"polygon2D.h"
#include"fade.h"
#include"audio.h"

void Title::Init()
{
	Scene::AddGameObject<Polygon2D>(0)->SetPolygon2D(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT, "asset\\texture\\title.png");
	m_fade = Scene::AddGameObject<Fade>(1);
	m_fade->Init();
	m_fade->StartFadeIn();


	m_BGM = AddGameObject<GameObject>(0)->AddComponent<Audio>();
	m_BGM->Load("asset\\audio\\titlebgm.wav");
	m_BGM->Play(true);


	m_se = AddGameObject<GameObject>(0)->AddComponent<Audio>();
	m_se->Load("asset\\audio\\start.wav");
	m_next = false;
}

void Title::Update()
{
	Scene::Update();

	if (m_fade->GetFadeEnd() && m_next == true) {
		Manager::SetScene<Explanation>();
	}

	if (m_next == false) {
		if (Input::GetKeyTrigger('J') || Input::GetKeyTrigger('K') ||
			Input::GetKeyTrigger('L') || Input::GetKeyTrigger('I')) {
			m_next = true;
			m_se->Play();
			m_fade->StartFadeOut();
		}
	}
}
