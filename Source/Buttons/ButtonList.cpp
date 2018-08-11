#include <SFML/Graphics.hpp>
#include "ButtonList.hpp"

ButtonList::ButtonList()
: currentButtonNumber(0)
{}

void ButtonList::addButton(sf::Vector2f pos, std::string message, sf::Font &font, std::function<int()> function)
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

void ButtonList::updateHighlightedButton(unsigned int nextButtonNumber)
{
    if (nextButtonNumber != currentButtonNumber)
    {
        buttonList[currentButtonNumber].get()->setHighlight(false);
        buttonList[nextButtonNumber].get()->setHighlight(true);
        currentButtonNumber = nextButtonNumber;
    }
}

void ButtonList::prevButton()
{
    unsigned int nextButtonNumber = 0;
    if (currentButtonNumber == 0)
        nextButtonNumber = buttonList.size() - 1;
    else
        nextButtonNumber = (currentButtonNumber - 1) % buttonList.size();
    updateHighlightedButton(nextButtonNumber);
}

void ButtonList::nextButton()
{
    unsigned int nextButtonNumber = (currentButtonNumber + 1) % buttonList.size();
    updateHighlightedButton(nextButtonNumber);
}

int ButtonList::callCBFunction()
{
    return buttonList[currentButtonNumber].get()->callHBFunction();
}

int ButtonList::getCurrentButtonNumber()
{
    return currentButtonNumber;
}