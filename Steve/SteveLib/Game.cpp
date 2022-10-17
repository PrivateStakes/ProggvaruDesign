#include "pch.h"
#include "Game.h"
#include "Inventory.h"
#include "InputSanitizer.h"
#include "Notification.h"
#include "Secretary.h"
#include <random>

Game::Game() : 
	currentScene(nullptr),
	idIncrementTracker(0)
{
	playerInventory = new Inventory(this);
	secretary = new Secretary();
}

Game::~Game()
{
	delete secretary;
	secretary = nullptr;

	//We do not have to delete currentScene since it is either playerInventory or in allScenes
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

Inventory* Game::getInventory()
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

std::vector<Scene*> Game::getAllScenes()
{
	return allScenes;
}

void Game::createScene()
{
	allScenes.push_back(new Scene(this));
}

GameObject* Game::getItemFromScene(int x, WhichScene scene)
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

void Game::removeItem(int x, WhichScene scene)
{
	switch (scene)
	{
	case WhichScene::e_currentScene:
		currentScene->removeItemInScene(x);
		break;
	case WhichScene::e_playerInventory:
		playerInventory->removeItemInScene(x);
		break;
	default:
		break;
	}
}

inline EventManager* Game::getEventManager()
{
	return eventManager;
}

void Game::updateEventsInScene(Scene* input)
{
	for (int i = 0; i < input->getGameObjectHolderSize(); i++)
	{
		if (input->getItemFromScene_index(i)->hasNotification())
		{
			bool elementAdded = false;

			switch (input->getItemFromScene_index(i)->getEventType())
			{
			case NotificationType::elementMoved:
				while (!elementAdded)
				{
					int randomScene = randomNumberGenerator(0, allScenes.size());
					if (allScenes[randomScene] != input)
					{
						allScenes[randomScene]->addItemInScene(this, input->getItemFromScene_index(i));
						input->removeItemInScene(i);
						elementAdded = true;
					}
				}
				break;

			case NotificationType::elementOptionsExtended:	//useless, they always have all optíons available
				break;

			case NotificationType::addNewElement:
				
				while (!elementAdded)
				{
					int randomScene = randomNumberGenerator(0, allScenes.size());
					if (allScenes[randomScene] != currentScene)
					{
						allScenes[randomScene]->addItemInScene(this);
						elementAdded = true;
					}
				}
				break;

			case NotificationType::addNewScene:
				createScene();
				for (int j = 0; j < randomNumberGenerator(1, 5); j++)
				{
					allScenes.back()->addItemInScene(this);
				}
				break;

			case NotificationType::addObjectToInventory:
				playerInventory->addItemInScene(this, input->getItemFromScene_index(i));	//NOTE: needs rework
				input->removeItemInScene(i);
				break;
			}
			secretary->addNotification(input->getItemFromScene_index(i)->getNotification()->getNotificationMessage());
		}
	}

	for (int i = 0; i < input->getCharacterHolderSize(); i++)
	{
		if (input->getCharacterFromScene_index(i)->hasNotification())
		{
			//do shit here
			secretary->addNotification(input->getItemFromScene_index(i)->getNotification()->getNotificationMessage());
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

int Game::getIdIncrementTracker()
{
	return idIncrementTracker;
}

void Game::setIdIncrementTracker(int input)
{
	idIncrementTracker = input;
}

void Game::handleInteractions(InputSanitizer input, int index)
{
	std::string object = getCurrentScene()->selectObject(index);
	std::cout << "You chose the " << object << ".\nThe interactions are: \n";

	bool interactinWithObject = true;
	while (interactinWithObject)
	{
		updateEvents();
		const int numberOfInteractions = getCurrentScene()->getItemFromScene_index(index)->listInteractionTypes().size();
		for (int i = 0; i < numberOfInteractions; i++)
		{
			std::cout << std::to_string(i + 1) << " " << getCurrentScene()->getItemFromScene_index(index)->listInteractionTypes()[i] << std::endl;
		}
		std::cout << std::to_string(numberOfInteractions + 1) << " return to scene" << std::endl;

		int playerInputInteraction = input.playerInputNumbers(1, numberOfInteractions + 1) - 1;
		if (playerInputInteraction == numberOfInteractions) interactinWithObject = false;
		else
		{
			std::string type = getCurrentScene()->getItemFromScene_index(index)->listInteractionTypes()[playerInputInteraction];
			getCurrentScene()->getItemFromScene_index(index)->startInteraction(object, type);
			std::string message = getCurrentScene()->getItemFromScene_index(index)->returnInteractionMessage();
			std::cout << message << std::endl;
		}
	}
}