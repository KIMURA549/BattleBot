#pragma once
#include"motion.h"
#include"parameter.h"

class StandardParameter :public Parameter {
public:
	void Init() override {
		SetParameter(
			100,
			10.0f,
			5.0f,
			0.025f,
			0.03f
		);
	}
};


//ë“ã@
class MotionStay : public Motion {
private:
public:
	void Init() override {
		m_num = 3;
		m_roop = true;

		//ç≈èâÇ∆ç≈å„ÇÃäpìxÇÕìØÇ∂ílÇ…Ç∑ÇÈ
		{
			m_motion[0].fcnt = 0.0f;
			m_motion[0].stomachPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].chest = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[0].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[0].armDownL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[0].legUpR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[0].legDownR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[0].legUpL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[0].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[0].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}

		{
			m_motion[1].fcnt = 25.0f;
			m_motion[1].stomachPos = D3DXVECTOR3(0.0f, -0.1f, 0.0f);
			m_motion[1].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].chest = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[1].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[1].armDownR = D3DXVECTOR3(-ONEANGLE * 125, 0.0f, 0.0f);
			m_motion[1].armUpL = D3DXVECTOR3(-ONEANGLE * 55, 0.0f, 0.0f);
			m_motion[1].armDownL = D3DXVECTOR3(-ONEANGLE * 105, 0.0f, 0.0f);
			m_motion[1].legUpR = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[1].legDownR = D3DXVECTOR3(ONEANGLE * 60, 0.0f, 0.0f);
			m_motion[1].legUpL = D3DXVECTOR3(ONEANGLE * 5, 0.0f, 0.0f);
			m_motion[1].legDownL = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[1].footR = D3DXVECTOR3(-ONEANGLE * 5, 0.0f, 0.0f);
			m_motion[1].footL = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
		}

		{
			m_motion[2].fcnt = 50.0f;
			m_motion[2].stomachPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].chest = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[2].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[2].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[2].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[2].armDownL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[2].legUpR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[2].legDownR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[2].legUpL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[2].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[2].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}
	}
};

//ïöÇπ
class MotionStayDown : public Motion {
private:
public:
	void Init() override {
		m_wait = true;
		m_stop = true;

		m_num = 3;

		//ç≈èâÇ∆ç≈å„ÇÃäpìxÇÕìØÇ∂ílÇ…Ç∑ÇÈ
		{
			m_motion[0].fcnt = 0.0f;
			m_motion[0].stomachPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].chest = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[0].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[0].armDownL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[0].legUpR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[0].legDownR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[0].legUpL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[0].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[0].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}

