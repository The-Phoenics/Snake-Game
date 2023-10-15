#pragma once
#include <SFML/Graphics.hpp>
#include "Fruit.h"

class Snake
{
public:
    Snake();
    ~Snake() {}

    void drawSnake(sf::RenderWindow &win);
    void eatFruit(Fruit &fruit);
    bool isGameOver();
    void updateSnakePos();
    void changeDir();
    void restartSnake();

    inline void setSnakePosition(sf::Vector2f pos) { m_snake.setPosition(pos); }
    inline sf::Vector2f getSnakePosition() const { return m_snake.getPosition(); }

    // TODO: Replace (int)dir with (enum)dir 
    int dir;

private:
    inline void initSnake();

private:
    sf::RectangleShape m_snake;
    sf::Texture m_snakeText;
    std::vector<sf::Vector2f> coords;
    sf::Font m_scoreFont;
    sf::Text m_score;
    long m_scoreValue;
};
