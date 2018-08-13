#include <SFML/Graphics.hpp>
#include "Button.hpp"

Button::Button(sf::Vector2f &pos, std::string &message, sf::Font &font, std::function<int()> function)
: function(function)
, relativePosition(pos)
{
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setString(message);
    text.setCharacterSize(52); // in pixels, not points! 
    text.setStyle(sf::Text::Bold);
    text.setOutlineColor(sf::Color(255, 255, 255, 200));

    rectangle.setSize(sf::Vector2f((float)(text.getLocalBounds().width + 20), 60));
    rectangle.setOutlineColor(sf::Color(255, 255, 255, 96));
    rectangle.setOutlineThickness(4);
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
        text.setOutlineThickness(1.0f);
        //text.setCharacterSize(28); // in pixels, not points! 

        //rectangle.setOutlineColor(sf::Color(0, 64, 255));
        //rectangle.setFillColor(sf::Color::Black);
        //rectangle.setOutlineThickness(2);
    } 
    else
    {
        //text.setOutlineColor(sf::Color::Black);
        text.setOutlineThickness(0.0f);
        //text.setCharacterSize(26); // in pixels, not points! 

        //rectangle.setOutlineColor(sf::Color::Cyan);
        //rectangle.setFillColor(sf::Color::Black);
        //rectangle.setOutlineThickness(2);
    }

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
            textRect.top  + textRect.height/2.0f);
}

int Button::callHBFunction() // int потому что число можно игнорировать, а из войда даже капельку информации не получишь
{
    return function();
}

void Button::setRealPosition(sf::Vector2u currentResolution)
{
    sf::Vector2f newPosition;
    newPosition.x = relativePosition.x*currentResolution.x;
    newPosition.y = relativePosition.y*currentResolution.y;

    rectangle.setPosition(newPosition);
    text.setPosition(newPosition);
}