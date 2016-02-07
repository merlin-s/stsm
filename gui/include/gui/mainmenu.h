#pragma once
#include "gui.h"
#include "hexboard.h"

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <list>

namespace gui {
class MainMenu {

public:
  enum class MenuResult { Nothing, Exit, Play };

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
