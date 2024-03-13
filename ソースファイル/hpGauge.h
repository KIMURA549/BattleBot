#pragma once

#include"gameObject.h"

struct Gauge {
	class Sprite* gauge;
	float max;
	float old;
};

class HpGauge :public GameObject {
private:
	ID3D11VertexShader* m_VertexShader = nullptr;
	ID3D11PixelShader* m_PixelShader = nullptr;
	ID3D11InputLayout* m_VertexLayout = nullptr;

	Gauge m_leftNone;
	Gauge m_left;
	Gauge m_rightNone;
	Gauge m_right;

public:
	void Init();
	void Uninit();
	void Update();
	void Draw();
};