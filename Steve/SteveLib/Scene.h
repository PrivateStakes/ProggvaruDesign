#include "pch.h"
#pragma once
#include <iostream>

class GameObject;
class GameObjectRepos;
class Game;

class Scene
{
private:
	GameObjectRepos* gameObjectRepos;
	Game* myGame;

public:
	Scene(Game*);
	~Scene();
	
	//change to element return type (whatever that is)
	void listAvailableElements();

	bool isAvailable(std::string name);
	bool isGameObject(std::string name);
	GameObject* getItemFromScene(std::string);
	GameObject* getItemFromScene_index(int index);
	void addItemInScene(GameObject);
};