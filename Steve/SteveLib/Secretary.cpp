#include "pch.h"
#include "Secretary.h"

Secretary::Secretary(std::string name)
	:Character(name)
{

}


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

std::string Secretary::getTopNotification()
{
	if (notifications.size() == 0)
	{
		std::cout << "No messages\n";
		return "";
	}
	std::string str;
	str = notifications[0].getNotificationMessage();
	for (int i = 0; i < notifications.size() - 1; i++)
	{
		notifications[i] = notifications[i + 1];
	}
	notifications.pop_back();
	return str;
}

std::vector<std::string> Secretary::getAllTopNotification()
{
	std::vector<std::string> messages;
	if (notifications.size() == 0)
	{
		std::cout << "No messages\n";
		return messages;
	}
	for (int i = 0; i < notifications.size(); i++)
	{
		messages.emplace_back(notifications[i].getNotificationMessage());
	}
	for (int i = 0; i < notifications.size(); i++)
	{
		notifications.pop_back();
	}
	return messages;
}

void Secretary::getNotifcation()
{
	if (notifications.size() == 0) 
	{
		std::cout << "No messages\n"; 
		return;
	}
	std::cout << notifications[0].getNotificationMessage() << std::endl;
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
		std::cout << notifications[i].getNotificationMessage() << std::endl;
	}
	for (int i = 0; i < notifications.size(); i++)
	{
		notifications.pop_back();
	}
}

int Secretary::getNotificationAmount()
{
	return notifications.size();
}