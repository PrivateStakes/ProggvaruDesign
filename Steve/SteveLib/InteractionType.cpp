#include "pch.h"
#include "InteractionType.h"

InteractionType::InteractionType()
{
	interactionOptions = new InteractionType;

	interactions = new std::string[5];
	interactions[0] = "Open";
	interactions[1] = "Move";
	interactions[2] = "TurnOn";
	interactions[3] = "TurnOff";
	interactions[4] = "Taste";
}

inline std::string* InteractionType::listOfInteractions()
{
	return interactions;
}