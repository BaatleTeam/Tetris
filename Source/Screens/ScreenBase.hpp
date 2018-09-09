#ifndef SCREEN_BASE_HPP_INCLUDED
#define SCREEN_BASE_HPP_INCLUDED

#include <SFML/Graphics.hpp>

const int SCREEN_BASE_NOT_CHANGING_SCREEN = -10;

class ScreenBase {
public:
    virtual int run (sf::RenderWindow &window) = 0;
    virtual ~ScreenBase() {};
private:
	// TODO:
	// Returning 0 if everything is okay? There's 'return -1' statement in older
	// code that was in run function. I'm not sure exactly how it's used and my code could break smthng.
	// Also because of that I can't put while loop in this function.(@Denmey)
	virtual int processEvent(const sf::Event &event) = 0;
};

#endif
