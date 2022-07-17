#include "pch.h"
#pragma once
#include "Father.h"

class Open : public Father
{
private:
	std::string message(std::string object);

public:
	Open();
	Open(std::string object);
};