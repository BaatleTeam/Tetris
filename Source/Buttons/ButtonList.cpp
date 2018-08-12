#include <SFML/Graphics.hpp>
#include "ButtonList.hpp"
#include <iostream>

ButtonList::ButtonList(sf::Vector2u resolution)
: currentButtonNumber(0)
, currentResolution(resolution)
{}

void ButtonList::addButton(sf::Vector2f relativePosition, std::string message, sf::Font &font, std::function<int()> function)
{
    buttonList.push_back(std::unique_ptr<Button>(new Button(relativePosition, message, font, function)));
    buttonList.back()->setRealPosition(currentResolution);
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

void ButtonList::updateResolution(sf::Vector2u newResolution)
{
    for(auto &button : buttonList)
    {
        button->setRealPosition(newResolution);
    }
}