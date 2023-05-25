#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"

//3

typedef struct Character {
	char* characterClass;
	char* Gender;
	char* Name;
}Character;

//3,9,14,4

Character* createCharacter() {
	Character* character = malloc(sizeof(Character));


	printf("Choose your class:\n");
	printf("1. Warrior\n");
	printf("2. Archer\n");

	int classChoice;
	printf("Pick a number.\n");
	scanf("%d", &classChoice);

	switch (classChoice) {
	case 1:
		character->characterClass = "Warrior";
		break;
	case 2:
		character->characterClass = "Archer";
		break;
	default:
		printf("Invalid choice. Setting character class to Warrior by default.\n");
		character->characterClass = "Warrior";
	}

	printf("Choose your gender:\n");
	printf("1. Male\n");
	printf("2. Female\n");

	int genderChoice;
	scanf("%d", &genderChoice);

	switch (genderChoice) {
	case 1:
		character->Gender = "Male";
		break;
	case 2:
		character->Gender = "Female";
		break;
	default:
		printf("Invalid choice. Setting character gender to Male by default.\n");
		character->characterClass = "Male";
	}

	return character;

}

void saveCharacterToFile(Character* character) {
	FILE* file = fopen("character.txt", "w");

	if (file == NULL) {
		printf("Error opening the file.\n");
		return;
	}
	fprintf(file, "Character class:%s\n", character->characterClass);
	fprintf(file, "Character gender:%s\n", character->Gender);

	fclose(file);
	printf("Character information has been saved to character.txt\n");
