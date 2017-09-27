#ifndef PLAYER_H
#define PLAYER_H
#include <Potion.h>
#include <Monster.h>
#include <Boss.h>
class Monster;
class Boss;
  class Player
		{
    public:
			int HP;
			int DMG;
			int Armor;
			int max_life=1500;
			void take_dmg(int dmg);
			void PotionUse(Potion &pot);
			void armor_eq (int armor);
			void armor_un (int armor);
			void weapon_eq (int mp, int pm, int attack);
			void weapon_un (int mp, int pm, int attack);
			int double_slash(int dmg);
			int fire_charge (int dmg);
			int BodySlamSuperStarShiaLabeouf(int dmg);
			int DealDmg();
			void end_of_battle(int WoF);
            void PotMen(Potion &S,Potion &M,Potion &L);
            void BatMen(Monster &enemy);
            void Fight(Monster &enemy,Potion s, Potion m, Potion l);
            void EneAtk(Monster &enemy);
            void BossAtk(Boss &enemy);
			};


#endif // PLAYER_H
