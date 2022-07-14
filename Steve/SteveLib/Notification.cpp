#include "pch.h"
#include "Notification.h"

Notification::Notification()
{
}

Notification::~Notification()
{
}

std::string Notification::getNotificationMessage()
{
	return message;
}

inline void Notification::setMessage(std::string newMessage, NotificationType input)
{
	message = newMessage;
	notificationType = input;
}