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
    textures.load(TexCursor, "img/cursor.png");
    textures.load(TexGrass, "img/Tiles/Terrain/Grass/grass_05.png");
    textures.load(TexBarracks, "img/Objects/sheriff.png");

    font.loadFromFile("font/arial.ttf");
}


}
