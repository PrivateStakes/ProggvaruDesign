#include "pch.h"
#include "Game.h"
#include "Scene.h"
#include "Inventory.h"
#include "GameObject.h"
#include "InputSanitizer.h"
#include "GameObjectRepos.h"

Game::Game()
{
	currentScene = nullptr;
	playerInventory = new Inventory(this);
	inputSanitizer = new InputSanitizer;
}

Game::~Game()
{
	delete currentScene;
	currentScene = nullptr;

	delete playerInventory;
	playerInventory = nullptr;

	delete inputSanitizer;
	inputSanitizer = nullptr;
}

void Game::Update()
{
	bool gameOn = true;

	while (gameOn)
	{
		//std::cout << inputSanitizer->playerInputText() << std::endl;
	}
}

inline Inventory* Game::getInventory()
{
	return playerInventory;
}

inline Scene* Game::getCurrentScene()
{
	return currentScene;
}

inline void Game::setCurrentScene(Scene& scene)
{
	if (currentScene != nullptr)
	{
		delete currentScene;
		currentScene = nullptr;
	}

	currentScene = new Scene(scene);
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

GameObjectRepos* Game::getGameObjectRepos()
{
	return gameObjectRepos;
}
