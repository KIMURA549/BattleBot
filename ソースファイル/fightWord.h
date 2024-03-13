#pragma once
#include"GameObject.h"

enum WordState {
	FIGHT_WORD,
	KO_WORD,
	WIN_WORD,
	LOSE_WORD,
};

class Word : public GameObject
{
private:
	ID3D11VertexShader* m_VertexShader = nullptr;
	ID3D11PixelShader* m_PixelShader = nullptr;
	ID3D11InputLayout* m_VertexLayout = nullptr;

	class Sprite* m_sprite;

	bool m_use = false;

	class Audio* m_voice;
public:
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;

	void SetWordTexture(WordState ws);

	void SetUse(bool use) {
		m_use = use;
	}

	void Voice();
};