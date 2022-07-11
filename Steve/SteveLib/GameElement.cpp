#include "pch.h"
#include "EventManager.h"
#include "GameElement.h"

GameElement::GameElement()
{
}

GameElement::~GameElement()
{
}

std::string GameElement::getName()
{
	return name;
}

inline void GameElement::generateEvent(EventManager eventManager, std::string typeOfEvent)
{
	eventManager.createEvent(typeOfEvent);
}