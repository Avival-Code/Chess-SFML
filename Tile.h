#pragma once
#include <SFML/Graphics.hpp>
#include "Vec2.h"

class Tile
{
public:
    Tile() = default;
    Tile( const sf::Color& color );
    Tile( const Vef2& pos_in, const sf::Color& color );
    void Draw( sf::RenderWindow& wnd );
    void setPos( const Vef2& pos_in );

private:
    sf::RectangleShape rect;
    Vef2 rectSize = Vef2( 50.0f, 50.0f );
    Vef2 pos;
};
