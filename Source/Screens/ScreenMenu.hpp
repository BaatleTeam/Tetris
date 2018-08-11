#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include "ScreenBase.hpp"


class ScreenMenu : public ScreenBase {
private:
	// bool playing;
	sf::Font font;
	
public:
	ScreenMenu();
	int run(sf::RenderWindow &App);
};