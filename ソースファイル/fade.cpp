
#include"main.h"
#include"renderer.h"
#include"component.h"
#include "fade.h"
#include"sprite.h"


void Fade::Init()
{
	Renderer::CreateVertexShader(&m_VertexShader, &m_VertexLayout,
		"shader\\unlitTextureVS.cso");
	Renderer::CreatePixelShader(&m_PixelShader,
		"shader\\unlitTexturePS.cso");

	m_sprite = AddComponent<Sprite>();
	m_sprite->Init(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT,  "asset\\texture\\black.png");

	m_sprite->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
	m_state = WAIT;
}
void Fade::Uninit()
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

	GameObject::Uninit();
}
void Fade::Update() {

	switch (m_state)
	{
	case FADEOUT:
		m_alpha += 0.01f;
		if (m_alpha >= 1.0f) {
			m_alpha = 1.0f;
			m_state = WAIT;
		}
		m_sprite->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, m_alpha));
		break;
	case FADEIN:
		m_alpha -= 0.01f;
		if (m_alpha <= 0.0f) {
			m_alpha = 0.0f;
			m_state = WAIT;
		}
		m_sprite->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, m_alpha));
		break;
	case WAIT:
		m_sprite->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
		break;
	default:
		break;
	}

	GameObject::Update();
}
void Fade::Draw()
{
	//入力レイアウト
	Renderer::GetDeviceContext()->IASetInputLayout(m_VertexLayout);

	//シェーダー設定
	Renderer::GetDeviceContext()->VSSetShader(m_VertexShader, NULL, 0);
	Renderer::GetDeviceContext()->PSSetShader(m_PixelShader, NULL, 0);

	//マトリクス設定
	Renderer::SetWorldViewProjection2D();


	GameObject::Draw();
}

void Fade::StartFadeIn()
{
	m_alpha = 1.0f;
	m_state = FADEIN;
}

void Fade::StartFadeOut()
{
	m_alpha = 0.0f;
	m_state = FADEOUT;
}
