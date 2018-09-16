#include "ScreenManager.hpp"

ScreenManager::ScreenManager(Settings &settings, ResourceManager &resourceManager)
    : settings(settings), isResolutionChanged(true)
{
	Screens.reserve(4);
	int screen = 0;

	try {
		Screens.push_back(std::unique_ptr<ScreenMenu>(new ScreenMenu(settings, resourceManager)));
		Screens.push_back(std::unique_ptr<ScreenGame>(new ScreenGame(settings, resourceManager)));
		Screens.push_back(std::unique_ptr<ScreenSettings>(new ScreenSettings(settings, resourceManager, *this)));
		// Screens.push_back(std::unique_ptr<ScreenGame>(new ScreenGame(settings, resourceManager)));
	}
	catch(...) {
		std::cout << "Fail to load screens";
		exit(-1);
	}
}

void ScreenManager::start()
{
    std::cout << "[SM] Opening menu..." << std::endl;

    ScreenType nextScreen = ScreenType::Menu;

    while(true)
    {
        nextScreen = Screens[static_cast<int>(nextScreen)]->run(settings.getRenderWindow());

        if (isResolutionChanged)
        {
            resizeAllSprites();
            isResolutionChanged = false;
        } 

        switch(nextScreen)
        {
            case ScreenType::Menu:
                break;
            
            case ScreenType::Game:
                std::cout << "[SM] Game!!!!!" << std::endl;
                break;
            
            case ScreenType::Settings:
                std::cout << "[SM] Settings!!!" << std::endl;
                break;

            case ScreenType::Exit:
                std::cout << "[SM] Return value \"Exit\" catched! Exiting" << std::endl;
                return;
                break;

            case ScreenType::Error:
                std::cout << "[SM] Return value \"Error\" catched! Exiting" << std::endl;
                return;
                break;
        }
    }
    
}

void ScreenManager::resizeAllSprites(){
    for (auto &screen : Screens)
        screen.get()->resizeSprites();
}   

void ScreenManager::setResolutionChanged(){
    isResolutionChanged = true;
}