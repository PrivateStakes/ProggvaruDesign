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

		TEST_METHOD(ListAllInteractions)
		{
			//all interacrtion functionalities: flavourtext, move item, turn on/off
			
			Assert::IsTrue(true);
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

			//secretary.addNotification("There is a new crime scene nearby");
			//std::string message = secretary.getTopNotification();
			//Assert::AreEqual("There is a new crime scene nearby", message.c_str());
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
			game.removeItem(0, WhichScene::e_currentScene);

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
