#pragma once
#include "component.h"

class Sprite :public Component
{
private:
	ID3D11Buffer* m_VertexBuffer = nullptr;
	ID3D11ShaderResourceView* m_Texture = nullptr;

	D3DXCOLOR m_Color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
public:
	void Init(float x, float y, float Width, float Height, const char* TeextureName);
	void Uninit();
	void Update();
	void Draw();

	void SetColor(D3DXCOLOR color) { m_Color = color; }

};