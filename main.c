#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include "razclanjivanje.h"


static char input[100] = "look around";
static bool getInput(void)
{
	printf("\n--> ");
	return fgets(input, sizeof input, stdin) != NULL;
}
int main()
{
	printf("Welcome to the adventure!\n");
	while (parseAndExecute(input) && getInput());
	printf("\nBye!\n");
	return 0;
}
