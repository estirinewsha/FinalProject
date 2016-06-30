#include "Building.h"

Building::Building(){
    bar.setFillColor(sf::Color::Green);
    treasurySample=new sf::Sprite(Configuration::textures.get(Configuration::TexTreasury));
    barracksSample = new sf::Sprite(Configuration::textures.get(Configuration::TexBarracks));
    castleSample = new sf::Sprite(Configuration::textures.get(Configuration::TexCastle));
    castleSample->setPosition(convertToHexPos(sf::Vector2f(100, 200)));

}
int Building::setSize(int x){
    bar.setSize(sf::Vector2f(x, 20));
}
void Building::getCoor(int x,int y){
		this->x=x;
		this->y=y;
		HexPosition h=convertToHexPos(sf::Vector2f(x,y));
        bar.setPosition(((sf::Vector2f)h).x-20,((sf::Vector2f)h).y-40);
	}
void Building::add(int t){
	;
}
void Building::gettype(int t){
	this->type=t;
}
void Castel::add(int t){
	;
}
 void Barracks::add(int t){


	if(t>60){
		num++;}
}
 void Treasury::add(int t){
	if(t>60){
		num+=10;}
}
HexPosition Building::convertToHexPos(sf::Vector2f p)
{
    sf::Vector2f pt(p.x/(71), p.y/(71));
    double q = (sqrt(3.0)/3) * pt.x + (-1.0/3) * pt.y;
    double r = 0.0 * pt.x + (2.0/3) * pt.y;

    return HexFractionalPosition(q, r, -q - r);
}
void Building::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
        if(type==1){
            HexPosition h=convertToHexPos(sf::Vector2f(x,y));
            barracksSample->setPosition(((sf::Vector2f)h).x-30,((sf::Vector2f)h).y-20);
            target.draw(*barracksSample);
        }
        else if(type==2){
            HexPosition h=convertToHexPos(sf::Vector2f(x,y));
            treasurySample->setPosition(((sf::Vector2f)h).x-30,((sf::Vector2f)h).y-20);
            target.draw(*treasurySample);
        }
        else if(type==0){
            HexPosition h=convertToHexPos(sf::Vector2f(x,y));
            castleSample->setPosition(((sf::Vector2f)h).x-51,((sf::Vector2f)h).y-51);
            target.draw(*castleSample);
        }
}
