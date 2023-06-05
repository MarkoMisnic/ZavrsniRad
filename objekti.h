#pragma once
#ifndef OBJEKTI_H
#define OBJEKTI_H

//OBJEKTI.H

typedef struct object {
	const char* description;
	const char* tag;
	struct object* location;
	struct object* destination;
} OBJECT;
extern OBJECT objs[];
#define field      (objs + 0)
#define cave       (objs + 1)
#define silver     (objs + 2)
#define gold       (objs + 3)
#define guard      (objs + 4)
#define player     (objs + 5)
#define intoCave   (objs + 6)
#define exitCave   (objs + 7)
#define endOfObjs  (objs + 8)

//RAZNO.H

typedef enum {
	distSelf,
	distHeld,
	distHeldContained,
	distLocation,
	distHere,
	distHereContained,
	distOverthere,
	distNotHere,
	distUnknownObject
} DISTANCE;
extern bool isHolding(OBJECT* container, OBJECT* obj);
extern OBJECT* getPassage(OBJECT* from, OBJECT* to);
extern DISTANCE getDistance(OBJECT* from, OBJECT* to);
extern OBJECT* actorHere(void);
extern int listObjectsAtLocation(OBJECT* location);



extern int listObjectsAtLocation(OBJECT* location);
extern OBJECT* actorHere(void);


extern void moveObject(OBJECT* obj, OBJECT* to);

#endif
