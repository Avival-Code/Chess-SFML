#include "Player.h"

Player::Player( TextureCodex& Codex, bool isPlayer1_in, bool colorWhite_in )
    :
    isPlayer1( isPlayer1_in ),
    colorWhite( colorWhite_in )
{
    if( colorWhite )
    {
        isMovingDown = false;

        Vei2 temp = Vei2( 0, 6 );
        for( int i = 0; i < 8; i++)
        {
            Pieces.emplace_back( temp, Codex, 5, isMovingDown, colorWhite );
            temp += Vei2( 1, 0 );
        }

        temp = Vei2( 0, 7 );
        for( int i = 4; i > -1; i-- )
        {
            Pieces.emplace_back( temp, Codex, i, isMovingDown, colorWhite );
            temp += Vei2( 1, 0 );
        }

        for( int i = 2; i < 5; i++)
        {
            Pieces.emplace_back( temp, Codex, i, isMovingDown, colorWhite );
            temp += Vei2( 1, 0 );
        }
    }
    else
    {
        isMovingDown = true;

        Vei2 temp = Vei2( 0, 1 );
        for( int i = 0; i < 8; i++)
        {
            Pieces.emplace_back( temp, Codex, 5, isMovingDown, colorWhite );
            temp += Vei2( 1, 0 );
        }

        temp = Vei2( 0, 0 );
        for( int i = 4; i > -1; i-- )
        {
            Pieces.emplace_back( temp, Codex, i, isMovingDown, colorWhite );
            temp += Vei2( 1, 0 );
        }

        for( int i = 2; i < 5; i++)
        {
            Pieces.emplace_back( temp, Codex, i, isMovingDown, colorWhite );
            temp += Vei2( 1, 0 );
        }
    }
}

void Player::Update()
{
    if( !getKingStatus() )
    {
        isAlive = false;
    }
}

void Player::Draw( sf::RenderWindow& wnd )
{
    for( int i = 0; i < int(Pieces.size()); i++)
    {
        Pieces[i].Draw( wnd );
    }
}

bool Player::getAliveState()
{
    return isAlive;
}

bool Player::getKingStatus()
{
    return Pieces[12].isAliveStatus();
}
