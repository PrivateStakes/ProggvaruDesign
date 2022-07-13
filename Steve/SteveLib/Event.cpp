#include "pch.h"
#include "Notification.h"
#include "GameElement.h"
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
	std::cout << "Missing bound game element\n";
}

inline void Event::activate(GameElement* gameElement)
{
	//if(gameElement != nullptr) gameElement->startCurrentInteraction(); //fix
}

inline void Event::createNotification(Notification notification)
{
	std::string notificationMessage;
	NotificationType notificationType = NotificationType::none;

	if (typeOfEvent == "pickup")
	{
		notificationMessage = "You picked up an item!";
		notificationType = NotificationType::addObjectToInventory;
	}
	else if ("lick") notificationMessage = ":(";
	else notificationMessage = "Unknown Event occured";

	notification.setMessage(notificationMessage, notificationType);
}
int Event::getId() const
{
	return elementId;
}
void Event::setId(int input)
{
	elementId = input;
}

