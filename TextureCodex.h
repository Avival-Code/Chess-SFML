#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class TextureCodex
{
public:
    TextureCodex();
    sf::Texture& getTexture( const int texture_pos);

private:
    static constexpr int totalTextures = 12;
    std::vector<sf::Texture> Textures;
    std::vector<std::string> fileNames = {"King Bl.png", "King Wh.png", "Queen Bl.png", "Queen Wh.png", "Bishop Bl.png", "Bishop Wh.png",
                                     "Knight Bl.png", "Knight Wh.png", "Rook Bl.png", "Rook Wh.png", "Pawn Bl.png", "Pawn Wh.png"};
};
