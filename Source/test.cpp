// Demonstrate creating a spritesheet
#include "SFML/Graphics.hpp"

int main(int argc, char ** argv){
  sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Demo Game");

  sf::Event event;
  sf::Texture texture;

//   sf::Sprite sprite(texture,sf::IntRect(0,0,300,400));
    texture.loadFromFile("Resources/Pictures/testSprite.png");
    sf::Sprite sprite1(texture);
    sprite1.setColor(sf::Color::Green);
    sprite1.setScale(0.5f, 0.5f);
    sprite1.setPosition(100,100);

    sf::Sprite sprite2(texture);
    sprite2.setColor(sf::Color::Red);
    sprite2.setScale(0.5f, 0.5f);
    sprite2.setPosition(200, 100);

    sf::Sprite sprite3(texture);
    sprite3.setColor(sf::Color::Cyan);
    sprite3.setScale(0.5f, 0.5f);
    sprite3.setPosition(300, 100);

    sf::Sprite sprite4(texture);
    sprite4.setColor(sf::Color::Yellow);
    sprite4.setScale(0.5f, 0.5f);
    sprite4.setPosition(300, 0);

  while (renderWindow.isOpen()){
    while (renderWindow.pollEvent(event)){
      if (event.type == sf::Event::EventType::Closed)
        renderWindow.close();
    }

    renderWindow.clear();
    renderWindow.draw(sprite1);
    renderWindow.draw(sprite2);
    renderWindow.draw(sprite3);
    renderWindow.draw(sprite4);
    renderWindow.display();
  }
}