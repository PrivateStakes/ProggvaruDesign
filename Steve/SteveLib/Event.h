#include "pch.h"
#include "NotificationTypes_e.h"
#pragma once
#include <iostream>

class GameElement;
class Notification;

class Event
{
private:
	NotificationType eventType;
	int elementId;
	Notification* notification;

public:
	Event();
	Event(NotificationType typeOfEvent);
	~Event();

	void setEventType(NotificationType);
	NotificationType getEventType();
	bool createNotification(NotificationType notification);
	void clearNotification();
	Notification* readNotification() const;

	int getId() const;
	void setId(int);
};


