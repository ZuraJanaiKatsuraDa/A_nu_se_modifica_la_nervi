#ifndef MONSTER_H
#define MONSTER_H
#include <Player.h>
class Player;

class Monster
{
	public:
	int HP;
	int dmg;
	int max_hp=3000;
	char name[20];
	int type;
	void take_damage(int dmg);
	void regen(int life);
    void on_fire(unsigned &turns,Player plyr);
    int DealDmg();
	};


#endif // MONSTER_H
