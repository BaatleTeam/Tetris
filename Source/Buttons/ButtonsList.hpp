#include <SFML/Graphics.hpp>
#include <memory>

class ButtonList : public sf::Drawable, public sf::Transformable
{
public:
    ButtonList()
    : currentButtonNumber(0)
    {}

    void add_button(sf::Vector2f pos, std::string message, sf::Font &font, std::function<int()> function)
    {
        buttonList.push_back(std::unique_ptr<Button>(new Button(pos, message, font, function)));
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

    void update_highlighted_button(unsigned int nextButtonNumber)
    {
        if (nextButtonNumber != currentButtonNumber)
        {
            buttonList[currentButtonNumber].get()->setHighlighted(false);
            buttonList[nextButtonNumber].get()->setHighlighted(true);
            currentButtonNumber = nextButtonNumber;
        }
    }

    void prev_button()
    {
        unsigned int nextButtonNumber = 0;
        if (currentButtonNumber == 0)
            nextButtonNumber = buttonList.size() - 1;
        else
            nextButtonNumber = (currentButtonNumber - 1) % buttonList.size();
        update_highlighted_button(nextButtonNumber);
    }

    void next_button()
    {
        unsigned int nextButtonNumber = (currentButtonNumber + 1) % buttonList.size();
        update_highlighted_button(nextButtonNumber);
    }

    int current_function()
    {
        return buttonList[currentButtonNumber].get()->call_function();
    }
    
private:
    std::vector<std::unique_ptr<Button>> buttonList;
    unsigned int currentButtonNumber;
};