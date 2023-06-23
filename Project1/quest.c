#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "quest.h"
#include "charLoc.h"
#include "combat.h"

void activateQuest(Character character) {
    printf("Old Woman: Listen carefully, %s. I am not just an old woman. I am a powerful witch!\n", character.name);
    printf("Old Woman: My magic circlet, which preserves my youth, has been stolen by a wicked monster.\n");
    printf("Old Woman: It has caused me to age rapidly. I need you to retrieve it for me.\n");
    printf("I will teleport you to the beasts lair to fight him, get ready!\n");
    printf("You are in the lair. Good luck!\n");
}


    void endQuest(Character character) {


        printf("Congratulations! You have defeated the monster and retrieved the magic circlet.\n");
        printf("Old Woman: Thank you, %s. You have saved me from this dreadful fate.\n", character.name);
        printf("Old Woman: As a token of my gratitude, I offer you a reward.\n");
    }

