#include"main.h"
#include"manager.h"
#include "result.h"
#include "title.h"
#include"input.h"

#include"polygon2D.h"
#include"fade.h"

void Result::Init()
{
	Scene::AddGameObject<Polygon2D>(0)->SetPolygon2D(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT, "asset\\texture\\result00.png");
	m_fade = Scene::AddGameObject<Fade>(1);
	m_fade->Init();
	m_fade->StartFadeIn();
}

void Result::Update()
{
	Scene::Update();


	if (m_fade->GetFadeEnd() && m_next == true) {
		Manager::SetScene<Title>();
	}

	if (Input::GetKeyTrigger(VK_RETURN)) {
		m_next = true;
		m_fade->StartFadeOut();
	}
}
