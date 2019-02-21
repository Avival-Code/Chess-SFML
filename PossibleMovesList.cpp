#include "PossibleMovesList.h"

void PossibleMovesList::Draw( sf::RenderWindow& wnd )
{
    for( int i = 0; i < int(rects.size()); i++)
    {
        wnd.draw( rects[i]);
    }
}

void PossibleMovesList::CalculateMoves( ChessPiece& any, std::vector<ChessPiece>& teamVec, std::vector<ChessPiece>& enemyVec )
{
    switch( int(any.getType()) )
    {
    case 0:     //King moves
        PossibleMoves.emplace_back( Vei2( any.getPos().x - 1, any.getPos().y - 1) );
        PossibleMoves.emplace_back( Vei2( any.getPos().x - 1, any.getPos().y ) );
        PossibleMoves.emplace_back( Vei2( any.getPos().x - 1, any.getPos().y + 1) );
        PossibleMoves.emplace_back( Vei2( any.getPos().x, any.getPos().y - 1) );
        PossibleMoves.emplace_back( Vei2( any.getPos().x, any.getPos().y + 1) );
        PossibleMoves.emplace_back( Vei2( any.getPos().x + 1, any.getPos().y + 1) );
        PossibleMoves.emplace_back( Vei2( any.getPos().x + 1, any.getPos().y ) );
        PossibleMoves.emplace_back( Vei2( any.getPos().x + 1, any.getPos().y - 1) );
        break;

    case 1:     //Queen moves
        for( int xPos = 0; xPos <= 7; xPos++)
        {
            if( xPos != any.getPos().x)
            {
                PossibleMoves.emplace_back( Vei2( xPos, any.getPos().y ) );
            }
        }
        for( int yPos = 0; yPos <= 7; yPos++)
        {
            if( yPos != any.getPos().y)
            {
                PossibleMoves.emplace_back( Vei2( any.getPos().x, yPos ) );
            }
        }
        for( int i = 0; i < 8; i++)
        {
            PossibleMoves.emplace_back( Vei2( any.getPos().x - i, any.getPos().y - i ) );
        }
        for( int i = 0; i < 8; i++)
        {
            PossibleMoves.emplace_back( Vei2( any.getPos().x + i, any.getPos().y - i ) );
        }
        for( int i = 0; i < 8; i++)
        {
            PossibleMoves.emplace_back( Vei2( any.getPos().x - i, any.getPos().y + i ) );
        }
        for( int i = 0; i < 8; i++)
        {
            PossibleMoves.emplace_back( Vei2( any.getPos().x + i, any.getPos().y + i ) );
        }
        break;

    case 2:     //Bishop moves
        for( int i = 0; i < 8; i++)
        {
            PossibleMoves.emplace_back( Vei2( any.getPos().x - i, any.getPos().y - i ) );
        }
        for( int i = 0; i < 8; i++)
        {
            PossibleMoves.emplace_back( Vei2( any.getPos().x + i, any.getPos().y - i ) );
        }
        for( int i = 0; i < 8; i++)
        {
            PossibleMoves.emplace_back( Vei2( any.getPos().x - i, any.getPos().y + i ) );
        }
        for( int i = 0; i < 8; i++)
        {
            PossibleMoves.emplace_back( Vei2( any.getPos().x + i, any.getPos().y + i ) );
        }
        break;

    case 3:     //Knight moves
        PossibleMoves.emplace_back( Vei2( any.getPos().x - 1, any.getPos().y - 2 ) );
        PossibleMoves.emplace_back( Vei2( any.getPos().x - 1, any.getPos().y + 2 ) );
        PossibleMoves.emplace_back( Vei2( any.getPos().x + 1, any.getPos().y - 2 ) );
        PossibleMoves.emplace_back( Vei2( any.getPos().x + 1, any.getPos().y + 2 ) );
        PossibleMoves.emplace_back( Vei2( any.getPos().x - 2, any.getPos().y - 1 ) );
        PossibleMoves.emplace_back( Vei2( any.getPos().x - 2, any.getPos().y + 1 ) );
        PossibleMoves.emplace_back( Vei2( any.getPos().x + 2, any.getPos().y - 1 ) );
        PossibleMoves.emplace_back( Vei2( any.getPos().x + 2, any.getPos().y + 1 ) );
        break;

    case 4:     //Rook moves
        for( int xPos = 0; xPos <= 7; xPos++)
        {
            if( xPos != any.getPos().x)
            {
                PossibleMoves.emplace_back( Vei2( xPos, any.getPos().y ) );
            }
        }
        for( int yPos = 0; yPos <= 7; yPos++)
        {
            if( yPos != any.getPos().y)
            {
                PossibleMoves.emplace_back( Vei2( any.getPos().x, yPos ) );
            }
        }
        break;

    case 5:     //Pawn moves
        if( any.movingDown )
        {
            if( !any.movedSinceStart )
            {
                PossibleMoves.emplace_back( Vei2( any.getPos().x, any.getPos().y + 1 ) );
                PossibleMoves.emplace_back( Vei2( any.getPos().x, any.getPos().y + 2 ) );
            }
            else
            {
                PossibleMoves.emplace_back( Vei2( any.getPos().x, any.getPos().y + 1 ) );
            }
        }
        else
        {
            if( !any.movedSinceStart )
            {
                PossibleMoves.emplace_back( Vei2( any.getPos().x, any.getPos().y - 1 ) );
                PossibleMoves.emplace_back( Vei2( any.getPos().x, any.getPos().y - 2 ) );
            }
            else
            {
                PossibleMoves.emplace_back( Vei2( any.getPos().x, any.getPos().y - 1 ) );
            }
        }
        break;

    }

    removeOutOfBoundsVei2();
    removeBlockedVei2( any, teamVec, enemyVec );
    removeSameTeamPieceVei2( teamVec );
    setRects();
}

