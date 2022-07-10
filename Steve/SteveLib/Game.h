#include "pch.h"
#pragma once

class Scene;
class Inventory;
class GameObject;
class EventManager;
class InputSanitizer;
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
	Inventory* playerInventory;
	EventManager* eventManager;
	InputSanitizer* inputSanitizer;
	GameObjectRepos* gameObjectRepos;

	
public:
	Game();
	~Game();

	void Update();

	Inventory* getInventory();
	Scene* getCurrentScene();
	void setCurrentScene(Scene& currentScene);	//creates a version for game to have as its currentScene

	GameObject* getItemFromScene(int x, WhichScene scene);
	EventManager* getEventManager();
	GameObjectRepos* getGameObjectRepos();
};