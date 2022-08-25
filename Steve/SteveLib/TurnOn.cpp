#include "pch.h"
#include "TurnOn.h"

std::string TurnOn::message(std::string object)
{
	std::string outputMessage;

	if (object == "cheese")
	{
		outputMessage = "...try again\n";
	}
	else if (object == "TV")
	{
		int random = rand() % 2;
		if (random == 0)
		{
			outputMessage = "You turned on the TV\nIt got very loud in here\n";
		}
		else
		{
			outputMessage = "You tried to turn on the TV but something got wrong\n";
		}
	}
	else if (object == "closet")
	{
		outputMessage = "It did not work\n";
	}

	return outputMessage;
}

TurnOn::TurnOn()
	:Father("Nothing happened\n")
{
}

TurnOn::TurnOn(std::string object)
	:Father(message(object))
{
}