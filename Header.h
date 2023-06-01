#pragma once
#ifndef HEADER_H
#define HEADER_H
//.H za raščlanjivanje i izvršavanje

extern bool parseAndExecute(char* input);

//.H za lokacija

extern void executeLook(const char* noun);
extern void executeGo(const char* noun);

//.H za objekt

typedef struct object {
	const char* description;
	const char* tag;
	const char* location;
}OBJECT;

extern OBJECT objs[];

#define field (objs+0)
#define cave (objs+1)
#define gold (objs+2)
#define bronze (objs+3)
#define player (objs+4)

#define endOfObjs(objs+5)

//.H za funkcije imenica

extern OBJECT* getVisible(const char* obj, const char* noun);

//.H za pomoćnu funkciju

extern int listObjectsAtLocation(OBJECT* location);

#endif
