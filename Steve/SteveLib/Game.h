#include "pch.h"
#include "InputSanitizer.h"
#include "Inventory.h"
#pragma once

class Inventory;
class GameObject;
class EventManager;
class GameObjectRepos;
class Secretary;

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
	Secretary* secretary;

	int idIncrementTracker;

	void updateEventsInScene(Scene* input);
	
public:
	Game();
	~Game();

	int randomNumberGenerator(int low, int high);

	Inventory* getInventory();
	Scene* getCurrentScene();
	void setCurrentScene(int);	//creates a version for game to have as its currentScene
	int getAllScenesSize();
	std::vector<Scene*> getAllScenes();
	void createScene();

	GameObject* getItemFromScene(int x, WhichScene scene);
	void removeItem(int x, WhichScene scene);
	EventManager* getEventManager();

	void updateEvents();

	int getIdIncrementTracker();
	void setIdIncrementTracker(int);

	void handleInteractions(InputSanitizer input, int index);
};