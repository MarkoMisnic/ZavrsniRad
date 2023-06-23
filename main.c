#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "charLoc.h"
#include "quest.h"
#include "combat.h"

int main() {
    int playerResponse;
    static int questActivated = 0;

    Character myCharacter = createCharacter();
    saveCharacterToFile(myCharacter);

    Direction directions[] = { NORTH, NORTHEAST, EAST, SOUTHEAST, SOUTH, SOUTHWEST, WEST, NORTHWEST };
    int numDirections = sizeof(directions) / sizeof(directions[0]);

    Direction chosenDirection = chooseDirection();
    saveLocationToFile(chosenDirection);


    if (chosenDirection == NORTH) {
        printf("You have reached a desolate house in the North.\n");

        printf("Old Woman: Hello, young adventurer!\n");
        printf("Player: Hi, I'm %s.\n", myCharacter.name);

        printf("Old Woman: Nice to meet you, %s. I need your help with a quest. Are you willing to assist me?\n", myCharacter.name);
        printf("Player:\n");
        printf("1. Yes, I'll help you.\n");
        printf("2. No, I'm not interested.\n");
        scanf("%d", &playerResponse);
        saveCharacterToFile(myCharacter);

        if (playerResponse == 1) {
            printf("Old Woman: Great! Let me explain the quest to you.\n");
            activateQuest(myCharacter);
            questActivated = 1;
        }
        else if (playerResponse == 2) {
            printf("Old Woman: Very well. Farewell!\n");
            questActivated = 2;
        }
        else if(playerResponse!=1 || playerResponse!=2){
            printf("Old Woman: Oh, thank you so much for helping such a fragile old lady!\n");
            activateQuest(myCharacter);
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
            endQuest(myCharacter);

        }
    }
    else if(chosenDirection != NORTH){
        printf("There's nothing there. You return to the starting position.\n");
        printf("When you returned to your starting position you saw a flash of light in the distance, you decided to go the direction of the light which flashed in the North.\n");
        printf("\n");
        printf("\n");
        printf("You have reached a desolate house in the North.\n");
 

        printf("Old Woman: Hello, young adventurer! I was hoping someone would answer my call to help.\n");
        printf("Player: Hi, I'm %s.\n", myCharacter.name);

 
        printf("Old Woman: Nice to meet you, %s. I need your help with a quest. Are you willing to assist me?\n", myCharacter.name);
        printf("Player:\n");
        printf("1. Yes, I'll help you.\n");
        printf("2. No, I'm not interested.\n");
        scanf("%d", &playerResponse);
        saveCharacterToFile(myCharacter);

        if (playerResponse == 1) {
            printf("Old Woman: Great! Let me explain the quest to you.\n");
            activateQuest(myCharacter);
            questActivated = 1;
        }
        else if (playerResponse == 2) {
            printf("Old Woman: Very well. Farewell!\n");
            questActivated = 2;
        }
        else if (playerResponse != 1 || playerResponse != 2) {
            printf("Old Woman: Oh, thank you so much for helping such a fragile old lady!\n");
            activateQuest(myCharacter);
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
            endQuest(myCharacter);

        }
    }



    return 0;
}



