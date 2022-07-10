#include "pch.h"
#include "Scene.h"
#include "Game.h"
#include "GameObjectRepos.h"
#include "GameObject.h"

Scene::Scene(Game* game)
{
	myGame = game;
}

Scene::~Scene()
{
}

inline void Scene::listAvailableElements()
{
	myGame->getGameObjectRepos()->listAllElements();
	//list all elements through characterRepos also
}

inline bool Scene::isAvailable(std::string name)
{
	return true;
}

inline bool Scene::isGameObject(std::string name)
{
	if (myGame->getGameObjectRepos()->getGameObject(name) != nullptr) return true;
	else return false;
}

bool Scene::isCharacter(std::string name)
{
	return false;
}

inline GameObject* Scene::getItemFromScene(std::string input)
{
	return myGame->getGameObjectRepos()->getGameObject(input);
}

inline GameObject* Scene::getItemFromScene_index(int index)
{
	return myGame->getGameObjectRepos()->getGameObject_index(index);
}

inline void Scene::addItemInScene(GameObject input)
{
	myGame->getGameObjectRepos()->addGameObject(input);
}

GameObject* Scene::getCharacterFromScene(std::string)
{
	return nullptr;
}

GameObject* Scene::getCharacterFromScene_index(int index)
{
	return nullptr;
}

void Scene::addCharacterInScene(GameObject)
{

}
