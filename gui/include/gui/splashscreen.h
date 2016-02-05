#pragma once
#include "gui.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
namespace gui {
class SplashScreen {
public:
  void Show(sf::RenderWindow &window);
};
}
