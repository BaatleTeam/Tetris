#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class ResourceManager {
private:
    sf::Font font;
    sf::Texture cellTexture;
public:
    ResourceManager();
    sf::Font& getFont();

    sf::Texture& getCellTexture();
};