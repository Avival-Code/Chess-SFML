#include <SFML/Graphics.hpp>
#include "Game.h"
#include "TextureCodex.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");
    TextureCodex Codex;
    Game Game( window, Codex );


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        Game.Go();

        window.display();
    }

    return 0;
}
