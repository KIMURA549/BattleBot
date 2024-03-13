#pragma once
#include"main.h"

#define ONEANGLE (D3DX_PI / 180.0f)

struct MOTIONDATA {
public:
	//フェードカウント
	float fcnt;
	//起点	プレイヤーのY位置調節
	D3DXVECTOR3 stomachPos;//腹
	D3DXVECTOR3 head;
	D3DXVECTOR3 neck;
	D3DXVECTOR3 chest;
	D3DXVECTOR3 waist;
	D3DXVECTOR3 armUpR;
	D3DXVECTOR3 armUpL;
	D3DXVECTOR3 armDownR;
	D3DXVECTOR3 armDownL;
	D3DXVECTOR3 legUpR;
	D3DXVECTOR3 legUpL;
	D3DXVECTOR3 legDownR;
	D3DXVECTOR3 legDownL;
	D3DXVECTOR3 footR;
	D3DXVECTOR3 footL;
};

class Motion {
private:
protected:
	MOTIONDATA m_motion[10];
	int m_num;
	bool m_roop = false;
	bool m_stop = false;
	bool m_wait = false;
public:
	virtual void Init(){}
	virtual void Uninit() {}
	virtual MOTIONDATA GetMotion(int num) { return m_motion[num]; }
	virtual float ToNextFrame(int num) { return 0.0f; }
	int GetMotionEndNum() {
		return m_num;
	}
	bool GetRoop() {
		return m_roop;
	}
	bool GetStop() {
		return m_stop;
	}
	void SetStop(bool stop) {
		m_stop = stop;
	}
	bool GetWait() {
		return m_wait;
	}

	void SetWait(bool w) {
		m_wait = w;
	}
};