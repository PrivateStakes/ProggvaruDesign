#include "pch.h"
#include "InteractionType.h"

InteractionType::InteractionType()
{
	//interactionOptions = new InteractionType;

	interactions.push_back("Open");
	interactions.push_back("Move");
	interactions.push_back("TurnOn");
	interactions.push_back("TurnOff");
	interactions.push_back("Taste");
}

std::vector<std::string> InteractionType::listOfInteractions()
{
	return interactions;
}

void InteractionType::addInteractionOptions(InteractionType input)
{
	interactionOptions.push_back(input);
}
