#pragma once
#ifndef HEADER_H
#define HEADER_H

//3

typedef struct Character {
	char* characterClass;
	char* Gender;
}Character;

Character* createCharacter();
void saveCharacterToFile(Character* character);
void Location(char** location);

#endif
