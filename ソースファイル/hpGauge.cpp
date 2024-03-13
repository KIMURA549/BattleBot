#include"main.h"
#include"manager.h"
#include"renderer.h"

#include"scene.h"

#include "player.h"
#include"enemy.h"

#include "hpGauge.h"
#include"component.h"
#include"sprite.h"


#define GAUGE_WHIDTH 500.0f

void HpGauge::Init()
{
	Renderer::CreateVertexShader(&m_VertexShader, &m_VertexLayout,
		"shader\\unlitTextureVS.cso");
	Renderer::CreatePixelShader(&m_PixelShader,
		"shader\\unlitTexturePS.cso");


	Scene* scene = Manager::GetScene();
	Player* player = scene->GetGameObject<Player>();
	Enemy* enemy = scene->GetGameObject<Enemy>();

	m_left.gauge = AddComponent<Sprite>();
	m_left.gauge->Init(50.0f, 40.0f, GAUGE_WHIDTH, 30.0f, "asset\\texture\\white.png");
	m_left.gauge->SetColor(D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f));
	m_left.max = player->GetHp();
	m_left.old = player->GetHp();

	m_leftNone.gauge = AddComponent<Sprite>();
	m_leftNone.gauge->Init(50.0f, 40.0f, GAUGE_WHIDTH, 30.0f, "asset\\texture\\white.png");
	m_leftNone.gauge->SetColor(D3DXCOLOR(0.3f, 0.3f, 0.3f, 1.0f));
	
	m_right.gauge = AddComponent<Sprite>();
	m_right.gauge->Init(SCREEN_WIDTH - 50.0f, 70.0f, -GAUGE_WHIDTH, -30.0f, "asset\\texture\\white.png");
	m_right.gauge->SetColor(D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f));
	m_right.max = enemy->GetHp();
	m_right.old = enemy->GetHp();

	m_rightNone.gauge = AddComponent<Sprite>();
	m_rightNone.gauge->Init(SCREEN_WIDTH - 50.0f, 70.0f, -GAUGE_WHIDTH, -30.0f, "asset\\texture\\white.png");
	m_rightNone.gauge->SetColor(D3DXCOLOR(0.3f, 0.3f, 0.3f, 1.0f));
}
void HpGauge::Uninit()
{
	if (m_VertexLayout != NULL) {
		m_VertexLayout->Release();
	}
	if (m_VertexShader != NULL) {
		m_VertexShader->Release();
	}
	if (m_PixelShader != NULL) {
		m_PixelShader->Release();
	}


}
void HpGauge::Update()
{
	Scene* scene = Manager::GetScene();
	Player* player = scene->GetGameObject<Player>();
	Enemy* enemy = scene->GetGameObject<Enemy>();

	if (m_left.old > player->GetHp()) {
		m_left.old = player->GetHp();
		m_left.gauge->Init(50.0f, 40.0f, GAUGE_WHIDTH * (m_left.old / m_left.max), 30.0f, "asset\\texture\\white.png");

	}

	if (m_right.old > enemy->GetHp()) {
		m_right.old = enemy->GetHp();
		m_right.gauge->Init(SCREEN_WIDTH - 50.0f, 70.0f, -GAUGE_WHIDTH * (m_right.old / m_right.max), -30.0f, "asset\\texture\\white.png");

	}

}
void HpGauge::Draw()
{
	//入力レイアウト
	Renderer::GetDeviceContext()->IASetInputLayout(m_VertexLayout);

	//シェーダー設定
	Renderer::GetDeviceContext()->VSSetShader(m_VertexShader, NULL, 0);
	Renderer::GetDeviceContext()->PSSetShader(m_PixelShader, NULL, 0);

	//マトリクス設定
	Renderer::SetWorldViewProjection2D();

	m_leftNone.gauge->Draw();
	m_left.gauge->Draw();
	m_rightNone.gauge->Draw();
	m_right.gauge->Draw();
}