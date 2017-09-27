#ifndef BATTLE_H
#define BATTLE_H
#include <Player.h>
#include <Monster.h>
#include <Potion.h>

class Battle
{
public:
void end_of_battle(int WoF);
void PotMen(Player &you,Potion &S,Potion &M,Potion &L);
void BatMen(Player &you, Monster &enemy);
void Fight(Player &you, Monster &enemy,Potion s, Potion m, Potion l);
void EneAtk();
};

#endif // BATTLE_H
