#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class ResourceManager {
private:
    sf::Texture cellTexture;
public:
    ResourceManager();

    sf::Texture& getCellTexture();
};