		{
			m_motion[1].fcnt = 15.0f;
			m_motion[1].stomachPos = D3DXVECTOR3(0.0f, -0.75f, 0.0f);
			m_motion[1].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].neck = D3DXVECTOR3(-ONEANGLE * 60, 0.0f, 0.0f);
			m_motion[1].chest = D3DXVECTOR3(ONEANGLE * 75, 0.0f, 0.0f);
			m_motion[1].waist = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[1].armUpR = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[1].armDownR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[1].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[1].armDownL = D3DXVECTOR3(-ONEANGLE * 45, 0.0f, 0.0f);
			m_motion[1].legUpR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[1].legDownR = D3DXVECTOR3(ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[1].legUpL = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[1].legDownL = D3DXVECTOR3(ONEANGLE * 160, 0.0f, 0.0f);
			m_motion[1].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].footL = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
		}

		{
			m_motion[2].fcnt = 30.0f;
			m_motion[2].stomachPos = D3DXVECTOR3(0.0f, -1.0f, 0.0f);
			m_motion[2].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].neck = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[2].chest = D3DXVECTOR3(ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[2].waist = D3DXVECTOR3(ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[2].armUpR = D3DXVECTOR3(-ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[2].armDownR = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[2].armUpL = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[2].armDownL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[2].legUpR = D3DXVECTOR3(-ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[2].legDownR = D3DXVECTOR3(ONEANGLE * 105, 0.0f, 0.0f);
			m_motion[2].legUpL = D3DXVECTOR3(-ONEANGLE * 90, 0.0f, 0.0f);
			m_motion[2].legDownL = D3DXVECTOR3(ONEANGLE * 105, 0.0f, 0.0f);
			m_motion[2].footR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[2].footL = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
		}
	}
};

class MotionStayed : public Motion {
private:
public:
	void Init() override {
		m_stop = true;
		m_num = 2;

		//ç≈èâÇ∆ç≈å„ÇÃäpìxÇÕìØÇ∂ílÇ…Ç∑ÇÈ
		{
			m_motion[0].fcnt = 00.0f;
			m_motion[0].stomachPos = D3DXVECTOR3(0.0f, -1.0f, 0.0f);
			m_motion[0].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].neck = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[0].chest = D3DXVECTOR3(ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[0].waist = D3DXVECTOR3(ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[0].armUpR = D3DXVECTOR3(-ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[0].armDownR = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[0].armUpL = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[0].armDownL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[0].legUpR = D3DXVECTOR3(-ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[0].legDownR = D3DXVECTOR3(ONEANGLE * 105, 0.0f, 0.0f);
			m_motion[0].legUpL = D3DXVECTOR3(-ONEANGLE * 90, 0.0f, 0.0f);
			m_motion[0].legDownL = D3DXVECTOR3(ONEANGLE * 105, 0.0f, 0.0f);
			m_motion[0].footR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[0].footL = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
		}

		{
			m_motion[1].fcnt = 10.0f;
			m_motion[1].stomachPos = D3DXVECTOR3(0.0f, -1.0f, 0.0f);
			m_motion[1].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].neck = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[1].chest = D3DXVECTOR3(ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[1].waist = D3DXVECTOR3(ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[1].armUpR = D3DXVECTOR3(-ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[1].armDownR = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[1].armUpL = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[1].armDownL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[1].legUpR = D3DXVECTOR3(-ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[1].legDownR = D3DXVECTOR3(ONEANGLE * 105, 0.0f, 0.0f);
			m_motion[1].legUpL = D3DXVECTOR3(-ONEANGLE * 90, 0.0f, 0.0f);
			m_motion[1].legDownL = D3DXVECTOR3(ONEANGLE * 105, 0.0f, 0.0f);
			m_motion[1].footR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[1].footL = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
		}
	}
};

class MotionStandUp : public Motion {
private:
public:
	void Init() override {
		m_wait = true;
		m_num = 3;

		{
			m_motion[0].fcnt = 0.0f;
			m_motion[0].stomachPos = D3DXVECTOR3(0.0f, -1.0f, 0.0f);
			m_motion[0].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].neck = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[0].chest = D3DXVECTOR3(ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[0].waist = D3DXVECTOR3(ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[0].armUpR = D3DXVECTOR3(-ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[0].armDownR = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[0].armUpL = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[0].armDownL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[0].legUpR = D3DXVECTOR3(-ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[0].legDownR = D3DXVECTOR3(ONEANGLE * 105, 0.0f, 0.0f);
			m_motion[0].legUpL = D3DXVECTOR3(-ONEANGLE * 90, 0.0f, 0.0f);
			m_motion[0].legDownL = D3DXVECTOR3(ONEANGLE * 105, 0.0f, 0.0f);
			m_motion[0].footR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[0].footL = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
		}

		{
			m_motion[1].fcnt = 15.0f;
			m_motion[1].stomachPos = D3DXVECTOR3(0.0f, -0.75f, 0.0f);
			m_motion[1].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].neck = D3DXVECTOR3(-ONEANGLE * 60, 0.0f, 0.0f);
			m_motion[1].chest = D3DXVECTOR3(ONEANGLE * 75, 0.0f, 0.0f);
			m_motion[1].waist = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[1].armUpR = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[1].armDownR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[1].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[1].armDownL = D3DXVECTOR3(-ONEANGLE * 45, 0.0f, 0.0f);
			m_motion[1].legUpR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[1].legDownR = D3DXVECTOR3(ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[1].legUpL = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[1].legDownL = D3DXVECTOR3(ONEANGLE * 160, 0.0f, 0.0f);
			m_motion[1].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].footL = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
		}

		{
			m_motion[2].fcnt = 30.0f;
			m_motion[2].stomachPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].chest = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[2].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[2].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[2].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[2].armDownL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[2].legUpR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[2].legDownR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[2].legUpL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[2].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[2].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}
	}
};
//ï‡Ç´
class MotionWalk : public Motion {
private:
public:
	void Init() override {
		m_roop = false;
		m_num = 3;

		////ç≈èâÇ∆ç≈å„ÇÃäpìxÇÕìØÇ∂ílÇ…Ç∑ÇÈ

		{
			m_motion[0].fcnt = 0.0f;
			m_motion[0].stomachPos = D3DXVECTOR3(0.1f, -0.1f, 0.0f);
			m_motion[0].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].chest = D3DXVECTOR3(ONEANGLE * 25, 0.0f, 0.0f);
			m_motion[0].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].armDownR = D3DXVECTOR3(-ONEANGLE * 125, 0.0f, 0.0f);
			m_motion[0].armUpL = D3DXVECTOR3(-ONEANGLE * 55, 0.0f, 0.0f);
			m_motion[0].armDownL = D3DXVECTOR3(-ONEANGLE * 105, 0.0f, 0.0f);
			m_motion[0].legUpR = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[0].legDownR = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].legUpL = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].legDownL = D3DXVECTOR3(ONEANGLE * 35, 0.0f, 0.0f);
			m_motion[0].footR = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].footL = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
		}

		{
			m_motion[1].fcnt = 20.0f;
			m_motion[1].stomachPos = D3DXVECTOR3(-0.1f, 0.0f, 0.0f);
			m_motion[1].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].chest = D3DXVECTOR3(ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[1].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[1].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[1].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[1].armDownL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[1].legUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[1].legDownR = D3DXVECTOR3(ONEANGLE * 25, 0.0f, 0.0f);
			m_motion[1].legUpL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[1].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[1].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}

		{
			m_motion[2].fcnt = 40.0f;
			m_motion[2].stomachPos = D3DXVECTOR3(0.1f, -0.1f, 0.0f);
			m_motion[2].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].chest = D3DXVECTOR3(ONEANGLE * 25, 0.0f, 0.0f);
			m_motion[2].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[2].armDownR = D3DXVECTOR3(-ONEANGLE * 125, 0.0f, 0.0f);
			m_motion[2].armUpL = D3DXVECTOR3(-ONEANGLE * 55, 0.0f, 0.0f);
			m_motion[2].armDownL = D3DXVECTOR3(-ONEANGLE * 105, 0.0f, 0.0f);
			m_motion[2].legUpR = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[2].legDownR = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[2].legUpL = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[2].legDownL = D3DXVECTOR3(ONEANGLE * 35, 0.0f, 0.0f);
			m_motion[2].footR = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[2].footL = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
		}

	}
};

//ïöÇπï‡Ç´
class MotionWalkDown : public Motion {
private:
public:
	void Init() override {
		m_roop = true;
		m_num = 5;

		{
			m_motion[0].fcnt = 0.0f;
			m_motion[0].stomachPos = D3DXVECTOR3(0.0f, -1.0f, 0.0f);
			m_motion[0].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].neck = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[0].chest = D3DXVECTOR3(ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[0].waist = D3DXVECTOR3(ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[0].armUpR = D3DXVECTOR3(-ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[0].armDownR = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[0].armUpL = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[0].armDownL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[0].legUpR = D3DXVECTOR3(-ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[0].legDownR = D3DXVECTOR3(ONEANGLE * 105, 0.0f, 0.0f);
			m_motion[0].legUpL = D3DXVECTOR3(-ONEANGLE * 90, 0.0f, 0.0f);
			m_motion[0].legDownL = D3DXVECTOR3(ONEANGLE * 105, 0.0f, 0.0f);
			m_motion[0].footR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[0].footL = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
		}

		{
			m_motion[1].fcnt = 15.0f;
			m_motion[1].stomachPos = D3DXVECTOR3(0.0f, -1.0f, 0.0f);
			m_motion[1].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].neck = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[1].chest = D3DXVECTOR3(ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[1].waist = D3DXVECTOR3(ONEANGLE * 70, 0.0f, 0.0f);
			m_motion[1].armUpR = D3DXVECTOR3(-ONEANGLE * 110, 0.0f, 0.0f);
			m_motion[1].armDownR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[1].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[1].armDownL = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[1].legUpR = D3DXVECTOR3(-ONEANGLE * 60, 0.0f, 0.0f);
			m_motion[1].legDownR = D3DXVECTOR3(ONEANGLE * 90, 0.0f, 0.0f);
			m_motion[1].legUpL = D3DXVECTOR3(-ONEANGLE * 110, 0.0f, 0.0f);
			m_motion[1].legDownL = D3DXVECTOR3(ONEANGLE * 130, 0.0f, 0.0f);
			m_motion[1].footR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[1].footL = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
		}

		{
			m_motion[2].fcnt = 30.0f;
			m_motion[2].stomachPos = D3DXVECTOR3(0.0f, -1.0f, 0.0f);
			m_motion[2].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].neck = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[2].chest = D3DXVECTOR3(ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[2].waist = D3DXVECTOR3(ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[2].armUpR = D3DXVECTOR3(-ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[2].armDownR = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[2].armUpL = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[2].armDownL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[2].legUpR = D3DXVECTOR3(-ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[2].legDownR = D3DXVECTOR3(ONEANGLE * 105, 0.0f, 0.0f);
			m_motion[2].legUpL = D3DXVECTOR3(-ONEANGLE * 90, 0.0f, 0.0f);
			m_motion[2].legDownL = D3DXVECTOR3(ONEANGLE * 105, 0.0f, 0.0f);
			m_motion[2].footR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[2].footL = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
		}
		{
			m_motion[3].fcnt = 45.0f;
			m_motion[3].stomachPos = D3DXVECTOR3(0.0f, -1.0f, 0.0f);
			m_motion[3].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].neck = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[3].chest = D3DXVECTOR3(ONEANGLE * 90, 0.0f, 0.0f);
			m_motion[3].waist = D3DXVECTOR3(ONEANGLE * 80, 0.0f, -ONEANGLE * 10);
			m_motion[3].armUpR = D3DXVECTOR3(-ONEANGLE * 60, 0.0f, 0.0f);
			m_motion[3].armDownR = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[3].armUpL = D3DXVECTOR3(-ONEANGLE * 110, 0.0f, 0.0f);
			m_motion[3].armDownL = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[3].legUpR = D3DXVECTOR3(-ONEANGLE * 110, 0.0f, 0.0f);
			m_motion[3].legDownR = D3DXVECTOR3(ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[3].legUpL = D3DXVECTOR3(-ONEANGLE * 70, 0.0f, 0.0f);
			m_motion[3].legDownL = D3DXVECTOR3(ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[3].footR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[3].footL = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
		}

		{
			m_motion[4].fcnt = 60.0f;
			m_motion[4].stomachPos = D3DXVECTOR3(0.0f, -1.0f, 0.0f);
			m_motion[4].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[4].neck = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[4].chest = D3DXVECTOR3(ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[4].waist = D3DXVECTOR3(ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[4].armUpR = D3DXVECTOR3(-ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[4].armDownR = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[4].armUpL = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[4].armDownL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[4].legUpR = D3DXVECTOR3(-ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[4].legDownR = D3DXVECTOR3(ONEANGLE * 105, 0.0f, 0.0f);
			m_motion[4].legUpL = D3DXVECTOR3(-ONEANGLE * 90, 0.0f, 0.0f);
			m_motion[4].legDownL = D3DXVECTOR3(ONEANGLE * 105, 0.0f, 0.0f);
			m_motion[4].footR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[4].footL = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
		}

	}
};

//ÉWÉÉÉìÉv
class MotionJump : public Motion {
private:
public:
	void Init() override {
		m_stop = true;
		m_num = 4;

		//ç≈èâÇ∆ç≈å„ÇÃäpìxÇÕìØÇ∂ílÇ…Ç∑ÇÈ
		{
			m_motion[0].fcnt = 0.0f;
			m_motion[0].stomachPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

			m_motion[0].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].chest = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[0].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[0].armDownL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[0].legUpR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[0].legDownR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[0].legUpL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[0].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[0].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}

		{
			m_motion[1].fcnt = 15.0f;
			m_motion[1].stomachPos = D3DXVECTOR3(0.0f, -0.4f, 0.0f);
			m_motion[1].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].chest = D3DXVECTOR3(ONEANGLE * 45, 0.0f, 0.0f);
			m_motion[1].waist = D3DXVECTOR3(-ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[1].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[1].armDownR = D3DXVECTOR3(-ONEANGLE * 125, 0.0f, 0.0f);
			m_motion[1].armUpL = D3DXVECTOR3(-ONEANGLE * 55, 0.0f, 0.0f);
			m_motion[1].armDownL = D3DXVECTOR3(-ONEANGLE * 105, 0.0f, 0.0f);
			m_motion[1].legUpR = D3DXVECTOR3(-ONEANGLE * 60, 0.0f, 0.0f);
			m_motion[1].legDownR = D3DXVECTOR3(ONEANGLE * 110, 0.0f, 0.0f);
			m_motion[1].legUpL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[1].legDownL = D3DXVECTOR3(ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[1].footR = D3DXVECTOR3(-ONEANGLE * 25, 0.0f, 0.0f);
			m_motion[1].footL = D3DXVECTOR3(-ONEANGLE * 10, 0.0f, 0.0f);
		}

		{
			m_motion[2].fcnt = 35.0f;
			m_motion[2].stomachPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].chest = D3DXVECTOR3(ONEANGLE * 45, 0.0f, 0.0f);
			m_motion[2].waist = D3DXVECTOR3(-ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[2].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[2].armDownR = D3DXVECTOR3(-ONEANGLE * 125, 0.0f, 0.0f);
			m_motion[2].armUpL = D3DXVECTOR3(-ONEANGLE * 55, 0.0f, 0.0f);
			m_motion[2].armDownL = D3DXVECTOR3(-ONEANGLE * 105, 0.0f, 0.0f);
			m_motion[2].legUpR = D3DXVECTOR3(-ONEANGLE * 60, 0.0f, 0.0f);
			m_motion[2].legDownR = D3DXVECTOR3(ONEANGLE * 110, 0.0f, 0.0f);
			m_motion[2].legUpL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[2].legDownL = D3DXVECTOR3(ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[2].footR = D3DXVECTOR3(-ONEANGLE * 25, 0.0f, 0.0f);
			m_motion[2].footL = D3DXVECTOR3(-ONEANGLE * 10, 0.0f, 0.0f);
		}

	}
};

//ÉWÉÉÉìÉvçUåÇ
class MotionAttackJump : public Motion {
private:
public:
	void Init() override {
		m_num = 2;
		m_stop = true;

		//ç≈èâÇ∆ç≈å„ÇÃäpìxÇÕìØÇ∂ílÇ…Ç∑ÇÈ
		{
			m_motion[0].fcnt = 0.0f;
			m_motion[0].stomachPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].neck = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].chest = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].waist = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[0].armUpR = D3DXVECTOR3(ONEANGLE * 160, 0.0f, 0.0f);
			m_motion[0].armDownR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].armUpL = D3DXVECTOR3(ONEANGLE * 160, 0.0f, 0.0f);
			m_motion[0].armDownL = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].legUpR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].legDownR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].legUpL = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].legDownL = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].footL = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		}

		{
			m_motion[1].fcnt = 15.0f;
			m_motion[1].stomachPos = D3DXVECTOR3(-0.0f, 0.0f, 0.0f);
			m_motion[1].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].neck = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[1].chest = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[1].waist = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[1].armUpR = D3DXVECTOR3(ONEANGLE * 160, 0.0f, 0.0f);
			m_motion[1].armDownR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].armUpL = D3DXVECTOR3(ONEANGLE * 160, 0.0f, 0.0f);
			m_motion[1].armDownL = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].legUpR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].legDownR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].legUpL = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].legDownL = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].footL = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		}
	}
};

