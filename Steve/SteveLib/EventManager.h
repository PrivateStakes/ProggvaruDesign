#include "pch.h"
#pragma once
#include <iostream>

class Event;
class Notification;

class EventManager
{
private:
	Event** currentEvent;
	int amountOfEvents;

public:
	EventManager();
	~EventManager();

	void createEvent(std::string typeOfEvent);
	void listAffectedEvents(std::string eventCondition);
	void triggerEvents(std::string eventCondition);
	void clearEvent(std::string eventCondition);
	void clearEvent(Event *event);
};




