#include "pch.h"
#include "EventManager.h"
#include "GameElement.h"
#include "Notification.h"
#include "Event.h"

GameElement::GameElement()
{
}

GameElement::~GameElement()
{
	myEvent = nullptr;
}

bool GameElement::hasNotification()
{
	if (myEvent != nullptr && myEvent->readNotification() != nullptr) return true;
	else return false;
}

Notification* GameElement::getNotification()
{
	if (myEvent != nullptr && myEvent->readNotification() != nullptr) return myEvent->readNotification();
	else return nullptr;
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

void GameElement::generateEvent(EventManager* eventManager, NotificationType eventType)
{
	myEvent = eventManager->createEvent(eventType);
	myEvent->setId(id);
	this->myEvent->createNotification(eventType);
}

NotificationType GameElement::getEventType()
{
	NotificationType eventType = myEvent->getEventType();
	this->removeEvent();
	return eventType;
}

void GameElement::startEvent()
{
	if (this->myEvent != nullptr) 
	{ 
		std::cout << myEvent->readNotification()->getNotificationMessage() << std::endl; 
	}
}

void GameElement::removeEvent()
{
	myEvent = nullptr;
}
