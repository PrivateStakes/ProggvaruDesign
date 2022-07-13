#include "pch.h"
#include "Notification.h"
#include "Event.h"
#include "EventManager.h"

EventManager::EventManager()
{

}

EventManager::~EventManager()
{
}

inline Event* EventManager::createEvent(std::string typeOfEvent)
{
	eventContainer.push_back(new Event(typeOfEvent));
	return eventContainer[eventContainer.size()-1];
}

inline void EventManager::listAffectedEvents(std::string eventCondition)
{
}

inline void EventManager::triggerEvents(std::string eventCondition)
{
	for (int i = 0; i < eventContainer.size(); i++)
	{
		if (eventCondition == eventContainer[i]->getTypeOfEvent()) eventContainer[i]->activate();
	}

}

inline void EventManager::clearEvent(std::string eventCondition)
{
	for (int i = 0; i < eventContainer.size(); i++)
	{
		if (eventCondition == eventContainer[i]->getTypeOfEvent())
		{
			if (i != eventContainer.size() - 1) eventContainer[i] = new Event(*(eventContainer.back()));
			
			eventContainer.back() = nullptr;
			delete eventContainer.back();
			eventContainer.pop_back();
		}
	}

}

inline void EventManager::clearEvent(Event* theEventIWantToDelete)
{
	for (int i = 0; i < eventContainer.size(); i++)
	{
		if (theEventIWantToDelete == eventContainer[i])
		{
			if (i != eventContainer.size() - 1) eventContainer[i] = new Event(*(eventContainer.back()));

			eventContainer.back() = nullptr;
			delete eventContainer.back();
			eventContainer.pop_back();
		}
	}
}