#include <iostream>
#include <string>
#include "Game.h"

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
		for (int i = 0; i < game.getAllScenesSize(); i++)
		{
			if (i < game.getAllScenesSize() - 1) availableScenes += std::to_string(i + 1) + ", ";
			else availableScenes += "or " + std::to_string(i + 1) + '?';
		}
		std::cout << availableScenes << std::endl;

		game.setCurrentScene(inputSanitizer.playerInputNumbers(1, game.getAllScenesSize()) - 1);
		if (game.getCurrentScene() == nullptr) std::cout << "Invalid scene!" << std::endl;

		//generates a random amount of objects in the room
		//NOTE: temporary, should be done individually for all rooms (except the Inverntory) upon generation
		switch (game.randomNumberGenerator(0, 2))
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
			
			std::cout << game.getCurrentScene()->listAllGameObjects();
			int exitIndex = game.getCurrentScene()->getGameObjectHolderSize() + game.getCurrentScene()->getCharacterHolderSize() + 1;
			std::cout << std::to_string(exitIndex) << " exit" << std::endl;

			int playerInput = inputSanitizer.playerInputNumbers(1, exitIndex);
			if (playerInput == exitIndex) inScene = false;
			else
			{
				//for (int i = 0; i < game.getCurrentScene()->getItemFromScene_index(playerInput)->listInteractionTypes().size(); i++)
				//{
				//	//std::cout << std::to_string(i + 1) << " " << game.getCurrentScene()->getItemFromScene_index(playerInput)->listInteractionTypes()[i] << std::endl;
				//}
				
			}
			//else std::cout << game.getCurrentScene()->getItemFromScene_index(playerInput);

			//std::system("CLS");
		}
	}

	return 0;
}