#pragma once
#include"GameObject.h"
#include"transform.h"
class Parts;

class Field : public GameObject
{
private:
	Parts* m_field;
	D3DMATRIX m_matrix{};

public:
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
};
