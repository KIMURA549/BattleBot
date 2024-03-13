#pragma once
#include"gameObject.h"
#include<list>

enum CHARACTERSTATUS;

class Player : public GameObject
{
private:
	//��{�̈ʒu���
	class Transform* m_transform;
	class MoveManager* m_move; //�v���C���[�̈ʒu���̐���

	bool m_dirLeft = true; //�v���C���[�����鑤

	class Charactor* m_body;
	class Parameter* m_param;

	ID3D11VertexShader* m_VertexShader = nullptr;
	ID3D11PixelShader* m_PixelShader = nullptr;
	ID3D11InputLayout* m_VertexLayout = nullptr;
	class Audio* m_SE;
	class Shadow* m_shadow;

	float m_hp = 300.0f;

	CHARACTERSTATUS m_state;

	//�͂݃t���O
	bool m_caught = false;

	//�U��������s�����ǂ���
	bool m_attack = false;

	//se
	class Audio* m_se;

	class Ball* m_ball;

	int m_commandCnt = 0;

	class Shield* m_shield;

	class Cursor* m_icon;

public:
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;

	class Transform* GetTransform();
	bool GetDirLeft() {
		return m_dirLeft;
	}

	float GetHp() {
		return m_hp;
	}


	bool AttackCollision(float len, class Transform* me, class Transform* enemy);
	//�^����_���[�W
	void Attack(class Enemy * enemy, float atk, D3DXVECTOR3 v, bool left, bool down, bool jump);

	bool GetFlyFlag();


	/*void AtkPA(class Enemy e);
	void AtkPB();
	void AtkK();
	void AtkJump();*/

	//�U�����ꂽ
	void Damage(float atk, D3DXVECTOR3 v, bool down, bool fly, bool hold);
	//�߂܂ꂽ
	void Caught();
	//������ꂽ
	void Thrown(float atk, D3DXVECTOR3 v);

	void SetPosition(D3DXVECTOR3 pos);
	D3DXMATRIX GetHandMatrix();
};
