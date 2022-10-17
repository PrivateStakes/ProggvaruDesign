#include "pch.h"
#include "Notification.h"
#include "GameElement.h"
#include "Event.h"


Event::Event() :
	notification(nullptr)
{
}

Event::Event(NotificationType typeOfEvent) :
	eventType(typeOfEvent),
	notification(nullptr)
{
}

Event::~Event()
{
	if (notification != nullptr)
	{
		delete notification;
		notification = nullptr;
	}
}

void Event::setEventType(NotificationType input)
{
	eventType = input;
}

NotificationType Event::getEventType()
{
	return eventType;
}

bool Event::createNotification(NotificationType notificationType)
{
	std::string notificationMessage = "";

	switch (notificationType)
	{
	case NotificationType::addNewElement:
		notificationMessage = "A new thing appeared in a scene";
		break;
	case NotificationType::addNewScene:
		notificationMessage = "A new scene appeared";
		break;
	case NotificationType::addObjectToInventory:
		notificationMessage = "You added the item to your inventory";
		break;
	case NotificationType::elementMoved:
		notificationMessage = "Something moved to another scene";
		break;
	case NotificationType::elementOptionsExtended:
		notificationMessage = "There are now more interactions avaiable for something";
		break;
	case NotificationType::none:
		notificationMessage = "Unknown Event occured: event set to 'none'";
		break;
	default:
		notificationMessage = "Unknown Event occured: outside NotificationType parameters";
		break;
	}

	if (notificationMessage != "")
	{
		if (notification != nullptr)
		{
			delete notification;
			notification = nullptr;
		}
		
		notification = new Notification();
		notification->setMessage(notificationMessage, notificationType);
		return true;
	}
	else std::cerr << "ERROR: cannot create notification" << std::endl;
	return false;
}

void Event::clearNotification()
{
	if (notification != nullptr)
	{
		delete notification;
		notification = nullptr;
	}
}

Notification* Event::readNotification() const
{
	return notification;
}

int Event::getId() const
{
	return elementId;
}

void Event::setId(int input)
{
	elementId = input;
}

