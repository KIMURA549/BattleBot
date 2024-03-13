
#include"main.h"
#include"renderer.h"
#include"polygon2D.h"
#include"sprite.h"


void Polygon2D::Init()
{
	Renderer::CreateVertexShader(&m_VertexShader, &m_VertexLayout, 
		"shader\\unlitTextureVS.cso");
	Renderer::CreatePixelShader(&m_PixelShader, 
		"shader\\unlitTexturePS.cso");

	//AddComponent<Sprite>()->Init(300.0f, 300.0f, 300.0f, 200.0f, "asset\\texture\\lizuna.jpg");
}
void Polygon2D::Uninit()
{
	if (m_VertexLayout != NULL) {
		m_VertexLayout->Release();
	}
	if (m_VertexShader != NULL) {
		m_VertexShader->Release();
	}
	if (m_PixelShader != NULL) {
		m_PixelShader->Release();
	}
	
	GameObject::Uninit();
}
void Polygon2D::Update(){
	GameObject::Update();
}
void Polygon2D::Draw()
{
	//入力レイアウト
	Renderer::GetDeviceContext()->IASetInputLayout(m_VertexLayout);

	//シェーダー設定
	Renderer::GetDeviceContext()->VSSetShader(m_VertexShader, NULL, 0);
	Renderer::GetDeviceContext()->PSSetShader(m_PixelShader, NULL, 0);

	//マトリクス設定
	Renderer::SetWorldViewProjection2D();


	GameObject::Draw();
}

void Polygon2D::SetPolygon2D(float x, float y, float Width, float Height, const char * TeextureName)
{
	AddComponent<Sprite>()->Init(x, y, Width, Height, TeextureName);
}
