#include <SFML/Graphics.hpp>
#include <vector>
#include "Background.h"
#include "Fruit.h"
#include "Snake.h"

constexpr float VELOCITY = 25.f;

#define WIDTH  800
#define HEIGHT 600

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Snake Game", sf::Style::Close);
    window.setFramerateLimit(60);

    Background backg;
    Snake snake;
    Fruit fruit;
    int tick = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                backg.isPlaying = true;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
                backg.isPlaying = false;

        }

        // change snake direction with key input (WASD)
        if (backg.isPlaying)
        {
            snake.changeDir();
            
            if (tick == 10)
            {
                if (snake.isGameOver())
                {
                    snake.restartSnake();
                    fruit.setRandomPos();
                    backg.isPlaying = false;
                }
                snake.updateSnakePos();
                snake.eatFruit(fruit);
                tick = 1;
            }

            if (tick == 0) {
                backg.isPlaying = false;
            }
            tick++;

            // rendering
            window.clear(sf::Color::White);
            backg.drawBackg(window);
            fruit.drawFruit(window);
            snake.drawSnake(window);
            window.display();
        }
    }

    return 0;
}