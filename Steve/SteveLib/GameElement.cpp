#include "pch.h"
#include "EventManager.h"
#include "GameElement.h"
#include "Event.h"

GameElement::GameElement()
{
}

GameElement::~GameElement()
{
}

int GameElement::getId() const
{
	return id;
}

void GameElement::setId(int input)
{
	id = input;
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
	myEvent = eventManager.createEvent(typeOfEvent);
	myEvent->setId(id);
}