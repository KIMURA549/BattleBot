#include"main.h"
#include "charactor.h"
#include"parts.h"

#include"motionStandard.h"

void Charactor::Init()
{
	{

		m_head = new Parts;			//“ª
		m_neck = new Parts;			//Žñ
		m_chest = new Parts;		//‹¹
		m_waist = new Parts;		//˜

		m_stomach = new Parts;

		m_armUpR = new Parts;		//˜r
		m_armDownR = new Parts;		//‘O˜r
		m_fistR = new Parts;		//Œ
		m_legUpR = new Parts;		//‘¾‚à‚à
		m_legDownR = new Parts;		//’¯ãø
		m_footR = new Parts;		//‘«
		m_armUpL = new Parts;		//˜r
		m_armDownL = new Parts;		//‘O˜r
		m_fistL = new Parts;		//Œ
		m_legUpL = new Parts;		//‘¾‚à‚à
		m_legDownL = new Parts;		//’¯ãø
		m_footL = new Parts;		//‘«

		m_jointChest = new Parts;
		m_jointWaist = new Parts;
		m_jointArmUpR = new Parts;
		m_jointArmDownR = new Parts;
		m_jointArmUpL = new Parts;
		m_jointArmDownL = new Parts;
		m_jointLegUpR = new Parts;
		m_jointLegDownR = new Parts;
		m_jointLegUpL = new Parts;
		m_jointLegDownL = new Parts;
	}


	{
		m_stomach->Init("asset\\model\\sphere00.obj");		//• 
		m_stomach->SetPosition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		m_stomach->SetScale(D3DXVECTOR3(1.0f, 1.0f, 1.0f));


		m_chest->Init("asset\\model\\chest00.obj");		//‹¹
		m_chest->SetPosition(D3DXVECTOR3(0.0f, 0.5f, 0.0f));
		m_chest->SetScale(D3DXVECTOR3(1.0f, 1.0f, 1.0f));


		m_neck->Init("asset\\model\\sphere00.obj");			//Žñ
		m_neck->SetPosition(D3DXVECTOR3(0.0f, 0.3f, 0.0f));
		m_neck->SetScale(D3DXVECTOR3(0.5f, 0.5f, 0.5f));

		m_head->Init("asset\\model\\head00.obj");			//“ª
		m_head->SetPosition(D3DXVECTOR3(0.0f, 0.25f, 0.05f));
		m_head->SetScale(D3DXVECTOR3(1.0f, 1.0f, 1.0f));

		m_armUpR->Init("asset\\model\\arm00.obj");		//˜r
		m_armUpR->SetPosition(D3DXVECTOR3(0.05f, -0.1f, 0.0f));
		m_armUpR->SetScale(D3DXVECTOR3(1.0f, 1.0f, 1.0f));
		m_armDownR->Init("asset\\model\\arm00.obj");		//‘O˜r
		m_armDownR->SetPosition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		m_armDownR->SetScale(D3DXVECTOR3(0.8f, 1.0f, 0.75f));
		m_fistR->Init("asset\\model\\sphere00.obj");		//Œ
		m_fistR->SetPosition(D3DXVECTOR3(0.0f, -0.5f, 0.0f));
		m_fistR->SetScale(D3DXVECTOR3(1.25f, 1.25f, 1.25f));

		m_armUpL->Init("asset\\model\\arm00.obj");		//˜r
		m_armUpL->SetPosition(D3DXVECTOR3(-0.05f, -0.1f, 0.0f));
		m_armUpL->SetScale(D3DXVECTOR3(1.0f, 1.0f, 1.0f));
		m_armDownL->Init("asset\\model\\arm00.obj");		//‘O˜r
		m_armDownL->SetPosition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		m_armDownL->SetScale(D3DXVECTOR3(0.8f, 1.0f, 0.75f));
		m_fistL->Init("asset\\model\\sphere00.obj");		//Œ
		m_fistL->SetPosition(D3DXVECTOR3(0.0f, -0.5f, 0.0f));
		m_fistL->SetScale(D3DXVECTOR3(1.25f, 1.25f, 1.25f));


		m_waist->Init("asset\\model\\waist00.obj");		//˜
		m_waist->SetPosition(D3DXVECTOR3(0.0f, -0.25f, 0.0f));
		m_waist->SetScale(D3DXVECTOR3(1.0f, 1.0f, 1.0f));

		m_legUpR->Init("asset\\model\\legUp00.obj");		//‘¾‚à‚à
		m_legUpR->SetPosition(D3DXVECTOR3(0.0f, -0.0f, 0.0f));
		m_legUpR->SetScale(D3DXVECTOR3(1.25f, 1.25f, 1.25f));
		m_legDownR->Init("asset\\model\\legDown00.obj");		//’¯ãø
		m_legDownR->SetPosition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		m_legDownR->SetScale(D3DXVECTOR3(1.0f, 1.0f, 1.0f));
		m_footR->Init("asset\\model\\foot00.obj");		//‘«
		m_footR->SetPosition(D3DXVECTOR3(0.0f, -0.5f, 0.0f));
		m_footR->SetScale(D3DXVECTOR3(1.0f, 1.0f, 1.0f));

		m_legUpL->Init("asset\\model\\legUp00.obj");		//‘¾‚à‚à
		m_legUpL->SetPosition(D3DXVECTOR3(0.0f, -0.0f, 0.0f));
		m_legUpL->SetScale(D3DXVECTOR3(1.25f, 1.25f, 1.25f));
		m_legDownL->Init("asset\\model\\legDown00.obj");		//’¯ãø
		m_legDownL->SetPosition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		m_legDownL->SetScale(D3DXVECTOR3(1.0f, 1.0f, 1.0f));
		m_footL->Init("asset\\model\\foot00.obj");		//‘«
		m_footL->SetPosition(D3DXVECTOR3(0.0f, -0.5f, 0.0f));
		m_footL->SetScale(D3DXVECTOR3(1.0f, 1.0f, 1.0f));



		m_jointChest->Init("asset\\model\\sphere00.obj");		//• 
		m_jointChest->SetPosition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		m_jointChest->SetScale(D3DXVECTOR3(0.1f, 0.1f, 0.1f));
		m_jointWaist->Init("asset\\model\\sphere00.obj");		//• 
		m_jointWaist->SetPosition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		m_jointWaist->SetScale(D3DXVECTOR3(0.1f, 0.1f, 0.1f));




		m_jointArmUpR->Init("asset\\model\\sphere00.obj");	//Œ¨
		m_jointArmUpR->SetPosition(D3DXVECTOR3(0.3f, 0.1f, 0.0f));
		m_jointArmUpR->SetScale(D3DXVECTOR3(1.25f, 1.25f, 1.25f));
		m_jointArmDownR->Init("asset\\model\\sphere00.obj");		//•I
		m_jointArmDownR->SetPosition(D3DXVECTOR3(0.0f, -0.5f, 0.0f));
		m_jointArmDownR->SetScale(D3DXVECTOR3(0.75f, 0.75f, 0.75f));

		m_jointArmUpL->Init("asset\\model\\sphere00.obj");	//Œ¨
		m_jointArmUpL->SetPosition(D3DXVECTOR3(-0.3f, 0.1f, 0.0f));
		m_jointArmUpL->SetScale(D3DXVECTOR3(1.25f, 1.25f, 1.25f));
		m_jointArmDownL->Init("asset\\model\\sphere00.obj");		//•I
		m_jointArmDownL->SetPosition(D3DXVECTOR3(0.0f, -0.5f, 0.0f));
		m_jointArmDownL->SetScale(D3DXVECTOR3(0.75f, 0.75f, 0.75f));

		m_jointLegUpR->Init("asset\\model\\sphere00.obj");		//‘«‚Ì•t‚¯ª
		m_jointLegUpR->SetPosition(D3DXVECTOR3(-0.25f, -0.3f, 0.0f));
		m_jointLegUpR->SetScale(D3DXVECTOR3(1.25f, 1.25f, 1.25f));
		m_jointLegDownR->Init("asset\\model\\sphere00.obj");		//•G
		m_jointLegDownR->SetPosition(D3DXVECTOR3(0.0f, -0.75f, 0.0f));
		m_jointLegDownR->SetScale(D3DXVECTOR3(1.0f, 1.0f, 1.0f));

		m_jointLegUpL->Init("asset\\model\\sphere00.obj");		//‘«‚Ì•t‚¯ª
		m_jointLegUpL->SetPosition(D3DXVECTOR3(0.25f, -0.3f, 0.0f));
		m_jointLegUpL->SetScale(D3DXVECTOR3(1.25f, 1.25f, 1.25f));
		m_jointLegDownL->Init("asset\\model\\sphere00.obj");		//•G
		m_jointLegDownL->SetPosition(D3DXVECTOR3(0.0f, -0.75f, 0.0f));
		m_jointLegDownL->SetScale(D3DXVECTOR3(1.0f, 1.0f, 1.0f));
	}

	m_fram = 0.0f;
	m_motion = new MotionStay;
	//m_motion = new MotionTest;
	m_motion->Init();
	m_next = 1;


	m_head->SetRotation(m_motion->GetMotion(m_next - 1).head);
	m_neck->SetRotation(m_motion->GetMotion(m_next - 1).neck);
	m_jointChest->SetRotation(m_motion->GetMotion(m_next - 1).chest);//ã”¼g
	m_jointWaist->SetRotation(m_motion->GetMotion(m_next - 1).waist);//‰º”¼g
	m_jointArmUpR->SetRotation(m_motion->GetMotion(m_next - 1).armUpR);//‰EŒ¨
	m_jointArmUpL->SetRotation(m_motion->GetMotion(m_next - 1).armUpL);//¶Œ¨
	m_jointArmDownR->SetRotation(m_motion->GetMotion(m_next - 1).armDownR);//‰E‚Ð‚¶
	m_jointArmDownL->SetRotation(m_motion->GetMotion(m_next - 1).armDownL);//¶‚Ð‚¶
	m_jointLegUpR->SetRotation(m_motion->GetMotion(m_next - 1).legUpR);//‰E‹r
	m_jointLegUpL->SetRotation(m_motion->GetMotion(m_next - 1).legUpL);//¶‹r
	m_jointLegDownR->SetRotation(m_motion->GetMotion(m_next - 1).legDownR);//‰E•G
	m_jointLegDownL->SetRotation(m_motion->GetMotion(m_next - 1).legDownL);//¶•G

	m_f = m_motion->GetMotion(m_next).fcnt - m_motion->GetMotion(m_next - 1).fcnt;
}

