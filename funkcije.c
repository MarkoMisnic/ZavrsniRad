#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Header.h"

//Funkcija za raščlanjivanje stringa i izvršavanja naredbe

bool parseAndExecute(char* input) {
	char* verb = strtok(input, " \n");
	char* noun = strtok(NULL, " \n");
	if (verb != NULL) {
		if (strcmp(verb, "quit") == 0) {
			return false;
		}
		else if (strcmp(verb, "look") == 0) {
			printf("\n");
		}
		else if (strcmp(verb, "go") == 0) {
			printf("It's too dark to go anywhere.\n");
		}
		else {
			printf("I don't know how to '%s'.\n", verb);
		}
	}
	return true;
}

//Funkcije za lokaciju, struktura, korištenje pokazivača, 


//Funkcije za objekte

OBJECT objs[] = {
	{"", "", NULL},
	{"", "", NULL},
	{"","",cave},
	{"","",field},
	{"","",field}
};

//Funkcije za imenice

static bool objectHasTag(OBJECT* obj, const char* noun) {
	return noun != NULL && *noun != '\0' && strcmp(noun, obj->tag) == 0;

}

static OBJECT* getObject(const char* noun) {
	OBJECT* obj, * res = NULL;
	for (obj = objs; obj < endOfObjs; obj++) {
		if (objectHasTag(obj, noun)) {
			res = obj;
		}
	}
	return res;
}

OBJECT* getVisible(const char* intention, const char* noun) {
	OBJECT* obj = getObject(noun);
	if (obj == NULL) {
		printf("I don't understand %s.\n", intention);
	}
	else if (!(obj == player 
		|| obj == player->location 
		|| obj->location == player 
		|| obj->location == player->location 
		|| obj->location == NULL 
		|| obj->location->location == player 
		|| obj->location->location == player->location)) {
		printf("You don't see any %s here.\n", noun);
		obj = NULL;
	}
	return obj;
}

//Pomocna funkcija za printanje broja objekata u lokaciji

int listObjectsAtLocation(OBJECT* location) {
	int count = 0;
	OBJECT* obj;
	for (obj = objs; obj < endOfObjs; obj++) {
		if (obj != player && obj->location == location) {
			if (count++ == 0) {
				printf("You see:\n");
			}
			printf("%s\n", obj->description);
		}
	}
	return count;
}
