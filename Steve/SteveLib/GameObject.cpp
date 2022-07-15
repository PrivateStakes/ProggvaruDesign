#include "pch.h"
#include "Game.h"
#include "GameObject.h"

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
		setName("YOU_FUCKED_UP");
		break;
	}

	myGame = game;
}

GameObject::~GameObject()
{
	myGame = nullptr;
}

std::vector<std::string> GameObject::listInteractionTypes()
{
	return listOfInteractions();
}

inline string GameObject::returnInteractionMessage()
{
	return interactionMessage;
}

inline void GameObject::startInteraction(string theInteractionType)
{
	if (theInteractionType == "Open")
	{
		Open open;
		interactionMessage = open.getMessage();
	}
	else if (theInteractionType == "Move")
	{
		Move move;
		interactionMessage = move.getMessage();
	}
	else if (theInteractionType == "TurnOn")
	{
		TurnOn turnOn;
		interactionMessage = turnOn.getMessage();
	}
	else if (theInteractionType == "TurnOff")
	{
		TurnOff turnOff;
		interactionMessage = turnOff.getMessage();
	}
	else if (theInteractionType == "Taste")
	{
		Taste taste;
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
	//myGame->getEventManager()->createEvent("ur mum gay");
	//myGame->getEventManager()->clearEvent("ur mum gay");
	//std::string interaction = interactionTypes->getInteraction();
	std::string interaction = "";
	if (interaction == "Open")
	{
		Open open;
		interactionMessage = open.getMessage();
	}
	else if (interaction == "Move")
	{
		Move move;
		interactionMessage = move.getMessage();
	}
	else if (interaction == "TurnOn")
	{
		TurnOn turnOn;
		interactionMessage = turnOn.getMessage();
	}
	else if (interaction == "TurnOff")
	{
		TurnOff turnOff;
		interactionMessage = turnOff.getMessage();
	}
	else if (interaction == "Taste")
	{
		Taste taste;
		interactionMessage = taste.getMessage();
	}
	else
	{
		interactionMessage = "E du dum i hövve? Detta kan du int gör";
	}
}

inline void GameObject::abortCurrentInteraction()
{

}