//ÉKÅ[Éh
class MotionGuard : public Motion {
private:
public:
	void Init() override {
		m_num = 2;

		//ç≈èâÇ∆ç≈å„ÇÃäpìxÇÕìØÇ∂ílÇ…Ç∑ÇÈ
		{
			m_motion[0].fcnt = 0.0f;
			m_motion[0].stomachPos = D3DXVECTOR3(0.0f, -0.1f, 0.0f);
			m_motion[0].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].chest = D3DXVECTOR3(ONEANGLE * 35, 0.0f, 0.0f);
			m_motion[0].waist = D3DXVECTOR3(-ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[0].armUpR = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[0].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[0].armUpL = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[0].armDownL = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[0].legUpR = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[0].legDownR = D3DXVECTOR3(ONEANGLE * 60, 0.0f, 0.0f);
			m_motion[0].legUpL = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].legDownL = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[0].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].footL = D3DXVECTOR3(-ONEANGLE * 35, 0.0f, 0.0f);
		}

		{
			m_motion[1].fcnt = 20.0f;
			m_motion[1].stomachPos = D3DXVECTOR3(0.0f, -0.1f, 0.0f);
			m_motion[1].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].chest = D3DXVECTOR3(ONEANGLE * 35, 0.0f, 0.0f);
			m_motion[1].waist = D3DXVECTOR3(-ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[1].armUpR = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[1].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[1].armUpL = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[1].armDownL = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[1].legUpR = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[1].legDownR = D3DXVECTOR3(ONEANGLE * 60, 0.0f, 0.0f);
			m_motion[1].legUpL = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[1].legDownL = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[1].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].footL = D3DXVECTOR3(-ONEANGLE * 35, 0.0f, 0.0f);
		}
	}
};

//ïöÇπÉKÅ[Éh
class MotionGuardDown : public Motion {
private:
public:
	void Init() override {
		m_num = 2;

		//ç≈èâÇ∆ç≈å„ÇÃäpìxÇÕìØÇ∂ílÇ…Ç∑ÇÈ
		{
			m_motion[0].fcnt = 0.0f;
			m_motion[0].stomachPos = D3DXVECTOR3(0.0f, -0.5f, 0.0f);
			m_motion[0].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].neck = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[0].chest = D3DXVECTOR3(ONEANGLE * 55, 0.0f, 0.0f);
			m_motion[0].waist = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].armUpR = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[0].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[0].armUpL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[0].armDownL = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[0].legUpR = D3DXVECTOR3(-ONEANGLE * 60, 0.0f, 0.0f);
			m_motion[0].legDownR = D3DXVECTOR3(ONEANGLE * 90, 0.0f, 0.0f);
			m_motion[0].legUpL = D3DXVECTOR3(-ONEANGLE * 5, 0.0f, 0.0f);
			m_motion[0].legDownL = D3DXVECTOR3(ONEANGLE * 110, 0.0f, 0.0f);
			m_motion[0].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].footL = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
		}

		{
			m_motion[1].fcnt = 25.0f;
			m_motion[1].stomachPos = D3DXVECTOR3(0.0f, -0.5f, 0.0f);
			m_motion[1].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].neck = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[1].chest = D3DXVECTOR3(ONEANGLE * 55, 0.0f, 0.0f);
			m_motion[1].waist = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[1].armUpR = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[1].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[1].armUpL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[1].armDownL = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[1].legUpR = D3DXVECTOR3(-ONEANGLE * 60, 0.0f, 0.0f);
			m_motion[1].legDownR = D3DXVECTOR3(ONEANGLE * 90, 0.0f, 0.0f);
			m_motion[1].legUpL = D3DXVECTOR3(-ONEANGLE * 5, 0.0f, 0.0f);
			m_motion[1].legDownL = D3DXVECTOR3(ONEANGLE * 110, 0.0f, 0.0f);
			m_motion[1].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].footL = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
		}
	}
};

