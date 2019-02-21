#include "Texturecodex.h"

TextureCodex::TextureCodex()
{
    for( int x = 0; x < totalTextures; x++ )
    {
        sf::Texture filler;
        filler.loadFromFile( fileNames[x] );
        Textures.emplace_back( filler );
    }
}

sf::Texture& TextureCodex::getTexture( const int texture_pos )
{
    return Textures[ texture_pos ];
}
