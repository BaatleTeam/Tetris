#include "Button.hpp"
#include <iostream>

Button::Button(sf::Vector2f &pos, std::string &message, sf::Font &font, std::function<int()> function, sf::Vector2f &scale)
: relativePosition(pos)
, function(function)
, scale(scale)
{
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setString(message);
    text.setCharacterSize(B_DEF_CHAR_SIZE * scale.y); // in pixels, not points! 
    text.setStyle(sf::Text::Bold);
    text.setOutlineColor(sf::Color(255, 255, 255, 200));

   rectangle.setSize(sf::Vector2f((float)(text.getLocalBounds().width +  B_DEF_SPACES_FROM_BUTTON_SIDES * scale.x) 
                                                                        , B_DEF_BUTTON_HEIGHT * scale.y));
    rectangle.setOutlineThickness(B_DEF_RECT_OUTLINE_THICKNESS * scale.y);
    rectangle.setOutlineColor(sf::Color(255, 255, 255, 96));
    rectangle.setFillColor(sf::Color(255, 255, 255, 64));
    
    setOriginToCenter();
}

void Button::setOriginToCenter()
{
    sf::FloatRect newOrigin = rectangle.getLocalBounds();
    rectangle.setOrigin(newOrigin.left + newOrigin.width/2.0f,
            newOrigin.top  + newOrigin.height/2.0f);

    newOrigin = text.getLocalBounds();
    text.setOrigin(newOrigin.left + newOrigin.width/2.0f,
            newOrigin.top  + newOrigin.height/2.0f); 
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply the transform
    states.transform *= getTransform();

    // our particles don't use a texture
    states.texture = NULL;

    // draw the vertex array
    target.draw(rectangle, states);
    target.draw(text, states);
}

void Button::setHighlight(bool isHighlighted)
{
    if(isHighlighted)
    {
        text.setOutlineThickness(2.0f * scale.y);
        //text.setCharacterSize(28); // in pixels, not points! 

        //rectangle.setOutlineColor(sf::Color(0, 64, 255));
        //rectangle.setFillColor(sf::Color::Black);
        //rectangle.setOutlineThickness(2);
    } 
    else
    {
        text.setOutlineThickness(0.0f);
    }
}

int Button::callHBFunction()
{
    return function();
}

void Button::setRealPosition(sf::Vector2u currentResolution)
{
    //std::cout << "scale " << (float)scale.x << ":" << (float)scale.y << std::endl;

    sf::Vector2f newPosition;
    newPosition.x = relativePosition.x*currentResolution.x;
    newPosition.y = relativePosition.y*currentResolution.y;

    text.setCharacterSize(B_DEF_CHAR_SIZE * scale.y);
    rectangle.setSize(sf::Vector2f((float)(text.getLocalBounds().width +  B_DEF_SPACES_FROM_BUTTON_SIDES * scale.x) 
                                                                        , B_DEF_BUTTON_HEIGHT * scale.y));
    rectangle.setOutlineThickness(B_DEF_RECT_OUTLINE_THICKNESS * scale.y);

    rectangle.setPosition(newPosition);
    text.setPosition(newPosition);
    setOriginToCenter();
}