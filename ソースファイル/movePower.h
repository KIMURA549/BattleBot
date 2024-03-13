#pragma once
#include "component.h"

class MovePower :public Component
{
private:
	D3DXVECTOR3 m_Velocity = {0.0f, 0.0f, 0.0f};
	D3DXVECTOR3 m_l = { 0.0f, 0.0f, 0.0f };
public:
	void Init();
	void Uninit();
	void Update();
	void Draw();
	
	void AddVelocity(D3DXVECTOR3 vel, float n);
	D3DXVECTOR3 GetVelocity() {
		return m_Velocity;
	}
};