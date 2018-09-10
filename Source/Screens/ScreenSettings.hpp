#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Screens.hpp"


class ScreenSettings : public ScreenBase {
private:
	ButtonList buttonList;
	virtual int processEvent(const sf::Event &event) override;
public:
	ScreenSettings(Settings &settings);
	// TODO:
	// Why do we need to pass sf::RenderWindow here if we have it in settings?
	// Can't we use settings.getRenderWindow() instead?(@Denmey)
	int run(sf::RenderWindow &window);
protected:
    Settings &settings;

};
