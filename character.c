#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "charLoc.h"

Character createCharacter() {
    Character character;
    int classChoice, genderChoice;

    printf("Choose a character class:\n");
    printf("1. Warrior\n");
    printf("2. Archer\n");
    scanf("%d", &classChoice);

    switch (classChoice) {
    case 1:
        character.class = WARRIOR;
        break;
    case 2:
        character.class = ARCHER;
        break;
    default:
        printf("Invalid choice. Defaulting to Warrior.\n");
        character.class = WARRIOR;
        break;
    }

    printf("Choose a gender:\n");
    printf("1. Male\n");
    printf("2. Female\n");
    scanf("%d", &genderChoice);

    switch (genderChoice) {
    case 1:
        character.gender = MALE;
        break;
    case 2:
        character.gender = FEMALE;
        break;
    default:
        printf("Invalid choice. Defaulting to Male.\n");
        character.gender = MALE;
        break;
    }

    printf("Enter the character's name: ");
    scanf("%s", character.name);

    return character;
}

void saveCharacterToFile(Character character) {
    FILE* file = fopen("character.txt", "w");
    if (file == NULL) {
        printf("Failed to open the file for writing.\n");
        return;
    }

    fprintf(file, "Character Details:\n");
    fprintf(file, "Name: %s\n", character.name);

    fprintf(file, "Class: ");
    switch (character.class) {
    case WARRIOR:
        fprintf(file, "Warrior\n");
        break;
    case ARCHER:
        fprintf(file, "Archer\n");
        break;
    }

    fprintf(file, "Gender: ");
    switch (character.gender) {
    case MALE:
        fprintf(file, "Male\n");
        break;
    case FEMALE:
        fprintf(file, "Female\n");
        break;
    }

    fclose(file);
    printf("Character details saved to character.txt.\n");
}
