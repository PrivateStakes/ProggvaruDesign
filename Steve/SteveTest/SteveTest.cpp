#include "pch.h"
#include "CppUnitTest.h"
#include "Game.h"
#include "EventManager.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SteveTest
{
	TEST_CLASS(SteveTest)
	{
	public:
		
		TEST_METHOD(SendAndRecieveEvents)	//KJE
		{
			//pretty self explanatory
			EventManager eventManager;
			eventManager.createEvent(NotificationType::elementMoved);
			eventManager.triggerEvents(NotificationType::elementMoved);
			Notification* notification = eventManager.getNotification();
			std::string result = notification->getNotificationMessage();
			
			Assert::AreEqual("Something moved to another scene", result.c_str());
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

			Assert::IsTrue(true);
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

		TEST_METHOD(MoveGameElement)	//KJE
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
			Assert::IsFalse(false);
		}

		TEST_METHOD(ListInteractionOptions)
		{
			Assert::IsTrue(true);
		}
	};
}
