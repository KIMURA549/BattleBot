#pragma once
#include"main.h"
#include"component.h"

#define FIELD_LIMIT 10.0f

class MoveManager : public Component
{
private:
	bool m_fly = false;
	D3DXVECTOR3 m_Velocity = { 0.0f, 0.0f, 0.0f };
	D3DXVECTOR3 m_NextPos{};
	float m_ground = 0.0f;
public:
	void Init(float ground);
	void Update()override;

	void MoveX(float x);

	void Jump(float vely);

	void SetNowPosition(D3DXVECTOR3 pos) {
		m_NextPos = pos;
	}

	void SetNowPositionX(float x) {
		m_NextPos.x = x;
	}

	void SetGround(float g) {
		m_ground = g;
	}

	void SetVelocity(D3DXVECTOR3 v) {
		m_Velocity = v;
	}

	D3DXVECTOR3 GetNextPosition() {
		return m_NextPos;
	}

	bool GetFly();
};

