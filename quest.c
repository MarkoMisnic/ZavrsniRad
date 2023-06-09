#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "quest.h"
#include "charLoc.h"
#include "combat.h"

void activateQuest(Character character) {
    static int questActivated = 0;

    if (!questActivated) {
        printf("Old Woman: Hello, young adventurer!\n");
        printf("Player: Hi, I'm %s.\n", character.name);

        int playerResponse;
        printf("Old Woman: Nice to meet you, %s. I need your help with a quest. Are you willing to assist me?\n", character.name);
        printf("Player:\n");
        printf("1. Yes, I'll help you.\n");
        printf("2. No, I'm not interested.\n");
        scanf("%d", &playerResponse);
        saveCharacterToFile(character);

        switch (playerResponse) {
        case 1:
            printf("Old Woman: Great! Let me explain the quest to you.\n");
            questActivated = 1;
            break;
        case 2:
            printf("Old Woman: Very well. Farewell!\n");
            return;
        default:
            printf("Old Woman: Oh, thank you so much for helping such a fragile old lady!\n");
            questActivated = 1;
            break;
        }
    }

    printf("Old Woman: Listen carefully, %s. I am not just an old woman. I am a powerful witch!\n", character.name);
    printf("Old Woman: My magic circlet, which preserves my youth, has been stolen by a wicked monster.\n");
    printf("Old Woman: It has caused me to age rapidly. I need you to retrieve it for me.\n");

    printf("Old Woman: I will teleport you to the monster's lair. Be prepared for a fierce battle!\n");

    printf("You have been teleported to the monster's lair.\n");

    Combatant* player = createCombatant(character.name, 100, 20, 10);
    Combatant* enemy = createCombatant("Monster", 80, 15, 5);

    if (player != NULL && enemy != NULL) {
        performCombat(player, enemy);
    }

    destroyCombatant(&player);
    destroyCombatant(&enemy);

    printf("Congratulations! You have defeated the monster and retrieved the magic circlet.\n");
    printf("Old Woman: Thank you, %s. You have saved me from this dreadful fate.\n", character.name);
    printf("Old Woman: As a token of my gratitude, I offer you a reward.\n");

}
