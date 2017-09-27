#include "Shia.h"

void Shia::WaitHeIsntDead(int MaxLife)
    {
       HP=MaxLife;
    }

int Shia::DeathInHisEyes(int dmg)
    {
        int attack=dmg*10;
        return attack;
    }

void Shia::Stabbed(int dmg)
         {
             HP-=dmg;
         }
