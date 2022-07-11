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
//		game.getCurrentScene()->addItemInScene(&game);

		bool inScene = true;
		while (inScene)
		{
			//std::cout << "In this scene there are " << currentScene->listAllGameObjects() << " objects available," << std::endl;
			//std::cout << "and " << currentScene->listAllCharacters() << " characters available." << std::endl;



		}
	}

	return 0;
}