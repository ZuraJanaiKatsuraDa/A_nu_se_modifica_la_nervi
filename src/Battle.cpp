#include "Battle.h"
#include <Player.h>
#include <Monster.h>
#include <Potion.h>
#include <bits/stdc++.h>
#include <windows.h>
unsigned fire_turns,cd1,cd2,dodge;
void Battle::Fight(Player &you, Monster &enemy,Potion s, Potion m, Potion l)
{
char op;
while(you.HP>0 && enemy.HP>0)
{
system("cls");
std::cout<<enemy.name<<" has "<<enemy.HP<<" left\n";
std::cout<<"You, on the other hand have:"<<you.HP<<" left\n";
std::cout<<"a-Potion menu\nb-Attack menu\n";
std::cin>>op;
switch(op)
{
 case 'a':PotMen(you,s,m,l); break;
 case 'b':BatMen(you,enemy);break;
}

}
}

void Battle::PotMen(Player &you,Potion &S,Potion &M,Potion &L)
{
 system("cls");
 char op;
 std::cout<<"You have:\n"<<"a-"<<S.quantity<<" Small Potions\n"<<"b-"<<M.quantity<<" Medium Potions\n"<<"c-"<<L.quantity<<" Big Potions\n";
 std::cin>>op;
 switch(op)
     {
     case 'a':you.PotionUse(S); break;
     case 'b':you.PotionUse(M); break;
     case 'c':you.PotionUse(L); break;
     }
}

void Battle::BatMen(Player &you, Monster &enemy)
{
    system("cls");
    unsigned sa_cha;
    sa_cha=rand()%100;
    char op;
    std::cout<<"a-Normal attack\nb-Double Slash, Cooldown:"<<cd1<<"\nc-Fire Charge, Cooldown:"<<cd2<<"\n";
    if(sa_cha>0 && sa_cha<4)
        std::cout<<"d-Bodyslam of Shia LaBeouf";
    std::cin>>op;
    switch(op)
    {
        case 'a':enemy.take_damage(you.DealDmg()); break;
        case 'b':{
            if(cd1==0)
            {
            enemy.take_damage(you.double_slash(you.DealDmg()));
            cd1=4;
            break;
            }
        goto def;
        }
        case 'c':{
        if(cd2==0)
        {
         fire_turns=4;
         cd2=8;
         break;
        }
        goto def;
        }
       case 'd':
           {
             if(sa_cha>0 && sa_cha<4)
           {
               enemy.take_damage(you.BodySlamSuperStarShiaLabeouf(you.DealDmg()));
                break;
           }
           goto def;
           }

       def: default: system("cls"); std::cout<<"You tried but nothing happened..."; Sleep(1000);
    }
}
