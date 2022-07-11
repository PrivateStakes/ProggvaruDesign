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

void GameElement::setName(std::string input)
{
	name = input;
}

inline void GameElement::generateEvent(EventManager eventManager, std::string typeOfEvent)
{
	eventManager.createEvent(typeOfEvent);
}