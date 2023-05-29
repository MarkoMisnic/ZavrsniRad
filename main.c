#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"

int main() {
	Character* character = createCharacter();

	printf("Character class: %s\n",character->characterClass);
	printf("Character gender: %s\n", character->Gender);

	saveCharacterToFile(character);
	free(character);

	Location(&Location);
	
	return 0;
}
