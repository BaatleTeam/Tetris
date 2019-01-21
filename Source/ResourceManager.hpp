#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class ResourceManager {
private:
    sf::Font font;
    sf::Texture cellTexture;
    sf::Texture backgroundGame;

    sf::SoundBuffer figureLanded;
public:
    ResourceManager();
    sf::Font& getFont();

    sf::Texture& getCellTexture();
    sf::Texture& getBackground(std::string bcg_name);
};