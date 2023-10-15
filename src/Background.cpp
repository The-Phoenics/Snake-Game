#include "../include/Background.h"

void Background::drawBackg(sf::RenderWindow& win)
{
    unsigned int row = WIDTH / background.getSize().x;
    unsigned int column = HEIGHT / background.getSize().y;

    for (size_t i = 0; i < row; i++)
    {
        if (i == 2) column += 2;
        for (size_t j = 0; j < column; j++)
        {
            background.setPosition(i * background.getSize().x, j * background.getSize().x);
            win.draw(background);
        }
    }
}