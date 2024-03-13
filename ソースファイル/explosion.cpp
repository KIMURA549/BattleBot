#include "explosion.h"
#include"camera.h"
#include "texture.h"
#include"fade.h"

//*****************************************************************************
// グローバル変数
//*****************************************************************************
static ID3D11Buffer		*g_VertexBuffer = NULL;	// 頂点バッファ

static EXPLOSION		g_Explosion;	// 弾データ
static MATERIAL		g_Material;
static int			g_texNo = 0;
static int g_SENoExplosion;
void InitExplosion(void)
{
	// 頂点バッファ生成
	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DYNAMIC;
	bd.ByteWidth = sizeof(VERTEX_3D) * 4;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

	GetDevice()->CreateBuffer(&bd, NULL, &g_VertexBuffer);


	// 頂点バッファに値をセットする
	{
		D3D11_MAPPED_SUBRESOURCE msr;
		GetDeviceContext()->Map(g_VertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);

		VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;

		float width = 300.0f;
		float height = 300.0f;

		// 頂点座標の設定
		vertex[0].Position = D3DXVECTOR3(-width / 2.0f, 0.0f, 0.0f);
		vertex[1].Position = D3DXVECTOR3(-width / 2.0f, height, 0.0f);
		vertex[2].Position = D3DXVECTOR3(width / 2.0f, 0.0f, 0.0f);
		vertex[3].Position = D3DXVECTOR3(width / 2.0f, height, 0.0f);

		// 頂点カラーの設定
		vertex[0].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[1].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[2].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[3].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		// テクスチャ座標の設定
		vertex[0].TexCoord = D3DXVECTOR2(0.0f, 1.0f);
		vertex[1].TexCoord = D3DXVECTOR2(0.0f, 0.0f);
		vertex[2].TexCoord = D3DXVECTOR2(1.0f, 1.0f);
		vertex[3].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

		GetDeviceContext()->Unmap(g_VertexBuffer, 0);
	}

	// テクスチャ生成
	g_texNo = LoadTexture((char*)"data/TEXTURE/explosion000.png");
	g_SENoExplosion = LoadSound((char*)"data/SE/打撃3.wav");
	SetVolume(g_SENoExplosion, 30);
	// マテリアル初期化
	ZeroMemory(&g_Material, sizeof(g_Material));
	g_Material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	// 初期化

	g_Explosion.pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_Explosion.use = false;
}

void UninitExplosion(void)
{
	if (g_VertexBuffer != NULL)
	{// 頂点バッファの解放
		g_VertexBuffer->Release();
		g_VertexBuffer = NULL;
	}
}

void UpdateExplosion(void)
{
	if (g_Explosion.use)
	{
		//消滅処理
		if (g_Explosion.frame > (float)g_Explosion.animWait)
		{
			g_Explosion.animIndex += 1;
			g_Explosion.frame = 0;
			if (g_Explosion.animIndex > 7) {
				//RESULTへ移行する
				SceneTransition(SCENE_RESULT);
				g_Explosion.use = false;
			}
		}

		//時間経過
		g_Explosion.frame += 0.5f;
	}
}

void DrawExplosion(void)
{
	// αテストを有効に
	SetAlphaTestEnable(true);

	// ライティングを無効
	SetLightEnable(false);

	D3DXMATRIX mtxView, mtxScale, mtxTranslate;

	// 頂点バッファ設定
	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	GetDeviceContext()->IASetVertexBuffers(0, 1, &g_VertexBuffer, &stride, &offset);

	// プリミティブトポロジ設定
	GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	if (g_Explosion.use) {
	// ワールドマトリックスの初期化
	D3DXMatrixIdentity(&g_Explosion.mtxWorld);

	CAMERA *cam = GetCamera();

	// ポリゴンを正面に向ける
#if 0
			// ビューマトリックスの逆行列を取得
	g_Bullet[i].mtxWorld = cam->mtxInvView;
	g_Bullet[i].mtxWorld._41 = 0.0f;
	g_Bullet[i].mtxWorld._42 = 0.0f;
	g_Bullet[i].mtxWorld._43 = 0.0f;
#else
			// ビューマトリックスを取得
	D3DXMATRIX mtxView = cam->mtxView;

	g_Explosion.mtxWorld._11 = mtxView._11;
	g_Explosion.mtxWorld._12 = mtxView._21;
	g_Explosion.mtxWorld._13 = mtxView._31;
	g_Explosion.mtxWorld._21 = mtxView._12;
	g_Explosion.mtxWorld._22 = mtxView._22;
	g_Explosion.mtxWorld._23 = mtxView._32;
	g_Explosion.mtxWorld._31 = mtxView._13;
	g_Explosion.mtxWorld._32 = mtxView._23;
	g_Explosion.mtxWorld._33 = mtxView._33;
#endif


	// 移動を反映
	D3DXMatrixTranslation(&mtxTranslate, g_Explosion.pos.x,
		g_Explosion.pos.y,
		g_Explosion.pos.z);
	D3DXMatrixMultiply(&g_Explosion.mtxWorld, &g_Explosion.mtxWorld, &mtxTranslate);

	// ワールドマトリックスの設定
	SetWorldMatrix(&g_Explosion.mtxWorld);

	// マテリアル設定
	SetMaterial(g_Material);

	// テクスチャ設定
	GetDeviceContext()->PSSetShaderResources(0, 1, GetTexture(g_texNo));


	//UV値の更新
	D3D11_MAPPED_SUBRESOURCE msr;
	GetDeviceContext()->Map(g_VertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);
	VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;

	float width = 100.0f;
	float height = 100.0f;

	// 頂点座標の設定
	vertex[0].Position = D3DXVECTOR3(-width / 2.0f, 0.0f, 0.0f);
	vertex[1].Position = D3DXVECTOR3(-width / 2.0f, height, 0.0f);
	vertex[2].Position = D3DXVECTOR3(width / 2.0f, 0.0f, 0.0f);
	vertex[3].Position = D3DXVECTOR3(width / 2.0f, height, 0.0f);

	// 頂点カラーの設定
	vertex[0].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[1].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[2].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[3].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	// テクスチャ座標の設定
	float u = 0.125f * g_Explosion.animIndex;
	vertex[0].TexCoord = D3DXVECTOR2(u, 1.0f);
	vertex[1].TexCoord = D3DXVECTOR2(u, 0.0f);
	vertex[2].TexCoord = D3DXVECTOR2(u + 0.125f, 1.0f);
	vertex[3].TexCoord = D3DXVECTOR2(u + 0.125f, 0.0f);
	GetDeviceContext()->Unmap(g_VertexBuffer, 0);

	// ポリゴンの描画
	GetDeviceContext()->Draw(4, 0);
}

	// ライティングを有効に
	SetLightEnable(true);

	// αテストを無効に
	SetAlphaTestEnable(false);
}

EXPLOSION * GetExplosion()
{
	return &g_Explosion;
}

void SetExplosion(D3DXVECTOR3 pos)
{
	if (g_Explosion.use == false)
	{
		g_Explosion.pos = pos;
		g_Explosion.frame = 0.0f;

		g_Explosion.animIndex = 0;
		g_Explosion.animWait = 3;

		g_Explosion.use = true;
		StopSoundAll();
		PlaySound(g_SENoExplosion, 0);
	}
}
