#include <SFML/Graphics.hpp>
#include <memory>

class ButtonList : public sf::Drawable, public sf::Transformable
{
public:
    ButtonList()
    : currentButtonNumber(0)
    {}

    void add_button(sf::Vector2f pos, std::string message, sf::Font &font)
    {
        buttonList.push_back(std::unique_ptr<Button>(new Button(pos, message, font)));
        if(buttonList.size() == 1) // set first button as highlighted
        {
            buttonList[0].get()->setHighlighted(true);
        }
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const
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

    void next_button()
    {

    }

    void prev_button()
    {
        
    }
    
private:
    std::vector<std::unique_ptr<Button>> buttonList;
    unsigned int currentButtonNumber;
};