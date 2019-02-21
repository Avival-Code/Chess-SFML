#include "Game.h"

Game::Game( sf::RenderWindow& wnd, TextureCodex& txtCodex_in )
    :
    wnd( &wnd ),
    codex( &txtCodex_in ),
    Board( *codex )
{
}

Game::~Game()
{
    wnd = nullptr;
    codex = nullptr;
}

void Game::Go()
{
    UpdateModel();
    ComposeFrame();
}

void Game::UpdateModel()
{
    deltaTime += ft.Mark();
    Board.Update( deltaTime );
}

void Game::ComposeFrame()
{
    Board.Draw( *wnd );
}
