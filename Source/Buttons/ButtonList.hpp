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

    void add_button(sf::Vector2f pos, std::string message, sf::Font &font, std::function<int()> function);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void update_highlighted_button(unsigned int nextButtonNumber);

    void prev_button();

    void next_button();

    int current_function();

    int getCurrentButtonNumber();
    
private:
    std::vector<std::unique_ptr<Button>> buttonList;
    unsigned int currentButtonNumber;
};