void Charactor::Uninit()
{
	m_head->Uninit();
	delete m_head;
	m_neck->Uninit();
	delete m_neck;
	m_chest->Uninit();
	delete m_chest;
	m_waist->Uninit();
	delete m_waist;

	m_armUpR->Uninit();
	delete m_armUpR;
	m_armDownR->Uninit();
	delete m_armDownR;
	m_fistR->Uninit();
	delete m_fistR;

	m_legUpR->Uninit();
	delete m_legUpR;
	m_legDownR->Uninit();
	delete m_legDownR;
	m_footR->Uninit();
	delete m_footR;

	m_armUpL->Uninit();
	delete m_armUpL;
	m_armDownL->Uninit();
	delete m_armDownL;
	m_fistL->Uninit();
	delete m_fistL;


	m_legUpL->Uninit();
	delete m_legUpL;
	m_legDownL->Uninit();
	delete m_legDownL;
	m_footL->Uninit();
	delete m_footL;


	m_jointChest->Uninit();
	delete m_jointChest;
	m_jointWaist->Uninit();
	delete m_jointWaist;
	m_jointArmUpR->Uninit();
	delete m_jointArmUpR;
	m_jointArmDownR->Uninit();
	delete m_jointArmDownR;
	m_jointArmUpL->Uninit();
	delete m_jointArmUpL;
	m_jointArmDownL->Uninit();
	delete m_jointArmDownL;
	m_jointLegUpR->Uninit();
	delete m_jointLegUpR;
	m_jointLegDownR->Uninit();
	delete m_jointLegDownR;
	m_jointLegUpL->Uninit();
	delete m_jointLegUpL;
	m_jointLegDownL->Uninit();
	delete m_jointLegDownL;
}
void Charactor::Update()
{
	m_fram += 1.0f;
	if (m_motion->GetMotion(m_next).fcnt <= m_fram) {
		m_next += 1;
		if (m_motion->GetMotionEndNum() <= m_next) {

			if (m_motion->GetStop() == false) {
				m_fram = 0.0f;
				m_next = 1;

				if (m_motionStatus != MOTION_NONE) {
					SetNextMotion(MOTION_STAY);
				}

				if (m_move == true) {
					m_move = false;
				}

				m_motion->SetWait(false);
			}
			else {
				m_motion->SetWait(false);
				m_next = m_motion->GetMotionEndNum() - 1;
				m_fram = m_motion->GetMotion(m_next).fcnt;
			}
		}
		m_f = m_motion->GetMotion(m_next).fcnt - m_motion->GetMotion(m_next - 1).fcnt;
	}
	else {
		//1Fram‚Å‚Ç‚ê‚­‚ç‚¢•Ï‰»‚·‚é‚©‚ÌŒvŽZ
		MotionMove();
	}

}
void Charactor::Draw(D3DXMATRIX w)
{
	//‹N“_
	m_stomach->Draw(w);

	m_jointChest->Draw(m_stomach->GetWorldMatrix());//• 
	m_jointWaist->Draw(m_stomach->GetWorldMatrix());//• 

	////‚P’i–Ú
	m_chest->Draw(m_jointChest->GetWorldMatrix());//‹¹
	m_waist->Draw(m_jointWaist->GetWorldMatrix());//˜

	////‚Q’i–Ú
	m_neck->Draw(m_chest->GetWorldMatrix());
	m_jointArmUpR->Draw(m_chest->GetWorldMatrix());
	m_jointArmUpL->Draw(m_chest->GetWorldMatrix());
	m_jointLegUpR->Draw(m_waist->GetWorldMatrix());
	m_jointLegUpL->Draw(m_waist->GetWorldMatrix());

	////‚R’i–Ú
	m_head->Draw(m_neck->GetWorldMatrix());
	m_armUpR->Draw(m_jointArmUpR->GetWorldMatrix());
	m_armUpL->Draw(m_jointArmUpL->GetWorldMatrix());
	m_legUpR->Draw(m_jointLegUpR->GetWorldMatrix());
	m_legUpL->Draw(m_jointLegUpL->GetWorldMatrix());

	////‚S’i–Ú
	m_jointArmDownR->Draw(m_armUpR->GetWorldMatrix());
	m_jointArmDownL->Draw(m_armUpL->GetWorldMatrix());
	m_jointLegDownR->Draw(m_legUpR->GetWorldMatrix());
	m_jointLegDownL->Draw(m_legUpL->GetWorldMatrix());

	////‚T’i–Ú
	m_armDownR->Draw(m_jointArmDownR->GetWorldMatrix());
	m_armDownL->Draw(m_jointArmDownL->GetWorldMatrix());
	m_legDownR->Draw(m_jointLegDownR->GetWorldMatrix());
	m_legDownL->Draw(m_jointLegDownL->GetWorldMatrix());

	/////‚U’i–Ú
	m_fistR->Draw(m_armDownR->GetWorldMatrix());
	m_fistL->Draw(m_armDownL->GetWorldMatrix());
	m_footR->Draw(m_legDownR->GetWorldMatrix());
	m_footL->Draw(m_legDownL->GetWorldMatrix());
}

