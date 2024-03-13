#pragma once
#include "component.h"
#include<list>
class GameObject
{
protected:
	bool m_Destroy = false;
	std::list<Component*> m_Component;
public:
	virtual void Init() {}
	virtual void Uninit() {

		for (Component* component : m_Component) {
			component->Uninit();
			delete component;
		}

		m_Component.clear();
	}
	virtual void Update() {
		for (Component* component : m_Component) {
			component->Update();
		}
	}
	virtual void Draw() {
		for (Component* component : m_Component) {
			component->Draw();
		}
	}

	void SetDestroy() {
		m_Destroy = true;
	}

	bool Destroy() {
		if (m_Destroy) {
			Uninit();
			delete this;
			return true;
		}
		else {
			return false;
		}
	}

	template<typename T>  //テンプレート関数
	T*  AddComponent()
	{
		Component* component = new T();
		m_Component.push_back(component);
		component->Init();
		return (T*)component;
	}

	//template<typename T>  //テンプレート関数
	//T*  GetComponent() {
	//	for (Component* component : m_Component) {
	//		//型を調べる
	//		if (typeid(*object) == typeid(T)) {
	//			return (T*)object;
	//		}
	//	}
	//	return nullptr;
	//}

};