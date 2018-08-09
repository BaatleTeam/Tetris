#include <SFML/Graphics.hpp>
#include "Buttons.hpp"

Button::Button(sf::Vector2f &pos, std::string &message, sf::Font &font)
{
    text.setFont(font);
    text.setFillColor(sf::Color::Blue);
    text.setString(message);
    text.setCharacterSize(26); // in pixels, not points! 
    text.setStyle(sf::Text::Bold);

    rectangle.setSize(sf::Vector2f((float)(message.size() * CHARACTER_SIZE + 10), 30));
    rectangle.setOutlineColor(sf::Color::Cyan);
    rectangle.setOutlineThickness(2);
    rectangle.setPosition(pos);
    rectangle.setFillColor(sf::Color::Black);
    
    sf::FloatRect textRect = rectangle.getLocalBounds();
    rectangle.setOrigin(textRect.left + textRect.width/2.0f,
            textRect.top  + textRect.height/2.0f);

    text.setPosition(pos);

    textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
            textRect.top  + textRect.height/2.0f); 
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