#ifndef CELLTEXTURE_H_INCLUDED
#define CELLTEXTURE_H_INCLUDED

#include <SFML-utils/core/ResourceManager.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
namespace netWars
{

class Configuration
{
public:
    enum Textures : int {
    TexCursor,
    TexGrass,
    TexBarracks,
    TexTreasury
    };

    static sf::Font font;
    static sfutils::ResourceManager<sf::Texture,int> textures;
    static void init();

private:
    static void initialize();
};

}
#endif // CELLTEXTURE_H_INCLUDED
