#pragma once
#include "Tile.h"
#include "TextureCodex.h"
#include "Selector.h"
#include "Vec2.h"
#include "Player.h"
#include "Announcer.h"

class Board
{
public:
    Board( TextureCodex& txtCodex );
    ~Board();
    void Draw( sf::RenderWindow& wnd );
    void Update( float& deltaTime );

private:
    static constexpr int width = 8;
    static constexpr int height = 8;
    static constexpr float tileSize = 50.0f;
    int TotalTiles = width * height;
    Tile* Tiles = nullptr;
    Vef2 pos = Vef2( 200.0f, 100.0f );
    TextureCodex* Codex = nullptr;
    Selector selector;
    Player Player1;
    Player Player2;
	Announcer Ann;
    bool isItPlayer1Turn = true;
};
