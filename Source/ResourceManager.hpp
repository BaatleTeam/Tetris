#pragma once
#include <iostream>
#include <map>
#include <array>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

static constexpr size_t TexturesNumber = 2;
static constexpr size_t SoundsNumber = 2;

static constexpr auto resourceDirectory = "Resources";
static constexpr auto textureDirectory = "Pictures";
static constexpr auto soundDirectory = "Sounds";

static constexpr std::array<const char*, TexturesNumber> textureNames {
    "clear.wav",
    "fall.wav",
};
static constexpr std::array<const char*, SoundsNumber> soundNames {
    "testSprite.png",
    "background.png",
};

class ResourceManager {
private:
    sf::Font font;
    sf::Texture cellTexture;
    sf::Texture backgroundGame;

    sf::SoundBuffer figureLanded;
    sf::SoundBuffer lineCleared;

    std::map <std::string, sf::SoundBuffer> soundsContainer;
    std::map <std::string, sf::Texture> textureContainer;
public:
    ResourceManager();
    sf::Font& getFont();

    sf::Texture& getCellTexture();
    sf::Texture& getBackground(std::string bcg_name);
};