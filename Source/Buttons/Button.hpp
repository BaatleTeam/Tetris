#include <SFML/Graphics.hpp>
#include <functional>

#define CHARACTER_SIZE 24 // Зависит от шрифта и хотелки программера

class Button : public sf::Drawable, public sf::Transformable
{
public:
    Button(sf::Vector2f &pos, std::string &message, sf::Font &font, std::function<int()> function);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void setHighlight(bool isHighlighted);

    int callHBFunction(); // int потому что число можно игнорировать, а из войда даже капельку информации не получишь

    void setRealPosition(sf::Vector2u currentResolution);
    
private:
    sf::RectangleShape rectangle;
    sf::Text text;
    sf::Vector2f relativePosition;
    std::function<int()> function;
};

