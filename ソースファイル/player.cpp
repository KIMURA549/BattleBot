#include"main.h"
#include"manager.h"
#include"renderer.h"

#include"scene.h"
#include "player.h"
#include"enemy.h"
#include"input.h"

#include"transform.h"
#include"moveManager.h"
#include"parts.h"
#include"charactor.h"
#include"audio.h"
#include"shadow.h"
#include"ball.h"
#include"shield.h"
#include"cursor.h"

#include"parameter.h"

#include"field.h"

#define MOVE_X 0.025f


void Player::Init()
{
	//位置　回転　モデルの大きさ　当たり判定の大きさ
	m_transform = AddComponent<Transform>();
	m_transform->SetPosition(D3DXVECTOR3(-2.5f, 2.0f, 0.0f));
	m_transform->SetRotation(D3DXVECTOR3(0.0f, -D3DX_PI * 0.4f, 0.0f));
	m_transform->SetScale(D3DXVECTOR3(1.0f, 1.0f, 1.0f));
	m_transform->SetSize(D3DXVECTOR3(0.6f, 1.0f, 1.0f));

	m_dirLeft = true;

	m_move = AddComponent<MoveManager>();
	m_move->Init(0.0f);
	m_move->SetNowPosition(m_transform->GetPosition());



	m_body = AddComponent<Charactor>();
	m_body->Init();

	m_shadow = AddComponent<Shadow>();
	m_shadow->Init();

	Renderer::CreateVertexShader(&m_VertexShader, &m_VertexLayout,
		"shader\\vertexLightingVS.cso");
	Renderer::CreatePixelShader(&m_PixelShader,
		"shader\\vertexLightingPS.cso");

	m_move->SetGround(1.9f);

	m_param = m_body->GetParameter();

	m_state = STAND;

	m_attack = true;


	m_se = AddComponent<Audio>();
	m_se->Init();
	m_se->Load("asset\\audio\\hit.wav");


	m_ball = AddComponent<Ball>();
	m_ball->SetShadowSize(0.5f);


	m_shield = AddComponent<Shield>();
	m_shield->SetSize(1.5);


	m_hp = 300.0f;
	m_body->SetNextMotion(MOTION_STAY);

	m_icon = AddComponent<Cursor>();
	m_icon->SetTexture("asset\\texture\\cursor1p.png", 0.5f);

	//m_icon = AddComponent<Icon>();
	//m_icon->Init("asset\\texture\\cursor1p.png", 1.0f);


}
void Player::Uninit()
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
void Player::Update() {
	//敵の情報入手
	Scene* scene = Manager::GetScene();
	Enemy* enemy = scene->GetGameObject<Enemy>();




	//damageテスト
	if (Input::GetKeyTrigger('N')) {
		
		Damage(100.0f, D3DXVECTOR3(0.0f,0.0f,0.0f), true, false, false);
	}

	m_move->SetNowPosition(m_transform->GetPosition());

	static float m_comCnt = 0.0f;
	if (m_body->GetMotionFlag() == false && scene->GetNoInputFlag() == false) {

		if (m_hp >= 0.0f) {
			switch (m_commandCnt)
			{
			case 0:
				m_comCnt = 0.0f;
				if (Input::GetKeyTrigger('S')) {
					m_comCnt = 15.0f;
					m_commandCnt = 1;
				}
				break;
			case 1:
				m_comCnt -= 1.0f;

				if (m_comCnt <= 0.0f) {
					m_commandCnt = 0;

				}

				if (m_dirLeft == true) {
					if (Input::GetKeyTrigger('D')) {
						m_comCnt = 15.0f;
						m_commandCnt = 2;
					}
				}
				else {
					if (Input::GetKeyTrigger('A')) {
						m_comCnt = 15.0f;
						m_commandCnt = 2;
					}
				}
				break;
			case 2:
				m_comCnt -= 1.0f;

				if (m_comCnt <= 0.0f) {
					m_commandCnt = 0;

				}

				if (Input::GetKeyTrigger('J')) {
					m_comCnt = 0.0f;
					m_commandCnt = 0;
					m_state = ATTACK;
					m_body->SetNextMotion(MOTION_SHOT);
				}
				break;
			default:
				break;
			}

			//移動
			switch (m_state)
			{
			case STAND:

				if (Input::GetKeyPress('A')) {
					m_move->MoveX(-m_param->GetMoveX());
					m_body->SetNextMotion(MOTION_WALK);
				}
				else if (Input::GetKeyPress('D')) {
					m_move->MoveX(m_param->GetMoveX());
					m_body->SetNextMotion(MOTION_WALK);
				}
				else if (Input::GetKeyPress('S')) {
					if (m_comCnt <= 0.0f) {
						m_body->SetNextMotion(MOTION_DOWNSTAY);
						m_state = DOWN;

					}
				}
				else {
					if (m_body->GetMotionWait() == false) {
						m_body->SetNextMotion(MOTION_STAY);
					}
					//
				}

				//ジャンプ
				if (Input::GetKeyTrigger('W')) {
					if (Input::GetKeyPress('A')) {
						m_move->SetVelocity(D3DXVECTOR3(-0.15f, 0.0f, 0.0f));
					}
					else if (Input::GetKeyPress('D')) {
						m_move->SetVelocity(D3DXVECTOR3(0.15f, 0.0f, 0.0f));
					}
					m_move->Jump(0.3f);
					m_body->SetNextMotion(MOTION_JUMP);
					m_state = JUMP;
					m_se->Load("asset\\audio\\pa.wav");
					m_se->Play();
				}

				//攻撃
				if (Input::GetKeyTrigger('J')) {		//パンチA
					m_body->SetNextMotion(MOTION_ATTACKPA);
					m_state = ATTACK;
				}
				else if (Input::GetKeyTrigger('K')) {		//キック
					m_body->SetNextMotion(MOTION_ATTACKK);
					m_state = ATTACK;
				}
				else if (Input::GetKeyTrigger('L')) {		//パンチB
					m_body->SetNextMotion(MOTION_ATTACKPB);
					m_state = ATTACK;
				}
				else if (Input::GetKeyTrigger('I')) {		//掴み攻撃
					m_body->SetNextMotion(MOTION_HOLD);
					m_state = CATCH;
				}
				break;
			case DOWN:
				if (m_body->GetMotionWait() == false) {
					if (Input::GetKeyPress('S')) {
						if (Input::GetKeyPress('A')) {
							m_move->MoveX(-m_param->GetMoveX());
							m_body->SetNextMotion(MOTION_DOWNWALK);
						}
						else if (Input::GetKeyPress('D')) {
							m_move->MoveX(m_param->GetMoveX());
							m_body->SetNextMotion(MOTION_DOWNWALK);
						}
						else if (Input::GetKeyTrigger('J')) {
							m_body->SetNextMotion(MOTION_ATTACKDOWN);
							m_attack = true;
							//m_state = ATTACK;
						}
						else {
							if (m_body->GetMotionState() == MOTION_DOWNWALK) {
								m_body->SetNextMotion(MOTION_DOWNSTAYED);
							}
						}
					}
					else {
						m_body->SetNextMotion(MOTION_STANDUP);
						m_state = STAND;
					}
				}

				if (m_attack == true) {
					if (m_body->GetMotionState() == MOTION_ATTACKDOWN) {
						if (m_body->GetFrame() >= 10.0f && 20.0f >= m_body->GetFrame()) {
							if (AttackCollision(1.75f, m_transform, enemy->GetTransform()) == true) {
								//吹き飛ぶ力　正の値
								//相手　ダメージ　自分の向き　下攻撃か　ジャンプ攻撃か
								Attack(enemy, 10.0f, D3DXVECTOR3(0.03f, 0.1f, 0.0f), m_dirLeft, true, false);
								m_se->Load("asset\\audio\\hit.wav");
								m_se->Play();
								m_attack = false;
							}
						}
					}
				}

				break;
			case JUMP:
				//ジャンプ攻撃
				if (m_body->GetMotionState() == MOTION_JUMP) {
					if (Input::GetKeyTrigger('K')) {
						m_body->SetNextMotion(MOTION_JUMPATTACK);
						m_state = ATTACK;
					}
				}

				//地面に着いたら
				if (m_move->GetFly() == false) {
					m_state = STAND;
				}

				break;
			case ATTACK:

				//攻撃の当たり判定が行われていない
				if (m_attack == true) {

					//攻撃の終了判定

					//攻撃の当たり判定
					switch (m_body->GetMotionState())
					{
					case MOTION_ATTACKPA:
						if (m_body->GetFrame() >= 0.0f && 5.0f <= m_body->GetFrame()) {
							if (AttackCollision(1.75, m_transform, enemy->GetTransform()) == true) {
								//吹き飛ぶ力　正の値
								//相手　ダメージ　自分の向き　下攻撃か　ジャンプ攻撃か
								Attack(enemy, 5.0f, D3DXVECTOR3(0.001f, 0.0f, 0.0f), m_dirLeft, false, false);
								m_se->Load("asset\\audio\\hit.wav");
								m_se->Play();
								m_attack = false;
							}
						}
						break;
					case MOTION_ATTACKPB:
						if (m_body->GetFrame() >= 0.0f && 10.0f <= m_body->GetFrame()) {
							if (AttackCollision(2.0f, m_transform, enemy->GetTransform()) == true) {
								//吹き飛ぶ力　正の値
								//相手　ダメージ　自分の向き　下攻撃か　ジャンプ攻撃か
								Attack(enemy, 15.0f, D3DXVECTOR3(0.025f, 0.1f, 0.0f), m_dirLeft, false, true);
								m_se->Load("asset\\audio\\hitb.wav");
								m_se->Play();
								m_attack = false;
							}
						}

						break;
					case MOTION_ATTACKK:
						if (m_body->GetFrame() >= 30.0f && 40.0f >= m_body->GetFrame()) {
							if (AttackCollision(2.0f, m_transform, enemy->GetTransform()) == true) {
								//吹き飛ぶ力　正の値
								//相手　ダメージ　自分の向き　下攻撃か　ジャンプ攻撃か
								Attack(enemy, 15.0f, D3DXVECTOR3(0.05f, 0.2f, 0.0f), m_dirLeft, false, true);
								m_se->Load("asset\\audio\\hitc.wav");
								m_se->Play();
								m_attack = false;
							}
						}

						break;
					case MOTION_JUMPATTACK:

						//向きによって左右移動
						if (m_dirLeft == true) {
							m_move->MoveX(0.1f);
						}
						else {

							m_move->MoveX(-0.1f);
						}
						if (m_attack == true) {
							if (m_transform->GetPosition().y < enemy->GetTransform()->GetPosition().y + 2.0f) {
								if (m_transform->GetPosition().x + 2.3f > enemy->GetTransform()->GetPosition().x) {
									if (m_transform->GetPosition().x - 2.3f < enemy->GetTransform()->GetPosition().x) {
										//吹き飛ぶ力　正の値
										//相手　ダメージ　自分の向き　下攻撃か　ジャンプ攻撃か
										Attack(enemy, 15.0f, D3DXVECTOR3(0.1f, 0.1f, 0.0f), m_dirLeft, false, false);
										m_se->Load("asset\\audio\\hit.wav");
										m_se->Play();
										m_attack = false;
									}
								}
							}
						}
						break;
					case MOTION_SHOT:
						if (m_attack == true) {
							if (m_body->GetFrame() >= 40) {
								D3DXVECTOR3 p = m_transform->GetPosition();
								if (m_dirLeft == true) {
									p.x += 1.0f;
									m_ball->StartBall(true, 0.075f, p);
								}
								else {
									p.x -= 1.0f;
									m_ball->StartBall(true, -0.075f, p);
								}
								m_attack = false;
							}
						}
						break;
					default:
						break;
					}
				}


				//ジャンプ攻撃時
				if (m_body->GetMotionState() == MOTION_JUMPATTACK) {
					//地面に着いたら
					if (m_move->GetFly() == false) {
						m_state = STAND;
						m_attack = true;
					}
				}
				else {		//その他の攻撃
					//動き終わったら
					if (m_body->GetMotionWait() == false) {

						m_state = STAND;
						m_attack = true;
					}

				}



				break;
			case CATCH:
				if (m_body->GetMotionState() == MOTION_HOLD) {
					if (m_body->GetMotionWait() == false) {
						//当たり判定
						if (m_dirLeft == true) {
							if (m_transform->GetPosition().x + 1.9f >= enemy->GetTransform()->GetPosition().x && enemy->GetFlyFlag() == false) {
								m_body->SetNextMotion(MOTION_HOLDATTACK);
								m_se->Load("asset\\audio\\hold.wav");
								m_se->Play();
								enemy->Caught();
							}
							else {
								m_body->SetNextMotion(MOTION_HOLDMISS);
							}
						}
						else {
							if (m_transform->GetPosition().x - 1.9f <= enemy->GetTransform()->GetPosition().x && enemy->GetFlyFlag() == false) {
								m_body->SetNextMotion(MOTION_HOLDATTACK);
								enemy->Caught();
							}
							else {
								m_body->SetNextMotion(MOTION_HOLDMISS);
							}
						}
					}
				}
				else {
					if (m_body->GetFrame() == 50.0f) {
						//掴めた場合投げる
						if (m_body->GetMotionState() == MOTION_HOLDATTACK) {
							m_se->Load("asset\\audio\\throw.wav");
							m_se->Play();
							enemy->Thrown(50.0f, D3DXVECTOR3(0.3f, 0.1f, 0.0f));
						}

					}

					if (m_body->GetMotionWait() == false) {
						m_body->SetNextMotion(MOTION_STAY);
						m_state = STAND;
					}
				}
				break;
			case DAMAGE:
				break;
			case HOLD:
				break;
			case OVER:
				if (m_body->GetMotionState() == MOTION_OVERUP) {
					if (m_body->GetFrame() >= 45.0f) {
						m_body->SetNextMotion(MOTION_STAY);
						m_state = STAND;
						break;
					}
				}
				else {
					if (m_body->GetMotionState() == MOTION_OVER) {

						if (Input::GetKeyPress('A') || Input::GetKeyPress('D')||
							Input::GetKeyPress('W') || Input::GetKeyPress('S')) {
							m_body->SetNextMotion(MOTION_OVERUP);

						}
					}
					else {
						if (m_body->GetFrame() >= 9.0f) {
							m_body->SetNextMotion(MOTION_OVER);
						}
					}
				}
				break;
			default:
				break;
			}
		}
	}

	if (m_hp <= 0.0f) {
		m_body->SetNextMotion(MOTION_OVER);
	}

	
	//コンポーネントのアップデート
	GameObject::Update();

	//影更新
	m_shadow->SetPosX(m_transform->GetPosition().x);
	m_shadow->SetPosZ(m_transform->GetPosition().z);
	m_shadow->SetPosY(0.005f);

	m_icon->SetPosX(m_transform->GetPosition().x);
	m_icon->SetPosZ(m_transform->GetPosition().z);
	m_icon->SetPosY(m_transform->GetPosition().y + 1.5f);
	//m_shadow->SetShadowSize(m_transform->GetPosition().x + 3.0f);


	//当たり判定（体）
	//高さ
	if (m_transform->GetPosition().y < enemy->GetTransform()->GetPosition().y + 2.0f &&
		m_transform->GetPosition().y + 2.0f > enemy->GetTransform()->GetPosition().y) {
		if (m_dirLeft == true) {
			if (m_transform->GetPosition().x + 0.9f >
				enemy->GetTransform()->GetPosition().x - 0.9f) {
				m_move->SetNowPositionX(enemy->GetTransform()->GetPosition().x - 1.8f);
			}

		}
		else {
			if (m_transform->GetPosition().x - 0.9f <
				enemy->GetTransform()->GetPosition().x + 0.9f) {
				m_move->SetNowPositionX(enemy->GetTransform()->GetPosition().x + 1.8f);
			}
		}
	}
	else {

		if (m_transform->GetPosition().x <
			enemy->GetTransform()->GetPosition().x) {
			m_dirLeft = true;
		}
		else if (m_transform->GetPosition().x >
			enemy->GetTransform()->GetPosition().x) {
			m_dirLeft = false;
		}
	}


	//プレイヤーの向き調節
	if (m_state == STAND) {
		D3DXVECTOR3 r = m_transform->GetRotation();
		if (enemy->GetTransform()->GetPosition().x > m_transform->GetPosition().x + (m_transform->GetSize().x / 2)) {
			r.y -= 0.25f;

			if (r.y <= -D3DX_PI * 0.5f) {
				r.y = -D3DX_PI * 0.5f;
				m_dirLeft = true;
			}
		}
		else {
			if (enemy->GetTransform()->GetPosition().x < m_transform->GetPosition().x - (m_transform->GetSize().x / 2)) {
				r.y += 0.25f;
				if (r.y >= D3DX_PI * 0.5f) {
					r.y = D3DX_PI * 0.5f;
					m_dirLeft = false;
				}
			}
		}
		m_transform->SetRotation(r);
	}

	m_transform->SetPosition(m_move->GetNextPosition());
}
void Player::Draw()
{
	//入力レイアウト
	Renderer::GetDeviceContext()->IASetInputLayout(m_VertexLayout);

	//シェーダー設定
	Renderer::GetDeviceContext()->VSSetShader(m_VertexShader, NULL, 0);
	Renderer::GetDeviceContext()->PSSetShader(m_PixelShader, NULL, 0);


	//マトリクス設定
	D3DXMATRIX world, scale, rot, trans;

	if (m_caught == true) {		//敵につかまれている
		D3DXMatrixScaling(&scale, m_transform->GetScale().x, m_transform->GetScale().y, m_transform->GetScale().z);
		if (m_dirLeft == true) {
			D3DXMatrixRotationYawPitchRoll(&rot, 0.0f, D3DX_PI * 0.4f, D3DX_PI);
		}
		else {
			D3DXMatrixRotationYawPitchRoll(&rot, 0.0f, -D3DX_PI * 0.4f, D3DX_PI);
		}
		D3DXMatrixTranslation(&trans, 0.0f, 0.0f, 0.0f);
		world = scale * rot  *trans;
		Scene* scene = Manager::GetScene();
		Enemy* enemy = scene->GetGameObject<Enemy>();
		world *= enemy->GetHandMatrix();
	}
	else {
		D3DXMatrixScaling(&scale, m_transform->GetScale().x, m_transform->GetScale().y, m_transform->GetScale().z);
		D3DXMatrixRotationYawPitchRoll(&rot, m_transform->GetRotation().y + D3DX_PI, m_transform->GetRotation().x, m_transform->GetRotation().z);
		D3DXMatrixTranslation(&trans, m_transform->GetPosition().x, m_transform->GetPosition().y, m_transform->GetPosition().z);
		world = scale * rot  *trans;
	}


	Renderer::SetWorldMatrix(&world);


	m_body->Draw(world);

	m_shadow->Draw();

	m_icon->Draw();

	m_ball->Draw();

	m_shield->Draw();

}

