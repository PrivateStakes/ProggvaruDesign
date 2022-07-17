#include "pch.h"
#include "Move.h"
#include <iostream>

std::string Move::message(std::string object)
{
	std::string outputMessage;

	if (object == "cheese")
	{
		outputMessage = "You decided to move the cheese.\nIt did not make any difference\n";
	}
	else if (object == "TV")
	{
		int random = rand() % 2;
		if (random == 0)
		{
			outputMessage = "You decided to move the TV and found a secret passage behind it!\n";
		}
		else
		{
			outputMessage = "You decided to move the TV.\nNothing was behind it\n";
		}
	}
	else if (object == "closet")
	{
		int random = rand() % 2;
		if (random == 0)
		{
			outputMessage = "You decided to move the closet.\nIt was very heavy but you found a secret passage behind it!\n";
		}
		else
		{
			outputMessage = "You decided to move the closet.\nNothing was behind it\n";
		}
	}

	return outputMessage;
}

Move::Move()
	:Father("Nothing happened")
{

}

Move::Move(std::string object)
	:Father(message(object))
{
}