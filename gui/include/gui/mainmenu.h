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
  struct MenuItem {
  public:
    AbsRect rect;
    MenuResult action;
  };
  MenuResult Show(sf::RenderWindow &window);

private:
  MenuResult GetMenuResponse(sf::RenderWindow &window);
  MenuResult HandleClick(int x, int y);
  std::list<MenuItem> mmenuItems;
};
}