//ÇÑÇÅÇçÇÅÇáÇÖ
class MotionDamage : public Motion {
private:
public:
	void Init() override {
		m_wait = true;
		m_num = 2;

		//ç≈èâÇ∆ç≈å„ÇÃäpìxÇÕìØÇ∂ílÇ…Ç∑ÇÈ
		{
			m_motion[0].fcnt = 0.0f;
			m_motion[0].stomachPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].chest = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[0].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[0].armDownL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[0].legUpR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[0].legDownR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[0].legUpL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[0].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[0].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}

		{
			m_motion[1].fcnt = 25.0f;
			m_motion[1].stomachPos = D3DXVECTOR3(-0.0f, 0.0f, 0.0f);
			m_motion[1].head = D3DXVECTOR3(0.0f, ONEANGLE * 20, 0.0f);
			m_motion[1].neck = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[1].chest = D3DXVECTOR3(-ONEANGLE * 5, 0.0f, 0.0f);
			m_motion[1].waist = D3DXVECTOR3(ONEANGLE * 5, 0.0f, 0.0f);
			m_motion[1].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[1].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[1].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[1].armDownL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[1].legUpR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[1].legDownR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[1].legUpL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[1].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[1].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}
	}
};


//êÅÇ´îÚÇ‘
class MotionBurst : public Motion {
private:
public:
	void Init() override {
		m_wait = true;
		m_num = 4;

		//ç≈èâÇ∆ç≈å„ÇÃäpìxÇÕìØÇ∂ílÇ…Ç∑ÇÈ
		{
			m_motion[0].fcnt = 0.0f;
			m_motion[0].stomachPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].chest = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[0].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[0].armDownL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[0].legUpR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[0].legDownR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[0].legUpL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[0].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[0].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}

		{
			m_motion[1].fcnt = 5.0f;
			m_motion[1].stomachPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].chest = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[1].waist = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[1].armUpR = D3DXVECTOR3(-ONEANGLE * 70, 0.0f, 0.0f);
			m_motion[1].armDownR = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[1].armUpL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[1].armDownL = D3DXVECTOR3(-ONEANGLE * 90, 0.0f, 0.0f);
			m_motion[1].legUpR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[1].legDownR = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[1].legUpL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[1].legDownL = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}

		{
			m_motion[2].fcnt = 10.0f;
			m_motion[2].stomachPos = D3DXVECTOR3(0.0f, -0.25f, 0.0f);
			m_motion[2].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].chest = D3DXVECTOR3(-ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[2].waist = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[2].armUpR = D3DXVECTOR3(-ONEANGLE * 70, 0.0f, 0.0f);
			m_motion[2].armDownR = D3DXVECTOR3(-ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[2].armUpL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[2].armDownL = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[2].legUpR = D3DXVECTOR3(-ONEANGLE * 70, 0.0f, 0.0f);
			m_motion[2].legDownR = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[2].legUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[2].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[2].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}
	}
};


//xÇ€ÇìÇ¢Ç∂ÇÈÇ©Ç«Ç§Ç©
//ì|ÇÍÇÈ
class MotionOver : public Motion {
private:
public:
	void Init() override {
		m_stop = true;
		m_num = 2;

		////ç≈èâÇ∆ç≈å„ÇÃäpìxÇÕìØÇ∂ílÇ…Ç∑ÇÈ
		{
			m_motion[0].fcnt = 0.0f;
			m_motion[0].stomachPos = D3DXVECTOR3(0.0f, -0.25f, 0.0f);
			m_motion[0].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].chest = D3DXVECTOR3(-ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[0].waist = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[0].armUpR = D3DXVECTOR3(-ONEANGLE * 70, 0.0f, 0.0f);
			m_motion[0].armDownR = D3DXVECTOR3(-ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[0].armUpL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[0].armDownL = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].legUpR = D3DXVECTOR3(-ONEANGLE * 70, 0.0f, 0.0f);
			m_motion[0].legDownR = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[0].legUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[0].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[0].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}

		{
			m_motion[1].fcnt = 10.0f;
			m_motion[1].stomachPos = D3DXVECTOR3(0.0f, -1.8f, 0.0f);
			m_motion[1].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].chest = D3DXVECTOR3(-ONEANGLE * 90, 0.0f, 0.0f);
			m_motion[1].waist = D3DXVECTOR3(-ONEANGLE * 90, 0.0f, 0.0f);
			m_motion[1].armUpR = D3DXVECTOR3(0.0f, 0.0f, ONEANGLE * 45);
			m_motion[1].armDownR = D3DXVECTOR3(0.0f, 0.0f, -ONEANGLE * 45);
			m_motion[1].armUpL = D3DXVECTOR3(0.0f, 0.0f, -ONEANGLE * 45);
			m_motion[1].armDownL = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].legUpR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].legDownR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].legUpL = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[1].legDownL = D3DXVECTOR3(ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[1].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].footL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
		}
	}
};

//ãNÇ´ÇÈ
class MotionOverUp : public Motion {
private:
public:
	void Init() override {
		m_num = 4;
		m_wait = true;

		//ç≈èâÇ∆ç≈å„ÇÃäpìxÇÕìØÇ∂ílÇ…Ç∑ÇÈ
		{
			m_motion[0].fcnt = 0.0f;
			m_motion[0].stomachPos = D3DXVECTOR3(0.0f, -1.8f, 0.0f);
			m_motion[0].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].chest = D3DXVECTOR3(-ONEANGLE * 90, 0.0f, 0.0f);
			m_motion[0].waist = D3DXVECTOR3(-ONEANGLE * 90, 0.0f, 0.0f);
			m_motion[0].armUpR = D3DXVECTOR3(0.0f, 0.0f, ONEANGLE * 45);
			m_motion[0].armDownR = D3DXVECTOR3(0.0f, 0.0f, -ONEANGLE * 45);
			m_motion[0].armUpL = D3DXVECTOR3(0.0f, 0.0f, -ONEANGLE * 45);
			m_motion[0].armDownL = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].legUpR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].legDownR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].legUpL = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[0].legDownL = D3DXVECTOR3(ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[0].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].footL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
		}

		{
			m_motion[1].fcnt = 20.0f;
			m_motion[1].stomachPos = D3DXVECTOR3(0.0f, -1.5f, 0.0f);
			m_motion[1].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].chest = D3DXVECTOR3(-ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[1].waist = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[1].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, ONEANGLE * 15);
			m_motion[1].armDownR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, -ONEANGLE * 20);
			m_motion[1].armUpL = D3DXVECTOR3(0.0f, 0.0f, -ONEANGLE * 30);
			m_motion[1].armDownL = D3DXVECTOR3(0.0f, 0.0f, ONEANGLE * 45);
			m_motion[1].legUpR = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[1].legDownR = D3DXVECTOR3(ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[1].legUpL = D3DXVECTOR3(-ONEANGLE * 70, 0.0f, 0.0f);
			m_motion[1].legDownL = D3DXVECTOR3(ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[1].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].footL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
		}

		{
			m_motion[2].fcnt = 40.0f;
			m_motion[2].stomachPos = D3DXVECTOR3(0.0f, -0.8f, 0.0f);
			m_motion[2].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].chest = D3DXVECTOR3(ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[2].waist = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[2].armUpR = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[2].armDownR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[2].armUpL = D3DXVECTOR3(0.0f, 0.0f, -ONEANGLE * 30);
			m_motion[2].armDownL = D3DXVECTOR3(0.0f, 0.0f, ONEANGLE * 45);
			m_motion[2].legUpR = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[2].legDownR = D3DXVECTOR3(ONEANGLE * 140, 0.0f, 0.0f);
			m_motion[2].legUpL = D3DXVECTOR3(-ONEANGLE * 70, 0.0f, 0.0f);
			m_motion[2].legDownL = D3DXVECTOR3(ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[2].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].footL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
		}

		{
			m_motion[3].fcnt = 50.0f;
			m_motion[3].stomachPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].chest = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[3].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[3].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[3].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[3].armDownL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[3].legUpR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[3].legDownR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[3].legUpL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[3].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[3].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}
	}
};

