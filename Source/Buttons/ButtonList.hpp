#ifndef BUTTON_LIST_HPP_INCLUDED
#define BUTTON_LIST_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "Button.hpp"

// Class for list of buttons
// Mean to use even for one button
class ButtonList : public sf::Drawable, public sf::Transformable
{
public:
    // Constructor with current resolution
    // Need to preset scale
    ButtonList(sf::Vector2u resolution);

    // Add button in list 
    void addButton(sf::Vector2f relativePosition, std::string message, sf::Font &font, std::function<int()> function);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    // Change highlighted button from one button to another 
    void updateHighlightedButton(unsigned int nextButtonNumber);

    // Change current button to previous button
    void prevButton();

    // Change current button to next button
    void nextButton();

    // Call lambda-function of current button
    int callCBFunction();

    // Return number of current button (index) in buttonList vector
    int getCurrentButtonNumber();
    
    // Update scale and change size of all buttons in list
    void updateScale(sf::Vector2u resolution);

    // Update position of all buttons in list
    void updateResolution(sf::Vector2u newResolution);

private:
    std::vector<std::unique_ptr<Button>> buttonList; // Container to save buttons
    unsigned int currentButtonNumber; // Index of highlighted button 
    sf::Vector2f scale;
};

#endif