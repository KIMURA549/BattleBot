#pragma once
#include"main.h"
#include"component.h"
#include<vector>
#include"motion.h"
class Parts;

enum CHARACTERSTATUS {
	STAND,
	DOWN,
	JUMP,
	ATTACK,
	CATCH,
	DAMAGE,
	HOLD,
	OVER,

	NONE,
};

enum MOTIONSTATUS {
	MOTION_STAY,
	MOTION_DOWNSTAY,
	MOTION_DOWNSTAYED,
	MOTION_STANDUP,
	MOTION_WALK,
	MOTION_DOWNWALK,
	MOTION_JUMP,
	MOTION_JUMPATTACK,

	MOTION_GUARD,
	MOTION_DOWNGUARD,

	MOTION_HOLD,
	MOTION_HOLDMISS,
	MOTION_HOLDATTACK,

	MOTION_DAMAGE,
	MOTION_BURST,
	MOTION_OVERUP,
	MOTION_OVER,

	MOTION_ATTACKPA,
	MOTION_ATTACKPB,
	MOTION_ATTACKK,

	MOTION_ATTACKDOWN,
	MOTION_SHOT,
	MOTION_NONE,
};


class Charactor : public Component
{
private:

	//gΜΜp[c
	Parts* m_head;			//ͺ
	Parts* m_neck;			//ρ
	Parts* m_chest;			//Ή
	Parts* m_waist;			//
	
	Parts* m_stomach;		// 

	//E€
	Parts* m_armUpR;		//r
	Parts* m_armDownR;		//Or
	Parts* m_fistR;			//
	//
	Parts* m_legUpR;		//Ύΰΰ
	Parts* m_legDownR;		//―γψ
	Parts* m_footR;			//«
	
	//Ά€
	Parts* m_armUpL;		//r
	Parts* m_armDownL;		//Or
	Parts* m_fistL;			//
	//
	Parts* m_legUpL;		//Ύΰΰ
	Parts* m_legDownL;		//―γψ
	Parts* m_footL;			//«		

	Parts* m_jointChest;
	Parts* m_jointWaist;
	Parts* m_jointArmUpR;
	Parts* m_jointArmDownR;
	Parts* m_jointArmUpL;
	Parts* m_jointArmDownL;
	Parts* m_jointLegUpR;
	Parts* m_jointLegDownR;
	Parts* m_jointLegUpL;
	Parts* m_jointLegDownL;

	float m_fram = 0.0f;

	MOTIONSTATUS m_motionStatus = MOTION_NONE;

	Motion* m_motion;
	int m_next = 1;//ΜzρΤ
	float m_f = 0.0f;//‘ΖΜframΜ΄o


	//ΜMotionΦJΪ
	MOTIONDATA m_nowMotion; //»σΜσΤ
	Motion* m_nextMotion;
	bool m_changeMotion = false;

	bool m_move = false;

	void MotionMove();

public:
	void Init();
	void Uninit();
	void Update();
	void Draw(D3DXMATRIX world);

	void SetNextMotion(MOTIONSTATUS ms);

	class Parameter* GetParameter();

	bool GetMotionFlag() {
		return m_move;
	}

	MOTIONSTATUS GetMotionState() {
		return m_motionStatus;
	}

	void SetMotionStop(bool stop) {
		m_motion->SetStop(stop);
	}

	bool GetMotionWait() {
		return m_motion->GetWait();
	}

	float GetFrame() {
		return m_fram;
	}

	D3DXMATRIX GetFistMatrix();
};