#include "Settings.hpp"
#include <iostream>

Settings::Settings(){
    screenSizes = {
                sf::Vector2u(1280, 960),
                sf::Vector2u(960, 640),
                sf::Vector2u(640, 480) };
    
    fieldSizes = { 
                sf::Vector2u(10, 20),
                sf::Vector2u(5, 10)};
    
    indexScreenSize = 0;
    indexFieldSize = 1;
    isFullScreenToggled = 0;

    if (!font.loadFromFile("Resources/Fonts/SIMPLIFICA Typeface.ttf"))
	{
		std::cout << "Font didn't load!" << std::endl;
		throw;
	}

    vars.emplace("isFullScreenToggled", isFullScreenToggled);
}

void Settings::printVars()
{
    for (auto const& x : vars)
    {
        std::cout << x.first 
                << ':' 
                << x.second 
                << std::endl;
    }
}

sf::Vector2u Settings::getScreenSize() const {
    return screenSizes[indexScreenSize];
}

sf::Vector2u Settings::getFieldSize() const {
    return fieldSizes[indexFieldSize];
}

sf::Font Settings::getFont() const {
    return font;
}

void Settings::setScreenSize(unsigned int new_index){
    // todo check value
    indexScreenSize = new_index;
}

void Settings::setFieldSize(unsigned int new_index){
    indexFieldSize = new_index;
}
