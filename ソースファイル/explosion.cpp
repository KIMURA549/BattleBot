#include "explosion.h"
#include"camera.h"
#include "texture.h"
#include"fade.h"

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static ID3D11Buffer		*g_VertexBuffer = NULL;	// ���_�o�b�t�@

static EXPLOSION		g_Explosion;	// �e�f�[�^
static MATERIAL		g_Material;
static int			g_texNo = 0;
static int g_SENoExplosion;
void InitExplosion(void)
{
	// ���_�o�b�t�@����
	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DYNAMIC;
	bd.ByteWidth = sizeof(VERTEX_3D) * 4;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

	GetDevice()->CreateBuffer(&bd, NULL, &g_VertexBuffer);


	// ���_�o�b�t�@�ɒl���Z�b�g����
	{
		D3D11_MAPPED_SUBRESOURCE msr;
		GetDeviceContext()->Map(g_VertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);

		VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;

		float width = 300.0f;
		float height = 300.0f;

		// ���_���W�̐ݒ�
		vertex[0].Position = D3DXVECTOR3(-width / 2.0f, 0.0f, 0.0f);
		vertex[1].Position = D3DXVECTOR3(-width / 2.0f, height, 0.0f);
		vertex[2].Position = D3DXVECTOR3(width / 2.0f, 0.0f, 0.0f);
		vertex[3].Position = D3DXVECTOR3(width / 2.0f, height, 0.0f);

		// ���_�J���[�̐ݒ�
		vertex[0].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[1].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[2].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[3].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		// �e�N�X�`�����W�̐ݒ�
		vertex[0].TexCoord = D3DXVECTOR2(0.0f, 1.0f);
		vertex[1].TexCoord = D3DXVECTOR2(0.0f, 0.0f);
		vertex[2].TexCoord = D3DXVECTOR2(1.0f, 1.0f);
		vertex[3].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

		GetDeviceContext()->Unmap(g_VertexBuffer, 0);
	}

	// �e�N�X�`������
	g_texNo = LoadTexture((char*)"data/TEXTURE/explosion000.png");
	g_SENoExplosion = LoadSound((char*)"data/SE/�Ō�3.wav");
	SetVolume(g_SENoExplosion, 30);
	// �}�e���A��������
	ZeroMemory(&g_Material, sizeof(g_Material));
	g_Material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	// ������

	g_Explosion.pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_Explosion.use = false;
}

void UninitExplosion(void)
{
	if (g_VertexBuffer != NULL)
	{// ���_�o�b�t�@�̉��
		g_VertexBuffer->Release();
		g_VertexBuffer = NULL;
	}
}

void UpdateExplosion(void)
{
	if (g_Explosion.use)
	{
		//���ŏ���
		if (g_Explosion.frame > (float)g_Explosion.animWait)
		{
			g_Explosion.animIndex += 1;
			g_Explosion.frame = 0;
			if (g_Explosion.animIndex > 7) {
				//RESULT�ֈڍs����
				SceneTransition(SCENE_RESULT);
				g_Explosion.use = false;
			}
		}

		//���Ԍo��
		g_Explosion.frame += 0.5f;
	}
}

void DrawExplosion(void)
{
	// ���e�X�g��L����
	SetAlphaTestEnable(true);

	// ���C�e�B���O�𖳌�
	SetLightEnable(false);

	D3DXMATRIX mtxView, mtxScale, mtxTranslate;

	// ���_�o�b�t�@�ݒ�
	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	GetDeviceContext()->IASetVertexBuffers(0, 1, &g_VertexBuffer, &stride, &offset);

	// �v���~�e�B�u�g�|���W�ݒ�
	GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	if (g_Explosion.use) {
	// ���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&g_Explosion.mtxWorld);

	CAMERA *cam = GetCamera();

	// �|���S���𐳖ʂɌ�����
#if 0
			// �r���[�}�g���b�N�X�̋t�s����擾
	g_Bullet[i].mtxWorld = cam->mtxInvView;
	g_Bullet[i].mtxWorld._41 = 0.0f;
	g_Bullet[i].mtxWorld._42 = 0.0f;
	g_Bullet[i].mtxWorld._43 = 0.0f;
#else
			// �r���[�}�g���b�N�X���擾
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


	// �ړ��𔽉f
	D3DXMatrixTranslation(&mtxTranslate, g_Explosion.pos.x,
		g_Explosion.pos.y,
		g_Explosion.pos.z);
	D3DXMatrixMultiply(&g_Explosion.mtxWorld, &g_Explosion.mtxWorld, &mtxTranslate);

	// ���[���h�}�g���b�N�X�̐ݒ�
	SetWorldMatrix(&g_Explosion.mtxWorld);

	// �}�e���A���ݒ�
	SetMaterial(g_Material);

	// �e�N�X�`���ݒ�
	GetDeviceContext()->PSSetShaderResources(0, 1, GetTexture(g_texNo));


	//UV�l�̍X�V
	D3D11_MAPPED_SUBRESOURCE msr;
	GetDeviceContext()->Map(g_VertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);
	VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;

	float width = 100.0f;
	float height = 100.0f;

	// ���_���W�̐ݒ�
	vertex[0].Position = D3DXVECTOR3(-width / 2.0f, 0.0f, 0.0f);
	vertex[1].Position = D3DXVECTOR3(-width / 2.0f, height, 0.0f);
	vertex[2].Position = D3DXVECTOR3(width / 2.0f, 0.0f, 0.0f);
	vertex[3].Position = D3DXVECTOR3(width / 2.0f, height, 0.0f);

	// ���_�J���[�̐ݒ�
	vertex[0].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[1].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[2].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[3].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	// �e�N�X�`�����W�̐ݒ�
	float u = 0.125f * g_Explosion.animIndex;
	vertex[0].TexCoord = D3DXVECTOR2(u, 1.0f);
	vertex[1].TexCoord = D3DXVECTOR2(u, 0.0f);
	vertex[2].TexCoord = D3DXVECTOR2(u + 0.125f, 1.0f);
	vertex[3].TexCoord = D3DXVECTOR2(u + 0.125f, 0.0f);
	GetDeviceContext()->Unmap(g_VertexBuffer, 0);

	// �|���S���̕`��
	GetDeviceContext()->Draw(4, 0);
}

	// ���C�e�B���O��L����
	SetLightEnable(true);

	// ���e�X�g�𖳌���
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
