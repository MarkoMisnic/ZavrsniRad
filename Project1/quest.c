#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "quest.h"
#include "charLoc.h"
#include "combat.h"

void startQuest() {
    FILE* file;
    char line[256];

    file = fopen("questStart.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
    return 0;
}

void midQuest() {
    FILE* file;
    char line[256];

    file = fopen("questMid.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
    return 0;
}

void endQuest() {
    FILE* file;
    char line[256];

    file = fopen("questEnd.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
    return 0;
}

void wrongPlace() {
    FILE* file;
    char line[256];

    file = fopen("wrongPlacelol.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
    return 0;
} 