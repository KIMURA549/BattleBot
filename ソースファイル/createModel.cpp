#include"main.h"
#include"renderer.h"
#include"createModel.h"

void CreateModel::Init(const char* ModelName)
{
	////位置　回転　モデルの大きさ　当たり判定の大きさ
	//m_transform = AddComponent<Transform>();
	//m_transform->SetPosition(D3DXVECTOR3(-2.5f, 0.0f, 0.0f));
	//m_transform->SetRotation(D3DXVECTOR3(0.0f, D3DX_PI * 0.5f, 0.0f));
	//m_transform->SetScale(D3DXVECTOR3(1.0f, 1.0f, 1.0f));
	//m_transform->SetSize(D3DXVECTOR3(1.0f, 1.0f, 1.0f));
	m_Model = new Model();
	m_Model->Load(ModelName);
/*

	Renderer::CreateVertexShader(&m_VertexShader, &m_VertexLayout,
		"shader\\vertexLightingVS.cso");
	Renderer::CreatePixelShader(&m_PixelShader,
		"shader\\vertexLightingPS.cso");*/

}
void CreateModel::Uninit()
{
	m_Model->Unload();
	delete m_Model;
/*
	if (m_VertexLayout != NULL) {
		m_VertexLayout->Release();
	}
	if (m_VertexShader != NULL) {
		m_VertexShader->Release();
	}
	if (m_PixelShader != NULL) {
		m_PixelShader->Release();
	}*/
}
void CreateModel::Update() {

}
void CreateModel::Draw()
{
	m_Model->Draw();
}
//
//void CreateModel::SetShader(const char * VSName, const char * PSName)
//{
//	Renderer::CreateVertexShader(&m_VertexShader, &m_VertexLayout, VSName);
//	Renderer::CreatePixelShader(&m_PixelShader, PSName);
//}
