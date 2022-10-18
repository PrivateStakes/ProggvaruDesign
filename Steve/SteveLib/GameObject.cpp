#include "pch.h"
#include "Game.h"
#include "GameObject.h"
#include "EventManager.h"

enum
{
	cheese,
	TV,
	closet
};

GameObject::GameObject(Game* game)
{
	switch (game->randomNumberGenerator(0, 2))
	{
	case cheese:
		setName("cheese");
		break;

	case TV:
		setName("TV");
		break;

	case closet:
		setName("closet");
		break;

	default:
		setName("N/A");
		break;
	}

	myGame = game;
}

GameObject::GameObject(Game* game, int number)
{
	switch (number)
	{
	case cheese:
		setName("cheese");
		break;

	case TV:
		setName("TV");
		break;

	case closet:
		setName("closet");
		break;

	default:
		setName("N/A");
		break;
	}

	myGame = game;
}

GameObject::GameObject(Game* game, GameObject* other)
{
	myGame = game;
	isOn = other->getIsOn();
	interactionMessage = other->getInteractionMessage();

	setId(other->getId());
	setName(other->getName());
}

GameObject::~GameObject()
{
	myGame = nullptr;
}

std::vector<std::string> GameObject::listInteractionTypes()
{
	return listOfInteractions();
}

string GameObject::returnInteractionMessage()
{
	return interactionMessage;
}

void GameObject::startInteraction(string object, string theInteractionType)
{
	if (theInteractionType == "Open")
	{
		Open open(this->getName());
		interactionMessage = open.getMessage();
	}
	else if (theInteractionType == "Move")
	{
		Move move(this->getName());
		interactionMessage = move.getMessage();
	}
	else if (theInteractionType == "TurnOn")
	{
		TurnOn turnOn(this->getName());
		interactionMessage = turnOn.getMessage();
	}
	else if (theInteractionType == "TurnOff")
	{
		TurnOff turnOff(this->getName());
		interactionMessage = turnOff.getMessage();
	}
	else if (theInteractionType == "Taste")
	{
		Taste taste(this->getName());
		interactionMessage = taste.getMessage();
	}
	else
	{
		interactionMessage = "E du dum i hövve? Detta kan du int gör";
	}
}

inline void GameObject::listCurrentInteractionOptions()
{
	cout << "https://cdn.discordapp.com/attachments/272801400029708288/844563127994679316/unknown.png";
}

inline void GameObject::setCurrentInteractionOptions(string theOptions)
{
	cout << theOptions;
}

inline void GameObject::startCurrentInteraction()
{
	
}

inline void GameObject::abortCurrentInteraction()
{

}

std::string GameObject::getInteractionMessage()
{
	return interactionMessage;
}

bool GameObject::getIsOn()
{
	return isOn;
}