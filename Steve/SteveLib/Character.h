#include "pch.h"
#pragma once
#include "GameElement.h"


class Notification;

class Character : public GameElement
{
private:

public:
	Character();
	~Character();

	void sendPlayerNotification(Notification notification);
	void setMessage(Notification notification, std::string message);
	std::string askQuestion(std::string text);
};

