#pragma once
#include"model.h"
#include"component.h"
#include"transform.h"
class CreateModel : public Component
{
private:

	Model* m_Model{};

	//Transform* m_transform;
/*
	ID3D11VertexShader* m_VertexShader = nullptr;
	ID3D11PixelShader* m_PixelShader = nullptr;
	ID3D11InputLayout* m_VertexLayout = nullptr;
*/
public:
	void Init(const char* ModelName);
	void Uninit();
	void Update();
	void Draw();
/*
	void SetShader(const char* VSName, const char* PSName);

	void SetPosition(D3DXVECTOR3 pos) {
		m_transform->SetPosition(pos);
	}
	void SetRotation(D3DXVECTOR3 rot) {
		m_transform->SetRotation(rot);
	}
	void SetScale(D3DXVECTOR3 scl) {
		m_transform->SetScale(scl);
	}

	Transform GetTransform() {
		return *m_transform;
	}*/
};
