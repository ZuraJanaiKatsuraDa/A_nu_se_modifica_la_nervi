#ifndef BOSS_H
#define BOSS_H

#include <Monster.h>
class Boss:public Monster{
    public:
       unsigned HP;
       unsigned max_hp=3000;
       int attack_1(int Dmg);
       void attack_2();
       int attack_3(int Dmg);
       int surprise_attack(int Dmg);
};

#endif // BOSS_H
