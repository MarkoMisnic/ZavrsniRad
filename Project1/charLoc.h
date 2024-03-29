#pragma once 
#ifndef CHARLOC_H
#define CHARLOC_H

//CHARACTER_H

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
void saveCharactersToFile(Character characters[], int count);

//LOCATION_H

typedef enum {
    NORTH,
    NORTHEAST,
    EAST,
    SOUTHEAST,
    SOUTH,
    SOUTHWEST,
    WEST,
    NORTHWEST,
} Direction;

const char* directionToString(Direction direction);
Direction chooseDirection();

#endif 