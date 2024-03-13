#pragma once

#include "main.h"
#include "renderer.h"

#define EXPLOSION_NUM	(10)

// バレット構造体
struct EXPLOSION
{
	D3DXMATRIX				mtxWorld;
	bool					use;	// true:使っている  false:未使用
	D3DXVECTOR3				pos;	// バレットの座標
	float					frame;
	int						animIndex;//アニメーションパターン
	int						animWait;//パターン表示ウェイト
};

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
void InitExplosion(void);
void UninitExplosion(void);
void UpdateExplosion(void);
void DrawExplosion(void);

EXPLOSION *GetExplosion();
void SetExplosion(D3DXVECTOR3 pos);

