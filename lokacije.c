#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Header.h"

//Funkcije za lokaciju, struktura, korištenje pokazivača, 

struct location{
	const char* description;
	const char* tag;
} locs[] = {
	{"", ""}, {"", ""}
};

#define numberOfLocations (sizeof locs / sizeof *locs)

static unsigned locationOfPlayer = 0;

void executeLook(const char* noun) {
	if (noun != NULL && strcmp(noun, "around") == 0) {
		printf("You are in %s.\n", player->location);
		listObjectsAtLocation(player->location);
	}
	else {
		printf("I don't understand what you want to see.\n");
	}
}

void executeGo(const char* noun) {
	OBJECT* obj = getVisible("Where you want to go", noun);
	if (obj == NULL) {
		//getVisible je ovo riješio
	}
	else if (obj->location == NULL && obj != player->location) {
		printf("Ok.\n");
		player->location = obj;
		executeLook("around");
	}
	else {
		printf("You can't get much closer than this.\n");
	}
}
