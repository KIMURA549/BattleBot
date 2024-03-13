#pragma once
#include"gameObject.h"
#include<list>

enum CHARACTERSTATUS;

class Player : public GameObject
{
private:
	//基本の位置情報
	class Transform* m_transform;
	class MoveManager* m_move; //プレイヤーの位置情報の制御

	bool m_dirLeft = true; //プレイヤーがいる側

	class Charactor* m_body;
	class Parameter* m_param;

	ID3D11VertexShader* m_VertexShader = nullptr;
	ID3D11PixelShader* m_PixelShader = nullptr;
	ID3D11InputLayout* m_VertexLayout = nullptr;
	class Audio* m_SE;
	class Shadow* m_shadow;

	float m_hp = 300.0f;

	CHARACTERSTATUS m_state;

	//掴みフラグ
	bool m_caught = false;

	//攻撃判定を行うかどうか
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
	//与えるダメージ
	void Attack(class Enemy * enemy, float atk, D3DXVECTOR3 v, bool left, bool down, bool jump);

	bool GetFlyFlag();


	/*void AtkPA(class Enemy e);
	void AtkPB();
	void AtkK();
	void AtkJump();*/

	//攻撃された
	void Damage(float atk, D3DXVECTOR3 v, bool down, bool fly, bool hold);
	//捕まれた
	void Caught();
	//投げられた
	void Thrown(float atk, D3DXVECTOR3 v);

	void SetPosition(D3DXVECTOR3 pos);
	D3DXMATRIX GetHandMatrix();
};
