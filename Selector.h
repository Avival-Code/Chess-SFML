#pragma once
#include <SFML/Graphics.hpp>
#include "Vec2.h"
#include "Player.h"
#include "PossibleMovesList.h"
#include "Announcer.h"

class Selector
{
public:
    Selector() = default;
    Selector( Vei2 pos_in);
    void Draw( sf::RenderWindow& wnd );
    void Update( float& deltaTime, Player& Player1, Player& Player2, bool& isItPlayer1Turn, Announcer& Ann );
    void SelectPiece( Player& Player1, Player& Player2, bool& isItPlayer1Turn, Announcer& Ann );
	void DeselectPiece( Announcer& Ann );
    void MovePiece( Player& Player1, Player& Player2, bool& isItPlayer1Turn );
    void AttackPiece( Player& Player1, Player& Player2, bool& isItPlayer1Turn );

private:
    void UpdatePosition();
    bool isValidPosition();

private:
    sf::RectangleShape rect;
    Vei2 pos;
    ChessPiece* selectedPiece = nullptr;
    ChessPiece* attackedPiece = nullptr;
    PossibleMovesList List;
};
