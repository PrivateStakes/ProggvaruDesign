#include "pch.h"
#include "Inventory.h"
#include "Game.h"
#include "GameObjectRepos.h"
#include "GameObject.h"

Inventory::Inventory(Game* game):
Scene(game)
{
}

GameObject* Inventory::getCharacterFromScene(std::string name)
{
	return this->gameObjectRepos->getGameObject(name);
}

GameObject* Inventory::getCharacterFromScene_index(int index)
{
	return this->gameObjectRepos->getGameObject_index(index);
}

void Inventory::addCharacterInScene(GameObject* object)
{
	this->gameObjectRepos->addGameObject(this->myGame, object);
}
	