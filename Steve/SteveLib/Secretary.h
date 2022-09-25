#pragma once
#include "Character.h"
#include "Notification.h"
#include <vector>

class Secretary : public Character
{
private:
	std::vector<Notification> notifications;

public:
	Secretary(std::string name = "Alex");
	void addNotification(std::string message);
	void addNotification(Notification &notification);
	std::string getTopNotification();
	std::vector<std::string> getAllTopNotification();
	void getNotifcation();
	void getAllNotifcations();
};