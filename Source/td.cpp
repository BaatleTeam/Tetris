#include <iostream>
#include <SFML/Graphics.hpp>

int main(int argc, char** argv)
{
  // std::cout << "Hello, World!" << std::endl;

  // Creating window:
  sf::ContextSettings settings;
  settings.depthBits = 24;
  settings.stencilBits = 8;
  settings.antialiasingLevel = 2; // Optional
  // Doesn't work on Linux without this?
  settings.majorVersion = 3;
  settings.minorVersion = 3;
  settings.attributeFlags = sf::ContextSettings::Core;
  sf::RenderWindow window(sf::VideoMode(800, 600), "Hi, SFML!", sf::Style::Close, settings);
  settings = window.getSettings();
  std::cout << "OpenGL version: " << settings.majorVersion << "." << settings.minorVersion << std::endl;

  bool running = true;

  sf::Event event;
  
  while (running) {
    while(window.pollEvent(event)) {
      switch(event.type) {
      case sf::Event::Closed:
	running = false;
	break;
      default:
	break;
      }
    }
  }
  
  return 0;
}
