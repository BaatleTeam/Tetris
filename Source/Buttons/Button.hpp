#pragma once
#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <functional>

// Predefined constants for default resolution
#define B_DEF_CHAR_SIZE 52
#define B_DEF_SPACES_FROM_BUTTON_SIDES 20
#define B_DEF_BUTTON_HEIGHT 60
#define B_DEF_RESOLUTION_WIDTH 1366
#define B_DEF_RESOLUTION_HEIGHT 768
#define B_DEF_RECT_OUTLINE_THICKNESS 4.0f

// Class for draw single button
// Created for use in ButtonList
// This class is not mean to use directly
class Button : public sf::Drawable, public sf::Transformable
{
public:
    Button(sf::Vector2f &pos, std::string &message, sf::Font &font, std::function<int()> function, sf::Vector2f &scale);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    // Change button appearance based on isHighlighted variable
    void setHighlight(bool isHighlighted);

    // Call the lambda-function, which you set in constructor 
    int callHBFunction(); // int потому что число можно игнорировать, а из войда даже капельку информации не получишь

    // Change the button position based on their relative position
    void setRealPosition(sf::Vector2u currentResolution);

    // Change button and text origins to centre of button
    // Needed only if button size changed
    void setOriginToCenter();
    
private:
    sf::RectangleShape rectangle; // Bounds of buttons 
    sf::Text text; // Text of button
    sf::Vector2f relativePosition; // Relative to the position. Values between 0 and 1.
    // x - width, y - height. For example, if 0 = x and y = 0.5 then button will appear here in P
    //          
    //   0------1x>
    //   |-------
    //   P-------
    //   |-------
    //   1-------
    //   y
    std::function<int()> function; // The function, which you could call on action
    sf::Vector2f &scale; // All constants are set for resolution 1366x768,
    // for good look in other resolutions we have this variable
};

#endif