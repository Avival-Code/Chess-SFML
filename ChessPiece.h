#pragma once
#include <SFML/Graphics.hpp>
#include "Vec2.h"
#include "TextureCodex.h"

class ChessPiece
{
public:
    enum class PieceType
    {
        King,
        Queen,
        Bishop,
        Knight,
        Rook,
        Pawn,
        None
    };

public:
    ChessPiece() = default;
    ChessPiece( const Vei2& pos_in, const sf::Texture& texture_in, bool isMovingDown );
    ChessPiece( const Vei2& pos_in, TextureCodex& codex, int PieceType, bool isMovingDown, bool isWhite );
    void Draw( sf::RenderWindow& wnd );
    void MovePiece( Vei2 new_pos );
    void Attack( ChessPiece& any );
    Vei2 getPos();
    void killed();
    bool isAliveStatus();
    PieceType& getType();

private:
    sf::Sprite sprite;
    PieceType Type = PieceType::None;
    Vei2 pos;
    bool isAlive = true;

public:
    bool movingDown;
    bool movedSinceStart = false;
};
