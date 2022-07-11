#include "pch.h"
#include "Game.h"
#include "Inventory.h"
#include "InputSanitizer.h"

Game::Game() : 
	currentScene(nullptr)
{
	playerInventory = new Inventory(this);

	allScenes.push_back(new Scene(this));
	allScenes.push_back(new Scene(this));
	allScenes.push_back(new Scene(this));
}

Game::~Game()
{
	delete currentScene;
	currentScene = nullptr;

	delete playerInventory;
	playerInventory = nullptr;
}

inline Inventory* Game::getInventory()
{
	return playerInventory;
}

Scene* Game::getCurrentScene()
{
	return currentScene;
}

void Game::setCurrentScene(int sceneIndex)
{
	if (currentScene != nullptr)
	{
		delete currentScene;
		currentScene = nullptr;
	}
	currentScene = allScenes[sceneIndex];
}

int Game::getAllScenesSize()
{
	return allScenes.size();
}

inline GameObject* Game::getItemFromScene(int x, WhichScene scene)
{
	switch (scene)
	{
	case WhichScene::e_currentScene:
		return currentScene->getItemFromScene_index(x);
		break;
	case WhichScene::e_playerInventory:
		return playerInventory->getItemFromScene_index(x);
		break;
	default:
		return nullptr;
		break;
	}
}

inline EventManager* Game::getEventManager()
{
	return eventManager;
}

