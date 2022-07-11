#include "pch.h"
#pragma once
#include <iostream>
#include "Father.h"
#include "Open.h"
#include "Move.h"
#include "TurnOn.h"
#include "TurnOff.h"
#include "Taste.h"

class InteractionType : public Open, public Move, public TurnOn, public TurnOff, public Taste
{
private:
	InteractionType* interactionOptions;

	std::string* interactions;

public:
	InteractionType();

	std::string* listOfInteractions();
	void addInteractionOptions(InteractionType);
};

