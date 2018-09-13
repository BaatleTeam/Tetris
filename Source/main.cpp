#include <iostream>
#include <memory>
#include "Screens/Screens.hpp"
#include "Settings/Settings.hpp"
#include "ResourceManager.hpp"
#include "ScreenManager.hpp"

int main()
{
	//Applications variables
	Settings settings;
	ResourceManager resourceManager{};
	ScreenManager screenManager(settings, resourceManager);

    std::cout << "[GameInit] Launching game..." << std::endl;
    screenManager.start();
    std::cout << "[GameInit] Exiting the game..." << std::endl;

	return EXIT_SUCCESS;
}
