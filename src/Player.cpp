#include "Player.h"
#include <Monster.h>
#include <Potion.h>
#include <bits/stdc++.h>
#include <windows.h>
#include <Boss.h>
   void Player::take_dmg(int dmg)
			{
				HP-=(dmg-Armor);
				}
		  	void Player::PotionUse(Potion &pot)
	{
	    if(pot.quantity>0)
        {
            HP+=pot.life;
            pot.quantity--;
        }
        if(HP>max_life)
            HP=max_life;
	}

		  	void Player::weapon_eq(int mp, int pm, int attack)
		  	{
		  	    mp+=attack*50/100;
		  	    pm+=attack*50/100;
		  	    DMG=rand()%mp+pm;
		  	}
		  	void Player::weapon_un(int mp, int pm, int attack)
		  	{
		  	    mp-=attack*50/100;
		  	    pm-=attack*50/100;
		  	    DMG=rand()%mp+pm;
		  	}
		  	void Player::armor_eq(int armor)
		  	{
		  	    Armor+=armor;
		  	}
		  	void Player::armor_un(int armor)
		  	{
		  	    Armor-=armor;
		  	}
		  int Player::double_slash(int dmg)
		  {
		  	int slash=dmg*2;
		  	return slash;
		  	}
		  	int Player::fire_charge(int dmg)
		  	{
		  	    int attack=dmg*30/100;
               return attack;
		  	}
		  	int Player::BodySlamSuperStarShiaLabeouf(int dmg)
		  	{
		  	    int Dmg=dmg*5;
		  	    return Dmg;
		  	}
		  	int Player::DealDmg()
		  	{
		  	   again:int dmg=(int)(DMG*((float)(rand()%2)));
		  	   if(dmg==0)
                goto again;
               return dmg;
		  	}





		  	unsigned fire_turns,cd1,cd2,dodge,heal;
		void Player::EneAtk(Monster &enemy)
{
    take_dmg(enemy.DealDmg());
}

void Player::BossAtk(Boss &enemy)
{
  int cha_of_atk=rand()%1000;
  if(cha_of_atk<=850)
  {
      take_dmg(enemy.DealDmg());
  }
  else
    if(cha_of_atk>850&&cha_of_atk<=950)
    {
        take_dmg(enemy.attack_1(enemy.DealDmg()));
    }
    else
    if(cha_of_atk>950&&cha_of_atk<=970)
    {
        enemy.attack_3(enemy.DealDmg());
    }
    else
    if(cha_of_atk>970&& cha_of_atk<=990)
    {
        if(heal==1)
        {
            enemy.attack_2();
            heal--;
        }
        else std::cout<<enemy.name<<" tried to heal, but he is too weak\n";
    }
    if(cha_of_atk>990)
    {
        enemy.surprise_attack(enemy.DealDmg());
        std::cout<<"Now you're dead\n"; Sleep(1500);
    }
}
void Player::Fight(Monster &enemy,Potion s, Potion m, Potion l)
{
char op;
heal=1;
while(HP>0 && enemy.HP>0)
{
system("cls");
std::cout<<enemy.name<<" has "<<enemy.HP<<" left\n";
std::cout<<"You, on the other hand have:"<<HP<<" left\n";
std::cout<<"a-Potion menu\nb-Attack menu\n";
std::cin>>op;
switch(op)
{
 case 'a':PotMen(s,m,l); break;
 case 'b':BatMen(enemy);break;
}
enemy.type==1? BossAtk(enemy): EneAtk(enemy);
}
}

void Player::PotMen(Potion &S,Potion &M,Potion &L)
{
 system("cls");
 char op;
 std::cout<<"You have:\n"<<"a-"<<S.quantity<<" Small Potions\n"<<"b-"<<M.quantity<<" Medium Potions\n"<<"c-"<<L.quantity<<" Big Potions\n";
 std::cin>>op;
 switch(op)
     {
     case 'a':PotionUse(S); break;
     case 'b':PotionUse(M); break;
     case 'c':PotionUse(L); break;
     }
}

void Player::BatMen(Monster &enemy)
{
    system("cls");
    unsigned sa_cha;
    sa_cha=rand()%100;
    char op;
    std::cout<<"a-Normal attack\nb-Double Slash, Cooldown:"<<cd1<<"\nc-Fire Charge, Cooldown:"<<cd2<<"\n";
    if(sa_cha>0 && sa_cha<4)
        std::cout<<"d-Bodyslam of Shia LaBeouf\n";
    std::cin>>op;
    switch(op)
    {
        case 'a':enemy.take_damage(DealDmg()); break;
        case 'b':{
            if(cd1==0)
            {
            enemy.take_damage(double_slash(DealDmg()));
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
               enemy.take_damage(BodySlamSuperStarShiaLabeouf(DealDmg()));
                break;
           }
           goto def;
           }

       def: default: system("cls"); std::cout<<"You tried but nothing happened..."; Sleep(1000);
    }
}


