#pragma once
#include <vector>
#include "ChessPiece.h"
#include "TextureCodex.h"


class Player
{
public:
    Player() = default;
    Player( TextureCodex& Codex, bool isPlayer1_in, bool colorWhite_in );
    void Update();
    void Draw( sf::RenderWindow& wnd );
    bool getAliveState();

private:
    bool getKingStatus();

public:
    std::vector<ChessPiece> Pieces;
    bool isPlayer1;
    bool colorWhite;
    bool isAlive = true;
    bool isMovingDown;
};
