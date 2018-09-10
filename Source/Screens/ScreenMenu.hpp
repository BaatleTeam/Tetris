#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Screens.hpp"
#include "../Settings/Settings.hpp"
#include "../Buttons/ButtonList.hpp"


class ScreenMenu : public ScreenBase {
private:
	ButtonList buttonList;
	virtual int processEvent(const sf::Event &event) override;
public:
	ScreenMenu(Settings &settings);
	// TODO:
	// Why do we need to pass sf::RenderWindow here if we have it in settings?
	// Can't we use settings.getRenderWindow() instead?(@Denmey)
	int run(sf::RenderWindow &window);
protected:
    Settings &settings;
};
