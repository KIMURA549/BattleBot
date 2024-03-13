#pragma once

class Parameter {
protected:

	float m_hp;
	float m_atk;

	float m_def;

	float m_moveX;
	float m_jumpPowwer;
public:
	virtual void Init() {};
	void SetParameter(float hp, float atk, float def, float x, float jumpPowwer) {
		m_hp = hp;
		m_atk = atk;
		m_def = def;
		m_moveX = x;
		m_jumpPowwer = jumpPowwer;
	}

	int GetHp() { return m_hp; }
	float GetAtk() { return m_atk; }
	float GetDef() { return m_def; }
	float GetMoveX() { return m_moveX; }
	float GetJumpPowwer() { return m_jumpPowwer; }
};