void PossibleMovesList::RemoveMoves()
{
    PossibleMoves.clear();
    rects.clear();
}

void PossibleMovesList::removeOutOfBoundsVei2()
{
    for( auto it = PossibleMoves.begin(); it != PossibleMoves.end(); )
    {
        if( it->x < 0 || it->x > 7 ||
            it->y < 0 || it->y > 7)
        {
            it = PossibleMoves.erase( it );
        }
        else
        {
            ++it;
        }
    }
}

void PossibleMovesList::removeSameTeamPieceVei2( std::vector<ChessPiece>& vec )
{
    bool samePosFound = false;
    for( auto moves = PossibleMoves.begin(); moves != PossibleMoves.end(); )
    {
        for( auto pos = vec.begin(); pos != vec.end(); ++pos )
        {
            if( moves->x == pos->getPos().x && moves->y == pos->getPos().y && pos->isAliveStatus() == true )
            {
                samePosFound = true;
            }
        }

        if( samePosFound )
        {
            moves = PossibleMoves.erase( moves );
            samePosFound = false;
        }
        else
        {
            ++moves;
        }
    }
}

void PossibleMovesList::setRects()
{
    for(int i = 0; i < int( PossibleMoves.size() ); i++)
    {
        sf::RectangleShape temp;
        temp.setSize( {50.0f, 50.0f} );
        temp.setPosition( 200.0f + ( float(PossibleMoves[i].x) * 50.0f), 100.0f + ( float(PossibleMoves[i].y) * 50.0f) );
        temp.setFillColor( {0, 0, 0, 0} );
        temp.setOutlineThickness( -2.0f );
        temp.setOutlineColor( {255, 255, 0, 210} );
        rects.emplace_back( temp );
    }
}