void Charactor::SetNextMotion(MOTIONSTATUS ms = MOTION_NONE)
{
	//ŽŸ‚ÌMotion‚ðƒZƒbƒg
	if (m_motionStatus != ms && ms != MOTION_NONE) {
		m_motionStatus = ms;

		m_move = false;

		m_motion->Uninit();
		delete m_motion;

		switch (m_motionStatus)
		{
		case MOTION_STAY:
			m_motion = new MotionStay;
			break;
		case MOTION_DOWNSTAY:
			m_motion = new MotionStayDown;
			break;
		case MOTION_DOWNSTAYED:
			m_motion = new MotionStayed;
			break;
		case MOTION_STANDUP:
			m_motion = new MotionStandUp;
			break;
		case MOTION_WALK:
			m_motion = new MotionWalk;
			break;
		case MOTION_DOWNWALK:
			m_motion = new MotionWalkDown;
			break;
		case MOTION_JUMP:
			m_motion = new MotionJump;
			break;
		case MOTION_JUMPATTACK:
			m_motion = new MotionAttackJump;
			break;
		case MOTION_GUARD:
			m_motion = new MotionGuard;
			break;
		case MOTION_DOWNGUARD:
			m_motion = new MotionGuardDown;
			break;
		case MOTION_HOLD:
			m_motion = new MotionHold;
			break;
		case MOTION_HOLDMISS:
			m_motion = new MotionHoldMiss;
			break;
		case MOTION_HOLDATTACK:
			m_motion = new MotionThrow;
			break;
		case MOTION_DAMAGE:
			m_motion = new MotionDamage;
			break;
		case MOTION_BURST:
			m_motion = new MotionBurst;
			break;
		case MOTION_OVERUP:
			m_motion = new MotionOverUp;
			break;
		case MOTION_OVER:
			m_motion = new MotionOver;
			break;
		case MOTION_ATTACKPA:
			m_motion = new MotionAttackPA;
			break;
		case MOTION_ATTACKPB:
			m_motion = new MotionAttackPB;
			break;
		case MOTION_ATTACKK:
			m_motion = new MotionAttackKB;
			break;
		case MOTION_ATTACKDOWN:
			m_motion = new MotionDownAttack;
			break;
		case MOTION_SHOT:
			m_motion = new MotionAttackShot;
			break;
		default:
			break;
		}


		m_motion->Init();

		m_fram = 0.0f;
		m_next = 1;
		m_f = m_motion->GetMotion(m_next).fcnt - m_motion->GetMotion(m_next - 1).fcnt;
	}

}

