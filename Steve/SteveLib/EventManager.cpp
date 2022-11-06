#include "pch.h"
#include "Notification.h"
#include "Event.h"
#include "EventManager.h"
#include "GameElement.h"

EventManager::EventManager()
{

}

EventManager::~EventManager()
{
	for (int i = 0; i < eventContainer.size(); i++)
	{
		delete eventContainer[i];
		eventContainer[i] = nullptr;
	}
}

Event* EventManager::createEvent(NotificationType eventType)
{
	eventContainer.push_back(new Event(eventType));
	return eventContainer.back();
}

Notification* EventManager::getNotification(int index)
{
	if (eventContainer[index] != nullptr) return eventContainer[index]->readNotification();
	else return nullptr;
}

void EventManager::listAffectedEvents(std::string eventCondition)
{

}

void EventManager::triggerEvents(NotificationType eventCondition)
{
	for (int i = 0; i < eventContainer.size(); i++)
	{
		if (eventCondition == eventContainer[i]->getEventType()) eventContainer[i]->createNotification(eventCondition);
	}
}

bool EventManager::triggerSpecificElement(int input)
{
	bool eventTriggered = false;

	for (int i = 0; i < eventContainer.size(); i++)
	{
		if (eventContainer[i]->getId() == (int)input)
		{
			eventContainer[i]->createNotification(NotificationType::none);
		}
	}

	return eventTriggered;
}

//add functionality where the host of the event must be parsed in here to remove it
inline void EventManager::clearEvent(GameElement &eventOwner)
{
	for (int i = 0; i < eventContainer.size(); i++)
	{
		if (eventOwner.getId() == eventContainer[i]->getId())
		{
			if (i != eventContainer.size() - 1) eventContainer[i] = new Event(*(eventContainer.back()));
			
			eventContainer.back() = nullptr;
			delete eventContainer.back();
			eventContainer.pop_back();

			eventOwner.removeEvent();
		}
	}

}