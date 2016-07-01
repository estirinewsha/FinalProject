#include "Configuration.h"

#include <iostream>
namespace netWars
{

sf::Font Configuration::font;
sfutils::ResourceManager<sf::Texture,int> Configuration::textures;

void Configuration::init()
{
    initialize();
}

void Configuration::initialize()
{
    textures.load(TexCursor, "./img/cursor.png");
    textures.load(TexGrass, "./img/Tiles/Terrain/Grass/grass_05.png");
    textures.load(TexBarracks, "./img/Objects/hangar.png");
    textures.load(TexTreasury, "./img/Objects/tre.png");
    textures.load(TexCastle, "./img/Objects/castle_large.png");
    textures.load(TexSoldier, "./img/Soldiers/alienYellow.png");
    font.loadFromFile("./font/arial.ttf");
}


}
