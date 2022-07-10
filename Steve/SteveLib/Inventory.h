#pragma once
#include "Scene.h"

class Inventory : public Scene
{
public:
	Inventory(Game* game);

	GameObject* getCharacterFromScene(std::string) override;
	GameObject* getCharacterFromScene_index(int index) override;
	void addCharacterInScene(GameObject) override;
};

