#include"main.h"
#include"manager.h"
#include"renderer.h"

#include"scene.h"
#include "enemy.h"
#include"player.h"
#include"input.h"

#include"transform.h"
#include"moveManager.h"
#include"parts.h"
#include"charactor.h"
#include"audio.h"
#include"shadow.h"
#include"ball.h"
#include"shield.h"
#include"parameter.h"

#include"field.h"

#define MOVE_X 0.025f


void Enemy::Init()
{
	//位置　回転　モデルの大きさ　当たり判定の大きさ
	m_transform = AddComponent<Transform>();
	m_transform->SetPosition(D3DXVECTOR3(2.5f, 2.0f, 0.0f));
	m_transform->SetRotation(D3DXVECTOR3(0.0f, D3DX_PI * 0.4f, 0.0f));
	m_transform->SetScale(D3DXVECTOR3(1.0f, 1.0f, 1.0f));
	m_transform->SetSize(D3DXVECTOR3(0.6f, 1.0f, 1.0f));

	m_dirLeft = false;

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
	m_maxHp = m_hp;

	m_next = true;
}
void Enemy::Uninit()
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
void Enemy::Update() {
	Scene* scene = Manager::GetScene();
	Player* player = scene->GetGameObject<Player>();

	static float jdelay = 0.0f;
	static float rdelay = 0.0f;

	m_move->SetNowPosition(m_transform->GetPosition());


	if (m_body->GetMotionFlag() == false && scene->GetNoInputFlag() == false) {

		if (m_hp >= 0.0f) {
			InputAI();

			//移動
			switch (m_state)
			{
			case STAND:
				switch (m_ai)
				{
				case AI_MOVELEFT:
					m_move->MoveX(-m_param->GetMoveX());
					m_body->SetNextMotion(MOTION_WALK);
					break;
				case AI_MOVERIGHT:
					m_move->MoveX(m_param->GetMoveX());
					m_body->SetNextMotion(MOTION_WALK);
					break;
				case AI_ATTACKA:
					m_body->SetNextMotion(MOTION_ATTACKPA);
					m_state = ATTACK;
					m_ai = AI_WAIT;
					break;
				case AI_ATTACKB:
					m_body->SetNextMotion(MOTION_ATTACKK);
					m_state = ATTACK;
					m_ai = AI_WAIT;
					break;
				case AI_ATTACKC:
					m_body->SetNextMotion(MOTION_ATTACKPB);
					m_state = ATTACK;
					m_ai = AI_WAIT;
					break;
				case AI_SHOT:
					m_state = ATTACK;
					m_body->SetNextMotion(MOTION_SHOT);
					m_ai = AI_WAIT;
					break;
				case AI_CHATCH:
					m_body->SetNextMotion(MOTION_HOLD);
					m_state = CATCH;
					m_ai = AI_WAIT;
					break;
				case AI_JUMP:
					m_move->Jump(0.3f);
					m_body->SetNextMotion(MOTION_JUMP);
					m_state = JUMP;
					m_se->Load("asset\\audio\\pa.wav");
					m_se->Play();
					break;
				case AI_JUMPLEFT:
					m_move->SetVelocity(D3DXVECTOR3(-0.15f, 0.0f, 0.0f));
					m_move->Jump(0.3f);
					m_body->SetNextMotion(MOTION_JUMP);
					m_state = JUMP;
					m_se->Load("asset\\audio\\pa.wav");
					m_se->Play();
					break;
				case AI_JUMPRIGHT:
					m_move->SetVelocity(D3DXVECTOR3(0.15f, 0.0f, 0.0f));
					m_move->Jump(0.3f);
					m_body->SetNextMotion(MOTION_JUMP);
					m_state = JUMP;
					m_se->Load("asset\\audio\\pa.wav");
					m_se->Play();
					break;
				case AI_DOWN:
					m_body->SetNextMotion(MOTION_DOWNSTAY);
					m_state = DOWN;
					break;
				default:
					if (m_body->GetMotionWait() == false) {
						m_body->SetNextMotion(MOTION_STAY);
					}
					break;
				}


				break;
			case DOWN:
				if (m_body->GetMotionWait() == false) {
					switch (m_ai)
					{
					case AI_DOWN:
						if (m_body->GetMotionState() == MOTION_DOWNWALK) {
							m_body->SetNextMotion(MOTION_DOWNSTAYED);
						}
						break;
					case AI_DOWNMOVELEFT:

						m_move->MoveX(-m_param->GetMoveX());
						m_body->SetNextMotion(MOTION_DOWNWALK);
						break;
					case AI_DOWNMOVERIGHT:
						m_move->MoveX(m_param->GetMoveX());
						m_body->SetNextMotion(MOTION_DOWNWALK);
						break;
					case AI_DOWNATTACK:
						m_body->SetNextMotion(MOTION_ATTACKDOWN);
						m_ai = AI_WAIT;
						break;
					default:
						m_body->SetNextMotion(MOTION_STANDUP);
						m_state = STAND;
						break;
					}
				}

				if (m_body->GetMotionState() == MOTION_ATTACKDOWN) {
					if (m_downatk == true) {
						if (m_body->GetFrame() >= 10.0f && 20.0f >= m_body->GetFrame()) {
							if (AttackCollision(1.75f, m_transform, player->GetTransform()) == true) {
								//吹き飛ぶ力　正の値
								//相手　ダメージ　自分の向き　下攻撃か　ジャンプ攻撃か
								Attack(player, 10.0f, D3DXVECTOR3(0.03f, 0.1f, 0.0f), m_dirLeft, true, false);
								m_se->Load("asset\\audio\\hit.wav");
								m_se->Play();
								m_downatk = false;
							}
						}
					}
				}


				break;
			case JUMP:
				//ジャンプ攻撃
				if (m_jumpatk == true) {
					jdelay++;
					if (jdelay >= 25.0f) {
						m_body->SetNextMotion(MOTION_JUMPATTACK);
						m_state = ATTACK;
						m_ai = AI_WAIT;
						jdelay = 0;
						m_jumpatk = false;
					}
				}

				//地面に着いたら
				if (m_move->GetFly() == false) {
					m_state = STAND;

					m_ai = AI_WAIT;
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
							if (AttackCollision(1.75, m_transform, player->GetTransform()) == true) {
								//吹き飛ぶ力　正の値
								//相手　ダメージ　自分の向き　下攻撃か　ジャンプ攻撃か
								Attack(player, 5.0f, D3DXVECTOR3(0.001f, 0.0f, 0.0f), m_dirLeft, false, false);
								m_se->Load("asset\\audio\\hit.wav");
								m_se->Play();
								m_attack = false;
							}
						}
						break;
					case MOTION_ATTACKPB:
						if (m_body->GetFrame() >= 0.0f && 10.0f <= m_body->GetFrame()) {
							if (AttackCollision(2.0f, m_transform, player->GetTransform()) == true) {
								//吹き飛ぶ力　正の値
								//相手　ダメージ　自分の向き　下攻撃か　ジャンプ攻撃か
								Attack(player, 15.0f, D3DXVECTOR3(0.025f, 0.1f, 0.0f), m_dirLeft, false, true);
								m_se->Load("asset\\audio\\hitb.wav");
								m_se->Play();
								m_attack = false;
							}
						}

						break;
					case MOTION_ATTACKK:
						if (m_body->GetFrame() >= 30.0f && 40.0f >= m_body->GetFrame()) {
							if (AttackCollision(2.0f, m_transform, player->GetTransform()) == true) {
								//吹き飛ぶ力　正の値
								//相手　ダメージ　自分の向き　下攻撃か　ジャンプ攻撃か
								Attack(player, 15.0f, D3DXVECTOR3(0.05f, 0.2f, 0.0f), m_dirLeft, false, true);
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
							if (m_transform->GetPosition().y < player->GetTransform()->GetPosition().y + 2.0f) {
								if (m_transform->GetPosition().x + 2.3f > player->GetTransform()->GetPosition().x) {
									if (m_transform->GetPosition().x - 2.3f < player->GetTransform()->GetPosition().x) {
										//吹き飛ぶ力　正の値
										//相手　ダメージ　自分の向き　下攻撃か　ジャンプ攻撃か
										Attack(player, 15.0f, D3DXVECTOR3(0.1f, 0.1f, 0.0f), m_dirLeft, false, false);
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
									m_ball->StartBall(false, 0.075f, p);
								}
								else {
									p.x -= 1.0f;
									m_ball->StartBall(false, -0.075f, p);
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
						m_ai = AI_WAIT;
					}
				}
				else {		//その他の攻撃
					//動き終わったら
					if (m_body->GetMotionWait() == false) {

						m_state = STAND;
						m_attack = true;
						m_ai = AI_WAIT;
					}

				}



				break;
			case CATCH:
				if (m_body->GetMotionState() == MOTION_HOLD) {
					if (m_body->GetMotionWait() == false) {
						//当たり判定
						if (m_dirLeft == true) {
							if (m_transform->GetPosition().x + 1.9f >= player->GetTransform()->GetPosition().x && player->GetFlyFlag() == false) {
								m_body->SetNextMotion(MOTION_HOLDATTACK);
								m_se->Load("asset\\audio\\hold.wav");
								m_se->Play();
								player->Caught();
							}
							else {
								m_body->SetNextMotion(MOTION_HOLDMISS);
							}
						}
						else {
							if (m_transform->GetPosition().x - 1.9f <= player->GetTransform()->GetPosition().x && player->GetFlyFlag() == false) {
								m_body->SetNextMotion(MOTION_HOLDATTACK);
								player->Caught();
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
							player->Thrown(50.0f, D3DXVECTOR3(0.3f, 0.1f, 0.0f));
						}

					}

					if (m_body->GetMotionWait() == false) {
						m_body->SetNextMotion(MOTION_STAY);
						m_state = STAND;
					}
				}
				break;
			case DAMAGE:
				if (m_body->GetMotionWait() == false) {
					m_body->SetNextMotion(MOTION_STAY);
					m_state = STAND;
				}
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
				else if (m_body->GetMotionState() == MOTION_OVER) {
					if (m_hp >= 1.0f) {
						m_body->SetNextMotion(MOTION_OVERUP);
					}
				}
				else {
					if (m_body->GetFrame() >= 9.0f) {
						m_body->SetNextMotion(MOTION_OVER);
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

	//m_shadow->SetShadowSize(m_transform->GetPosition().x + 3.0f);

	if (m_state != HOLD) {
		//当たり判定（体）
		//高さ
		if (m_transform->GetPosition().y < player->GetTransform()->GetPosition().y + 2.0f &&
			m_transform->GetPosition().y + 2.0f > player->GetTransform()->GetPosition().y) {
			if (m_dirLeft == true) {
				if (m_transform->GetPosition().x + 0.9f >
					player->GetTransform()->GetPosition().x - 0.9f) {
					m_move->SetNowPositionX(player->GetTransform()->GetPosition().x - 1.8f);
				}

			}
			else {
				if (m_transform->GetPosition().x - 0.9f <
					player->GetTransform()->GetPosition().x + 0.9f) {
					m_move->SetNowPositionX(player->GetTransform()->GetPosition().x + 1.8f);
				}
			}
		}
		else {

			if (m_transform->GetPosition().x <
				player->GetTransform()->GetPosition().x) {
				m_dirLeft = true;
			}
			else if (m_transform->GetPosition().x >
				player->GetTransform()->GetPosition().x) {
				m_dirLeft = false;
			}
		}
	}


	//向き調節
	if (m_state == STAND) {
		D3DXVECTOR3 r = m_transform->GetRotation();
		if (player->GetTransform()->GetPosition().x > m_transform->GetPosition().x) {
			r.y -= 0.25f;

			if (r.y <= -D3DX_PI * 0.5f) {
				r.y = -D3DX_PI * 0.5f;
				m_dirLeft = true;
			}
		}
		else {
			if (player->GetTransform()->GetPosition().x < m_transform->GetPosition().x) {
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
void Enemy::Draw()
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
		Player* player = scene->GetGameObject<Player>();
		world *= player->GetHandMatrix();
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

	m_ball->Draw();

	m_shield->Draw();

}

Transform* Enemy::GetTransform()
{
	return m_transform;
}

bool Enemy::AttackCollision(float len, Transform* me, Transform* player)
{

	if (me->GetPosition().y < player->GetPosition().y + 2.0f &&
		me->GetPosition().y + 2.0f > player->GetPosition().y) {
		if (m_dirLeft == true) {
			if (me->GetPosition().x + len >
				player->GetPosition().x - player->GetSize().x) {
				return true;
			}

		}
		else {
			if (me->GetPosition().x - len <
				player->GetPosition().x + player->GetSize().x) {
				return true;
			}

		}
	
	}
	return false;
}

void Enemy::Attack(class Player* player, float atk, D3DXVECTOR3 v, bool left, bool down, bool jump)
{
	//向きによって判定判別
	player->Damage(atk, v, down, jump, false);
}


bool Enemy::GetFlyFlag()
{
	if (m_body->GetMotionState() == MOTION_JUMP ||
		m_body->GetMotionState() == MOTION_JUMPATTACK) {
		return true;
	}

	return false;
}



void Enemy::Damage(float atk, D3DXVECTOR3 v, bool down, bool fly, bool hold)
{
	if (m_dirLeft == true) {
		v.x *= -1.0f;
	}

	if (hold == false) {
		D3DXVECTOR3 p = m_transform->GetPosition();
		if (GuardAI() == true) {

			if (m_dirLeft == true) {
				if (down == true) {
					p.x += 1.5f;
					p.y -= 1.0f;
					m_shield->SetSize(1.5f);

				}
				else {
					p.x += 1.0f;
					m_shield->SetSize(1.5f);

				}

			}
			else {
				if (down == true) {
					p.x -= 1.5f;
					p.y -= 1.0f;
					m_shield->SetSize(-1.5f);

				}
				else {
					p.x -= 1.0f;
					m_shield->SetSize(-1.5f);

				}

			}
			m_shield->StartShield(p);
			m_se->Load("asset\\audio\\gurd.wav");
			m_se->Play();


		}
		else {

			m_move->SetVelocity(v);
			m_hp -= atk;
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

void Enemy::Caught()
{
	m_caught = true;

	m_state = HOLD;
}

void Enemy::Thrown(float atk, D3DXVECTOR3 v)
{
	m_caught = false;
	Damage(atk, v, false, false, true);
	//m_state = OVER;
}

void Enemy::SetPosition(D3DXVECTOR3 pos)
{
	m_transform->SetPosition(pos);
}


D3DXMATRIX Enemy::GetHandMatrix()
{
	return m_body->GetFistMatrix();
}

void Enemy::InputAI()
{
	static float delay = 0.0f;

	Scene* scene = Manager::GetScene();
	Player* player = scene->GetGameObject<Player>();

	m_aiLevel = m_maxHp / m_hp;

	//1~100
	int mv = rand() % 100 + 1;
	mv += m_aiLevel * 5;
	int a = rand() % 6 + 1;


	if (delay <= 0.0f) {


		if (m_state == STAND) {
			if (mv <= 30) {
				m_ai = AI_MOVELEFT;
				delay = mv;
			}
			else if (mv <= 60) {
				m_ai = AI_MOVERIGHT;
				delay = mv;
			}
			else if (mv <= 75) {
				//ジャンプ
				if (mv < 62) {
					m_ai = AI_JUMPLEFT;
					delay = 10.0f;
				}
				else if (mv < 64) {
					m_ai = AI_JUMPLEFT;
					delay = 10.0f;

				}
				else {
					m_ai = AI_JUMP;
					delay = 10.0f;

				}

				if (a >= 4) {
					m_jumpatk = true;
				}
			}
			else {
				if (player->GetTransform()->GetPosition().x <= m_transform->GetPosition().x + 3.0f &&
					player->GetTransform()->GetPosition().x >= m_transform->GetPosition().x - 3.0f) {
					delay = 25.0f;
					switch (a)
					{
					case 1:
						m_ai = AI_ATTACKA;
						break;
					case 2:
						m_ai = AI_ATTACKB;
						break;
					case 3:
						m_ai = AI_ATTACKC;
						break;
					case 4:
						m_ai = AI_JUMP;
						m_jumpatk = true;
						break;
					case 5:
						m_ai = AI_CHATCH;
						break;
					case 6:
						m_ai = AI_SHOT;
						break;
					default:
						break;
					}
				}
				else {

					if (a <= 2) {
						m_ai = AI_MOVELEFT;
						delay = mv /2 ;
					}
					else if (mv <= 4) {
						m_ai = AI_MOVERIGHT;
						delay = mv / 2;
					}
					else {
						m_ai = AI_SHOT;
					}
				}
			}
		}
		/*else if (m_state == DOWN) {
			if (mv <= 45) {
				m_ai = AI_MOVELEFT;
				delay = mv * 3.0f;
			}
			else if (mv <= 90) {
				m_ai = AI_MOVERIGHT;
				delay = mv * 3.0f;
			}
			else {
				m_ai = AI_DOWNATTACK;
				delay = mv;
			}
		}*/
	}
	else {
		delay -= 1.0f;
		if (m_ai == AI_MOVELEFT || m_ai == AI_MOVERIGHT
			|| m_ai == AI_DOWNMOVELEFT || m_ai == AI_DOWNMOVERIGHT) {

		}
		else {
			m_ai = AI_WAIT;
		}

		if (m_transform->GetPosition().x >= FIELD_LIMIT) {
			delay = 0.0f;
		}
		else if (m_transform->GetPosition().x <= -FIELD_LIMIT) {
			delay = 0.0f;
		}
	}
}

bool Enemy::GuardAI()
{
	static int gurdCnt = 0;

	int g = rand() % 30 + 1;

	if (g >= 20 - (gurdCnt * m_aiLevel)) {
		gurdCnt = 0;
		return true;
	}
	gurdCnt++;
	return false;

}