//íÕÇﬁ
class MotionHold : public Motion {
private:
public:
	void Init() override {
		m_num = 4;
		m_stop = true;
		m_wait = true;

		//ç≈èâÇ∆ç≈å„ÇÃäpìxÇÕìØÇ∂ílÇ…Ç∑ÇÈ
		{
			m_motion[0].fcnt = 0.0f;
			m_motion[0].stomachPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].chest = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[0].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[0].armDownL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[0].legUpR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[0].legDownR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[0].legUpL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[0].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[0].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}

		{
			m_motion[1].fcnt = 30.0f;
			m_motion[1].stomachPos = D3DXVECTOR3(0.0f, -0.1f, 0.25f);
			m_motion[1].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].chest = D3DXVECTOR3(ONEANGLE * 25, 0.0f, 0.0f);
			m_motion[1].waist = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[1].armUpR = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, ONEANGLE * 20);
			m_motion[1].armDownR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[1].armUpL = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, -ONEANGLE * 20);
			m_motion[1].armDownL = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[1].legUpR = D3DXVECTOR3(-ONEANGLE * 60, 0.0f, 0.0f);
			m_motion[1].legDownR = D3DXVECTOR3(ONEANGLE * 60, 0.0f, 0.0f);
			m_motion[1].legUpL = D3DXVECTOR3(ONEANGLE * 5, 0.0f, 0.0f);
			m_motion[1].legDownL = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[1].footR = D3DXVECTOR3(-ONEANGLE * 5, 0.0f, 0.0f);
			m_motion[1].footL = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
		}

		{
			m_motion[2].fcnt = 40.0f;
			m_motion[2].stomachPos = D3DXVECTOR3(0.0f, -0.1f, 0.4f);
			m_motion[2].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].chest = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[2].waist = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[2].armUpR = D3DXVECTOR3(-ONEANGLE * 40, -ONEANGLE * 60, ONEANGLE * 30);
			m_motion[2].armDownR = D3DXVECTOR3(-ONEANGLE * 70, 0.0f, 0.0f);
			m_motion[2].armUpL = D3DXVECTOR3(-ONEANGLE * 30, ONEANGLE * 60, -ONEANGLE * 30);
			m_motion[2].armDownL = D3DXVECTOR3(-ONEANGLE * 70, 0.0f, 0.0f);
			m_motion[2].legUpR = D3DXVECTOR3(-ONEANGLE * 70, 0.0f, 0.0f);
			m_motion[2].legDownR = D3DXVECTOR3(ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[2].legUpL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[2].legDownL = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[2].footR = D3DXVECTOR3(-ONEANGLE * 5, 0.0f, 0.0f);
			m_motion[2].footL = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
		}


		{
			m_motion[3].fcnt = 50.0f;
			m_motion[3].stomachPos = D3DXVECTOR3(0.0f, -0.1f, 0.4f);
			m_motion[3].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].chest = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[3].waist = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[3].armUpR = D3DXVECTOR3(-ONEANGLE * 40, -ONEANGLE * 60, ONEANGLE * 30);
			m_motion[3].armDownR = D3DXVECTOR3(-ONEANGLE * 70, 0.0f, 0.0f);
			m_motion[3].armUpL = D3DXVECTOR3(-ONEANGLE * 30, ONEANGLE * 60, -ONEANGLE * 30);
			m_motion[3].armDownL = D3DXVECTOR3(-ONEANGLE * 70, 0.0f, 0.0f);
			m_motion[3].legUpR = D3DXVECTOR3(-ONEANGLE * 70, 0.0f, 0.0f);
			m_motion[3].legDownR = D3DXVECTOR3(ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[3].legUpL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[3].legDownL = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[3].footR = D3DXVECTOR3(-ONEANGLE * 5, 0.0f, 0.0f);
			m_motion[3].footL = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
		}
	}
};

//íÕÇﬁÉ~ÉX
class MotionHoldMiss : public Motion {
private:
public:
	void Init() override {
		m_num = 4;
		m_wait = true;

		{
			m_motion[0].fcnt = 0.0f;
			m_motion[0].stomachPos = D3DXVECTOR3(0.0f, -0.1f, 0.4f);
			m_motion[0].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].chest = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[0].waist = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].armUpR = D3DXVECTOR3(-ONEANGLE * 40, -ONEANGLE * 60, ONEANGLE * 30);
			m_motion[0].armDownR = D3DXVECTOR3(-ONEANGLE * 70, 0.0f, 0.0f);
			m_motion[0].armUpL = D3DXVECTOR3(-ONEANGLE * 30, ONEANGLE * 60, -ONEANGLE * 30);
			m_motion[0].armDownL = D3DXVECTOR3(-ONEANGLE * 70, 0.0f, 0.0f);
			m_motion[0].legUpR = D3DXVECTOR3(-ONEANGLE * 70, 0.0f, 0.0f);
			m_motion[0].legDownR = D3DXVECTOR3(ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[0].legUpL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[0].legDownL = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].footR = D3DXVECTOR3(-ONEANGLE * 5, 0.0f, 0.0f);
			m_motion[0].footL = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
		}

		{
			m_motion[1].fcnt = 20.0f;
			m_motion[1].stomachPos = D3DXVECTOR3(0.0f, -0.4f, 0.7f);
			m_motion[1].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].neck = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[1].chest = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[1].waist = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[1].armUpR = D3DXVECTOR3(-ONEANGLE * 40, -ONEANGLE * 80, ONEANGLE * 30);
			m_motion[1].armDownR = D3DXVECTOR3(-ONEANGLE * 90, 0.0f, 0.0f);
			m_motion[1].armUpL = D3DXVECTOR3(-ONEANGLE * 30, ONEANGLE * 80, -ONEANGLE * 30);
			m_motion[1].armDownL = D3DXVECTOR3(-ONEANGLE * 90, 0.0f, 0.0f);
			m_motion[1].legUpR = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[1].legDownR = D3DXVECTOR3(ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[1].legUpL = D3DXVECTOR3(-ONEANGLE * 5, 0.0f, 0.0f);
			m_motion[1].legDownL = D3DXVECTOR3(ONEANGLE * 45, 0.0f, 0.0f);
			m_motion[1].footR = D3DXVECTOR3(-ONEANGLE * 35, 0.0f, 0.0f);
			m_motion[1].footL = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
		}


		{
			m_motion[2].fcnt = 40.0f;
			m_motion[2].stomachPos = D3DXVECTOR3(0.0f, -0.1f, 0.4f);
			m_motion[2].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].neck = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[2].chest = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[2].waist = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[2].armUpR = D3DXVECTOR3(-ONEANGLE * 40, -ONEANGLE * 80, ONEANGLE * 30);
			m_motion[2].armDownR = D3DXVECTOR3(-ONEANGLE * 90, 0.0f, 0.0f);
			m_motion[2].armUpL = D3DXVECTOR3(-ONEANGLE * 30, ONEANGLE * 80, -ONEANGLE * 30);
			m_motion[2].armDownL = D3DXVECTOR3(-ONEANGLE * 90, 0.0f, 0.0f);
			m_motion[2].legUpR = D3DXVECTOR3(-ONEANGLE * 70, 0.0f, 0.0f);
			m_motion[2].legDownR = D3DXVECTOR3(ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[2].legUpL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[2].legDownL = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[2].footR = D3DXVECTOR3(-ONEANGLE * 5, 0.0f, 0.0f);
			m_motion[2].footL = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
		}


		{
			m_motion[3].fcnt = 60.0f;
			m_motion[3].stomachPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].chest = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[3].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[3].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[3].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[3].armDownL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[3].legUpR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[3].legDownR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[3].legUpL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[3].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[3].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}
	}
};

