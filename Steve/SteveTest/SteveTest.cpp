#include "pch.h"
#include "CppUnitTest.h"
#include "Game.h"
#include "Inventory.h"
#include "EventManager.h"
#include "Character.h"
#include "Secretary.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SteveTest
{
	TEST_CLASS(SteveTest)
	{
	public:
		
		TEST_METHOD(SendAndRecieveEvents)	//KJE
		{
			//pretty self explanatory
			Game game;
			EventManager eventManager;
			GameObject testObject(&game, 1); //Creates a TV in the scene
			testObject.setEventManager(&eventManager);
			testObject.startInteraction(testObject.getName(), "TurnOn");

			Notification* notification = testObject.getNotification();
			std::string result = notification->getNotificationMessage();
			bool expectedResult = false;
			std::string message = notification->getNotificationMessage();
			if (message == "When the object was turned on it gave some clues")
			{
				expectedResult = true;
			}

			Assert::IsTrue(expectedResult);
		}

		TEST_METHOD(TestAllInteractions)
		{
			//all interacrtion functionalities: flavourtext, move item, turn on/off
			Game game;
			GameObject obj1(&game);

			//These are the interactions that should be available to us
			std::vector<std::string> interactions;
			interactions.push_back("Open");
			interactions.push_back("Move");
			interactions.push_back("TurnOn");
			interactions.push_back("TurnOff");
			interactions.push_back("Taste");
			
			//These are the interactions that are available to us
			std::vector<std::string> interactionTypes = obj1.listInteractionTypes();

			//Convert them to strings to compare them
			std::string expectedString;
			for (int i = 0; i < interactions.size(); i++)
			{
				expectedString += interactions[i];
			}
			
			std::string returnedString;
			for (int i = 0; i < interactionTypes.size(); i++)
			{
				returnedString += interactionTypes[i];
			}
		
			//Check whether they are the same or not
			Assert::AreEqual(expectedString.c_str(), returnedString.c_str());
		}

		TEST_METHOD(CharacterPlayerNotificationSystem)
		{
			//character sends a notification to the player/secretary
			Character character("Steve");
			Secretary secretary("Alex");

			//We ask the character "Steve" a question
			std::string answer = character.askQuestion("Hello, we are here to solve the mystery");
			
			//The secretary saves the answer to relay it to the player
			secretary.addNotification(answer);

			//If everything goes as plans, the charcter "Steve" should repond with this
			std::string expectedAnswer = "Thank you, I owe you all";
			std::string returnedAnswer = secretary.getTopNotification();

			Assert::AreEqual(expectedAnswer.c_str(), returnedAnswer.c_str());
		}

		TEST_METHOD(SecretaryNotificationRelay)
		{
			//access secretary options and relay to player
			Secretary secretary;
			for (int i = 0; i < 10; i++)
			{
				secretary.addNotification("Message: " + std::to_string(i));
			}

			for (int i = 0; i < 10; i++)
			{
				secretary.getNotifcation();
			}

			//If we have gone through every single notification there should be none left
			int messagesLeft = secretary.getNotificationAmount();
			Assert::AreEqual(0, messagesLeft);
		}

		TEST_METHOD(MoveGameElement)
		{
			//move game element from one scene to another
			Game game;

			GameObject* gameElement;
			GameObject* gameElementTwo;

			//Creates first scene and adds item to it
			game.createScene();
			game.setCurrentScene(0);
			game.getCurrentScene()->addItemInScene(&game);

			gameElement = game.getItemFromScene(0, WhichScene::e_currentScene);
			game.removeItem(0, WhichScene::e_currentScene); //Remove item from scene since we want to move it to another scene

			//Creates second scene and adds the item from first scene to it
			game.createScene();
			game.setCurrentScene(1);
			game.getCurrentScene()->addItemInScene(&game, gameElement);

			gameElementTwo = game.getItemFromScene(0, WhichScene::e_currentScene);

			bool sameItem = false;
			if (gameElement == gameElementTwo) sameItem = true;

			Assert::IsTrue(sameItem);
		}

		TEST_METHOD(FalseStatement)
		{
			//This creates a TV object
			GameObject* gameObj = new GameObject(nullptr, 1);
			
			//Here we interact with the ocbject
			gameObj->startInteraction("TV", "Taste");
			
			std::string expectedAnswer = "It worked!";
			std::string returnedAnswer = gameObj->returnInteractionMessage();
			
			bool areSame = expectedAnswer == returnedAnswer;

			Assert::IsFalse(areSame);
		}

		TEST_METHOD(TestInventory)
		{
			//Creates a game that can hold the inventory
			Game game;
			Inventory* inventory = game.getInventory();

			//Creates an item for us to test this use case
			GameObject* cheese = new GameObject(&game, 0);

			//Adds the cheese to the inventory
			inventory->addCharacterInScene(cheese);

			//Gets the latest added item from the inventory
			GameObject* itemInInventory = inventory->getItemFromScene_index(inventory->getGameObjectHolderSize() - 1);

			bool areEqual = cheese == itemInInventory;

			//Compares to see if we managed to add and retreive the same item
			Assert::IsTrue(areEqual);
		}
	};
}
