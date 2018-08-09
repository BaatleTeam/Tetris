#include <SFML/Graphics.hpp>

#define CHARACTER_SIZE 12 // Зависит от шрифта

class Button : public sf::Drawable, public sf::Transformable
{
public:
    Button(sf::Vector2f &pos, std::string &message, sf::Font &font);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void setHighlighted(bool isHighlighted)
    {
        if(isHighlighted)
        {
            text.setFillColor(sf::Color::Red);
            //text.setCharacterSize(24); // in pixels, not points! 

            rectangle.setOutlineColor(sf::Color::Red);
            //rectangle.setFillColor(sf::Color::Black);
            //rectangle.setOutlineThickness(2);
        } 
        else
        {
            text.setFillColor(sf::Color::Blue);
            //text.setCharacterSize(24); // in pixels, not points! 

            rectangle.setOutlineColor(sf::Color::Cyan);
            //rectangle.setFillColor(sf::Color::Black);
            //rectangle.setOutlineThickness(2);
        }
    }
private:
    sf::RectangleShape rectangle;
    sf::Text text;

};

