#include "Selector.h"

Selector::Selector( Vei2 pos_in )
    :
    pos(pos_in)
{
    rect.setSize( {50.0f, 50.0f} );
    rect.setPosition( 200.0f + ( float(pos.x) * 50.0f), 100.0f + ( float(pos.y) * 50.0f) );
    rect.setFillColor( {0, 0, 0, 0} );
    rect.setOutlineThickness( -3.0f );
    rect.setOutlineColor( {0, 0, 255, 255} );
}

void Selector::Draw( sf::RenderWindow& wnd )
{
    wnd.draw( rect );
    List.Draw( wnd );
}

void Selector::UpdatePosition()
{
    rect.setPosition( 200.0f + ( float(pos.x) * 50.0f), 100.0f + ( float(pos.y) * 50.0f) );
}

void Selector::Update( float& deltaTime, Player& Player1, Player& Player2, bool& isItPlayer1Turn, Announcer& Ann )
{
    float minimumTime = 0.17f;
    if( int(pos.x) <= 0 )
    {
        pos.x = 0;
    }
    if( int(pos.x) >= 7 )
    {
        pos.x = 7;
    }
    if( int(pos.y) <= 0 )
    {
        pos.y = 0;
    }
    if( int(pos.y) >= 7 )
    {
        pos.y = 7;
    }

    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left) && deltaTime > minimumTime)
    {
        pos.x = pos.x - 1;
        deltaTime = 0.0f;
    }
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right) && deltaTime > minimumTime)
    {
        pos.x = pos.x + 1;
        deltaTime = 0.0f;
    }
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up) && deltaTime > minimumTime)
    {
        pos.y = pos.y - 1;
        deltaTime = 0.0f;
    }
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down) && deltaTime > minimumTime)
    {
        pos.y = pos.y + 1;
        deltaTime = 0.0f;
    }

    UpdatePosition();
    SelectPiece( Player1, Player2, isItPlayer1Turn, Ann );
    MovePiece( Player1, Player2, isItPlayer1Turn );
}

void Selector::SelectPiece( Player& Player1, Player& Player2, bool& isItPlayer1Turn, Announcer& Ann )
{
    if( selectedPiece == nullptr && sf::Keyboard::isKeyPressed( sf::Keyboard::Enter ))
    {
        if( isItPlayer1Turn )
        {
            for( int i = 0; i < int(Player1.Pieces.size()); i++)
            {
                if( Player1.Pieces[i].isAliveStatus() == true && pos == Player1.Pieces[i].getPos() )
                {
                    selectedPiece = &Player1.Pieces[i];
                }
            }
        }
        else
        {
            for( int i = 0; i < int(Player2.Pieces.size()); i++)
            {
                if( Player2.Pieces[i].isAliveStatus() == true && pos == Player2.Pieces[i].getPos() )
                {
                    selectedPiece = &Player2.Pieces[i];
                }
            }
        }


        if( selectedPiece != nullptr )
        {
            if( isItPlayer1Turn )
            {
                List.CalculateMoves( *selectedPiece, Player1.Pieces, Player2.Pieces );
            }
            else
            {
                List.CalculateMoves( *selectedPiece, Player2.Pieces, Player1.Pieces );
            }
        }

		DeselectPiece( Ann );

    }
}

void Selector::DeselectPiece( Announcer& Ann)
{
	if( (int)List.PossibleMoves.size() < 1 )
	{
		selectedPiece = nullptr;
		Ann.printInvalidPieceSelection();
	}
}

void Selector::MovePiece( Player& Player1, Player& Player2, bool& isItPlayer1Turn )
{
    if( selectedPiece != nullptr && sf::Keyboard::isKeyPressed( sf::Keyboard::S ))
    {
        if( isValidPosition() )
        {
            AttackPiece( Player1, Player2, isItPlayer1Turn );

            selectedPiece->MovePiece( pos.getVei2() );
            isItPlayer1Turn = !isItPlayer1Turn;
            selectedPiece = nullptr;
            List.RemoveMoves();
        }
    }
}

void Selector::AttackPiece( Player& Player1, Player& Player2, bool& isItPlayer1Turn )
{
    if( isItPlayer1Turn )
        {
            for( auto pieces = Player2.Pieces.begin(); pieces != Player2.Pieces.end(); ++pieces)
            {
                if( pos.x == pieces->getPos().x && pos.y == pieces->getPos().y )
                {
                    attackedPiece = &(*pieces);
                }
            }
        }
        if( !isItPlayer1Turn )
        {
            for( auto pieces = Player1.Pieces.begin(); pieces != Player1.Pieces.end(); ++pieces)
            {
                if( pos.x == pieces->getPos().x && pos.y == pieces->getPos().y )
                {
                    attackedPiece = &(*pieces);
                }
            }
        }

        if( attackedPiece != nullptr )
        {
            attackedPiece->killed();
            attackedPiece = nullptr;
        }
}

bool Selector::isValidPosition()
{
    bool validPosition = false;
    for( auto place = List.PossibleMoves.begin(); place != List.PossibleMoves.end(); ++place)
    {
        if( pos.x == place->x && pos.y == place->y )
        {
            validPosition = true;
        }
    }

    return validPosition;
}
