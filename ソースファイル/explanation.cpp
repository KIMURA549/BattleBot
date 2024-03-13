#include"main.h"
#include"manager.h"
#include "explanation.h"
#include"game.h"
#include"input.h"

#include"polygon2D.h"
#include"fade.h"

void Explanation::Init()
{
	Scene::AddGameObject<Polygon2D>(0)->SetPolygon2D(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT, "asset\\texture\\explanation.png");
	m_fade = Scene::AddGameObject<Fade>(1);
	m_fade->Init();
	m_fade->StartFadeIn();
}

void Explanation::Update()
{
	Scene::Update();

	if (m_fade->GetFadeEnd() && m_next == true) {
		Manager::SetScene<Game>();
	}

	if (m_next == false) {
		if (Input::GetKeyTrigger('J') || Input::GetKeyTrigger('K') ||
			Input::GetKeyTrigger('L') || Input::GetKeyTrigger('I')) {
			m_next = true;
			m_fade->StartFadeOut();
		}
	}
}
