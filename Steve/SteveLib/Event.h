#include "pch.h"
#pragma once
#include <iostream>

class GameObject;
class Notification;

class Event
{
private:
	std::string typeOfEvent;

public:
	Event();
	Event(std::string typeOfEvent);
	~Event();

	std::string getTypeOfEvent();
	void setTypeOfEvent(std::string _event);
	void activate();
	void activate(GameObject* gameElement);
	void createNotification(Notification notification);
};

