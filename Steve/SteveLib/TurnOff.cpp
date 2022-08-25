#include "pch.h"
#include "TurnOff.h"

std::string TurnOff::message(std::string object)
{
	std::string outputMessage;

	if (object == "cheese")
	{
		outputMessage = "You can not turn off a cheese. Come on\n";
	}
	if (object == "TV")
	{
		int random = rand() % 2;
		if (random == 0)
		{
			outputMessage = "You turned off the TV\nIt got very quiet\n";
		}
		else
		{
			outputMessage = "You at least tried to turn off the TV\n";
		}
	}
	else if (object == "closet")
	{
		outputMessage = "How would you even do that?\n";
	}

	return outputMessage;
}

TurnOff::TurnOff()
	:Father("Nothing happened\n")
{
}

TurnOff::TurnOff(std::string object)
	:Father(message(object))
{
}