#include <bits/stdc++.h>
#include <Player.h>
#include <Monster.h>
#include <Potion.h>
#include <Boss.h>
using namespace std;
int mp=200,pm=120;

ifstream f("items.txt");

	class Equipement
	{
	    public:
    string name[20];
	    int id;
	    int quantity;

	    int defense;
	    int attack;
	    bool equiped;
	}itm[30],inv[30],aux;




		  	 void temp_init(Player &Me, Monster &Zombie, Monster &Skeleton, Boss &ShiaLaBeouf, Potion &SmallPotion, Potion &MediumPotion, Potion &BigPotion)
   {
       Me.HP=Me.max_life;
	Me.Armor=30;
	Me.DMG=200;
	Zombie.HP=500;
	Zombie.dmg=50;
	Zombie.type=0;
	strcpy(Zombie.name, "Zombie");
	Skeleton.HP=600;
	Skeleton.dmg=60;
	Skeleton.type=0;
	strcpy(Skeleton.name, "Skeleton");
	ShiaLaBeouf.HP=ShiaLaBeouf.max_hp;
	ShiaLaBeouf.dmg=100;
	ShiaLaBeouf.type=0;
	strcpy(ShiaLaBeouf.name,"Shia");
	SmallPotion.life=150;
	SmallPotion.quantity=10;
	MediumPotion.life=500;
	MediumPotion.quantity=5;
	BigPotion.life=1000;
	BigPotion.quantity=3;
   }

   void open_inv(Equipement inv[30])
   {
       for (int i=1;i<=3;i++)
       cout<<inv[i].id<<" "<<inv[i].attack<<" "<<inv[i].defense<<endl;
   }
   void initialization(Equipement itm[30])
   {
       for (int z=1;z<=3;z++)
       {
          f>>itm[z].id>>itm[z].defense>>itm[z].attack;
       }

   }

int main()
{
    if(f.is_open())
    cout<<"Mere"<<endl;
    else
    cout<<"Nu mere"<<endl;
    initialization(itm);
     Monster Zombie;
	Monster Skeleton;
	Boss ShiaLaBeouf;
	Player Me;
 	Potion SmallPotion,MediumPotion,BigPotion;
	temp_init(Me, Zombie, Skeleton, ShiaLaBeouf, SmallPotion, MediumPotion, BigPotion);
    char np;
    srand(time(0));
    cout<<"a-Inventory\nb-Combat\nc-Legendary Fight!\n";
    cin>>np;
    switch(np)
    {
        case 'a':{
         open_inv(itm);
         break;
        }
        case 'b':{
        Me.Fight(Skeleton,SmallPotion,MediumPotion,BigPotion);
        Me.Fight(Zombie,SmallPotion,MediumPotion,BigPotion);
        break;
        }

        case 'c':{
        Me.Fight(ShiaLaBeouf,SmallPotion,MediumPotion,BigPotion);
        break;
        }
    }

 f.close();
	return 0;
}
