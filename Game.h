#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "TextureCodex.h"
#include "FrameTimer.h"

class Game
{
public:
    Game( sf::RenderWindow& wnd, TextureCodex& txtCodex_in);
    void Go();
    void UpdateModel();
    void ComposeFrame();
    ~Game();

private:
    sf::RenderWindow* wnd = nullptr;
    TextureCodex* codex = nullptr;

private:
    /////////////////////////////////////
    ///// Enter User Variables Here /////
    /////////////////////////////////////
    FrameTimer ft;
    float deltaTime = 0.0f;
    Board Board;
};
