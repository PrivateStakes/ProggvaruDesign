#include "pch.h"
#include "Notification.h"
#include "GameObject.h"
#include "Event.h"


Event::Event()
{
}

Event::Event(std::string typeOfEvent):typeOfEvent(typeOfEvent)
{
}

Event::~Event()
{
}

inline std::string Event::getTypeOfEvent()
{
	return typeOfEvent;
}

inline void Event::setTypeOfEvent(std::string _event)
{
	typeOfEvent = _event;
}

inline void Event::activate()
{
	std::cout << "Försöker du utföra ett event som inte har med GaMeElEmEnTs att göra?\n";
}

inline void Event::activate(GameObject* gameElement)
{
	/*
	GameObject* gameObjectPtr;
	gameObjectPtr = dynamic_cast<GameObject*>(gameElement);
	if (gameObjectPtr != nullptr)
	{
		gameObjectPtr->startCurrentInteraction();
	}
	*/

	gameElement->startCurrentInteraction();
}

inline void Event::createNotification(Notification notification)
{
	std::string notificationMessage;

	if (typeOfEvent == "pickup") notificationMessage = "You picked up an item!";
	else if ("lick") notificationMessage = ":(";
	else notificationMessage = "Unknown Event occured";

	notification.setMessage(notificationMessage);
}