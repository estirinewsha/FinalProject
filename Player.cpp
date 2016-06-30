#include "Player.h"

bool Player::addnew(int x,int y,int type){
    if(coinnum>100){
		if(type==1){
			Building bu;
			bu.type=1;
			bu.x=x;
			bu.y=y;
			bld.push_back(bu);
		}
		else if(type==2){
			Building b;
			b.type=2;
			b.x=x;
			b.y=y;
			bld.push_back(b);
		}
		coinnum-=100;
		return true;
    }
    else{
        return false;
    }
}


Player::Player()
{

	soldiernum=0;
	coinnum=1000;
	Building b;
	b.x=100;
	b.y=200;
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
bool Player::eventHandler(Event& event,sf::RenderWindow *window,bool *b)
{
    if(event.clicked)
        {

              if(*b)
                {
                    bld[bld.size()-1].getCoor(sf::Mouse::getPosition(*window).x,sf::Mouse::getPosition(*window).y);
                    std::cout<<"clicked"<<sf::Mouse::getPosition(*window).x<<'\n'<<sf::Mouse::getPosition(*window).y<<'\n';

                    *b=false;
                    return true;
                }

        }
        return false;
}
void Player::timing(int i){
    if(bld[i].clock.getElapsedTime().asSeconds()>60){
                bld[i].clock.restart();
                if(bld[i].type==1){
                    soldiernum++;
                    Soldier s(bld[0].convertToHexPos(sf::Vector2f(100,100)));
                    sld.push_back(s);
                }
                else if(bld[i].type==2)coinnum+=10;
            }
}
void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

    for(int i=0;i<bld.size();i++){

        target.draw(bld[i]);

    }
}

