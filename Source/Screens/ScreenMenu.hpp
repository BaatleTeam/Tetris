#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Screens.hpp"
#include "../Settings/Settings.hpp"
#include "../Buttons/ButtonList.hpp"


class ScreenMenu : public ScreenBase {
private:
	sf::Font font;
	ButtonList buttonList;
public:
	// ScreenMenu();
	ScreenMenu(Settings &settings);
	int run(sf::RenderWindow &App);
protected:
    // Settings &settings;
};