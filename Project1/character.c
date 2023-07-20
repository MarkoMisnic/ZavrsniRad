#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "charLoc.h"

Character createCharacter() {
    Character character;
    char classChoice[50], genderChoice[50];

    printf("Choose a character class:\n");
    printf("1. Warrior\n");
    printf("2. Archer\n");
    scanf("%49s", classChoice);


    switch (classChoice[0]) {
    case '1':
        character.class = WARRIOR;
        break;
    case '2':
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
    scanf("%49s", genderChoice);


    switch (genderChoice[0]) {
    case '1':
        character.gender = MALE;
        break;
    case '2':
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

void saveCharactersToFile(Character characters[], int count) {
    FILE* file = fopen("characters.txt", "a"); 
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "Name: %s\n", characters[i].name);
        fprintf(file, "Class: %s\n", characters[i].class == WARRIOR ? "Warrior" : "Archer");
        fprintf(file, "Gender: %s\n", characters[i].gender == MALE ? "Male" : "Female");
        fprintf(file, "\n");
    }

    fclose(file);
}