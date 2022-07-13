#include "pch.h"
#pragma once
#include <iostream>
#include "NotificationTypes_e.h"

class Notification
{
private:
	std::string message;
	NotificationType notificationType;

public:
	Notification();
	~Notification();

	std::string getNotificationMessage();
	void setMessage(std::string message, NotificationType);
};

