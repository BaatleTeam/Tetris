#include <SFML/Graphics.hpp>
#include "ButtonList.hpp"
#include <iostream>

ButtonList::ButtonList()
: currentButtonNumber(0)
{}

void ButtonList::addButton(sf::Vector2f relativePosition, std::string message, sf::Font &font, std::function<ScreenType()> function)
{
    buttonList.push_back(std::unique_ptr<Button>(new Button(relativePosition, message, font, function, scale)));    
    buttonList.back()->setRealPosition(sf::Vector2u(B_DEF_RESOLUTION_WIDTH, B_DEF_RESOLUTION_HEIGHT));
    
    if(buttonList.size() == 1) buttonList[0].get()->setHighlight(true); // set first button as highlighted
}

void ButtonList::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply the transform
    states.transform *= getTransform();

    states.texture = NULL;

    unsigned int listSize = buttonList.size();

    for(unsigned int i = 0; i < listSize; i++)
        target.draw(*(buttonList[i].get()));
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

ScreenType ButtonList::callCBFunction()
{
    return buttonList[currentButtonNumber].get()->callHBFunction();
}

int ButtonList::getCurrentButtonNumber()
{
    return currentButtonNumber;
}

void ButtonList::updateScale(sf::Vector2u &resolution)
{
    scale.x = (float)resolution.x/B_DEF_RESOLUTION_WIDTH;
    scale.y = (float)resolution.y/B_DEF_RESOLUTION_HEIGHT;
}

void ButtonList::updateResolution(sf::Vector2u &resolution)
{
    for(auto &button : buttonList)
        button->setRealPosition(resolution);
}

void ButtonList::update(sf::Vector2u resolution)
{
    updateScale(resolution);
    updateResolution(resolution);
    buttonList[currentButtonNumber].get()->setHighlight(true);
}