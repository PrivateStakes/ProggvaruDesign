#include "pch.h"
#include "Character.h"
#include "Notification.h"

Character::Character(std::string characterName)
{
	this->setName(characterName);
}

Character::~Character()
{
}

inline void Character::sendPlayerNotification(Notification notification)
{
	std::cout << notification.getNotificationMessage();
}

inline void Character::setMessage(Notification notification, std::string message)
{
	notification.setMessage(message, (NotificationType)0);
}

inline std::string Character::askQuestion(std::string text)
{
	std::string response = "";

	if (text == "hello?") response = "hello luv";
	else response = "Bad choice bitzzz";

	return response;
}
