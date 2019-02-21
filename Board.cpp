#include "Board.h"

Board::Board( TextureCodex& txtCodex )
    :
    Tiles( new Tile[width * height] ),
    Codex( &txtCodex ),
    selector( {1, 1} )
{
    sf::Color colors[2] = { sf::Color(255, 255, 255, 255), sf::Color(167, 167, 167, 255) };

    for(int x = 0; x < TotalTiles; x += 2)  // Loop for white tiles.
    {
        Tiles[x] = Tile( colors[0] );
        if( x == 6 || x == 22 || x == 38 || x == 54)
            x += 1;
        else if( x == 15 || x == 31 || x == 47)
        {
            x += 1;
            Tiles[x] = Tile( colors[0] );
        }
    }
    for( int x = 1; x < TotalTiles; x += 2) // Loop for black tiles.
    {
       Tiles[x] = Tile( colors[1] );
        if( x == 7 || x == 23 || x == 39 || x == 55)
        {
            x += 1;
            Tiles[x] = Tile( colors[1] );
        }
        else if( x == 14 || x == 30 || x == 46)
            x += 1;
    }

    for(int y = 0; y < height; y++) // Set tile position.
    {
        for( int x = 0; x < width; x++)
        {
            Vef2 pos_in = Vef2(pos.x + (float(x) * 50.0f), pos.y + (float(y) * 50.0f));
            Tiles[ y * width + x].setPos( pos_in );
        }
    }

    Player1 = Player( *Codex, true, true );
    Player2 = Player( *Codex, false, false );
}

Board::~Board()
{
    delete [] Tiles;
    Tiles = nullptr;
    Codex = nullptr;
}

void Board::Draw( sf::RenderWindow& wnd )
{
    for( int y = 0; y < height; y++)
    {
        for( int x = 0; x < width; x++)
        {
            Tiles[ y * width + x ].Draw( wnd );
        }
    }
    selector.Draw( wnd );
    Player1.Draw( wnd );
    Player2.Draw( wnd );

}

void Board::Update( float& deltaTime )
{
    selector.Update( deltaTime, Player1, Player2, isItPlayer1Turn, Ann );
	Ann.Update( isItPlayer1Turn );
}
