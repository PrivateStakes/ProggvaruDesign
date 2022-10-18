#include "pch.h"
#pragma once
#include <iostream>
#include "GameElement.h"
#include "InteractionType.h"

using namespace std;
class Game;
class EventManager;

class GameObject : public GameElement, public InteractionType
{
private:
	std::string interactionMessage;
	Game* myGame;
	bool isOn = false;

public:
	GameObject(Game* game);
	GameObject(Game* game, int number);
	GameObject(Game* game, GameObject* other);
	//GameObject(Game* game, GameObject* gameObject);
	~GameObject();

	std::vector<std::string> listInteractionTypes();
	string returnInteractionMessage();
	void startInteraction(string object, string theInteractionType);
	void listCurrentInteractionOptions();
	void setCurrentInteractionOptions(string theOptions);
	void startCurrentInteraction();
	void abortCurrentInteraction();

	std::string getInteractionMessage();
	bool getIsOn();

};