#include "Settings.hpp"
#include <iostream>

Settings::Settings()
: window()
{
    window.requestFocus();

    screenSizes = {
                sf::Vector2u(1000, 800),
                sf::Vector2u(900, 720),
                sf::Vector2u(800, 640),
                sf::Vector2u(700, 560),
                sf::Vector2u(600, 480) };
    
    fieldSizes = { 
                sf::Vector2u(10, 20),
                sf::Vector2u(5, 10)    };
    
    indexScreenSize = 0;
    indexFieldSize = 1;
    windowName = "Tetris (beta 0.1)";
    windowStyle = 4; // 1 - sf::Style::Titlebar, 2- sf::Style::Resize,
                             //4 - sf::Style::Close, 8 sf::Style::Fullscreen

    vars.emplace("indexScreenSize", indexScreenSize);
    vars.emplace("indexFieldSize", indexFieldSize);
    vars.emplace("windowStyle", windowStyle);

    strings.emplace("windowName", windowName);

    window.create(sf::VideoMode(screenSizes[0].x, screenSizes[0].y, 32)
        , strings.find("windowName")->second
	    , vars.find("windowStyle")->second);

    window.requestFocus();
}

int Settings::getConfigurationVar(const std::string& var_name) const {
    return vars.find(var_name)->second;
}

const std::string& Settings::getConfigurationString(const std::string& string_name) const {
    return strings.find(string_name)->second;
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

sf::RenderWindow &Settings::getRenderWindow()
{
    return window;
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
