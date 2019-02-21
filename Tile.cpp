#include "Tile.h"

Tile::Tile( const sf::Color& color )
{
    rect.setSize( {rectSize.x, rectSize.y} );
    rect.setFillColor( color );
}

Tile::Tile( const Vef2& pos_in, const sf::Color& color )
    :
    pos( pos_in )
{
    rect.setPosition( {pos.x, pos.y} );
    rect.setSize( {rectSize.x, rectSize.y} );
    rect.setFillColor( color );
}

void Tile::Draw( sf::RenderWindow& wnd)
{
    wnd.draw( rect );
}

void Tile::setPos( const Vef2& pos_in )
{
    pos = pos_in;
    rect.setPosition( {pos.x, pos.y} );
}
