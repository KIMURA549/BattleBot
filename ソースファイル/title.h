#pragma once

#include"scene.h"

class Title :public Scene {
private:
	class Fade* m_fade;
	bool m_next = false;
	class Audio* m_BGM;
	class Audio* m_se;
public:
	void Init()override;
	void Update()override;
};