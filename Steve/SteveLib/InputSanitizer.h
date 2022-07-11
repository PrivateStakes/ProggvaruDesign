#pragma once
#include "pch.h"
#include <string>
#include <vector>

class InputSanitizer
{
private:


public:
	InputSanitizer();
	~InputSanitizer();

	std::string playerInputGeneral();	//returns whatever the player types
	std::string playerInputGeneral(std::vector<std::string>);	//returns whatever the player types

	int playerInputNumbers();	//returns a player-input int which cannot contain letter
	int playerInputNumbers(std::vector<int> oInput);	//returns an int identical to one in an array which the player has repeated
	int playerInputNumbers(int, int);	//takes player input based on a certain range

	std::string playerInputText();	//returns a player-input string which cannot contain numbers
	std::string playerInputText(std::vector<std::string> oInput);	//returns the string identical to one in an array which the player has repeated
};

