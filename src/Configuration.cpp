#include "Configuration.h"

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
    textures.load(TexCursor, "/Users/zahra/Desktop/FinalProject/runtime/img/cursor.png");
    textures.load(TexGrass, "/Users/zahra/Desktop/FinalProject/runtime/img/Tiles/Terrain/Grass/grass_05.png");
    textures.load(TexBarracks, "/Users/zahra/Desktop/FinalProject/runtime/img/Objects/hangar.png");
    textures.load(TexTreasury, "/Users/zahra/Desktop/FinalProject/runtime/img/Objects/tre.png");
    font.loadFromFile("/Users/zahra/Desktop/FinalProject/runtime/font/arial.ttf");
}


}
