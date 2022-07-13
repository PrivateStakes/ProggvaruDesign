#include "pch.h"
#pragma once
#include <iostream>
#include "GameElement.h"
#include "InteractionType.h"

using namespace std;
class Game;

class GameObject : public GameElement, public InteractionType
{
private:
	InteractionType* interactionTypes;
	std::string interactionMessage;
	Game* myGame;

public:
	GameObject(Game* game);
	~GameObject();

	std::vector<std::string> listInteractionTypes();
	string returnInteractionMessage();
	void startInteraction(string theInteractionType);
	void listCurrentInteractionOptions();
	void setCurrentInteractionOptions(string theOptions);
	void startCurrentInteraction();
	void abortCurrentInteraction();
};