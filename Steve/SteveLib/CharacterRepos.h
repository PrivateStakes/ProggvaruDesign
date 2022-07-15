#pragma once
#include "Character.h"
#include <vector>
#include <string>
#include "Game.h"

class CharacterRepos
{
private:
	std::vector<Character*> characterVector;
	int nameIncramenter;
	int incramentValue;
	std::string* characterNames;

	bool noCharacterFound(int id);
public:
	CharacterRepos();
	~CharacterRepos();

	void addCharacter(Character* character);
	void addCharacter(Game* game);
	void removeCharacter(std::string characterName);
	void removeCharacter(int id);

	Character* getCharacter(std::string characterName);
	Character* getCharacter(int id);

	std::string getCharacterName(int id);
	int getCharacterId(std::string characterName);

	std::string listAllCharacters();
};

