#include <SFML/Graphics.hpp>
#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED
#include "Button.hpp"
#endif
//#include <memory>

class ButtonList : public sf::Drawable, public sf::Transformable
{
public:
    ButtonList();

    void addButton(sf::Vector2f pos, std::string message, sf::Font &font, std::function<int()> function);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void updateHighlightedButton(unsigned int nextButtonNumber);

    void prevButton();

    void nextButton();

    int callCBFunction();

    int getCurrentButtonNumber();
    
private:
    std::vector<std::unique_ptr<Button>> buttonList;
    unsigned int currentButtonNumber;
};