//ìäÇ∞çUåÇ

class MotionThrow : public Motion {
private:
public:
	void Init() override {
		m_num = 5;
		m_wait = true;

		{
			m_motion[0].fcnt = 0.0f;
			m_motion[0].stomachPos = D3DXVECTOR3(0.0f, -0.1f, 0.4f);
			m_motion[0].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].chest = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[0].waist = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].armUpR = D3DXVECTOR3(-ONEANGLE * 40, -ONEANGLE * 60, ONEANGLE * 30);
			m_motion[0].armDownR = D3DXVECTOR3(-ONEANGLE * 70, 0.0f, 0.0f);
			m_motion[0].armUpL = D3DXVECTOR3(-ONEANGLE * 30, ONEANGLE * 60, -ONEANGLE * 30);
			m_motion[0].armDownL = D3DXVECTOR3(-ONEANGLE * 70, 0.0f, 0.0f);
			m_motion[0].legUpR = D3DXVECTOR3(-ONEANGLE * 70, 0.0f, 0.0f);
			m_motion[0].legDownR = D3DXVECTOR3(ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[0].legUpL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[0].legDownL = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].footR = D3DXVECTOR3(-ONEANGLE * 5, 0.0f, 0.0f);
			m_motion[0].footL = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
		}


		{
			m_motion[1].fcnt = 30.0f;
			m_motion[1].stomachPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].chest = D3DXVECTOR3(ONEANGLE * 5, 0.0f, 0.0f);
			m_motion[1].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].armUpR = D3DXVECTOR3(-ONEANGLE * 130, 0.0f, 0.0f);
			m_motion[1].armDownR = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[1].armUpL = D3DXVECTOR3(-ONEANGLE * 130, 0.0f, 0.0f);
			m_motion[1].armDownL = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[1].legUpR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[1].legDownR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[1].legUpL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[1].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[1].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}

		{
			m_motion[2].fcnt = 45.0f;
			m_motion[2].stomachPos = D3DXVECTOR3(0.0f, -0.2f, 0.2f);
			m_motion[2].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].chest = D3DXVECTOR3(ONEANGLE * 5, 0.0f, 0.0f);
			m_motion[2].waist = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[2].armUpR = D3DXVECTOR3(-ONEANGLE * 130, 0.0f, 0.0f);
			m_motion[2].armDownR = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[2].armUpL = D3DXVECTOR3(-ONEANGLE * 130, 0.0f, 0.0f);
			m_motion[2].armDownL = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[2].legUpR = D3DXVECTOR3(-ONEANGLE * 70, 0.0f, 0.0f);
			m_motion[2].legDownR = D3DXVECTOR3(ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[2].legUpL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[2].legDownL = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[2].footR = D3DXVECTOR3(-ONEANGLE * 5, 0.0f, 0.0f);
			m_motion[2].footL = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
		}


		{
			m_motion[3].fcnt = 60.0f;
			m_motion[3].stomachPos = D3DXVECTOR3(0.0f, -0.4f, 0.7f);
			m_motion[3].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].neck = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[3].chest = D3DXVECTOR3(ONEANGLE * 60, 0.0f, 0.0f);
			m_motion[3].waist = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[3].armUpR = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[3].armDownR = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[3].armUpL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[3].armDownL = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[3].legUpR = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[3].legDownR = D3DXVECTOR3(ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[3].legUpL = D3DXVECTOR3(-ONEANGLE * 5, 0.0f, 0.0f);
			m_motion[3].legDownL = D3DXVECTOR3(ONEANGLE * 45, 0.0f, 0.0f);
			m_motion[3].footR = D3DXVECTOR3(-ONEANGLE * 35, 0.0f, 0.0f);
			m_motion[3].footL = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
		}

		{
			m_motion[4].fcnt = 80.0f;
			m_motion[4].stomachPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[4].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[4].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[4].chest = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[4].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[4].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[4].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[4].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[4].armDownL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[4].legUpR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[4].legDownR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[4].legUpL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[4].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[4].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[4].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}
	}
};


//çUåÇÉpÉìÉ`A
class MotionAttackPA : public Motion {
private:
public:
	void Init() override {
		m_wait = true;
		m_num = 4;

		//ç≈èâÇ∆ç≈å„ÇÃäpìxÇÕìØÇ∂ílÇ…Ç∑ÇÈ
		{
			m_motion[0].fcnt = 0.0f;
			m_motion[0].stomachPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].chest = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[0].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[0].armDownL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[0].legUpR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[0].legDownR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[0].legUpL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[0].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[0].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}

		{
			m_motion[1].fcnt = 3.0f;
			m_motion[1].stomachPos = D3DXVECTOR3(0.0f, -0.1f, 0.25f);
			m_motion[1].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].chest = D3DXVECTOR3(ONEANGLE * 10, -ONEANGLE * 20, 0.0f);
			m_motion[1].waist = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[1].armUpR = D3DXVECTOR3(-ONEANGLE * 90, 0.0f, 0.0f);
			m_motion[1].armDownR = D3DXVECTOR3(-ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[1].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[1].armDownL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[1].legUpR = D3DXVECTOR3(-ONEANGLE * 45, 0.0f, 0.0f);
			m_motion[1].legDownR = D3DXVECTOR3(ONEANGLE * 60, 0.0f, 0.0f);
			m_motion[1].legUpL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[1].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[1].footR = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[1].footL = D3DXVECTOR3(-ONEANGLE * 25, 0.0f, 0.0f);
		}


		{
			m_motion[2].fcnt = 10.0f;
			m_motion[2].stomachPos = D3DXVECTOR3(0.0f, -0.1f, 0.25f);
			m_motion[2].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].chest = D3DXVECTOR3(ONEANGLE * 10, -ONEANGLE * 20, 0.0f);
			m_motion[2].waist = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[2].armUpR = D3DXVECTOR3(-ONEANGLE * 90, 0.0f, 0.0f);
			m_motion[2].armDownR = D3DXVECTOR3(-ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[2].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[2].armDownL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[2].legUpR = D3DXVECTOR3(-ONEANGLE * 45, 0.0f, 0.0f);
			m_motion[2].legDownR = D3DXVECTOR3(ONEANGLE * 60, 0.0f, 0.0f);
			m_motion[2].legUpL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[2].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[2].footR = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[2].footL = D3DXVECTOR3(-ONEANGLE * 25, 0.0f, 0.0f);
		}

		{
			m_motion[3].fcnt = 15.0f;
			m_motion[3].stomachPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].chest = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[3].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[3].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[3].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[3].armDownL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[3].legUpR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[3].legDownR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[3].legUpL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[3].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[3].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}

	}
};

//çUåÇÉpÉìÉ`B
class MotionAttackPB : public Motion {
private:
public:

	void Init() override {
		m_wait = true;
		m_num = 6;

		//ç≈èâÇ∆ç≈å„ÇÃäpìxÇÕìØÇ∂ílÇ…Ç∑ÇÈ
		{
			m_motion[0].fcnt = 0.0f;
			m_motion[0].stomachPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].chest = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[0].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[0].armDownL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[0].legUpR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[0].legDownR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[0].legUpL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[0].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[0].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}

