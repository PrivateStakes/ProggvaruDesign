#include "pch.h"
#pragma once
#include <iostream>

class EventManager;

class GameElement
{
private:
	int id;
	std::string name;

public:
	GameElement();
	~GameElement();

	std::string getName();
	void generateEvent(EventManager eventManager, std::string typeOfEvent);
};

