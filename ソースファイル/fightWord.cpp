#include"main.h"
#include"renderer.h"
#include"component.h"
#include "fightWord.h"
#include"sprite.h"
#include"audio.h"

void Word::Init()
{
	Renderer::CreateVertexShader(&m_VertexShader, &m_VertexLayout,
		"shader\\unlitTextureVS.cso");
	Renderer::CreatePixelShader(&m_PixelShader,
		"shader\\unlitTexturePS.cso");

	m_sprite = AddComponent<Sprite>();

	m_voice = new Audio;
	m_voice->Load("asset\\audio\\fight.wav");
}
void Word::Uninit()
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
void Word::Update() {

	GameObject::Update();
}
void Word::Draw()
{
	if (m_use == true) {
		//入力レイアウト
		Renderer::GetDeviceContext()->IASetInputLayout(m_VertexLayout);

		//シェーダー設定
		Renderer::GetDeviceContext()->VSSetShader(m_VertexShader, NULL, 0);
		Renderer::GetDeviceContext()->PSSetShader(m_PixelShader, NULL, 0);

		//マトリクス設定
		Renderer::SetWorldViewProjection2D();

		GameObject::Draw();
	}
}

void Word::SetWordTexture(WordState ws)
{
	switch (ws)
	{
	case FIGHT_WORD:
		m_sprite->Init(240.0f, 200.0f, 800.0f, 200.0f, "asset\\texture\\fight.png");
		m_voice->Load("asset\\audio\\fight.wav");
		break;
	case KO_WORD:
		m_sprite->Init(390.0f, 200.0f, 500.0f, 300.0f, "asset\\texture\\ko.png");
		m_voice->Load("asset\\audio\\ko.wav");
		break;
	case WIN_WORD:
		m_sprite->Init(140.0f, 200.0f, 1000.0f, 250.0f, "asset\\texture\\win.png");
		m_voice->Load("asset\\audio\\youwin.wav");
		break;
	case LOSE_WORD:
		m_sprite->Init(100.0f, 200.0f, 1080.0f, 250.0f, "asset\\texture\\lose.png");
		m_voice->Load("asset\\audio\\youlose.wav");
		break;
	default:
		break;
	}
	m_sprite->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
}

void Word::Voice()
{
	m_voice->Play();
}


