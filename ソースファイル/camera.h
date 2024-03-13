#pragma once
#include"GameObject.h"
class Camera : public GameObject
{
private:
	class Transform* m_transform;
	D3DXVECTOR3	m_Target{};
	D3DXMATRIX m_ViewMatrix{};
public:
	void Init()override;
	void Update()override;
	void Draw()override;

	D3DXMATRIX GetViewMatrix() {
		return m_ViewMatrix;
	}
};