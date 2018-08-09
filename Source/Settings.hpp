#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>

typedef unsigned int uint;

class Settings {
private:
    std::vector<sf::Vector2u> screenSizes;
    std::vector<sf::Vector2u> fieldSizes;
    // сложность
    // цвет - ?
    
    int indexScreenSize;
    int indexFieldSize;

public:
    Settings();
    ~Settings() = default;
    static const int StandartWidth = 1280;

    sf::Vector2u getScreenSize() const;
    sf::Vector2u getFieldSize() const;

    void setScreenSize(unsigned int index);
    void setFieldSize(unsigned int index);
};