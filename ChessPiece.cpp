#include "ChessPiece.h"

ChessPiece::ChessPiece( const Vei2& pos_in, const sf::Texture& texture_in, bool isMovingDown )
    :
    pos( pos_in ),
    movingDown( isMovingDown )
{
    sprite.setTexture( texture_in );
    sprite.setPosition( (200.0f + (float(pos.x) * 50.0f)), (100.0f + (float(pos.y) * 50.0f)) );
}

ChessPiece::ChessPiece( const Vei2& pos_in, TextureCodex& codex,int PieceType, bool isMovingDown, bool isWhite )
    :
    pos( pos_in ),
    movingDown( isMovingDown )
{
    switch( PieceType )
    {
    case 0:
        Type = ChessPiece::PieceType::King;
        if( isWhite )
        {
            sprite.setTexture( codex.getTexture( 1 ) );
        }
        else
        {
            sprite.setTexture( codex.getTexture( 0 ) );
        }
        break;

    case 1:
        Type = ChessPiece::PieceType::Queen;
        if( isWhite )
        {
            sprite.setTexture( codex.getTexture( 3 ) );
        }
        else
        {
            sprite.setTexture( codex.getTexture( 2 ) );
        }
        break;

    case 2:
        Type = ChessPiece::PieceType::Bishop;
        if( isWhite )
        {
            sprite.setTexture( codex.getTexture( 5 ) );
        }
        else
        {
            sprite.setTexture( codex.getTexture( 4 ) );
        }
        break;

    case 3:
        Type = ChessPiece::PieceType::Knight;
        if( isWhite )
        {
            sprite.setTexture( codex.getTexture( 7 ) );
        }
        else
        {
            sprite.setTexture( codex.getTexture( 6 ) );
        }
        break;

    case 4:
        Type = ChessPiece::PieceType::Rook;
        if( isWhite )
        {
            sprite.setTexture( codex.getTexture( 9 ) );
        }
        else
        {
            sprite.setTexture( codex.getTexture( 8 ) );
        }
        break;

    case 5:
        Type = ChessPiece::PieceType::Pawn;
        if( isWhite )
        {
            sprite.setTexture( codex.getTexture( 11 ) );
        }
        else
        {
            sprite.setTexture( codex.getTexture( 10 ) );
        }
        break;
    }
    sprite.setPosition( (200.0f + (float(pos.x) * 50.0f)), (100.0f + (float(pos.y) * 50.0f)) );

}

void ChessPiece::Draw( sf::RenderWindow& wnd)
{
    if( isAlive )
    {
        wnd.draw( sprite );
    }
}

void ChessPiece::MovePiece( Vei2 new_pos )
{
    pos = new_pos;
    sprite.setPosition( 200.0f + (float(pos.x) * 50.0f), 100.0f + (float(pos.y) * 50.0f) );

    if( movedSinceStart == false )
    {
        movedSinceStart = true;
    }
}

void ChessPiece::Attack( ChessPiece& any)
{
    if( pos == any.getPos() )
    {
        any.killed();
    }
}

Vei2 ChessPiece::getPos()
{
    return pos;
}

void ChessPiece::killed()
{
    isAlive = false;
}

bool ChessPiece::isAliveStatus()
{
    return isAlive;
}

ChessPiece::PieceType& ChessPiece::getType()
{
    return Type;
}
