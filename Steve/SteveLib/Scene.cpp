#include "pch.h"
#include "Scene.h"
#include "Game.h"
#include "GameObjectRepos.h"
#include "GameObject.h"

Scene::Scene(Game* game)
{
	gameObjectRepos = new GameObjectRepos();
	myGame = game;
}

Scene::~Scene()
{
	delete gameObjectRepos;
	gameObjectRepos = nullptr;
}

inline void Scene::listAvailableElements()
{
	gameObjectRepos->listAllElements();
}

inline bool Scene::isAvailable(std::string name)
{
	return true;
}

inline bool Scene::isGameObject(std::string name)
{
	if (gameObjectRepos->getGameObject(name) != nullptr) return true;
	else return false;
}

inline GameObject* Scene::getItemFromScene(std::string input)
{
	return gameObjectRepos->getGameObject(input);
}

inline GameObject* Scene::getItemFromScene_index(int index)
{
	return gameObjectRepos->getGameObject_index(index);
}

inline void Scene::addItemInScene(GameObject input)
{
	gameObjectRepos->addGameObject(input);
}