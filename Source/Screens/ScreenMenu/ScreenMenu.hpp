#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Screens.hpp"
#include "../../Settings/Settings.hpp"
#include "../../Buttons/ButtonList.hpp"

class ButtonList;

class ScreenMenu : public ScreenBase {
private:
	ButtonList buttonList;
	virtual ScreenType processEvent(const sf::Event &event) override;
public:
	ScreenMenu(Settings &settings, ResourceManager&);
	// TODO:
	// Why do we need to pass sf::RenderWindow here if we have it in settings?
	// Can't we use settings.getRenderWindow() instead?(@Denmey)
	ScreenType run(sf::RenderWindow &window) override;
	void resizeSprites() override;
protected:
    Settings &settings;
};
