#include "pch.h"
#pragma once
#include <iostream>

class Notification
{
private:
	std::string message;

public:
	Notification();
	~Notification();

	std::string getNotificationMessage();
	void setMessage(std::string message);
};