Parameter* Charactor::GetParameter()
{
	Parameter* p = new StandardParameter;
	p->Init();
	return p;
}

D3DXMATRIX Charactor::GetFistMatrix()
{
	return m_fistR->GetWorldMatrix();
}

void Charactor::MotionMove()
{
	D3DXVECTOR3 rot;
	//ƒRƒR‚ÍˆÊ’u’²ßi‹N“_‚Í• j
	rot = (m_motion->GetMotion(m_next).stomachPos - m_motion->GetMotion(m_next - 1).stomachPos) / m_f;
	m_stomach->SetPosition(m_motion->GetMotion(m_next - 1).stomachPos + (rot * (m_fram - m_motion->GetMotion(m_next - 1).fcnt)));
	//“ª
	rot = (m_motion->GetMotion(m_next).head - m_motion->GetMotion(m_next - 1).head) / m_f;
	m_head->SetRotation(m_motion->GetMotion(m_next - 1).head + (rot * (m_fram - m_motion->GetMotion(m_next - 1).fcnt)));
	//Žñ
	rot = (m_motion->GetMotion(m_next).neck - m_motion->GetMotion(m_next - 1).neck) / m_f;
	m_neck->SetRotation(m_motion->GetMotion(m_next - 1).neck + (rot * (m_fram - m_motion->GetMotion(m_next - 1).fcnt)));
	//ã”¼g
	rot = (m_motion->GetMotion(m_next).chest - m_motion->GetMotion(m_next - 1).chest) / m_f;
	m_jointChest->SetRotation(m_motion->GetMotion(m_next - 1).chest + (rot * (m_fram - m_motion->GetMotion(m_next - 1).fcnt)));
	//‰º”¼g
	rot = (m_motion->GetMotion(m_next).waist - m_motion->GetMotion(m_next - 1).waist) / m_f;
	m_jointWaist->SetRotation(m_motion->GetMotion(m_next - 1).waist + (rot * (m_fram - m_motion->GetMotion(m_next - 1).fcnt)));
	//‰EŒ¨
	rot = (m_motion->GetMotion(m_next).armUpR - m_motion->GetMotion(m_next - 1).armUpR) / m_f;
	m_jointArmUpR->SetRotation(m_motion->GetMotion(m_next - 1).armUpR + (rot * (m_fram - m_motion->GetMotion(m_next - 1).fcnt)));
	//¶Œ¨
	rot = (m_motion->GetMotion(m_next).armUpL - m_motion->GetMotion(m_next - 1).armUpL) / m_f;
	m_jointArmUpL->SetRotation(m_motion->GetMotion(m_next - 1).armUpL + (rot * (m_fram - m_motion->GetMotion(m_next - 1).fcnt)));
	//‰E‚Ð‚¶
	rot = (m_motion->GetMotion(m_next).armDownR - m_motion->GetMotion(m_next - 1).armDownR) / m_f;
	m_jointArmDownR->SetRotation(m_motion->GetMotion(m_next - 1).armDownR + (rot * (m_fram - m_motion->GetMotion(m_next - 1).fcnt)));
	//¶‚Ð‚¶
	rot = (m_motion->GetMotion(m_next).armDownL - m_motion->GetMotion(m_next - 1).armDownL) / m_f;
	m_jointArmDownL->SetRotation(m_motion->GetMotion(m_next - 1).armDownL + (rot * (m_fram - m_motion->GetMotion(m_next - 1).fcnt)));
	//‰E‹r
	rot = (m_motion->GetMotion(m_next).legUpR - m_motion->GetMotion(m_next - 1).legUpR) / m_f;
	m_jointLegUpR->SetRotation(m_motion->GetMotion(m_next - 1).legUpR + (rot * (m_fram - m_motion->GetMotion(m_next - 1).fcnt)));
	//¶‹r
	rot = (m_motion->GetMotion(m_next).legUpL - m_motion->GetMotion(m_next - 1).legUpL) / m_f;
	m_jointLegUpL->SetRotation(m_motion->GetMotion(m_next - 1).legUpL + (rot * (m_fram - m_motion->GetMotion(m_next - 1).fcnt)));
	//‰E•G
	rot = (m_motion->GetMotion(m_next).legDownR - m_motion->GetMotion(m_next - 1).legDownR) / m_f;
	m_jointLegDownR->SetRotation(m_motion->GetMotion(m_next - 1).legDownR + (rot * (m_fram - m_motion->GetMotion(m_next - 1).fcnt)));
	//¶•G
	rot = (m_motion->GetMotion(m_next).legDownL - m_motion->GetMotion(m_next - 1).legDownL) / m_f;
	m_jointLegDownL->SetRotation(m_motion->GetMotion(m_next - 1).legDownL + (rot * (m_fram - m_motion->GetMotion(m_next - 1).fcnt)));


	//‰E‘«
	rot = (m_motion->GetMotion(m_next).footR - m_motion->GetMotion(m_next - 1).footR) / m_f;
	m_footR->SetRotation(m_motion->GetMotion(m_next - 1).footR + (rot * (m_fram - m_motion->GetMotion(m_next - 1).fcnt)));
	//¶‘«
	rot = (m_motion->GetMotion(m_next).footL - m_motion->GetMotion(m_next - 1).footL) / m_f;
	m_footL->SetRotation(m_motion->GetMotion(m_next - 1).footL + (rot * (m_fram - m_motion->GetMotion(m_next - 1).fcnt)));

}



