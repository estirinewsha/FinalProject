#include "Player.h"

bool Player::addnew(int x,int y,int type){
    if(coinnum>100){
		if(type==1){
			/*Barracks b;
			b.type=1;
			b.x=x;
			b.y=y;*/
			Building bu;//=new Building[1];
			bu.type=1;
			bu.x=x;
			bu.y=y;
			bld.push_back(bu);
			//bld[bld.size()-1]->gettype(1);
//			cout<<"b created";
		}
		else if(type==2){
			/*Treasury t;
			t.type=2;
			t.x=x;
			t.y=y;*/
			Building b;//=new Building[1];
			b.type=2;
			b.x=x;
			b.y=y;
			bld.push_back(b);
			//bld[bld.size()-1]->gettype(2);
		}
		coinnum-=100;
		return true;
    }
    else{
        return false;
      //  std::cout<<"nomoney";
    }
}
/*void Player::addnewsoldier(int x,int y){
    Soldier s;
    s.x=x;
    s.y=y;
    sld.push_back(s);
}*/
void Player::addCoor(int x,int y,int i){
	bld[i].x=x;
	bld[i].y=y;
}
Player::Player()
{
	//Castel c;
	//c.x=c.y=100;
	soldiernum=0;
	coinnum=1000;
	Building b;
	b.type=0;
	bld.push_back(b);
	bld[0].type=0;
}
void Player::getType(int i){
	if(bld[i].type==1)
        soldiernum+=1;
    else if(bld[i].type==2)
        coinnum+=10;
}
Player::~Player()
{
    //dtor
}
