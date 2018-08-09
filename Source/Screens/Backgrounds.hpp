#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "../Settings.hpp"

class Background {
private:
	sf::Texture texture;
	sf::Sprite backgroundSprite;
public:
	Background(const Settings *settings, const std::string &path);
	void Draw(sf::RenderWindow &WIN);
};