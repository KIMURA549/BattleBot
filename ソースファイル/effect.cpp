#include"main.h"
#include"renderer.h"
#include"effect.h"


void Effect::Init()
{
	Effect::SetEffect("asset\\texture\\explosion00.png", D3DXVECTOR3(0.0f, 0.0f, 0.0f),5.0f, 4, 4);

}
void Effect::Uninit()
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
}
void Effect::Update() {
	if (m_use == true) {
		m_Count++;
		if (m_UCount * m_VCount >= m_Count) {
			m_use = false;
		}
	}
}
void Effect::Draw()
{
	if (m_use == true) {
		float x = m_Count % m_UCount * (1.0f / m_UCount);
		float y = m_Count / m_VCount * (1.0f / m_VCount);

		VERTEX_3D vertex[4];

		vertex[0].Position = D3DXVECTOR3(-m_size, m_size, 0.0f);
		vertex[0].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[0].TexCoord = D3DXVECTOR2(x, y);

		vertex[1].Position = D3DXVECTOR3(m_size, m_size, 0.0f);
		vertex[1].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[1].TexCoord = D3DXVECTOR2(x + m_Usize, y);

		vertex[2].Position = D3DXVECTOR3(-m_size, -m_size, 0.0f);
		vertex[2].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[2].TexCoord = D3DXVECTOR2(x, y + m_Vsize);

		vertex[3].Position = D3DXVECTOR3(m_size, -m_size, 0.0f);
		vertex[3].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		vertex[3].TexCoord = D3DXVECTOR2(x + m_Usize, y + m_Vsize);



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
		//入力レイアウト
		Renderer::GetDeviceContext()->IASetInputLayout(m_VertexLayout);

		//シェーダー設定
		Renderer::GetDeviceContext()->VSSetShader(m_VertexShader, NULL, 0);
		Renderer::GetDeviceContext()->PSSetShader(m_PixelShader, NULL, 0);

		//マトリクス設定
		D3DXMATRIX world, scale, rot, trans;
		D3DXMatrixScaling(&scale, 1.0f, 1.0f, 1.0f);
		D3DXMatrixRotationYawPitchRoll(&rot, 0.0f, 0.0f, 0.0f);
		D3DXMatrixTranslation(&trans, m_pos.x, m_pos.y, m_pos.z);
		world = scale * rot  *trans;
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

void Effect::SetEffect(const char * TextureName, D3DXVECTOR3 pos, float size, int uCnt, int vCnt)
{
	m_Usize = 1.0f / uCnt;
	m_Vsize = 1.0f / vCnt;

	m_UCount = uCnt;
	m_VCount = vCnt;

	m_Count = 0;

	float x = m_Count % m_UCount * (1.0f / m_UCount);
	float y = m_Count / m_VCount * (1.0f / m_VCount);

	m_use = true;

	m_pos = pos;

	VERTEX_3D vertex[4];

	vertex[0].Position = D3DXVECTOR3(-size, 0.0f, size);
	vertex[0].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[0].TexCoord = D3DXVECTOR2(x, y);

	vertex[1].Position = D3DXVECTOR3(size, 0.0f, size);
	vertex[1].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[1].TexCoord = D3DXVECTOR2(x + m_Usize, y);

	vertex[2].Position = D3DXVECTOR3(-size, 0.0f, -size);
	vertex[2].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[2].TexCoord = D3DXVECTOR2(x, y + m_Vsize);

	vertex[3].Position = D3DXVECTOR3(size, 0.0f, -size);
	vertex[3].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[3].TexCoord = D3DXVECTOR2(x + m_Usize, y + m_Vsize);



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
}