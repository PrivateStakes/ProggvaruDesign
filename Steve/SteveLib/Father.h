#include "pch.h"
#pragma once
#include <iostream>

class Father
{
private:
	std::string message;

public:
	Father(std::string message);
	std::string getMessage();
};

