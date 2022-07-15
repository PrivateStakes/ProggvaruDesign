#include "pch.h"
#include "CppUnitTest.h"
#include "Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SteveTest
{
	TEST_CLASS(SteveTest)
	{
	public:
		
		TEST_METHOD(SendAndRecieveEvents)
		{
			//pretty self explanatory

			Assert::IsTrue(true);
		}

		TEST_METHOD(TestAllInteractions)
		{
			//pretty self explanatory

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

			Assert::IsTrue(true);
		}

		TEST_METHOD(MoveGameElement)
		{
			//move game element from one scene to another

			Game game;
			//game.createScene();
			

			Assert::IsTrue(true);
		}
	};
}
