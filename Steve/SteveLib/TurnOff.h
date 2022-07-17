#include "pch.h"
#pragma once
#include "Father.h"

class TurnOff : public Father
{
private:
	std::string message(std::string object);

public:
	TurnOff();
	TurnOff(std::string object);
};