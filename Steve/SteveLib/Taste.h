#include "pch.h"
#pragma once
#include "Father.h"

class Taste : public Father
{
private:
	std::string message(std::string object);

public:
	Taste();
	Taste(std::string object);
};