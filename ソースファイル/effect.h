#pragma once
#include"component.h"
class Effect : public Component
{
private:
	ID3D11Buffer* m_VertexBuffer = nullptr;
	ID3D11ShaderResourceView* m_Texture = nullptr;

	ID3D11VertexShader* m_VertexShader = nullptr;
	ID3D11PixelShader* m_PixelShader = nullptr;
	ID3D11InputLayout* m_VertexLayout = nullptr;

	bool m_use = false;

	int m_Count{};
	int m_UCount;
	int m_VCount;

	float m_Usize;
	float m_Vsize;

	D3DXVECTOR3 m_pos;
	float m_size;

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

	void SetEffect(const char * TextureName, D3DXVECTOR3 pos, float size, int uCnt, int vCnt);

	bool GetUse() {
		return m_use;
	}
};
