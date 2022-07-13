#include "pch.h"
#pragma once
#include <iostream>
#include <vector>

class Event;

class EventManager
{
private:
	std::vector<Event*> eventContainer;

public:
	EventManager();
	~EventManager();

	Event* createEvent(std::string typeOfEvent);
	void listAffectedEvents(std::string eventCondition);
	void triggerEvents(std::string eventCondition);
	void clearEvent(std::string eventCondition);
	void clearEvent(Event *event);
};




