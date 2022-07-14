#include "pch.h"
#include "NotificationTypes_e.h"
#pragma once
#include <iostream>
#include <vector>

class Event;
class GameElement;

class EventManager
{
private:
	std::vector<Event*> eventContainer;

public:
	EventManager();
	~EventManager();

	Event* createEvent(NotificationType);
	void listAffectedEvents(std::string eventCondition);
	void triggerEvents(NotificationType eventCondition);
	bool triggerSpecificElement(int);	//requires ID of element

	void clearEvent(GameElement &eventOwner);
};




