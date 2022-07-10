#include "pch.h"
#include "Inventory.h"
#include "Game.h"
#include "GameObjectRepos.h"
#include "GameObject.h"

Inventory::Inventory(Game* game):
Scene(game)
{
}

GameObject* Inventory::getCharacterFromScene(std::string)
{
	return nullptr;
}

GameObject* Inventory::getCharacterFromScene_index(int index)
{
	return nullptr;
}

void Inventory::addCharacterInScene(GameObject)
{
	//nope
}
	