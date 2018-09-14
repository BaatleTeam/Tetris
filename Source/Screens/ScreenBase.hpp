#ifndef SCREEN_BASE_HPP_INCLUDED
#define SCREEN_BASE_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "../ResourceManager.hpp"

const int SCREEN_BASE_NOT_CHANGING_SCREEN = -10;

#include "../ScreenTypeEnum.hpp"

class ScreenBase {
public:
	ScreenBase(ResourceManager& r_m) : resourceManager(r_m) {} ;
    virtual ~ScreenBase() {};

    virtual ScreenType run (sf::RenderWindow &window) = 0;
	virtual void resizeSprites() = 0;
protected:
	ResourceManager &resourceManager;
private:
	// TODO:
	// Returning SCREEN_BASE_NOT_CHANGING_SCREEN if everything is okay? There's return statements in older
	// code that were in run function. I'm not sure exactly how it's used and my code could break smthng.
	// Also because of that I can't put while(window.PollEvent(...)) loop in processEvent function.(@Denmey)
	virtual ScreenType processEvent(const sf::Event &event) = 0;
};

#endif
