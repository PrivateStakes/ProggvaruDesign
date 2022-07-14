#include "pch.h"
#include "Game.h"
#include "Inventory.h"
#include "InputSanitizer.h"
#include "Notification.h"
#include <random>

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

	for (int i = 0; i < allScenes.size(); i++)
	{
		delete allScenes[i];
		allScenes[i] = nullptr;
	}
	currentScene = nullptr;
}

int Game::randomNumberGenerator(int low, int high)
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(low, high); // define the range

	return distr(gen);
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
	if (currentScene != nullptr) currentScene = nullptr;
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

void updateEventsInScene(Scene* input)
{
	for (int i = 0; i < input->getGameObjectHolderSize(); i++)
	{
		if (input->getItemFromScene_index(i)->hasNotification())
		{

			std::cout << input->getItemFromScene_index(i)->getNotification()->getNotificationMessage();
		}
	}

	for (int i = 0; i < input->getCharacterHolderSize(); i++)
	{
		if (input->getCharacterFromScene_index(i)->hasNotification())
		{
			//do shit here
			std::cout << input->getCharacterFromScene_index(i)->getNotification()->getNotificationMessage();
		}
	}
}

void Game::updateEvents()
{
	for (int i = 0; i <= allScenes.size(); i++)
	{
		if (i != allScenes.size()) updateEventsInScene(allScenes[i]);
		else updateEventsInScene(playerInventory);
	}
}
