#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "quest.h"
#include "charLoc.h"


void activateQuest(Character character) {
    static int questActivated = 0;

    if (!questActivated) {
        FILE* dialogueFile = fopen("dialogue.txt", "r");
        if (dialogueFile == NULL) {
            printf("Failed to open the dialogue file.\n");
            return;
        }

        char line[256];
        while (fgets(line, sizeof(line), dialogueFile)) {
            printf("%s", line);

            int playerResponse;
            scanf("%d", &playerResponse);

            saveCharacterToFile(character, line);

            switch (playerResponse) {
            case 1:
                printf("Old Woman: Great! Let me explain the quest to you.\n");
                questActivated = 1;
                break;
            case 2:
                printf("Old Woman: Very well. Farewell!\n");
                return;
            default:
                printf("Old Woman: I'm sorry, I didn't understand your response.\n");
                break;
            }
        }

        fclose(dialogueFile);
    }
}

