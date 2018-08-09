#include <SFML/Graphics.hpp>
#include "ButtonList.hpp"

ButtonList::ButtonList()
: currentButtonNumber(0)
{}

void ButtonList::add_button(sf::Vector2f pos, std::string message, sf::Font &font, std::function<int()> function)
{
    buttonList.push_back(std::unique_ptr<Button>(new Button(pos, message, font, function)));
    if(buttonList.size() == 1) // set first button as highlighted
    {
        buttonList[0].get()->setHighlight(true);
    } 
}

void ButtonList::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply the transform
    states.transform *= getTransform();

    states.texture = NULL;

    unsigned int listSize = buttonList.size();

    for(unsigned int i = 0; i < listSize; i++)
    {
        target.draw(*(buttonList[i].get()));
    }
}

void ButtonList::update_highlighted_button(unsigned int nextButtonNumber)
{
    if (nextButtonNumber != currentButtonNumber)
    {
        buttonList[currentButtonNumber].get()->setHighlight(false);
        buttonList[nextButtonNumber].get()->setHighlight(true);
        currentButtonNumber = nextButtonNumber;
    }
}

void ButtonList::prev_button()
{
    unsigned int nextButtonNumber = 0;
    if (currentButtonNumber == 0)
        nextButtonNumber = buttonList.size() - 1;
    else
        nextButtonNumber = (currentButtonNumber - 1) % buttonList.size();
    update_highlighted_button(nextButtonNumber);
}

void ButtonList::next_button()
{
    unsigned int nextButtonNumber = (currentButtonNumber + 1) % buttonList.size();
    update_highlighted_button(nextButtonNumber);
}

int ButtonList::current_function()
{
    return buttonList[currentButtonNumber].get()->call_function();
}

int ButtonList::getCurrentButtonNumber()
{
    return currentButtonNumber;
}