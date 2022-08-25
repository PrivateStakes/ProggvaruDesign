#include "pch.h"
#include "Secretary.h"

void Secretary::addNotification(std::string message)
{
	Notification notification;
	notification.setMessage(message, NotificationType::none);
	notifications.push_back(notification);
}

void Secretary::addNotification(Notification& notification)
{
	notifications.push_back(notification);
}

void Secretary::getNotifcation()
{
	if (notifications.size() == 0) 
	{
		std::cout << "No messages\n"; 
		return;
	}
	std::cout << notifications[0].getNotificationMessage();
	for (int i = 0; i < notifications.size()-1; i++)
	{
		notifications[i] = notifications[i + 1];
	}
	notifications.pop_back();
}

void Secretary::getAllNotifcations()
{
	if (notifications.size() == 0)
	{
		std::cout << "No messages\n";
		return;
	}
	
	for (int i = 0; i < notifications.size(); i++)
	{
		std::cout << notifications[i].getNotificationMessage();
	}
	for (int i = 0; i < notifications.size(); i++)
	{
		notifications.pop_back();
	}
}
