#pragma once
#include <iostream>


class Announcer
{
public:
	void Update( bool& playerTurn );
	void printIntroMessage();
	void printCurrentPlayerTurn();
	void printInvalidPieceSelection();

private:
	bool printedIntroMessage = false;
	bool announcedTurn = false;
	bool announcedMoveError = false;
	bool isPlayer1Turn = true;
};