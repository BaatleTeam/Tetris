#include "Settings.hpp"
#include <iostream>

Settings::Settings()
: App()
{
    App.requestFocus();

    screenSizes = {
                sf::Vector2u(1920,1080),
                sf::Vector2u(1366, 768),
                sf::Vector2u(1280, 768),
                sf::Vector2u(1280, 720),
                sf::Vector2u(1024, 600),
                sf::Vector2u(800 , 600) };
    
    fieldSizes = { 
                sf::Vector2u(10, 20),
                sf::Vector2u(5, 10)    };
    
    indexScreenSize = 1;
    indexFieldSize = 1;
    windowName = "!!Mega Tetris!!";
    windowStyle = 1 | 2 | 4; // 1 - sf::Style::Titlebar, 2- sf::Style::Resize,
                             //4 - sf::Style::Close, 8 sf::Style::Fullscreen

    vars.emplace("indexScreenSize", indexScreenSize);
    vars.emplace("indexFieldSize", indexFieldSize);
    vars.emplace("windowStyle", windowStyle);
    strings.emplace("windowName", windowName);

    if (!font.loadFromFile("Resources/Fonts/SIMPLIFICA Typeface.ttf")) {
		std::cout << "Font didn't load!" << std::endl;
		throw;
	}

    App.create(sf::VideoMode(1366, 768, 32)
        , strings.find("windowName")->second
	    , vars.find("windowStyle")->second);

    App.requestFocus();
}

void Settings::printVars() const {
    for (auto const& x : vars) 
        std::cout << x.first << ':' << x.second << std::endl;
    
    for (auto const& x : strings) 
        std::cout << x.first << ':' << x.second << std::endl;

    std::cout << std::endl;
}

sf::Vector2u Settings::getScreenSize() const {
    return screenSizes[indexScreenSize];
}

sf::Vector2u Settings::getFieldSize() const {
    return fieldSizes[indexFieldSize];
}

sf::Font &Settings::getFont(){
    return font;
}

sf::RenderWindow &Settings::getRenderWindow()
{
    return App;
}

void Settings::setScreenSize(unsigned int new_index) {
    if(new_index >= screenSizes.size()) {
        std::cout << "There is no such resolution index. Index set to default (0)" << std::endl;
        indexScreenSize = 0;
        return;
    }
    indexScreenSize = new_index;
}

void Settings::setFieldSize(unsigned int new_index) {
    if(new_index >= fieldSizes.size()) {
        std::cout << "There is no such field size index. Index set to default (0)" << std::endl;
        indexFieldSize = 0;
        return;
    }
    indexFieldSize = new_index;
}

void Settings::nextScreenSize() {
    setScreenSize(indexScreenSize + 1);
}
void Settings::nextFieldSize() {
    setFieldSize(indexFieldSize + 1);
}
