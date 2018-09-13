#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Settings/Settings.hpp"
#include "Screens/Screens.hpp"

class ScreenManager {
private:
    Settings &settings;
    // sf::RenderWindow window;
    std::vector<std::unique_ptr<ScreenBase>> Screens;
    
public:
    ScreenManager(Settings &settings, ResourceManager&);
    // ~ScreenManager();
    void start();
};