#include"main.h"
#include "moveManager.h"
#include"input.h"

void MoveManager::Init(float ground)
{
	m_ground = ground;
}

void MoveManager::Update()
{
	m_Velocity.y -= 0.01f;

	//êÅÇ´îÚÇŒÇµóp
	if (m_Velocity.x != 0.0f) {
		m_Velocity.x *= 0.99f;
		if (m_Velocity.x <= 0.0001f && m_Velocity.x >= -0.0001f) {
			m_Velocity.x = 0.0f;
		}
	}

	D3DXVECTOR3 m;
	m = m_Velocity;

	if (m_NextPos.x >= FIELD_LIMIT) {
		m_NextPos.x = FIELD_LIMIT;
	}
	else if (m_NextPos.x <= -FIELD_LIMIT) {
		m_NextPos.x = -FIELD_LIMIT;
	}

	m_NextPos += m_Velocity;


	////ê⁄ín
	if (m_NextPos.y < m_ground && m_Velocity.y < 0.0f) {
		m_NextPos.y = m_ground;
		m_Velocity.y = 0.0f;
		m_Velocity.x = 0.0f;
		m_Velocity.z = 0.0f;
		m_fly = false;
	}
}

void MoveManager::MoveX(float x)
{
	m_NextPos.x += x;
}

void MoveManager::Jump(float vely)
{
	if (m_fly == false) {
		m_Velocity.y = vely;
		m_fly = true;
	}
}

bool MoveManager::GetFly()
{
	return m_fly;
}

