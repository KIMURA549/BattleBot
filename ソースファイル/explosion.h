#pragma once

#include "main.h"
#include "renderer.h"

#define EXPLOSION_NUM	(10)

// �o���b�g�\����
struct EXPLOSION
{
	D3DXMATRIX				mtxWorld;
	bool					use;	// true:�g���Ă���  false:���g�p
	D3DXVECTOR3				pos;	// �o���b�g�̍��W
	float					frame;
	int						animIndex;//�A�j���[�V�����p�^�[��
	int						animWait;//�p�^�[���\���E�F�C�g
};

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
void InitExplosion(void);
void UninitExplosion(void);
void UpdateExplosion(void);
void DrawExplosion(void);

EXPLOSION *GetExplosion();
void SetExplosion(D3DXVECTOR3 pos);

