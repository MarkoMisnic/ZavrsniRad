#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"

static char input[100] = "look around";
static bool getInput(void) {
	printf("n--> ");
	return fgets(input, sizeof input, stdin) != NULL;
}


int main() {
	printf("Welcome to the adventure!\n");
	while (parseAndExecute(input) && getInput());
	printf("\n");
	printf("\nBye!\n");
	return 0;
}
}