void PossibleMovesList::removeBlockedVei2( ChessPiece& any, std::vector<ChessPiece>& teamVec, std::vector<ChessPiece>& enemyVec )
{
    switch( int(any.getType()) )
    {
    case 1:     //Remove Queen excess moves
        removeHorizontalCenter2Left( any, teamVec, enemyVec );
        removeHorizontalCenter2Right( any, teamVec, enemyVec );
        removeVerticalCenter2Top( any, teamVec, enemyVec );
        removeVerticalCenter2Bottom( any, teamVec, enemyVec );
        removeDiagonalCenter2TopLeft( any, teamVec, enemyVec );
        removeDiagonalCenter2TopRight( any, teamVec, enemyVec );
        removeDiagonalCenter2BottomLeft( any, teamVec, enemyVec );
        removeDiagonalCenter2BottomRight( any, teamVec, enemyVec );
        break;

    case 2:     //Remove Bishop excess moves
        removeDiagonalCenter2TopLeft( any, teamVec, enemyVec );
        removeDiagonalCenter2TopRight( any, teamVec, enemyVec );
        removeDiagonalCenter2BottomLeft( any, teamVec, enemyVec );
        removeDiagonalCenter2BottomRight( any, teamVec, enemyVec );
        break;

    case 4:     //Remove rook excess moves
        removeHorizontalCenter2Left( any, teamVec, enemyVec );
        removeHorizontalCenter2Right( any, teamVec, enemyVec );
        removeVerticalCenter2Top( any, teamVec, enemyVec );
        removeVerticalCenter2Bottom( any, teamVec, enemyVec );
        break;

    case 5:
        if( any.movingDown && !any.movedSinceStart )
        {
            removeVerticalCenter2Bottom( any, teamVec, enemyVec );
        }

        if( !any.movingDown && !any.movedSinceStart )
        {
            removeVerticalCenter2Top( any, teamVec, enemyVec );
        }
        break;

    }
}

void PossibleMovesList::removeHorizontalCenter2Left( ChessPiece& any, std::vector<ChessPiece>& teamVec,
                                                    std::vector<ChessPiece>& enemyVec )
{
    bool isBlocked = false;
    Vei2 temp = Vei2( any.getPos().x - 1, any.getPos().y );

    for( ; temp.x >= 0; temp.x--)
    {
        for( auto currPos = PossibleMoves.begin(); currPos != PossibleMoves.end(); )
        {
            if( temp.x == currPos->x && temp.y == currPos->y )
            {
                if( isBlocked )
                {
                    currPos = PossibleMoves.erase( currPos );
                }
                else
                {
                    ++currPos;
                }
            }
            else
            {
                ++currPos;
            }
        }

        for( auto currPos = teamVec.begin(); currPos != teamVec.end(); ++currPos )
        {
            if( temp.x == currPos->getPos().x && temp.y == currPos->getPos().y )
            {
                isBlocked = true;
            }
        }
        for( auto currPos = enemyVec.begin(); currPos != enemyVec.end(); ++currPos )
        {
            if( temp.x == currPos->getPos().x && temp.y == currPos->getPos().y )
            {
                isBlocked = true;
            }
        }
    }
}

void PossibleMovesList::removeHorizontalCenter2Right( ChessPiece& any, std::vector<ChessPiece>& teamVec,
                                                     std::vector<ChessPiece>& enemyVec )
{
    bool isBlocked = false;
    Vei2 temp = Vei2( any.getPos().x + 1, any.getPos().y );

    for( ; temp.x <= 7; temp.x++)
    {
        for( auto currPos = PossibleMoves.begin(); currPos != PossibleMoves.end(); )
        {
            if( temp.x == currPos->x && temp.y == currPos->y )
            {
                if( isBlocked )
                {
                    currPos = PossibleMoves.erase( currPos );
                }
                else
                {
                    ++currPos;
                }
            }
            else
            {
                ++currPos;
            }
        }

        for( auto currPos = teamVec.begin(); currPos != teamVec.end(); ++currPos )
        {
            if( temp.x == currPos->getPos().x && temp.y == currPos->getPos().y )
            {
                isBlocked = true;
            }
        }
        for( auto currPos = enemyVec.begin(); currPos != enemyVec.end(); ++currPos )
        {
            if( temp.x == currPos->getPos().x && temp.y == currPos->getPos().y )
            {
                isBlocked = true;
            }
        }
    }
}

