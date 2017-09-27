#ifndef SHIA_H
#define SHIA_H

#include <Monster.h>


	class Shia:public Monster
    {
        public:
        int DeathInHisEyes(int dmg);
    void WaitHeIsntDead(int MaxLife);
    void Stabbed(int dmg);
    };

#endif // SHIA_H
