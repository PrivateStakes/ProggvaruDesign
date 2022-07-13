#include "pch.h"
#pragma once
#include <iostream>

class EventManager;
class Event;

class GameElement
{
private:
	int id;
	std::string name;
	Event* myEvent;	//always check if my event is a nullptr, and do nothing if that's the case

protected:
	void setName(std::string);

public:
	GameElement();
	~GameElement();

	int getId() const;
	void setId(int);
	std::string getName();
	void generateEvent(EventManager eventManager, std::string typeOfEvent);
};


