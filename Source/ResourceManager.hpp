#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class ResourceManager {
private:
    sf::Texture blockTexture;
    sf::Sprite blockSprite;
public:
    ResourceManager();

    const sf::Sprite& getSpriteBlock() const;
};