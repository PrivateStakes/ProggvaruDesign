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
			const int exitIndex = game.getCurrentScene()->getGameObjectHolderSize() + game.getCurrentScene()->getCharacterHolderSize() + 1;
			std::cout << std::to_string(exitIndex) << " exit" << std::endl;

			int playerInput = inputSanitizer.playerInputNumbers(1, exitIndex);
			if (playerInput == exitIndex) inScene = false;
			else
			{
				//Put all this shit in an external function so that he interaction types can increment infinitely

				bool interactinWithObject = true;
				while (interactinWithObject)
				{
					const int numberOfInteractions = game.getCurrentScene()->getItemFromScene_index(playerInput - 1)->listInteractionTypes().size();
					for (int i = 0; i < numberOfInteractions; i++)
					{
						std::cout << std::to_string(i + 1) << " " << game.getCurrentScene()->getItemFromScene_index(playerInput - 1)->listInteractionTypes()[i] << std::endl;
					}
					std::cout << std::to_string(numberOfInteractions + 1) << " return to scene" << std::endl;
					
					int playerInputInteraction = inputSanitizer.playerInputNumbers(1, numberOfInteractions + 1);
					if (playerInputInteraction == numberOfInteractions + 1) interactinWithObject = false;
					else
					{
						//access interaction type flavour text

						std::cout << "you did the thing" << std::endl;
					}
				}
			}

			std::system("CLS");
		}
	}

	return 0;
}