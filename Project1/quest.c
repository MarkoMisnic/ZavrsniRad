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

//void manageFile() {
//    FILE* file = fopen("example.txt", "w+");
//    if (file == NULL) {
//        perror("Failed to open file");
//        return;
//    }
//
//    fputs("Hello, World!\n", file);
//    fputs("This is an example text.\n", file);
//
//    
//    long currentPosition = ftell(file);
//    if (currentPosition == -1) {
//        perror("Error getting file position");
//        fclose(file);
//        return;
//    }
//
//    printf("Current position: %ld\n", currentPosition);
//
//    
//    if (fseek(file, 0, SEEK_SET) != 0) {
//        perror("Error setting file position");
//        fclose(file);
//        return;
//    }
//
//    
//    char buffer[100];
//    while (fgets(buffer, sizeof(buffer), file) != NULL) {
//        printf("%s", buffer);
//    }
//
//    
//    if (fseek(file, currentPosition, SEEK_SET) != 0) {
//        perror("Error setting file position");
//        fclose(file);
//        return;
//    }
//
//    
//    fputs("Appending new text.\n", file);
//
//    
//    rewind(file);
//
//    
//    while (fgets(buffer, sizeof(buffer), file) != NULL) {
//        printf("%s", buffer);
//    }
//
//    fclose(file);
//}