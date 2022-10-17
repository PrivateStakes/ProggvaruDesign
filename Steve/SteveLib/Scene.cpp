#include "pch.h"
#include "Scene.h"
#include "Game.h"
#include "GameObjectRepos.h"
#include "GameObject.h"
#include "Secretary.h"

Scene::Scene(Game* game) :
	myGame(game)
{
	gameObjectRepos = new GameObjectRepos();
}

Scene::~Scene()
{
	myGame = nullptr;

	delete gameObjectRepos;
	gameObjectRepos = nullptr;
}

std::string Scene::listAllGameObjects()
{
	return gameObjectRepos->listAllElements();
}

int Scene::getGameObjectHolderSize()
{
	return gameObjectRepos->getGameObjectHolderSize();
}

std::string Scene::listAllCharacters()
{
	return "none";
	//list all elements through characterRepos also
}

int Scene::getCharacterHolderSize()
{
	return 0;
}

bool Scene::isAvailable(std::string name)
{
	return true;
}

bool Scene::isGameObject(std::string name)
{
	if (gameObjectRepos->getGameObject(name) != nullptr) return true;
	else return false;
}

bool Scene::isCharacter(std::string name)
{
	return false;
}

GameObject* Scene::getItemFromScene(std::string input)
{
	return gameObjectRepos->getGameObject(input);
}

GameObject* Scene::getItemFromScene_index(int index)
{
	if (index >= gameObjectRepos->getGameObjectHolderSize()) return nullptr;
	return gameObjectRepos->getGameObject_index(index);
}

void Scene::addItemInScene(Game* input)
{
	gameObjectRepos->addGameObject(input);
}

void Scene::addItemInScene(Game* input, GameObject* gameObj)
{
	gameObjectRepos->addGameObject(input, gameObj);
}

void Scene::removeItemInScene(int index)
{
	gameObjectRepos->removeGameObject_index(index);
}

GameObject* Scene::getCharacterFromScene(std::string)
{
	return nullptr;
}

GameObject* Scene::getCharacterFromScene_index(int index)
{
	return nullptr;
}

void Scene::addCharacterInScene(GameObject* obj)
{

}

std::string Scene::selectObject(int index)
{
	return gameObjectRepos->getObjectName(index);
}