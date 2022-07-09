#include "pch.h"
#include "Notification.h"

Notification::Notification()
{
}

Notification::~Notification()
{
}

inline std::string Notification::getNotificationMessage()
{
	return message;
}

inline void Notification::setMessage(std::string newMessage)
{
	message = newMessage;
}