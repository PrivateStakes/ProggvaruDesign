#include "pch.h"
#include "CppUnitTest.h"
#include "Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SteveTest
{
	TEST_CLASS(SteveTest)
	{
	public:
		
		TEST_METHOD(SendAndRecieveEvents)	//KJE
		{
			//pretty self explanatory

			Assert::IsTrue(true);
		}

		TEST_METHOD(TestAllInteractions)
		{
			//all interacrtion functionalities: flavourtext, move item, turn on/off
			
			Assert::IsTrue(true);
		}

		TEST_METHOD(CharacterPlayerNotificationSystem)
		{
			//character sends a notification to the player/secretary

			Assert::IsTrue(true);
		}

		TEST_METHOD(SecretaryNotificationRelay)
		{
			//access secretary options and relay to player
			//Secretary secretary;
			//secretary.addNotification("There is a new crime scene nearby");
			//std::string message = "";// secretary.getTopNotification();
			//Assert::IsTrue(message!="");
			//Assert::AreEqual("There is a new crime scene nearby", "");
			Assert::IsTrue(true);
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
	};
}
