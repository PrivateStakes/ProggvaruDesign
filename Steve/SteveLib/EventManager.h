#include "pch.h"
#include "NotificationTypes_e.h"
#pragma once
#include <iostream>
#include <vector>

class Event;
class GameElement;
class Notification;

class EventManager
{
private:
	std::vector<Event*> eventContainer;

public:
	EventManager();
	~EventManager();

	Event* createEvent(NotificationType);
	Notification* getNotification(int index = 0);
	void listAffectedEvents(std::string eventCondition);
	void triggerEvents(NotificationType eventCondition);
	bool triggerSpecificElement(int);	//requires ID of element

	void clearEvent(GameElement &eventOwner);
};




