#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Screens.hpp"

class ScreenManager;

class ScreenSettings : public ScreenBase {
private:
	ButtonList buttonList;
	ScreenManager &screenManager;

	virtual ScreenType processEvent(const sf::Event &event) override;

public:
	ScreenSettings(Settings &settings, ResourceManager &r_m, ScreenManager &screenManager);
	// TODO:
	// Why do we need to pass sf::RenderWindow here if we have it in settings?
	// Can't we use settings.getRenderWindow() instead?(@Denmey)
	ScreenType run(sf::RenderWindow &window);
	void resizeSprites() override;
protected:
    Settings &settings;

};
