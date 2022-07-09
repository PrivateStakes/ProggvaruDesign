#include "pch.h"
#include "GameObjectRepos.h"
#include "GameObject.h"

GameObjectRepos::GameObjectRepos()
{
	
}

GameObjectRepos::~GameObjectRepos()
{
	for (int i = 0; i < gameObjectHolder.size(); i++)
	{
		delete gameObjectHolder[i];
		gameObjectHolder[i] = nullptr;
	}
}

inline GameObject* GameObjectRepos::getGameObject(string gameElementName)
{
	GameObject* returnObject = nullptr;

	for (int i = 0; i < gameObjectHolder.size(); i++)
	{
		if (gameElementName == gameObjectHolder[i]->getName()) returnObject = gameObjectHolder[i];
	}

	if (returnObject == nullptr) std::cout << "no such object was found" << std::endl;
	return returnObject;
}

inline GameObject* GameObjectRepos::getGameObject_index(int index)
{
	GameObject* returnObject = nullptr;
	if (index < gameObjectHolder.size()) returnObject = gameObjectHolder[index];

	if (returnObject == nullptr) std::cout << "no such object was found" << std::endl;
	return returnObject;
}

inline void GameObjectRepos::addGameObject(GameObject object)
{
	gameObjectHolder.push_back(new GameObject(object));
}

inline void GameObjectRepos::removeGameObject(std::string name)
{
	for (int i = 0; i < gameObjectHolder.size(); i++)
	{
		if (name == gameObjectHolder[i]->getName())
		{
			delete gameObjectHolder[i];
			gameObjectHolder[i] = nullptr;
			gameObjectHolder[i] = new GameObject(*gameObjectHolder.back());

			delete gameObjectHolder.back();
			gameObjectHolder.back() = nullptr;
		}
		else if (i == gameObjectHolder.size() - 1) std::cout << "no such object was found" << std::endl;
	}
}

inline void GameObjectRepos::removeGameObject_index(int index)
{
	if (index < gameObjectHolder.size())
	{
		delete gameObjectHolder[index];
		gameObjectHolder[index] = nullptr;
		gameObjectHolder[index] = new GameObject(*gameObjectHolder.back());

		delete gameObjectHolder.back();
		gameObjectHolder.back() = nullptr;
	}
	else std::cout << "no such object was found" << std::endl;
}

inline void GameObjectRepos::listAllElements()
{
	for (int i = 0; i < gameObjectHolder.size() - 1; i++)
	{
		std::cout << (i + 1) << ": " << gameObjectHolder[i]->getName() << std::endl;
	}
	
}
