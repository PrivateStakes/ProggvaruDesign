#include "pch.h"
#include "Game.h"
#include "Scene.h"
#include "GameObject.h"

Game::Game()
{
	currentScene = nullptr;
	playerInventory = nullptr;
}

Game::~Game()
{
	delete currentScene;
	currentScene = nullptr;

	delete playerInventory;
	playerInventory = nullptr;
}

void Game::Update()
{
	bool gameOn = true;
	while (gameOn)
	{

	}
}

inline Scene* Game::getInventory()
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