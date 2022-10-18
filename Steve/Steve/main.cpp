#include <iostream>
#include <string>
#include "Game.h"

int main()
{
	Game game;
	InputSanitizer inputSanitizer;

	game.createScene();
	game.createScene();
	game.createScene();

	for (int i = 0; i < game.getAllScenesSize(); i++)
	{
		for (int j = 0; j < game.randomNumberGenerator(1, 5); j++)
		{
			game.getAllScenes()[i]->addItemInScene(&game);
		}
	}

	bool gameOn = true;
	while (gameOn)
	{
		std::cout << "There are " << game.getAllScenesSize() << " scenes available. Which one do you want to enter?" << std::endl;
		std::string availableScenes;
		for (int i = 0; i < game.getAllScenesSize(); i++)
		{
			if (i < game.getAllScenesSize() - 1) availableScenes += std::to_string(i + 1) + ", ";
			else if (game.getAllScenesSize() > 1)availableScenes += "or " + std::to_string(i + 1) + '?';
			else availableScenes += std::to_string(i + 1) + " is the only one available";
		}
		std::cout << availableScenes << std::endl;

		game.setCurrentScene(inputSanitizer.playerInputNumbers(1, game.getAllScenesSize()) - 1);
		if (game.getCurrentScene() == nullptr) std::cout << "Invalid scene!" << std::endl;

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
			
			std::cout << game.getCurrentScene()->listAllGameObjects();
			const int exitIndex = game.getCurrentScene()->getGameObjectHolderSize() + game.getCurrentScene()->getCharacterHolderSize() + 1;
			std::cout << std::to_string(exitIndex) << " exit" << std::endl;

			int playerInput = inputSanitizer.playerInputNumbers(1, exitIndex) - 1;
			if (playerInput == exitIndex - 1) inScene = false;
			else game.handleInteractions(inputSanitizer, playerInput);

			std::system("CLS");
		}
	}

	return 0;
}