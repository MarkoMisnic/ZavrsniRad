#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "charLoc.h"
#include "quest.h"
#include "combat.h"


int main() {
    menu();
    int playerResponse;
    static int questActivated = 0;

    Character myCharacter = createCharacter();
    Character characters[1];
    characters[0] = myCharacter;

    saveCharactersToFile(characters, 1);

    Direction directions[] = { NORTH, NORTHEAST, EAST, SOUTHEAST, SOUTH, SOUTHWEST, WEST, NORTHWEST };
    int numDirections = sizeof(directions) / sizeof(directions[0]);

    Direction chosenDirection = chooseDirection();

    if (chosenDirection == NORTH) {
        startQuest();
        fflush(stdout);
        printf("\n");
        printf("1. Yes, I'll help you.\n");
        printf("2. No, I'm not interested.\n");
        scanf("%d", &playerResponse);
        saveCharactersToFile(characters, 1);

        if (playerResponse == 1) {
            printf("\n");
            printf("\n");
            midQuest();
            fflush(stdout);
            questActivated = 1;
        }
        else if (playerResponse == 2) {
            printf("Old Woman: Very well. Farewell!\n");
            questActivated = 2;
        }
        else if (playerResponse != 1 && playerResponse != 2) {
            printf("Old Woman: Oh, thank you so much for helping such a fragile old lady!\n");
            questActivated = 1;
        }

        if (questActivated != 2) {
            Combatant* player = createCombatant(myCharacter.name, 100, 20, 10);
            Combatant* enemy = createCombatant("Goblin", 80, 15, 5);

            if (player != NULL && enemy != NULL) {
                performCombat(player, enemy);
            }

            destroyCombatant(&player);
            destroyCombatant(&enemy);
            endQuest();
        }
    }
    else if (chosenDirection != NORTH) {
        wrongPlace();

        printf("Old Woman: Hello, young adventurer! I was hoping someone would answer my call to help.\n");
        printf("Player: Hi, I'm %s.\n", myCharacter.name);

        printf("Old Woman: Nice to meet you, %s. I need your help with a quest. Are you willing to assist me?\n", myCharacter.name);
        printf("Player:\n");
        printf("\n");
        printf("1. Yes, I'll help you.\n");
        printf("2. No, I'm not interested.\n");
        scanf("%d", &playerResponse);
        saveCharactersToFile(characters, 1);

        if (playerResponse == 1) {
            printf("Old Woman: Great! Let me explain the quest to you.\n");
            questActivated = 1;
        }
        else if (playerResponse == 2) {
            printf("Old Woman: Very well. Farewell!\n");
            questActivated = 2;
        }
        else if (playerResponse != 1 && playerResponse != 2) {
            printf("Old Woman: Oh, thank you so much for helping such a fragile old lady!\n");
            questActivated = 1;
        }

        if (questActivated != 2) {
            Combatant* player = createCombatant(myCharacter.name, 100, 20, 10);
            Combatant* enemy = createCombatant("Goblin", 80, 15, 5);

            if (player != NULL && enemy != NULL) {
                performCombat(player, enemy);
            }

            destroyCombatant(&player);
            destroyCombatant(&enemy);
            endQuest();
        }
    }
    return 0;
}