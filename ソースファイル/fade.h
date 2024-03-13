#pragma once
#include"GameObject.h"

enum FadeState {
	FADEOUT,
	FADEIN,
	WAIT,
};

class Fade : public GameObject
{
private:
	ID3D11VertexShader* m_VertexShader = nullptr;
	ID3D11PixelShader* m_PixelShader = nullptr;
	ID3D11InputLayout* m_VertexLayout = nullptr;

	FadeState m_state;
	float m_alpha;

	class Sprite* m_sprite;

public:
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;

	void StartFadeIn();
	void StartFadeOut();

	bool GetFadeEnd() {
		if (m_state == WAIT) {
			return true;
		}
		else {
			return false;
		}
	}
};