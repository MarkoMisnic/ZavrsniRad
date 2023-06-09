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
void saveCharacterToFile(Character character);

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
    UNKNOWN
} Direction;

const char* directionToString(Direction direction);
Direction chooseDirection();
void saveLocationToFile(Direction location);


#endif 
