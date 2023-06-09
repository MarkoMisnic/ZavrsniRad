#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "combat.h"



Combatant* createCombatant(const char* name, int health, int attack, int defense) {
    Combatant* combatant = malloc(sizeof(Combatant));
    if (combatant == NULL) {
        printf("Failed to allocate memory for combatant.\n");
        return NULL;
    }

    combatant->name = calloc(strlen(name) + 1, sizeof(char));
    if (combatant->name == NULL) {
        printf("Failed to allocate memory for combatant name.\n");
        free(combatant);
        return NULL;
    }

    strcpy(combatant->name, name);
    combatant->health = health;
    combatant->attack = attack;
    combatant->defense = defense;

    return combatant;
}

void destroyCombatant(Combatant** combatant) {
    if (combatant != NULL && *combatant != NULL) {
        free((*combatant)->name);
        free(*combatant);
        *combatant = NULL;
    }
}

void performCombat(Combatant* player, Combatant* enemy) {
    printf("Player: %s\n", player->name);
    printf("Enemy: %s\n", enemy->name);

    while (player->health > 0 && enemy->health > 0) {
        int playerDamage = player->attack - enemy->defense;
        if (playerDamage < 0) {
            playerDamage = 0;
        }
        enemy->health -= playerDamage;

        printf("Player attacks! %s loses %d health.\n", enemy->name, playerDamage);
        if (enemy->health <= 0) {
            printf("%s defeated!\n", enemy->name);
            printf("%s wins the combat!\n", player->name);
            return;
        }

        int enemyDamage = enemy->attack - player->defense;
        if (enemyDamage < 0) {
            enemyDamage = 0;
        }
        player->health -= enemyDamage;

        printf("Enemy attacks! %s loses %d health.\n", player->name, enemyDamage);
        if (player->health <= 0) {
            printf("%s defeated!\n", player->name);
            printf("%s wins the combat!\n", enemy->name);
            return;
        }

        printf("\n");
    }

    printf("Error: Combat ended unexpectedly!\n");
}
