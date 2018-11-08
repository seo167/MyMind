#pragma once
#include<map>
#include<string>
#include "GameObject.h"
using namespace std;

class GameObjectFactory{
	
	public:
		static GameObjectFactory  *Instace();

		GameObject* GetObj(string _name);
		//创建对象
		void CreateObj(GameObject* _obj,string _name);
	private:

		GameObjectFactory() {

		}

		map<string,GameObject*> mObjMap;//不可以存在重复key的对象 
		
		static GameObjectFactory  *mFactory;
};


