#pragma once 
#ifndef CHARACTER_H
#define CHARACTER_H

typedef enum {
    WARRIOR,
    ARCHER
} CharacterClass;

typedef enum {
    MALE,
    FEMALE
} Gender;

typedef struct {
    CharacterClass class;
    Gender gender;
    char name[20];
} Character;

Character createCharacter();
void saveCharacterToFile(Character character);

#endif 