		{
			m_motion[1].fcnt = 5.0f;
			m_motion[1].stomachPos = D3DXVECTOR3(0.0f, -0.1f, 0.5f);
			m_motion[1].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].chest = D3DXVECTOR3(ONEANGLE * 5, ONEANGLE * 40, 0.0f);
			m_motion[1].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[1].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[1].armUpL = D3DXVECTOR3(0.0f, 0.0f, -ONEANGLE * 60);
			m_motion[1].armDownL = D3DXVECTOR3(-ONEANGLE * 60, 0.0f, 0.0f);
			m_motion[1].legUpR = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[1].legDownR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[1].legUpL = D3DXVECTOR3(ONEANGLE * 25, 0.0f, 0.0f);
			m_motion[1].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[1].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}


		{
			m_motion[2].fcnt = 10.0f;
			m_motion[2].stomachPos = D3DXVECTOR3(0.0f, -0.1f, 0.75f);
			m_motion[2].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].chest = D3DXVECTOR3(ONEANGLE * 25, ONEANGLE * 80, 0.0f);
			m_motion[2].waist = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[2].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[2].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[2].armUpL = D3DXVECTOR3(0.0f, ONEANGLE * 60, -ONEANGLE * 80);
			m_motion[2].armDownL = D3DXVECTOR3(-ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[2].legUpR = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[2].legDownR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[2].legUpL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[2].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[2].footR = D3DXVECTOR3(-ONEANGLE * 5, 0.0f, 0.0f);
			m_motion[2].footL = D3DXVECTOR3(-ONEANGLE * 10, 0.0f, 0.0f);
		}


		{
			m_motion[3].fcnt = 20.0f;
			m_motion[3].stomachPos = D3DXVECTOR3(0.0f, -0.1f, 0.75f);
			m_motion[3].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].chest = D3DXVECTOR3(ONEANGLE * 25, ONEANGLE * 80, 0.0f);
			m_motion[3].waist = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[3].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[3].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[3].armUpL = D3DXVECTOR3(0.0f, ONEANGLE * 60, -ONEANGLE * 80);
			m_motion[3].armDownL = D3DXVECTOR3(-ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[3].legUpR = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[3].legDownR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[3].legUpL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[3].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[3].footR = D3DXVECTOR3(-ONEANGLE * 5, 0.0f, 0.0f);
			m_motion[3].footL = D3DXVECTOR3(-ONEANGLE * 10, 0.0f, 0.0f);
		}


		{
			m_motion[4].fcnt = 25.0f;
			m_motion[4].stomachPos = D3DXVECTOR3(0.0f, -0.1f, 0.5f);
			m_motion[4].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[4].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[4].chest = D3DXVECTOR3(ONEANGLE * 5, ONEANGLE * 40, 0.0f);
			m_motion[4].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[4].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[4].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[4].armUpL = D3DXVECTOR3(0.0f, 0.0f, -ONEANGLE * 60);
			m_motion[4].armDownL = D3DXVECTOR3(-ONEANGLE * 60, 0.0f, 0.0f);
			m_motion[4].legUpR = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[4].legDownR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[4].legUpL = D3DXVECTOR3(ONEANGLE * 25, 0.0f, 0.0f);
			m_motion[4].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[4].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[4].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}

		{
			m_motion[5].fcnt = 35.0f;
			m_motion[5].stomachPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[5].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[5].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[5].chest = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[5].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[5].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[5].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[5].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[5].armDownL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[5].legUpR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[5].legDownR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[5].legUpL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[5].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[5].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[5].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}
	}
};


//çUåÇÉLÉbÉNÇa
class MotionAttackKB : public Motion {
private:
public:

	void Init() override {
		m_num = 5;
		m_wait = true;

		//ç≈èâÇ∆ç≈å„ÇÃäpìxÇÕìØÇ∂ílÇ…Ç∑ÇÈ
		{
			m_motion[0].fcnt = 0.0f;
			m_motion[0].stomachPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].chest = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[0].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[0].armDownL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[0].legUpR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[0].legDownR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[0].legUpL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[0].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[0].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}

		{
			m_motion[1].fcnt = 20.0f;
			m_motion[1].stomachPos = D3DXVECTOR3(0.0f, -0.1f, 0.1f);
			m_motion[1].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].chest = D3DXVECTOR3(ONEANGLE * 20, -ONEANGLE * 50, 0.0f);
			m_motion[1].waist = D3DXVECTOR3(ONEANGLE * 10, ONEANGLE * 20, 0.0f);
			m_motion[1].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[1].armDownR = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[1].armUpL = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[1].armDownL = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[1].legUpR = D3DXVECTOR3(-ONEANGLE * 40, -ONEANGLE * 10, 0.0f);
			m_motion[1].legDownR = D3DXVECTOR3(ONEANGLE * 55, 0.0f, 0.0f);
			m_motion[1].legUpL = D3DXVECTOR3(ONEANGLE * 30, 0.0f, ONEANGLE * 20);
			m_motion[1].legDownL = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[1].footR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[1].footL = D3DXVECTOR3(ONEANGLE * 25, 0.0f, 0.0f);
		}

		{
			m_motion[2].fcnt = 30.0f;
			m_motion[2].stomachPos = D3DXVECTOR3(0.0f, 0.1f, 0.2f);
			m_motion[2].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].chest = D3DXVECTOR3(-ONEANGLE * 10, -ONEANGLE * 30, 0.0f);
			m_motion[2].waist = D3DXVECTOR3(-ONEANGLE * 20, -ONEANGLE * 20, 0.0f);
			m_motion[2].armUpR = D3DXVECTOR3(-ONEANGLE * 30, -ONEANGLE * 20, 0.0f);
			m_motion[2].armDownR = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[2].armUpL = D3DXVECTOR3(ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[2].armDownL = D3DXVECTOR3(-ONEANGLE * 130, 0.0f, 0.0f);
			m_motion[2].legUpR = D3DXVECTOR3(ONEANGLE * 10, -ONEANGLE * 10, 0.0f);
			m_motion[2].legDownR = D3DXVECTOR3(ONEANGLE * 25, 0.0f, 0.0f);
			m_motion[2].legUpL = D3DXVECTOR3(-ONEANGLE * 90, 0.0f, ONEANGLE * 20);
			m_motion[2].legDownL = D3DXVECTOR3(ONEANGLE * 0, 0.0f, 0.0f);
			m_motion[2].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].footL = D3DXVECTOR3(ONEANGLE * 75, 0.0f, 0.0f);
		}

		{
			m_motion[3].fcnt = 40.0f;
			m_motion[3].stomachPos = D3DXVECTOR3(0.0f, 0.1f, 0.2f);
			m_motion[3].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].chest = D3DXVECTOR3(-ONEANGLE * 10, -ONEANGLE * 30, 0.0f);
			m_motion[3].waist = D3DXVECTOR3(-ONEANGLE * 20, -ONEANGLE * 20, 0.0f);
			m_motion[3].armUpR = D3DXVECTOR3(-ONEANGLE * 30, -ONEANGLE * 20, 0.0f);
			m_motion[3].armDownR = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[3].armUpL = D3DXVECTOR3(ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[3].armDownL = D3DXVECTOR3(-ONEANGLE * 130, 0.0f, 0.0f);
			m_motion[3].legUpR = D3DXVECTOR3(ONEANGLE * 10, -ONEANGLE * 10, 0.0f);
			m_motion[3].legDownR = D3DXVECTOR3(ONEANGLE * 25, 0.0f, 0.0f);
			m_motion[3].legUpL = D3DXVECTOR3(-ONEANGLE * 90, 0.0f, ONEANGLE * 20);
			m_motion[3].legDownL = D3DXVECTOR3(ONEANGLE * 0, 0.0f, 0.0f);
			m_motion[3].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].footL = D3DXVECTOR3(ONEANGLE * 75, 0.0f, 0.0f);
		}

		{
			m_motion[4].fcnt = 70.0f;
			m_motion[4].stomachPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[4].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[4].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[4].chest = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[4].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[4].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[4].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[4].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[4].armDownL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[4].legUpR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[4].legDownR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[4].legUpL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[4].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[4].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[4].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}
	}
};



