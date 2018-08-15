#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <functional>

#define B_DEF_CHAR_SIZE 52
#define B_DEF_SPACES_FROM_BUTTON_SIDES 20
#define B_DEF_BUTTON_HEIGHT 60
#define B_DEF_RESOLUTION_WIDTH 1366
#define B_DEF_RESOLUTION_HEIGHT 768
#define B_DEF_RECT_OUTLINE_THICKNESS 4.0f

class Button : public sf::Drawable, public sf::Transformable
{
public:
    Button(sf::Vector2f &pos, std::string &message, sf::Font &font, std::function<int()> function, sf::Vector2f &scale);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void setHighlight(bool isHighlighted);

    int callHBFunction(); // int потому что число можно игнорировать, а из войда даже капельку информации не получишь

    void setRealPosition(sf::Vector2u currentResolution);

    void setOriginToCenter();
    
private:
    sf::RectangleShape rectangle;
    sf::Text text;
    sf::Vector2f relativePosition;
    std::function<int()> function;
    sf::Vector2f &scale;
};

#endif
