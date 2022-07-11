#include "pch.h"
#include "Scene.h"
#include "Game.h"
#include "GameObjectRepos.h"
#include "GameObject.h"

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

inline std::string Scene::listAllCharacters()
{
	return "none";
	//list all elements through characterRepos also
}

int Scene::getCharacterHolderSize()
{
	return 0;
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

inline bool Scene::isCharacter(std::string name)
{
	return false;
}

inline GameObject* Scene::getItemFromScene(std::string input)
{
	return gameObjectRepos->getGameObject(input);
}

inline GameObject* Scene::getItemFromScene_index(int index)
{
	return gameObjectRepos->getGameObject_index(index);
}

void Scene::addItemInScene(Game* input)
{
	gameObjectRepos->addGameObject(input);
}

inline GameObject* Scene::getCharacterFromScene(std::string)
{
	return nullptr;
}

inline GameObject* Scene::getCharacterFromScene_index(int index)
{
	return nullptr;
}

inline void Scene::addCharacterInScene(GameObject)
{

}
