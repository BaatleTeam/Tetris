#pragma once
#include <SFML/Graphics.hpp>

class ScreenBase {
public:
    virtual int run (sf::RenderWindow &App) = 0;
    virtual ~ScreenBase() {};
};