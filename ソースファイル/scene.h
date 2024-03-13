#pragma once
#include"gameObject.h"
#include<list>
#include<typeinfo>
#include<vector>


#define LAYER 5

class Scene 
{
protected:
	std::list<GameObject*> m_GameObject[LAYER];
	bool m_noinput = false;
public:
	virtual void Init(){}
	virtual void Uninit() {

		for (int i = 0; i < LAYER; i++) {
			for (GameObject* gameobject : m_GameObject[i]) {
				gameobject->Uninit();
				delete gameobject;
			}
		}
	}
	virtual void Update() {

		for (int i = 0; i < LAYER; i++) {
			for (GameObject* gameobject : m_GameObject[i]) {
				gameobject->Update();
			}
		}


		for (int i = 0; i < LAYER; i++) {
			//remove_if  returnがtrueだったら消す
			m_GameObject[i].remove_if([](GameObject* object) {return object->Destroy(); });
		}
	}
	//////////////////////////////////
	virtual void Draw() {
		for (int i = 0; i < LAYER; i++) {
			for (GameObject* gameobject : m_GameObject[i]) {
				gameobject->Draw();
			}
		}
	}


	template<typename T>  //テンプレート関数
	T*  AddGameObject(int num) 
	{
		T* gameObject = new T();
		m_GameObject[num].push_back(gameObject);
		gameObject->Init();
		return gameObject;
	}

	template<typename T>  //テンプレート関数
	T*  GetGameObject() {
		for (int i = 0; i < LAYER; i++) {
			for (GameObject* object : m_GameObject[i]) {
				//型を調べる
				if (typeid(*object) == typeid(T)) {
					return (T*)object;
				}
			}
		}
		return nullptr;
	}

	//可変長配列　要素の追加と削除ができる
	template<typename T>  //テンプレート関数
	std::vector<T*>  GetGameObjects() {
		std::vector<T*> objects;
		for (int i = 0; i < LAYER; i++) {
			for (GameObject* object : m_GameObject[i]) {
				//型を調べる
				if (typeid(*object) == typeid(T)) {
					objects.push_back((T*)object);
				}
			}
		}
		return objects;
	}

	bool GetNoInputFlag() {
		return m_noinput;
	}
};