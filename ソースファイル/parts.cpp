#include"main.h"
#include"renderer.h"

#include"model.h"
#include"parts.h"
#include"transform.h"

void Parts::Init(const char * ModelName)
{
	//�ʒu�@��]�@���f���̑傫���@�����蔻��̑傫��
	m_transform = new Transform;
	m_transform->SetPosition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_transform->SetRotation(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_transform->SetScale(D3DXVECTOR3(1.0f, 1.0f, 1.0f));
	m_transform->SetSize(D3DXVECTOR3(1.0f, 1.0f, 1.0f));

	m_Model = new Model();
	m_Model->Load(ModelName);

	Renderer::CreateVertexShader(&m_VertexShader, &m_VertexLayout,
		"shader\\vertexLightingVS.cso");
	Renderer::CreatePixelShader(&m_PixelShader,
		"shader\\vertexLightingPS.cso");

}

void Parts::Uninit()
{
	m_Model->Unload();
	delete m_Model;

	if (m_VertexLayout != NULL) {
		m_VertexLayout->Release();
	}
	if (m_VertexShader != NULL) {
		m_VertexShader->Release();
	}
	if (m_PixelShader != NULL) {
		m_PixelShader->Release();
	}
}

void Parts::Update()
{
}
void Parts::Draw(D3DXMATRIX w)
{
	// ���[���h�}�g���b�N�X�̏������i�P�ʍs������֐��j
	D3DXMatrixIdentity(&m_WorldMatrix);
	//���̓��C�A�E�g
	Renderer::GetDeviceContext()->IASetInputLayout(m_VertexLayout);

	//�V�F�[�_�[�ݒ�
	Renderer::GetDeviceContext()->VSSetShader(m_VertexShader, NULL, 0);
	Renderer::GetDeviceContext()->PSSetShader(m_PixelShader, NULL, 0);

	//�}�g���N�X�ݒ�
	D3DXMATRIX world, scale, r, trans;
	D3DXMatrixScaling(&scale, m_transform->GetScale().x , m_transform->GetScale().y, m_transform->GetScale().z);
	D3DXMatrixRotationYawPitchRoll(&r, m_transform->GetRotation().y, m_transform->GetRotation().x, m_transform->GetRotation().z);
	D3DXMatrixTranslation(&trans, m_transform->GetPosition().x, m_transform->GetPosition().y, m_transform->GetPosition().z);

	world = scale * r *trans;
	world *= w;
	Renderer::SetWorldMatrix(&world);

	m_Model->Draw();

	//�X�P�[����1 1 1
	D3DXMatrixScaling(&scale, 1.0f, 1.0, 1.0);

	m_WorldMatrix = scale * r * trans * w;


}

D3DXMATRIX Parts::GetWorldMatrix()
{
	return m_WorldMatrix;
}

void Parts::SetPosition(D3DXVECTOR3 pos)
{
	m_transform->SetPosition(pos);
}

void Parts::SetRotation(D3DXVECTOR3 rot)
{
	m_transform->SetRotation(rot);
}

void Parts::AdditionRotation(D3DXVECTOR3 rot)
{
	m_transform->SetRotation(m_transform->GetRotation() + rot);
}

void Parts::SetScale(D3DXVECTOR3 scl)
{
	m_transform->SetScale(scl);
}

Transform Parts::GetTransform()
{
	return *m_transform;
}
