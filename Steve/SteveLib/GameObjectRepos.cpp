#include "pch.h"
#include "GameObjectRepos.h"
#include "GameObject.h"
#include "Game.h"

GameObjectRepos::GameObjectRepos()
{
	
}

GameObjectRepos::~GameObjectRepos()
{
	for (int i = 0; i < gameObjectHolder.size(); i++)
	{
		if (gameObjectHolder[i] != nullptr) delete gameObjectHolder[i];
		gameObjectHolder[i] = nullptr;
	}
}

GameObject* GameObjectRepos::getGameObject(string gameElementName)
{
	GameObject* returnObject = nullptr;

	for (int i = 0; i < gameObjectHolder.size(); i++)
	{
		if (gameElementName == gameObjectHolder[i]->getName()) returnObject = gameObjectHolder[i];
	}

	if (returnObject == nullptr) std::cout << "no such object was found" << std::endl;
	return returnObject;
}

GameObject* GameObjectRepos::getGameObject_index(int index)
{
	GameObject* returnObject = nullptr;
	if (index < gameObjectHolder.size()) returnObject = gameObjectHolder[index];

	if (returnObject == nullptr) std::cout << "no such object was found" << std::endl;
	return returnObject;
}

void GameObjectRepos::addGameObject(Game* input)
{
	gameObjectHolder.push_back(new GameObject(input));
	gameObjectHolder.back()->setId(input->getIdIncrementTracker());
	input->setIdIncrementTracker(input->getIdIncrementTracker() + 1);
}

void GameObjectRepos::addGameObject(Game* input, GameObject* gameObj)
{
	//gameObjectHolder.push_back(new GameObject(input, gameObj));
	gameObjectHolder.push_back(gameObj);
	//gameObjectHolder.back()->generateEvent(eventManager, gameObj->getEventType());
	gameObjectHolder.back()->setId(input->getIdIncrementTracker());
	input->setIdIncrementTracker(input->getIdIncrementTracker() + 1);
}

void GameObjectRepos::removeGameObject_index(Game* input, int index)
{
	if (index < gameObjectHolder.size())
	{
		//delete gameObjectHolder[index];
		gameObjectHolder[index] = nullptr;
		gameObjectHolder[index] = gameObjectHolder.back();//new GameObject(input, gameObjectHolder.back());

		//gameObjectHolder[index]->generateEvent(eventManager, NotificationType(gameObjectHolder.back()->getEventType()));
		//NOTE: events need to be handled before removal to avoid circle-ref; can't be bothered to fix it

		//delete gameObjectHolder.back();
		gameObjectHolder.back() = nullptr;
		gameObjectHolder.pop_back();
	}
	else std::cerr << "no such object was found" << std::endl;
}

std::string GameObjectRepos::listAllElements()
{
	std::string output;
	for (int i = 0; i < gameObjectHolder.size(); i++)
	{
		output += std::to_string(1 + i) + ": " + gameObjectHolder[i]->getName() + "\n";
	}
	
	return output;
}

int GameObjectRepos::getGameObjectHolderSize()
{
	return gameObjectHolder.size();
}

std::string GameObjectRepos::getObjectName(int index)
{
	std::string name;

	if (index > gameObjectHolder.size())
	{
		name = "";
	}
	else
	{
		name = gameObjectHolder[index]->getName();
	}
	return name;
}