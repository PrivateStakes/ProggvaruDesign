#include "pch.h"
#pragma once
#include <iostream>

class GameObject;
class GameObjectRepos;
class Game;

class Scene
{
protected:
	//character repos
	Game* myGame;
	GameObjectRepos* gameObjectRepos;

public:
	Scene(Game*);
	~Scene();
	
	//change to element return type (whatever that is)
	std::string listAllGameObjects();
	int getGameObjectHolderSize();
	std::string listAllCharacters();
	int getCharacterHolderSize();

	bool isAvailable(std::string name);	//????
	bool isGameObject(std::string name);
	bool isCharacter(std::string name);	

	GameObject* getItemFromScene(std::string);
	GameObject* getItemFromScene_index(int index);
	void addItemInScene(Game*);

	virtual GameObject* getCharacterFromScene(std::string);
	virtual GameObject* getCharacterFromScene_index(int index);
	virtual void addCharacterInScene(GameObject);



};