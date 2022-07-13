#include "pch.h"
#pragma once
#include <iostream>

class GameElement;
class Notification;

class Event
{
private:
	std::string typeOfEvent;
	GameElement* meElement;
	int elementId;

public:
	Event();
	Event(std::string typeOfEvent);
	~Event();

	std::string getTypeOfEvent();
	void setTypeOfEvent(std::string _event);
	void activate();
	void activate(GameElement* gameElement);
	void createNotification(Notification notification);

	int getId() const;
	void setId(int);
};

