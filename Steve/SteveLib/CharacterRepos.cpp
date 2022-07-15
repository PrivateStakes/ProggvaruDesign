#include "pch.h"
#include "CharacterRepos.h"

bool CharacterRepos::noCharacterFound(int id)
{
	if (characterVector.size() - 1 < id) std::cout << "Character could not be found.\n"; return true;
	return false;
}

CharacterRepos::CharacterRepos()
{
	characterNames = new std::string[]{ "James",  "Mary", "Robert" , "Patricia", "John" , "Jennifer" , "Michael" , "Linda" , "David" , "Elizabeth" };
}

CharacterRepos::~CharacterRepos()
{
	for (int i = 0; i < characterVector.size(); i++)
	{
		delete characterVector[i];
		characterVector[i] = nullptr;
	}
}

void CharacterRepos::addCharacter(Game* game)
{
	std::string name; 
	if (nameIncramenter >= 10) name = characterNames[nameIncramenter % 10] + std::to_string(incramentValue);
	else name = characterNames[nameIncramenter % 10];
	characterVector.push_back(new Character(name));
	characterVector[characterVector.size() - 1]->setId(game->getIdIncrementTracker());
	game->setIdIncrementTracker(game->getIdIncrementTracker() + 1);
}

void CharacterRepos::addCharacter(Character* character)
{
	for (int i = 0; i < characterVector.size(); i++)
	{
		if (character->getName() == characterVector[i]->getName()) std::cout << "Character already exists!\n"; return;
	}
	characterVector.push_back(character);
}

Character* CharacterRepos::getCharacter(std::string characterName)
{
	Character* chrPtr = nullptr;
	for (int i = 0; i < characterVector.size(); i++)
	{
		if (characterVector[i]->getName() == characterName) chrPtr = characterVector[i]; break;
	}
	return chrPtr;
}

Character* CharacterRepos::getCharacter(int id)
{
	if (this->noCharacterFound(id)) return nullptr;
	return characterVector[id];
}

void CharacterRepos::removeCharacter(std::string characterName)
{
	for (int i = 0; i < characterVector.size(); i++)
	{
		if (characterName == characterVector[i]->getName())
		{
			delete characterVector[i];
			characterVector[i] = nullptr;
			characterVector[i] = characterVector.back();

			characterVector.back() = nullptr;
		}
		else if (i == characterVector.size() - 1) std::cout << "no such object was found" << std::endl;
	}
}

void CharacterRepos::removeCharacter(int id)
{
	if (this->noCharacterFound(id)) return;

	delete characterVector[id];
	characterVector[id] = nullptr;
	characterVector[id] = characterVector.back();

	characterVector.back() = nullptr;
		
}

std::string CharacterRepos::getCharacterName(int id)
{
	if (this->noCharacterFound(id)) return "";
	return characterVector[id]->getName();
}

int CharacterRepos::getCharacterId(std::string characterName)
{
	for (int i = 0; i < characterVector.size(); i++)
	{
		if (characterName == characterVector[i]->getName()) return i;
	}
	std::cout << "No character with that name was found.\n";
	return -1;
}

std::string CharacterRepos::listAllCharacters()
{
	std::string output;
	for (int i = 0; i < characterVector.size(); i++)
	{
		output += std::to_string(i + 1) + ": " + characterVector[i]->getName() + "\n";
	}
	return output;
}
