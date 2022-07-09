#include "pch.h"
#pragma once
#include <iostream>
#include <vector>

class GameObject;

class GameObjectRepos
{
private:

	std::vector<GameObject*> gameObjectHolder;

public:
	GameObjectRepos();
	~GameObjectRepos();

	GameObject* getGameObject(std::string gameElementName);
	GameObject* getGameObject_index(int index);

	void addGameObject(GameObject);
	void removeGameObject(std::string name);
	void removeGameObject_index(int index);

	void listAllElements();
};