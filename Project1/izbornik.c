#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "charLoc.h"

Character characters[100];
int numCharacters = 0;

void menu() {
    Character characters[100];
    int numCharacters = 0;
    int choice = 0; 

    do {
        printf("\n===== MENU =====\n");
        printf("1. Create a new character\n");
        printf("2. Print all characters\n");
        printf("3. Search for a character\n");
        printf("4. Sort characters by name\n");
        printf("5. Save characters to file\n");
        printf("6. Start the game.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (numCharacters < 100) {
                characters[numCharacters] = createCharacter();
                numCharacters++;
            }
            else {
                printf("Maximum number of characters reached.\n");
            }
            break;
        case 2:
                if (numCharacters > 0) {
                    printf("Printing all characters:\n");
                    for (int i = 0; i < numCharacters; i++) {
                        printf("Name: %s\n", characters[i].name);
                        printf("Class: %s\n", characters[i].class == WARRIOR ? "Warrior" : "Archer");
                        printf("Gender: %s\n", characters[i].gender == MALE ? "Male" : "Female");
                        printf("\n");
                    }
                }
                else {
                    printf("No characters to print.\n");
                }
                break;
        case 3:
                if (numCharacters > 0) {
                    char searchName[20];
                    printf("Enter the name to search: ");
                    scanf("%19s", searchName);
            
                    int found = 0;
                    for (int i = 0; i < numCharacters; i++) {
                        if (strcmp(characters[i].name, searchName) == 0) {
                            printf("Character found:\n");
                            printf("Name: %s\n", characters[i].name);
                            printf("Class: %s\n", characters[i].class == WARRIOR ? "Warrior" : "Archer");
                            printf("Gender: %s\n", characters[i].gender == MALE ? "Male" : "Female");
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Character not found.\n");
                    }
                }
                else {
                    printf("No characters to search.\n");
                }
                break;
        case 4:
                if (numCharacters > 0) {
                    Character temp;
                    for (int i = 0; i < numCharacters - 1; i++) {
                        for (int j = 0; j < numCharacters - i - 1; j++) {
                            if (strcmp(characters[j].name, characters[j + 1].name) > 0) {
                                temp = characters[j];
                                characters[j] = characters[j + 1];
                                characters[j + 1] = temp;
                            }
                        }
                    }
                    printf("Characters sorted by name.\n");
                }
                else {
                    printf("No characters to sort.\n");
                }
                break;

        case 5:
                if (numCharacters > 0) {
                    saveCharactersToFile(characters, numCharacters);
                    printf("Characters saved to 'characters.txt' file.\n");
                }
                else {
                    printf("No characters to save.\n");
                }
                break;
            break;
        case 6:
            printf("Starting the game...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}