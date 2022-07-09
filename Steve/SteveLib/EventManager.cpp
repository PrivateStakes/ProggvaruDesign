#include "pch.h"
#include "Notification.h"
#include "Event.h"
#include "EventManager.h"

EventManager::EventManager()
	:amountOfEvents(0)
{
	currentEvent = nullptr;
	currentEvent = new Event * [amountOfEvents] {nullptr};
}

EventManager::~EventManager()
{
}

inline void EventManager::createEvent(std::string typeOfEvent)
{
	currentEvent[amountOfEvents++] = new Event(typeOfEvent);
}

inline void EventManager::listAffectedEvents(std::string eventCondition)
{
}

inline void EventManager::triggerEvents(std::string eventCondition)
{
	for (int i = 0; i < amountOfEvents; i++)
	{
		if (eventCondition == currentEvent[i]->getTypeOfEvent()) currentEvent[i]->activate();
	}

}

inline void EventManager::clearEvent(std::string eventCondition)
{
	for (int i = 0; i < amountOfEvents; i++)
	{
		if (eventCondition == currentEvent[i]->getTypeOfEvent())
		{
			if (i != 0 || i != amountOfEvents - 1)
			{
				delete currentEvent[i];
				currentEvent[i] = nullptr;
				currentEvent[i] = currentEvent[amountOfEvents - 1];
				currentEvent[amountOfEvents - 1] = nullptr;
				amountOfEvents--;
			}

		}
	}

}

inline void EventManager::clearEvent(Event* theEventIWantToDelete)
{
	for (int i = 0; i < amountOfEvents; i++)
	{
		if (theEventIWantToDelete == currentEvent[i])
		{
			if (i != 0 || i != amountOfEvents - 1)
			{
				delete currentEvent[i];
				currentEvent[i] = nullptr;
				currentEvent[i] = currentEvent[amountOfEvents - 1];
				currentEvent[amountOfEvents - 1] = nullptr;
				amountOfEvents--;
			}

		}
	}
}