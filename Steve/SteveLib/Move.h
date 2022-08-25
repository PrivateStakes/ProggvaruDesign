#include "pch.h"
#pragma once
#include "Father.h"

class Move : public Father
{
private:
	std::string message(std::string object);

public:
	Move();
	Move(std::string object);
};