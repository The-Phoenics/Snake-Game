#pragma once
#include <SFML/Graphics.hpp>
#include "Global.h"

#define WIDTH  800
#define HEIGHT 600

class Background
{
public:
    Background() 
    { 
        initBackg();
        isPlaying = true; 
    }
    ~Background() { }

    void drawBackg(sf::RenderWindow& win);

public:
    bool isPlaying;

private:
    void initBackg()
    {
        backgText.loadFromFile(RESOURCE_PATH + std::string{ "/resources/grass.png" });
        background.setSize(sf::Vector2f(25.f, 25.f));
        background.setTexture(&backgText);
    }

    sf::RectangleShape background;
    sf::Texture backgText;
};

