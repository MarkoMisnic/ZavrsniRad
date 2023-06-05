#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "objekti.h"

struct location {
    const char* description;
    const char* tag;
}
locs[] = {
   {"an open field", "field"},
   {"a little cave", "cave"}
};
#define numberOfLocations   (sizeof locs / sizeof *locs)
static unsigned locationOfPlayer = 0;


void executeLook(const char* noun)
{
    if (noun != NULL && strcmp(noun, "around") == 0)
    {
        printf("You are in %s.\n", player->location->description);
        listObjectsAtLocation(player->location);
    }
    else
    {
        printf("I don't understand what you want to see.\n");
    }
}
void executeGo(const char* noun)
{
    OBJECT* obj = getVisible("where you want to go", noun);
    if (obj == NULL)
    {
        // getVisible je riješio ovo 
    }
    else if (getPassage(player->location, obj) != NULL)
    {
        printf("OK.\n");
        player->location = obj;
        executeLook("around");
    }
    else if (obj->location != player->location)
    {
        printf("You don't see any %s here.\n", noun);
    }
    else if (obj->destination != NULL)
    {
        printf("OK.\n");
        player->location = obj->destination;
        executeLook("around");
    }
    else
    {
        printf("You can't get much closer than this.\n");
    }
}
