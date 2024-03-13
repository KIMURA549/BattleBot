#pragma once
#include"main.h"
#include "component.h"

class Transform :public Component
{
private:
	D3DXVECTOR3 m_Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 m_Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	D3DXVECTOR3 m_Size = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
public:
	void Init()override{}
	void Uninit()override{}
	void Update()override{}
	void Draw()override{}

	void SetPosition(D3DXVECTOR3 pos) {
		m_Position = pos;
	}
	void SetRotation(D3DXVECTOR3 rot) {
		m_Rotation = rot;
	}
	void SetScale(D3DXVECTOR3 scl) {
		m_Scale = scl;
	}
	void SetSize(D3DXVECTOR3 size) {
		m_Size = size;
	}


	D3DXVECTOR3 GetPosition() {
		return m_Position;
	}
	D3DXVECTOR3 GetRotation() {
		return m_Rotation;
	}
	D3DXVECTOR3 GetScale() {
		return m_Scale;
	}
	D3DXVECTOR3 GetSize() {
		return m_Size;
	}


	//前方ベクトル
	D3DXVECTOR3 GetForward() {

		//4×4マトリクス
		D3DXMATRIX rot;
		//長さも１になっている（正規化もする）
		D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);

		D3DXVECTOR3 forward;
		forward.x = rot._31;
		forward.y = rot._32;
		forward.z = rot._33;

		return forward;
	}

	//右ベクトル
	D3DXVECTOR3 GetRight() {

		//4×4マトリクス
		D3DXMATRIX rot;
		//長さも１になっている（正規化もする）
		D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);

		D3DXVECTOR3 forward;
		forward.x = rot._11;
		forward.y = rot._12;
		forward.z = rot._13;

		return forward;
	}
};
