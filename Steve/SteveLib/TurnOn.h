#include "pch.h"
#pragma once
#include "Father.h"

class TurnOn : public Father
{
private:
	std::string message(std::string object);

public:
	TurnOn();
	TurnOn(std::string object);
};