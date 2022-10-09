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

void Character::sendPlayerNotification(Notification notification)
{
	std::cout << notification.getNotificationMessage();
}

void Character::setMessage(Notification notification, std::string message)
{
	notification.setMessage(message, (NotificationType)0);
}

std::string Character::askQuestion(std::string text)
{
	std::string response = "";

	if (text == "Hello, we are here to solve the mystery") response = "Thank you, I owe you all";
	else response = "What did you say again?";

	return response;
}
