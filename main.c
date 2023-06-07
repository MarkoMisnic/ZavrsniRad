#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "character.h"

int main() {
    Character myCharacter = createCharacter();
    saveCharacterToFile(myCharacter);

    return 0;
}
