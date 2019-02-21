#pragma once
#include <vector>
#include "ChessPiece.h"
#include "Player.h"

class PossibleMovesList
{
public:
    void Draw( sf::RenderWindow& wnd );
    void CalculateMoves( ChessPiece& any, std::vector<ChessPiece>& teamVecec, std::vector<ChessPiece>& enemyVec );
    void RemoveMoves();

private:
    void setRects();
    void removeOutOfBoundsVei2();
    void removeSameTeamPieceVei2( std::vector<ChessPiece>& any );
    void removeBlockedVei2( ChessPiece& any, std::vector<ChessPiece>& teamVec, std::vector<ChessPiece>& enemyVec);
    void removeHorizontalCenter2Left( ChessPiece& any, std::vector<ChessPiece>& teamVec, std::vector<ChessPiece>& enemyVec );
    void removeHorizontalCenter2Right( ChessPiece& any, std::vector<ChessPiece>& teamVec, std::vector<ChessPiece>& enemyVec );
    void removeVerticalCenter2Top( ChessPiece& any, std::vector<ChessPiece>& teamVec, std::vector<ChessPiece>& enemyVec );
    void removeVerticalCenter2Bottom( ChessPiece& any, std::vector<ChessPiece>& teamVec, std::vector<ChessPiece>& enemyVec );
    void removeDiagonalCenter2TopLeft( ChessPiece& any, std::vector<ChessPiece>& teamVec, std::vector<ChessPiece>& enemyVec );
    void removeDiagonalCenter2TopRight( ChessPiece& any, std::vector<ChessPiece>& teamVec, std::vector<ChessPiece>& enemyVec );
    void removeDiagonalCenter2BottomLeft( ChessPiece& any, std::vector<ChessPiece>& teamVec, std::vector<ChessPiece>& enemyVec );
    void removeDiagonalCenter2BottomRight( ChessPiece& any, std::vector<ChessPiece>& teamVec, std::vector<ChessPiece>& enemyVec );

private:
    std::vector< sf::RectangleShape > rects;

public:
    std::vector< Vei2 > PossibleMoves;
};
