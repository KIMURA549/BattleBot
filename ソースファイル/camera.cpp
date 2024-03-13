#include"main.h"
#include"manager.h"
#include"scene.h"
#include"renderer.h"
#include"component.h"
#include "camera.h"
#include"player.h"
#include"enemy.h"
#include"transform.h"

void Camera::Init()
{
	m_transform = AddComponent<Transform>();
	m_transform->SetPosition(D3DXVECTOR3(0.0f, 2.0f, -5.0f));
	m_transform->SetScale(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_Target = m_transform->GetPosition();
}

void Camera::Update()
{
	m_Target = m_transform->GetPosition();
	////�J�������Ɏ����ƓG�����܂�悤�ɒ���
	Scene* scene = Manager::GetScene();
	Player* player = scene->GetGameObject<Player>();
	Enemy* enemy = scene->GetGameObject<Enemy>();
	
	m_Target = player->GetTransform()->GetPosition();
	//m_Target.y +=0;

		////�����Ƒ���Ƃ̋���
	float len = sqrt(pow(player->GetTransform()->GetPosition().x - m_transform->GetPosition().x, 2)) - 1.0f;
	////�����Ƒ���̊Ԃ�Target
	m_Target.x = player->GetTransform()->GetPosition().x -
		((player->GetTransform()->GetPosition().x - enemy->GetTransform()->GetPosition().x) / 2);

	m_Target.y = player->GetTransform()->GetPosition().y;
	


	////��������ʓ��Ɏ��܂�悤�ɋ������Ƃ�
	float cz = -(len * 1.5f);
	if (cz > -5.0f) {
		cz = -5.0f;
	}

	//�g�b�v�r���[�i�Ǐ] �j �ʒu�𑫂��ČŒ�
	m_transform->SetPosition(m_Target + D3DXVECTOR3(0.0f, 0.0f, cz));
}

void Camera::Draw()
{
	//�r���[�}�g���b�N�X
	D3DXVECTOR3 up = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	D3DXVECTOR3 p = m_transform->GetPosition();
	D3DXMatrixLookAtLH(&m_ViewMatrix, &p, &m_Target, &up);

	Renderer::SetViewMatrix(&m_ViewMatrix);

	//�v���W�F�N�V�����}�g���N�X
	D3DXMATRIX projectionMatrix;
	D3DXMatrixPerspectiveFovLH(&projectionMatrix, 1.0f,
		(float)SCREEN_WIDTH / SCREEN_HEIGHT, 1.0f, 1000.0f);

	Renderer::SetProjectionMatrix(&projectionMatrix);
}
