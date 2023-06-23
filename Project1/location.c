#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "charLoc.h"

const char* directionToString(Direction direction) {
    switch (direction) {
    case NORTH:
        return "North";
    case NORTHEAST:
        return "North East";
    case EAST:
        return "East";
    case SOUTHEAST:
        return "South East";
    case SOUTH:
        return "South";
    case SOUTHWEST:
        return "South West";
    case WEST:
        return "West";
    case NORTHWEST:
        return "North West";
    default:
        return "North";
    }
}

Direction chooseDirection() {
    Direction directions[] = { NORTH, NORTHEAST, EAST, SOUTHEAST, SOUTH, SOUTHWEST, WEST, NORTHWEST };
    int numDirections = sizeof(directions) / sizeof(directions[0]);

    printf("Choose a direction:\n");
    for (int i = 0; i < numDirections; i++) {
        printf("%d. %s\n", i + 1, directionToString(directions[i]));
    }

    int choice;
    char stringChoice[50];
    printf("Enter the number corresponding to your choice: ");

    choice = atoi(stringChoice);    
    scanf("%49s", stringChoice);


    if (choice >= 1 && choice <= numDirections) {
        return directions[choice - 1];
    }
    else {
        printf("You fainted after you got too scared of making a choice were to go and after you woke up you realised where you wanted to go, which is North.\n");
        printf("\n");
        return NORTH;
    }
}

void saveLocationToFile(Direction location) {
    FILE* file = fopen("character.txt", "a");
    if (file == NULL) {
        printf("Failed to open the file for writing.\n");
        return;
    }

    fprintf(file, "Location: %s\n", directionToString(location));

    fclose(file);
}

//void checkLocation(Direction chosenDirection) {
//    if (chosenDirection != NORTH) {
//        printf("There's nothing there. You return to the starting position.\n");
//        printf("When you returned to your starting position you saw a flash of light in the distance, you decided to go the direction of the light which flashed in the North.\n");
//        printf("\n");
//        printf("\n");
//        Direction newDirection = chooseDirection();
//        saveLocationToFile(newDirection);
//    }
//}