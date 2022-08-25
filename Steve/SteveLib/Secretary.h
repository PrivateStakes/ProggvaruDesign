#pragma once
#include "Character.h"
#include "Notification.h"
#include <vector>

class Secretary : public Character
{
private:
	std::vector<Notification> notifications;

public:
	void addNotification(std::string message);
	void addNotification(Notification &notification);
	void getNotifcation();
	void getAllNotifcations();
};