#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "charLoc.h"
#include "quest.h"

int main() {
    Character myCharacter = createCharacter();
    saveCharacterToFile(myCharacter);

    Direction directions[] = { NORTH, NORTHEAST, EAST, SOUTHEAST, SOUTH, SOUTHWEST, WEST, NORTHWEST };
    int numDirections = sizeof(directions) / sizeof(directions[0]);


    Direction chosenDirection = chooseDirection();
    saveLocationToFile(chosenDirection);

    if (chosenDirection == NORTH) {
        printf("You have reached a desolate house in the North.\n");
        activateQuest(myCharacter);
    }

    return 0;
}
