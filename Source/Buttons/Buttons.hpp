#include <SFML/Graphics.hpp>

#define CHARACTER_SIZE 12 // Зависит от шрифта

class Button : public sf::Drawable, public sf::Transformable
{
public:
    Button(sf::Vector2f pos, std::string message, sf::Font &font);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    sf::RectangleShape rectangle;
    sf::Text text;
};