#include "GameObjectFactory.h"

GameObjectFactory  *GameObjectFactory::mFactory = nullptr;
GameObjectFactory  *GameObjectFactory::Instace() {
	
	if (mFactory ==nullptr) {
		mFactory = new GameObjectFactory();
	}
	return mFactory;
}

void GameObjectFactory::CreateObj(GameObject* _obj, string _name) {
	mObjMap[_name] = _obj;
}

GameObject* GameObjectFactory::GetObj(string _name) {
	return mObjMap.at(_name);
}

