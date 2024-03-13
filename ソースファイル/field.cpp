#include"main.h"
#include"renderer.h"
#include"component.h"
#include"field.h"
#include"parts.h"


void Field::Init()
{
	m_field = new Parts;

	m_field->Init("asset\\model\\field.obj");		//• 
	m_field->SetPosition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_field->SetScale(D3DXVECTOR3(0.8f, 0.8f, 0.8f));


	D3DXMATRIX scale, r, trans;
	D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
	D3DXMatrixRotationYawPitchRoll(&r, 0.0f, 0.0f, 0.0f);
	D3DXMatrixTranslation(&trans, 0.0f, 0.0f, 0.0f);
	m_matrix = scale * r *trans;
}
void Field::Uninit()
{
	m_field->Uninit();
	delete m_field;
}
void Field::Update() {

}
void Field::Draw()
{
	m_field->Draw(m_matrix);
}
