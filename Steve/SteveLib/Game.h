#include "pch.h"
#include "InputSanitizer.h"
#include "Scene.h"
#pragma once

class Inventory;
class GameObject;
class EventManager;
class GameObjectRepos;

enum class WhichScene
{
	e_currentScene,
	e_playerInventory
};

class Game
{
private:
	Scene* currentScene;
	std::vector<Scene*> allScenes;
	Inventory* playerInventory;
	EventManager* eventManager;

	
public:
	Game();
	~Game();

	Inventory* getInventory();
	Scene* getCurrentScene();
	void setCurrentScene(int);	//creates a version for game to have as its currentScene
	int getAllScenesSize();

	GameObject* getItemFromScene(int x, WhichScene scene);
	EventManager* getEventManager();
};