void PossibleMovesList::removeVerticalCenter2Top( ChessPiece& any, std::vector<ChessPiece>& teamVec,
                                                  std::vector<ChessPiece>& enemyVec )
{
    bool isBlocked = false;
    Vei2 temp = Vei2( any.getPos().x, any.getPos().y - 1 );

    for( ; temp.y >= 0; temp.y--)
    {
        for( auto currPos = PossibleMoves.begin(); currPos != PossibleMoves.end(); )
        {
            if( temp.x == currPos->x && temp.y == currPos->y )
            {
                if( isBlocked )
                {
                    currPos = PossibleMoves.erase( currPos );
                }
                else
                {
                    ++currPos;
                }
            }
            else
            {
                ++currPos;
            }
        }

        for( auto currPos = teamVec.begin(); currPos != teamVec.end(); ++currPos )
        {
            if( temp.x == currPos->getPos().x && temp.y == currPos->getPos().y )
            {
                isBlocked = true;
            }
        }
        for( auto currPos = enemyVec.begin(); currPos != enemyVec.end(); ++currPos )
        {
            if( temp.x == currPos->getPos().x && temp.y == currPos->getPos().y )
            {
                isBlocked = true;
            }
        }
    }
}

void PossibleMovesList::removeVerticalCenter2Bottom( ChessPiece& any, std::vector<ChessPiece>& teamVec,
                                                  std::vector<ChessPiece>& enemyVec )
{
    bool isBlocked = false;
    Vei2 temp = Vei2( any.getPos().x, any.getPos().y + 1 );

    for( ; temp.y <= 7; temp.y++)
    {
        for( auto currPos = PossibleMoves.begin(); currPos != PossibleMoves.end(); )
        {
            if( temp.x == currPos->x && temp.y == currPos->y )
            {
                if( isBlocked )
                {
                    currPos = PossibleMoves.erase( currPos );
                }
                else
                {
                    ++currPos;
                }
            }
            else
            {
                ++currPos;
            }
        }

        for( auto currPos = teamVec.begin(); currPos != teamVec.end(); ++currPos )
        {
            if( temp.x == currPos->getPos().x && temp.y == currPos->getPos().y )
            {
                isBlocked = true;
            }
        }
        for( auto currPos = enemyVec.begin(); currPos != enemyVec.end(); ++currPos )
        {
            if( temp.x == currPos->getPos().x && temp.y == currPos->getPos().y )
            {
                isBlocked = true;
            }
        }
    }
}

void PossibleMovesList::removeDiagonalCenter2TopLeft(ChessPiece& any, std::vector<ChessPiece>& teamVec,
                                                  std::vector<ChessPiece>& enemyVec)
{
    bool isBlocked = false;
    Vei2 temp = Vei2( any.getPos().x - 1, any.getPos().y - 1 );

    for( ; temp.x >= 0 && temp.y >= 0; temp.x--, temp.y--)
    {
        for( auto currPos = PossibleMoves.begin(); currPos != PossibleMoves.end(); )
        {
            if( temp.x == currPos->x && temp.y == currPos->y )
            {
                if( isBlocked )
                {
                    currPos = PossibleMoves.erase( currPos );
                }
                else
                {
                    ++currPos;
                }
            }
            else
            {
                ++currPos;
            }
        }

        for( auto currPos = teamVec.begin(); currPos != teamVec.end(); ++currPos )
        {
            if( temp.x == currPos->getPos().x && temp.y == currPos->getPos().y )
            {
                isBlocked = true;
            }
        }
        for( auto currPos = enemyVec.begin(); currPos != enemyVec.end(); ++currPos )
        {
            if( temp.x == currPos->getPos().x && temp.y == currPos->getPos().y )
            {
                isBlocked = true;
            }
        }
    }
}

