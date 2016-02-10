#pragma once
#include "gui.h"
#include "hexboard.h"

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "util/enum.h"

#include <list>

namespace gui {
DEF_ENUM_IN_NS(MenuResult, Nothing, Exit, Play);
class MainMenu {
public:
  MainMenu();
  MainMenu(MainMenu const&) = delete;
  MainMenu& operator=(MainMenu const&) = delete;

  MenuResult Show(sf::RenderWindow &window);

private:
  struct MenuItem {
    RelRect    rect;
    MenuResult action;
    sf::String text;
    sf::Color  color;
  };
  MenuResult GetMenuResponse(sf::RenderWindow &window);
  MenuResult HandleClick(int x, int y);
  std::list<MenuItem> mmenuItems;
};
}
