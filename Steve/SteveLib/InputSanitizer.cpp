#include "pch.h"
#include "InputSanitizer.h"
#include <iostream>

InputSanitizer::InputSanitizer()
{
}

InputSanitizer::~InputSanitizer()
{
}

std::string InputSanitizer::playerInputGeneral()
{
	std::string input;
	bool gameOn = true;

	while (gameOn == true)
	{
		std::cin >> input;

		if (std::cin.fail() != true) gameOn = false;
		else std::cout << "Invalid input" << std::endl;

		std::cin.clear();
		std::cin.ignore();
	}
	return input;
}

std::string InputSanitizer::playerInputGeneral(std::vector<std::string> oInput)
{
	std::string input;
	bool gameOn = true;

	while (gameOn == true)
	{
		std::cin >> input;

		for (size_t i = 0; i < oInput.size(); i++)
		{
			if (std::cin.fail() != true && input == oInput[i]) gameOn = false;
		}

		if (gameOn) std::cout << "Couldn't find that" << std::endl;

		std::cin.clear();
		std::cin.ignore();
	}
	return input;
}


bool numberChecker(const std::string& str)
{
	for (char const& c : str) 
	{
		if (std::isdigit(c)) return false;
	}
	return true;
}

bool letterChecker(const std::string& str)
{
	bool hasNoLetters = true;
	for (char const& c : str) 
	{
		if (!std::isdigit(c)) hasNoLetters = false;
	}
	return hasNoLetters;
}

int InputSanitizer::playerInputNumbers()
{
	std::string input;
	bool gameOn = true;

	while (gameOn == true)
	{
		std::cin >> input;
		
		if (std::cin.fail() != true && letterChecker(input)) gameOn = false;
		else std::cout << "Input may not contain letters" << std::endl;

		std::cin.clear();
		std::cin.ignore();
	}
	return std::stoi(input);
}

int InputSanitizer::playerInputNumbers(std::vector<int> oInput)
{
	std::string input;
	bool gameOn = true;

	while (gameOn == true)
	{
		std::cin >> input;

		for (size_t i = 0; i < oInput.size(); i++)
		{
			if (std::cin.fail() != true && letterChecker(input))
			{
				if (std::stoi(input) == oInput[i]) gameOn = false;
			}
		}
		if (gameOn) std::cout << "Couldn't find that" << std::endl;

		std::cin.clear();
		std::cin.ignore();
	}
	return std::stoi(input);
}

std::string InputSanitizer::playerInputText()
{
	std::string input;
	bool gameOn = true;

	while (gameOn == true)
	{
		std::cin >> input;

		if (std::cin.fail() != true && numberChecker(input)) gameOn = false;
		else std::cout << "Input may not be a number" << std::endl;

		std::cin.clear();
		std::cin.ignore();
	}
	return input;
}

std::string InputSanitizer::playerInputText(std::vector<std::string> oInput)
{
	std::string input;
	bool gameOn = true;

	while (gameOn == true)
	{
		std::cin >> input;

		for (size_t i = 0; i < oInput.size(); i++)
		{
			if (std::cin.fail() != true && numberChecker(input) && input == oInput[i]) gameOn = false;
		}
		
		if (gameOn) std::cout << "Couldn't find that" << std::endl;

		std::cin.clear();
		std::cin.ignore();
	}
	return input;
}
