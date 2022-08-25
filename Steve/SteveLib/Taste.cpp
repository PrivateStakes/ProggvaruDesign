#include "pch.h"
#include "Taste.h"

std::string Taste::message(std::string object)
{
	std::string outputMessage;

	if (object == "cheese")
	{
		int random = rand() % 2;
		if (random == 0)
		{
			outputMessage = "You tasted the cheese and realized that it did not taste right...\n";
		}
		else
		{
			outputMessage = "You tasted the cheese but it did not seem any different\n";
		}
	}
	else if (object == "TV")
	{
		outputMessage = "You thought tasting the TV would give you anything but decided against it\nwhen you realized that you are smarter than that\n";
	}
	else if (object == "closet")
	{
		outputMessage = "The closet tasted like wood.\nYou should have seen that coming\n";
	}

	return outputMessage;
}

Taste::Taste()
	:Father("Nothing happened\n")
{
}

Taste::Taste(std::string object)
	:Father(message(object))
{
}