#include "pch.h"
#include "Father.h"

Father::Father(std::string message)
	:message(message)
{
}

std::string Father::getMessage()
{
	return message;
}