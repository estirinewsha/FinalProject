#ifndef TILEMAP_H_INCLUDED
#define TILEMAP_H_INCLUDED

#include <iostream>
#include "HUD.h"
#include "Player.h"
#include <SFML/Window/Mouse.hpp>
namespace netWars
{

class TileMap : public sf::Drawable, public sf::Transformable
{
    std::vector<Cell*> hexs;
public:
    Player *player;

    sf::Sprite *barracksSample;
    sf::Sprite *treasurySample;
    enum MAPS : int {SAMPLE};
    TileMap(MAPS mapName, int radious=71);
    static HexPosition convertToHexPos(sf::Vector2f pt);
    void eventHandler(Event& event);
    ~TileMap();
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

}

#endif // TILEMAP_H_INCLUDED
