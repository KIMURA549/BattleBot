#pragma once

#include"scene.h"

class Explanation :public Scene {
private:
	class Fade* m_fade;
	bool m_next = false;
public:
	void Init()override;
	void Update()override;
};