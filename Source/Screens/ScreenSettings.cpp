#include "Screens.hpp"
#include "../Settings/Settings.hpp"
#include "../Buttons/ButtonList.hpp"

ScreenSettings::ScreenSettings(Settings &newSettings, ResourceManager& r_m)
	: ScreenBase(r_m)
	, settings(newSettings)
{
	auto callChangeResolution = [this]() -> ScreenType {
		settings.nextScreenSize();
		auto screenWidth = settings.getScreenSize().x;
		auto screenHeigth = settings.getScreenSize().y;

		settings.getRenderWindow().create(sf::VideoMode(screenWidth, screenHeigth, 32)
			, settings.getConfigurationString("windowName")
			, settings.getConfigurationVar("windowStyle"));

		buttonList.update({screenWidth, screenHeigth});

		return ScreenType::Menu;
	};

	auto callChangeFieldSize  = [this]() -> ScreenType {
		settings.nextFieldSize();
		return ScreenType::Menu;
	};

	auto callToggleFullScreen = [this]() -> ScreenType {
		// settings.vars.find("windowStyle")->second ^= sf::Style::Fullscreen;
		// sf::Vector2u windowSize = settings.getRenderWindow().getSize();

		// settings.getRenderWindow().create(sf::VideoMode(windowSize.x, windowSize.y, 32)
		// 	, settings.strings.find("windowName")->second
		// 	, settings.vars.find("windowStyle")->second);
		return ScreenType::Menu;
	};

	sf::Font &font = resourceManager.getFont();
	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*4), "Resolution",	font, callChangeResolution);
	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*6), "Field size", font, callChangeFieldSize);
	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*8), "Fullscreen", font, callToggleFullScreen);
	buttonList.update(settings.getRenderWindow().getSize());
}

ScreenType ScreenSettings::run(sf::RenderWindow &window)
{
	sf::Event event;
	bool isRunning = true;

	while (isRunning)
	{
		//Verifying events
		while (window.pollEvent(event))
		{
			auto result = processEvent(event);
			if (result != ScreenType::NotChange) {
				return result;
			}
		}

		//Clearing screen
		window.clear();

		//Drawing
		window.draw(buttonList);

		window.display();
	}

	//Never reaching this point normally, but just in case, exit the windowlication
	return ScreenType::Error;
}

void ScreenSettings::resizeSprites() {
	
}

ScreenType ScreenSettings::processEvent(const sf::Event &event) {
	sf::RenderWindow &window = settings.getRenderWindow();
	switch(event.type)
	{
		// Window closed
		case sf::Event::Closed:
			return ScreenType::Exit;
			break;

		case sf::Event::Resized:
				  std::cout << "Resize catched! New size [ " << event.size.width << ", " << event.size.height << "]" << std::endl;

				  window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
			buttonList.update(window.getSize());
				  break;

		//Key pressed
		case sf::Event::KeyPressed:
		{
			switch (event.key.code)
			{
				case sf::Keyboard::Enter:
					buttonList.callCBFunction();
					break;
				case sf::Keyboard::Escape:
					return ScreenType::Menu;
					break;
				case sf::Keyboard::Down:
					buttonList.nextButton();
					break;
				case sf::Keyboard::Up:
					buttonList.prevButton();
					break;
				default:
					break;
			}
		}
		default:
			break;
	}
	return ScreenType::NotChange;
}
