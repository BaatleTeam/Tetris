#pragma once

class cScreen
{
public:
    virtual int Run (sf::RenderWindow &App) = 0;
    virtual ~cScreen();
};