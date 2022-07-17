#include "pch.h"
#include "Open.h"

std::string Open::message(std::string object)
{
	std::string outputMessage;

	if (object == "cheese")
	{
		outputMessage = "You can not open a cheese unfortunately\n";
	}
	else if (object == "TV")
	{
		outputMessage = "Please do not try to open up a TV.\nIt will break\n";
	}
	else if (object == "closet")
	{
		int random = rand() % 2;
		if (random == 0)
		{
			outputMessage = "You opened up the closet and found some more evidence inside!\n";
		}
		else
		{
			outputMessage = "You opened up the closet but found nothing more than ordinary clothes inside\n";
		}
	}

	return outputMessage;
}

Open::Open()
	:Father("Nothing happened")
{
}

Open::Open(std::string object)
	:Father(message(object))
{
}