void PossibleMovesList::removeDiagonalCenter2TopRight(ChessPiece& any, std::vector<ChessPiece>& teamVec,
                                                  std::vector<ChessPiece>& enemyVec)
{
    bool isBlocked = false;
    Vei2 temp = Vei2( any.getPos().x + 1, any.getPos().y - 1 );

    for( ; temp.x <= 7 && temp.y >= 0; temp.x++, temp.y--)
    {
        for( auto currPos = PossibleMoves.begin(); currPos != PossibleMoves.end(); )
        {
            if( temp.x == currPos->x && temp.y == currPos->y )
            {
                if( isBlocked )
                {
                    currPos = PossibleMoves.erase( currPos );
                }
                else
                {
                    ++currPos;
                }
            }
            else
            {
                ++currPos;
            }
        }

        for( auto currPos = teamVec.begin(); currPos != teamVec.end(); ++currPos )
        {
            if( temp.x == currPos->getPos().x && temp.y == currPos->getPos().y )
            {
                isBlocked = true;
            }
        }
        for( auto currPos = enemyVec.begin(); currPos != enemyVec.end(); ++currPos )
        {
            if( temp.x == currPos->getPos().x && temp.y == currPos->getPos().y )
            {
                isBlocked = true;
            }
        }
    }
}

void PossibleMovesList::removeDiagonalCenter2BottomLeft(ChessPiece& any, std::vector<ChessPiece>& teamVec,
                                                  std::vector<ChessPiece>& enemyVec)
{
    bool isBlocked = false;
    Vei2 temp = Vei2( any.getPos().x - 1, any.getPos().y + 1 );

    for( ; temp.x >= 0 && temp.y <= 7; temp.x--, temp.y++)
    {
        for( auto currPos = PossibleMoves.begin(); currPos != PossibleMoves.end(); )
        {
            if( temp.x == currPos->x && temp.y == currPos->y )
            {
                if( isBlocked )
                {
                    currPos = PossibleMoves.erase( currPos );
                }
                else
                {
                    ++currPos;
                }
            }
            else
            {
                ++currPos;
            }
        }

        for( auto currPos = teamVec.begin(); currPos != teamVec.end(); ++currPos )
        {
            if( temp.x == currPos->getPos().x && temp.y == currPos->getPos().y )
            {
                isBlocked = true;
            }
        }
        for( auto currPos = enemyVec.begin(); currPos != enemyVec.end(); ++currPos )
        {
            if( temp.x == currPos->getPos().x && temp.y == currPos->getPos().y )
            {
                isBlocked = true;
            }
        }
    }
}

void PossibleMovesList::removeDiagonalCenter2BottomRight(ChessPiece& any, std::vector<ChessPiece>& teamVec,
                                                  std::vector<ChessPiece>& enemyVec)
{
    bool isBlocked = false;
    Vei2 temp = Vei2( any.getPos().x + 1, any.getPos().y + 1 );

    for( ; temp.x <= 7 && temp.y <= 7; temp.x++, temp.y++)
    {
        for( auto currPos = PossibleMoves.begin(); currPos != PossibleMoves.end(); )
        {
            if( temp.x == currPos->x && temp.y == currPos->y )
            {
                if( isBlocked )
                {
                    currPos = PossibleMoves.erase( currPos );
                }
                else
                {
                    ++currPos;
                }
            }
            else
            {
                ++currPos;
            }
        }

        for( auto currPos = teamVec.begin(); currPos != teamVec.end(); ++currPos )
        {
            if( temp.x == currPos->getPos().x && temp.y == currPos->getPos().y )
            {
                isBlocked = true;
            }
        }
        for( auto currPos = enemyVec.begin(); currPos != enemyVec.end(); ++currPos )
        {
            if( temp.x == currPos->getPos().x && temp.y == currPos->getPos().y )
            {
                isBlocked = true;
            }
        }
    }
}
