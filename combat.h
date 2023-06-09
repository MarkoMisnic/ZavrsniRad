#ifndef COMBAT_H
#define COMBAT_H


typedef struct {
    char* name;
    int health;
    int attack;
    int defense;
} Combatant;

Combatant* createCombatant(const char* name, int health, int attack, int defense);
void destroyCombatant(Combatant** combatant);
void performCombat(Combatant* player, Combatant* enemy);

#endif
