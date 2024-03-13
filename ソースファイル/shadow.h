#pragma once
#include"component.h"
class Shadow : public Component
{
private:
	D3DXVECTOR3 m_pos;
	ID3D11Buffer* m_VertexBuffer = nullptr;
	ID3D11ShaderResourceView* m_Texture = nullptr;

	ID3D11VertexShader* m_VertexShader = nullptr;
	ID3D11PixelShader* m_PixelShader = nullptr;
	ID3D11InputLayout* m_VertexLayout = nullptr;

	bool m_use = false;
	//Sprite m_shadow;

public:
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;

	void SetPosX(float x) {
		m_pos.x = x;
	}
	void SetPosY(float y) {
		m_pos.y = y;
	}
	void SetPosZ(float z) {
		m_pos.z = z;
	}

	void SetUse(bool use) {
		m_use = use;
	}

	void SetShadowSize(float size);

};