class MotionDownAttack : public Motion {
private:
public:
	void Init() override {
		m_wait = true;

		m_num = 3;

		//ç≈èâÇ∆ç≈å„ÇÃäpìxÇÕìØÇ∂ílÇ…Ç∑ÇÈ
		{
			m_motion[0].fcnt = 0.0f;
			m_motion[0].stomachPos = D3DXVECTOR3(0.0f, -1.0f, 0.0f);
			m_motion[0].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].neck = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[0].chest = D3DXVECTOR3(ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[0].waist = D3DXVECTOR3(ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[0].armUpR = D3DXVECTOR3(-ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[0].armDownR = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[0].armUpL = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[0].armDownL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[0].legUpR = D3DXVECTOR3(-ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[0].legDownR = D3DXVECTOR3(ONEANGLE * 105, 0.0f, 0.0f);
			m_motion[0].legUpL = D3DXVECTOR3(-ONEANGLE * 90, 0.0f, 0.0f);
			m_motion[0].legDownL = D3DXVECTOR3(ONEANGLE * 105, 0.0f, 0.0f);
			m_motion[0].footR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[0].footL = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
		}

		{
			m_motion[1].fcnt = 15.0f;
			m_motion[1].stomachPos = D3DXVECTOR3(0.0f, -0.8f, 0.1f);
			m_motion[1].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].neck = D3DXVECTOR3(-ONEANGLE * 25, 0.0f, 0.0f);
			m_motion[1].chest = D3DXVECTOR3(ONEANGLE * 25, 0.0f, 0.0f);
			m_motion[1].waist = D3DXVECTOR3(ONEANGLE * 60, 0.0f, 0.0f);
			m_motion[1].armUpR = D3DXVECTOR3(-ONEANGLE * 135, 0.0f, 0.0f);
			m_motion[1].armDownR = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[1].armUpL = D3DXVECTOR3(-ONEANGLE * 130, 0.0f, 0.0f);
			m_motion[1].armDownL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[1].legUpR = D3DXVECTOR3(-ONEANGLE * 55, 0.0f, 0.0f);
			m_motion[1].legDownR = D3DXVECTOR3(ONEANGLE * 105, 0.0f, 0.0f);
			m_motion[1].legUpL = D3DXVECTOR3(-ONEANGLE * 60, 0.0f, 0.0f);
			m_motion[1].legDownL = D3DXVECTOR3(ONEANGLE * 105, 0.0f, 0.0f);
			m_motion[1].footR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[1].footL = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
		}

		{
			m_motion[2].fcnt = 35.0f;
			m_motion[2].stomachPos = D3DXVECTOR3(0.0f, -1.0f, 0.0f);
			m_motion[2].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].neck = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[2].chest = D3DXVECTOR3(ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[2].waist = D3DXVECTOR3(ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[2].armUpR = D3DXVECTOR3(-ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[2].armDownR = D3DXVECTOR3(-ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[2].armUpL = D3DXVECTOR3(-ONEANGLE * 80, 0.0f, 0.0f);
			m_motion[2].armDownL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[2].legUpR = D3DXVECTOR3(-ONEANGLE * 85, 0.0f, 0.0f);
			m_motion[2].legDownR = D3DXVECTOR3(ONEANGLE * 105, 0.0f, 0.0f);
			m_motion[2].legUpL = D3DXVECTOR3(-ONEANGLE * 90, 0.0f, 0.0f);
			m_motion[2].legDownL = D3DXVECTOR3(ONEANGLE * 105, 0.0f, 0.0f);
			m_motion[2].footR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[2].footL = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
		}
	}
};


class MotionAttackShot: public Motion {
private:
public:
	void Init() override {
		m_num = 5;
		m_wait = true;

		//ç≈èâÇ∆ç≈å„ÇÃäpìxÇÕìØÇ∂ílÇ…Ç∑ÇÈ
		{
			m_motion[0].fcnt = 0.0f;
			m_motion[0].stomachPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].chest = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[0].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[0].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[0].armDownL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[0].legUpR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[0].legDownR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[0].legUpL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[0].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[0].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[0].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}

		{
			m_motion[1].fcnt = 20.0f;
			m_motion[1].stomachPos = D3DXVECTOR3(0.0f, 00.0f, -0.15f);
			m_motion[1].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].chest = D3DXVECTOR3(-ONEANGLE * 5, 0.0f, 0.0f);
			m_motion[1].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[1].armUpR = D3DXVECTOR3(-ONEANGLE * 180, 0.0f, -ONEANGLE * 15);
			m_motion[1].armDownR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[1].armUpL = D3DXVECTOR3(-ONEANGLE * 180, 0.0f, ONEANGLE * 15);
			m_motion[1].armDownL = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[1].legUpR = D3DXVECTOR3(-ONEANGLE * 5, 0.0f, -ONEANGLE * 15);
			m_motion[1].legDownR = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[1].legUpL = D3DXVECTOR3(-ONEANGLE * 5, 0.0f, ONEANGLE * 15);
			m_motion[1].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[1].footR = D3DXVECTOR3(-ONEANGLE * 0, 0.0f, 0.0f);
			m_motion[1].footL = D3DXVECTOR3(-ONEANGLE * 0, 0.0f, 0.0f);
		}

		{
			m_motion[2].fcnt = 25.0f;
			m_motion[2].stomachPos = D3DXVECTOR3(0.0f, 00.0f, -0.15f);
			m_motion[2].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].chest = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[2].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[2].armUpR = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, -ONEANGLE * 15);
			m_motion[2].armDownR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[2].armUpL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, ONEANGLE * 15);
			m_motion[2].armDownL = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[2].legUpR = D3DXVECTOR3(-ONEANGLE * 5, 0.0f, -ONEANGLE * 15);
			m_motion[2].legDownR = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[2].legUpL = D3DXVECTOR3(-ONEANGLE * 5, 0.0f, ONEANGLE * 15);
			m_motion[2].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[2].footR = D3DXVECTOR3(-ONEANGLE * 0, 0.0f, 0.0f);
			m_motion[2].footL = D3DXVECTOR3(-ONEANGLE * 0, 0.0f, 0.0f);
		}

		{
			m_motion[3].fcnt = 40.0f;
			m_motion[3].stomachPos = D3DXVECTOR3(0.0f, 00.0f, -0.15f);
			m_motion[3].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].chest = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[3].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[3].armUpR = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, -ONEANGLE * 15);
			m_motion[3].armDownR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[3].armUpL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, ONEANGLE * 15);
			m_motion[3].armDownL = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[3].legUpR = D3DXVECTOR3(-ONEANGLE * 5, 0.0f, -ONEANGLE * 15);
			m_motion[3].legDownR = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[3].legUpL = D3DXVECTOR3(-ONEANGLE * 5, 0.0f, ONEANGLE * 15);
			m_motion[3].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[3].footR = D3DXVECTOR3(-ONEANGLE * 0, 0.0f, 0.0f);
			m_motion[3].footL = D3DXVECTOR3(-ONEANGLE * 0, 0.0f, 0.0f);
		}

		{
			m_motion[4].fcnt = 60.0f;
			m_motion[4].stomachPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[4].head = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[4].neck = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[4].chest = D3DXVECTOR3(ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[4].waist = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[4].armUpR = D3DXVECTOR3(-ONEANGLE * 20, 0.0f, 0.0f);
			m_motion[4].armDownR = D3DXVECTOR3(-ONEANGLE * 120, 0.0f, 0.0f);
			m_motion[4].armUpL = D3DXVECTOR3(-ONEANGLE * 50, 0.0f, 0.0f);
			m_motion[4].armDownL = D3DXVECTOR3(-ONEANGLE * 100, 0.0f, 0.0f);
			m_motion[4].legUpR = D3DXVECTOR3(-ONEANGLE * 30, 0.0f, 0.0f);
			m_motion[4].legDownR = D3DXVECTOR3(ONEANGLE * 40, 0.0f, 0.0f);
			m_motion[4].legUpL = D3DXVECTOR3(ONEANGLE * 15, 0.0f, 0.0f);
			m_motion[4].legDownL = D3DXVECTOR3(ONEANGLE * 10, 0.0f, 0.0f);
			m_motion[4].footR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			m_motion[4].footL = D3DXVECTOR3(-ONEANGLE * 15, 0.0f, 0.0f);
		}

	}
};