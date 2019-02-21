#include "Announcer.h"

void Announcer::Update(bool & playerTurn)
{
	printIntroMessage();

	if( isPlayer1Turn != playerTurn)
	{
		isPlayer1Turn = playerTurn;
		announcedTurn = false;
		announcedMoveError = false;
	}

	printCurrentPlayerTurn();
}

void Announcer::printIntroMessage()
{
	if( !printedIntroMessage )
	{
		std::cout << "*********** Welcome to SFML chess ***********" << std::endl;
		std::cout << "************** Code by Avival ***************" << std::endl;
		std::cout << "********** Good luck and have fun! **********" << std::endl;

		printedIntroMessage = true;
	}
}

void Announcer::printCurrentPlayerTurn()
{
	if( !announcedTurn )
	{
		if (isPlayer1Turn)
		{
			std::cout << "It's player one's turn!" << std::endl;
		}
		else
		{
			std::cout << "It's player two's turn!" << std::endl;
		}
		announcedTurn = true;
	}
}

void Announcer::printInvalidPieceSelection()
{
	if( !announcedMoveError )
	{
		std::cout << "You can't move that piece right now! Move something else." << std::endl;
		announcedMoveError = true;
	}
}