Transform* Player::GetTransform()
{
	return m_transform;
}

bool Player::AttackCollision(float len, Transform* me, Transform* enemy)
{
	if (me->GetPosition().y < enemy->GetPosition().y + 2.0f &&
		me->GetPosition().y + 2.0f > enemy->GetPosition().y) {
		if (m_dirLeft == true) {
			if (me->GetPosition().x + len >
				enemy->GetPosition().x - enemy->GetSize().x) {
				return true;
			}

		}
		else {
			if (me->GetPosition().x - len <
				enemy->GetPosition().x + enemy->GetSize().x) {
				return true;
			}

		}

	}
	return false;
}

void Player::Attack(Enemy* enemy, float atk, D3DXVECTOR3 v, bool left, bool down, bool jump)
{
	enemy->Damage(atk, v, down, jump, false);
}


bool Player::GetFlyFlag()
{
	if (m_body->GetMotionState() == MOTION_JUMP ||
		m_body->GetMotionState() == MOTION_JUMPATTACK) {
		return true;
	}

	return false;
}



void Player::Damage(float atk, D3DXVECTOR3 v, bool down, bool fly, bool hold)
{
	if (m_dirLeft == true) {
		v.x *= -1.0f;
	}

	if (hold == false) {
		D3DXVECTOR3 p = m_transform->GetPosition();
		//下段GUARD
		if (Input::GetKeyPress('S')) {
			if (m_dirLeft == true) {
				if (Input::GetKeyPress('A')) {
					if (fly == true) {
						//空中攻撃だったら当たる
						m_move->SetVelocity(v);
						m_hp -= atk;
					}
					else {
						//GUARD成功
						p.x += 1.5f;
						p.y -= 1.0f;
						m_shield->SetSize(1.5f);
						m_shield->StartShield(p);
						m_se->Load("asset\\audio\\gurd.wav");
						m_se->Play();
					}
				}
			}
			else {
				if (Input::GetKeyPress('D')) {
					if (fly == true) {
						//空中攻撃だったら当たる
						m_move->SetVelocity(v);
						m_hp -= atk;
					}
					else {
						//GUARD成功
						p.x -= 1.5f;
						p.y -= 1.0f;
						m_shield->SetSize(-1.5f);
						m_shield->StartShield(p);
						m_se->Load("asset\\audio\\gurd.wav");
						m_se->Play();
					}
				}
			}

		}
		else {
			if (m_dirLeft == true) {
				if (Input::GetKeyPress('A')) {
					if (down == true) {
						//下段攻撃だったら当たる
						m_move->SetVelocity(v);
						m_hp -= atk;
					}
					else {
						//GUARD成功
						p.x += 1.0f;
						m_shield->SetSize(1.5f);
						m_shield->StartShield(p);
						m_se->Load("asset\\audio\\gurd.wav");
						m_se->Play();
					}
				}
				else {
					m_move->SetVelocity(v);
					m_hp -= atk;
				}

			}
			else {
				if (Input::GetKeyPress('D')) {
					if (down == true) {
						//下段攻撃だったら当たる
						m_move->SetVelocity(v);
						m_hp -= atk;
					}
					else {
						//GUARD成功
						p.x -= 1.0f;
						m_shield->SetSize(-1.5f);
						m_shield->StartShield(p);
						m_se->Load("asset\\audio\\gurd.wav");
						m_se->Play();
					}
				}
				else {
					m_move->SetVelocity(v);
					m_hp -= atk;
				}
			}
		}
	}
	else {
		//投げられた時
		m_move->SetVelocity(v);
		m_hp -= atk;
		m_body->SetNextMotion(MOTION_BURST);
		m_state = OVER;

	}


	if (m_hp <= 0.0f) {
		m_body->SetNextMotion(MOTION_BURST);
		m_state = OVER;

	}
}

void Player::Caught()
{
	m_caught = true;
	m_state = HOLD;
}

void Player::Thrown(float atk, D3DXVECTOR3 v)
{
	m_caught = false;
	Damage(atk, v, false, false, true);
	m_state = OVER;
}

void Player::SetPosition(D3DXVECTOR3 pos)
{
	m_transform->SetPosition(pos);
}


D3DXMATRIX Player::GetHandMatrix()
{
	return m_body->GetFistMatrix();
}
