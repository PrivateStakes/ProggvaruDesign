#include <iostream>
#include <random>
#include <string>
#include "Game.h"

int randomNumberGenerator(int low, int high)
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(low, high); // define the range

	return distr(gen);
}

int main()
{
	Game game = Game();
	InputSanitizer inputSanitizer;
	//game->Update();

	bool gameOn = true;

	while (gameOn)
	{
		std::cout << "There are " << game.getAllScenesSize() << " scenes available. Which one do you want to enter?" << std::endl;
		std::string availableScenes;
		std::vector<int> availableScenesQuantity;
		for (int i = 0; i < game.getAllScenesSize(); i++)
		{
			availableScenesQuantity.push_back(i + 1);
			if (i < game.getAllScenesSize() - 1) availableScenes += std::to_string(i + 1) + ", ";
			else availableScenes += "or " + std::to_string(i + 1) + '?';
		}
		std::cout << availableScenes << std::endl;

		game.setCurrentScene(inputSanitizer.playerInputNumbers(availableScenesQuantity) - 1);
		if (game.getCurrentScene() == nullptr) std::cout << "Invalid scene!" << std::endl;

		//generates a random amount of objects in the room
		//NOTE: temporary, should be done individually for all rooms (except the Inverntory) upon generation
		switch (randomNumberGenerator(0, 2))
		{
		case 0:
			game.getCurrentScene()->addItemInScene(&game);
			break;

		case 1:
			game.getCurrentScene()->addItemInScene(&game);
			game.getCurrentScene()->addItemInScene(&game);
			break;

		default:
			break;
		}

		bool inScene = true;
		while (inScene)
		{
			std::string wordQuantity = "";
			std::string wordTense = "is ";
			if (game.getCurrentScene()->getGameObjectHolderSize() > 1 || game.getCurrentScene()->getGameObjectHolderSize() == 0)
			{
				wordQuantity = "s";
				wordTense = "are ";
			}
			std::cout << "In this scene there " << wordTense << game.getCurrentScene()->getGameObjectHolderSize() << " object" << wordQuantity << " available," << std::endl;
			
			if (game.getCurrentScene()->getCharacterHolderSize() > 1 || game.getCurrentScene()->getCharacterHolderSize() == 0) wordQuantity = "s";
			std::cout << "and " << game.getCurrentScene()->getCharacterHolderSize() << " character" << wordQuantity << " available." << std::endl;
			


			inputSanitizer.playerInputGeneral();
		}
	}

	return 0;
}