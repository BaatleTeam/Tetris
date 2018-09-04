#ifndef SCREEN_BASE_HPP_INCLUDED
#define SCREEN_BASE_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class ScreenBase {
public:
    virtual int run (sf::RenderWindow &App) = 0;
    virtual ~ScreenBase() {};
};

#endif