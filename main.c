#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "charLoc.h"
#include "quest.h"
#include "combat.h"


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

        Combatant* player = createCombatant(myCharacter.name, 100, 20, 10);
        Combatant* enemy = createCombatant("Goblin", 80, 15, 5);

        if (player != NULL && enemy != NULL) {
            performCombat(player, enemy);
        }

        destroyCombatant(&player);
        destroyCombatant(&enemy);
    }
    else {
        checkLocation(chosenDirection);
    }

    return 0;
}
