#include "Boss.h"

 int Boss::attack_1(int Dmg)
 {
     return Dmg*2;
 }

 void Boss::attack_2()
 {
     HP=max_hp;
 }

 int Boss::attack_3(int Dmg)
 {
     return (int)(Dmg*3.5);
 }

 int surprise_attack(int Dmg)
 {
     return Dmg*5;
 }
