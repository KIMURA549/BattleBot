#include"main.h"
#include"manager.h"
#include"renderer.h"

#include"scene.h"
#include"camera.h"
#include "player.h"
#include"enemy.h"
#include"ball.h"
#include"transform.h"
#include"audio.h"

void Ball::Init()
{
	VERTEX_3D vertex[4];

	vertex[0].Position = D3DXVECTOR3(-2.5f, 0.0f, 2.5f);
	vertex[0].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

	vertex[1].Position = D3DXVECTOR3(2.5f, 0.0f, 2.5f);
	vertex[1].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

	vertex[2].Position = D3DXVECTOR3(-2.5f, 0.0f, -2.5f);
	vertex[2].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

	vertex[3].Position = D3DXVECTOR3(2.5f, 0.0f, -2.5f);
	vertex[3].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[3].TexCoord = D3DXVECTOR2(1.0f, 1.0f);



	//頂点バッファの生成
	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(VERTEX_3D) * 4;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;

	D3D11_SUBRESOURCE_DATA sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.pSysMem = vertex;

	Renderer::GetDevice()->CreateBuffer(&bd, &sd, &m_VertexBuffer);



	//テクスチャ読み込み
	D3DX11CreateShaderResourceViewFromFile(Renderer::GetDevice(),
		"asset\\texture\\shadow00.png",
		NULL,
		NULL,
		&m_Texture,
		NULL);
	assert(m_Texture);



	Renderer::CreateVertexShader(&m_VertexShader, &m_VertexLayout,
		"shader\\unlitTextureVS.cso");
	Renderer::CreatePixelShader(&m_PixelShader,
		"shader\\unlitTexturePS.cso");

	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	m_use = false;


	m_se = new Audio;
	m_se->Init();
	m_se->Load("asset\\audio\\ballshot.wav");
}
void Ball::Uninit()
{
	if (m_VertexBuffer != NULL) {
		m_VertexBuffer->Release();
	}
	if (m_Texture != NULL) {
		m_Texture->Release();
	}

	if (m_VertexLayout != NULL) {
		m_VertexLayout->Release();
	}
	if (m_VertexShader != NULL) {
		m_VertexShader->Release();
	}
	if (m_PixelShader != NULL) {
		m_PixelShader->Release();
	}

	m_se->Uninit();
	delete m_se;
}
void Ball::Update() {
	if (m_use == true) {
		m_pos.x += m_velx;

		m_delay -= 1.0f;
		if (m_delay <= 0.0f) {
			m_use = false;
		}

		Scene* scene = Manager::GetScene();
		float px;
		if (m_player == true) {
			Enemy* enemy = scene->GetGameObject<Enemy>();
			px = enemy->GetTransform()->GetPosition().x;
			if (m_pos.x - 0.25f <= px && px <= m_pos.x + 0.25f) {
				if (enemy->GetTransform()->GetPosition().y <= m_pos.y + 2.0f) {
					enemy->Damage(5.0f, D3DXVECTOR3(0.0f, 0.0f, 0.0f), false, false, false);
					m_use = false;
					m_se->Load("asset\\audio\\ballhit.wav");
					m_se->Play();
				}
			}

		}
		else {
			Player* player = scene->GetGameObject<Player>();
			px = player->GetTransform()->GetPosition().x;
			if (m_pos.x - 0.25f <= px && px <= m_pos.x + 0.25f) {
				if (player->GetTransform()->GetPosition().y <= m_pos.y + 2.0f) {
					player->Damage(5.0f, D3DXVECTOR3(0.0f, 0.0f, 0.0f), false, false, false);
					m_use = false;
					m_se->Load("asset\\audio\\ballhit.wav");
					m_se->Play();
				}
			}
			

		}


	}
}
void Ball::Draw()
{
	if (m_use == true) {
		//入力レイアウト
		Renderer::GetDeviceContext()->IASetInputLayout(m_VertexLayout);

		//シェーダー設定
		Renderer::GetDeviceContext()->VSSetShader(m_VertexShader, NULL, 0);
		Renderer::GetDeviceContext()->PSSetShader(m_PixelShader, NULL, 0);

		Scene* scene = Manager::GetScene();
		Camera* camera = scene->GetGameObject<Camera>();
		D3DXMATRIX view = camera->GetViewMatrix();

		D3DXMATRIX invView;
		D3DXMatrixInverse(&invView, NULL, &view);
		//移動の成分を0　（回転はさせるが移動はさせない）
		invView._41 = 0.0f;
		invView._42 = 0.0f;
		invView._43 = 0.0f;

		//マトリクス設定
		D3DXMATRIX world, scale, rot, trans;
		D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
		//D3DXMatrixRotationYawPitchRoll(&rot, 0.0f, 0.0f, 0.0f);
		D3DXMatrixTranslation(&trans, m_pos.x, m_pos.y, m_pos.z);
		world = scale * invView  *trans;
		Renderer::SetWorldMatrix(&world);

		//頂点バッファ設定
		UINT stride = sizeof(VERTEX_3D);
		UINT offset = 0;
		Renderer::GetDeviceContext()->IASetVertexBuffers(0, 1, &m_VertexBuffer, &stride, &offset);

		//マテリアル設定
		MATERIAL material;
		ZeroMemory(&material, sizeof(material));
		material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		material.TextureEnable = true;
		Renderer::SetMaterial(material);

		//テクスチャ設定
		Renderer::GetDeviceContext()->PSSetShaderResources(0, 1, &m_Texture);

		//プリミティとポロジ設定
		Renderer::GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

		//ポリゴン描画
		Renderer::GetDeviceContext()->Draw(4, 0);
	}


}

void Ball::SetShadowSize(float size)
{
	VERTEX_3D vertex[4];

	vertex[0].Position = D3DXVECTOR3(-size, size, 0.0f);
	vertex[0].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

	vertex[1].Position = D3DXVECTOR3(size, size, 0.0f);
	vertex[1].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

	vertex[2].Position = D3DXVECTOR3(-size, -size, 0.0f);
	vertex[2].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

	vertex[3].Position = D3DXVECTOR3(size, -size, 0.0f);
	vertex[3].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[3].TexCoord = D3DXVECTOR2(1.0f, 1.0f);



	//頂点バッファの生成
	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(VERTEX_3D) * 4;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;

	D3D11_SUBRESOURCE_DATA sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.pSysMem = vertex;

	Renderer::GetDevice()->CreateBuffer(&bd, &sd, &m_VertexBuffer);

	//テクスチャ読み込み
	D3DX11CreateShaderResourceViewFromFile(Renderer::GetDevice(),
		"asset\\texture\\ball.png",
		NULL,
		NULL,
		&m_Texture,
		NULL);
	assert(m_Texture);

	Renderer::CreateVertexShader(&m_VertexShader, &m_VertexLayout,
		"shader\\unlitTextureVS.cso");
	Renderer::CreatePixelShader(&m_PixelShader,
		"shader\\unlitTexturePS.cso");
}

void Ball::StartBall(bool player, float velx, D3DXVECTOR3 p)
{
	m_delay = 1000.0f;

	m_pos = p;

	m_velx = velx;

	m_player = player;
	m_use = true;

	m_se->Load("asset\\audio\\ballshot.wav");
	m_se->Play();
}
