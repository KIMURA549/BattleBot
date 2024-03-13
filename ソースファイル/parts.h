#pragma once
#include"component.h"
//
//struct Motion {
//	float fcnt;
//	D3DXVECTOR3 rotate;
//};

class Parts :public Component
{
private:
	class Transform* m_transform;

	class Model* m_Model{};

	//ÉÇÉfÉãÇ™à⁄ìÆÇµÇƒÇ¢ÇÈç≈íÜÇ©Ç«Ç§Ç©
	//bool m_move = false;

	//ïœâªë¨ìx
	//float m_speed = 0.0f;

	ID3D11VertexShader* m_VertexShader = nullptr;
	ID3D11PixelShader* m_PixelShader = nullptr;
	ID3D11InputLayout* m_VertexLayout = nullptr;

	D3DXMATRIX m_WorldMatrix{};

	//Motion m_NowMotion;
	//Motion m_NextMotion;

public:

	void Init(const char * ModelName);
	void Uninit();
	void Update();
	void Draw(D3DXMATRIX w);

	D3DXMATRIX GetWorldMatrix();

	void SetPosition(D3DXVECTOR3 pos);
	void SetRotation(D3DXVECTOR3 rot);
	void AdditionRotation(D3DXVECTOR3 rot);
	void SetScale(D3DXVECTOR3 scl);
	class Transform GetTransform();
};