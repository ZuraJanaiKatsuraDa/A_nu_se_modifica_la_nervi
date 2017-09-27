#include "Monster.h"
#include <Player.h>
#include <bits/stdc++.h>
   void Monster::take_damage(int dmg)
{
		HP-=dmg;
}

void Monster::regen(int life)
{
		HP+=life;
}
void Monster::on_fire(unsigned &turns, Player plry)
{
    if(turns>0)
    {
        HP-=plry.fire_charge(plry.DealDmg());
        turns--;
    }

}


    int Monster::DealDmg()
		  	{
		  	   again:int DMG=(int)(dmg*((float)(rand()%2)));
		  	   if(DMG==0)
                goto again;
               return DMG;
		  	}
