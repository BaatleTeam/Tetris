#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class ResourceManager {
private:
    sf::Font font;
    sf::Texture cellTexture;
    sf::Texture backgroundGame;
public:
    ResourceManager();
    sf::Font& getFont();

    sf::Texture& getCellTexture();
    sf::Texture& getBackground(std::string bcg_name);
};