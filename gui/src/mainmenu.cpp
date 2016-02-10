#include "mainmenu.h"
#include "hexagon.h"
#include "mainwindow.h"
#include "texturecache.h"
#include <algorithm>


namespace gui {
using namespace std;

MainMenu::MainMenu()
{
  mmenuItems.emplace_back( MenuItem {
      RelRect{0.25, 0.3, 0.5, 0.3},
      MenuResult::Play,
      sf::String{"Play"},
      sf::Color::Blue
    }
  );
  mmenuItems.emplace_back( MenuItem {
    RelRect{0.25, 0.7, 0.5, 0.2},
    MenuResult::Exit,
    sf::String{"Exit"},
    sf::Color::Red
  });
}

MenuResult MainMenu::Show(sf::RenderWindow &window) {
  for( auto const & mi : mmenuItems ) {
    AbsRect absrect = mainWindow->GetAbsRectFromRel(mi.rect);
    sf::RectangleShape r{
      sf::Vector2f{float(absrect.width), float(absrect.height)}
    };
    r.setPosition(absrect.left, absrect.top);
    sf::Color c = mi.color;
    c.a = 125;
    r.setFillColor(c);
    window.draw(r);
  }
  window.display();
  return GetMenuResponse(window);
}

MenuResult MainMenu::HandleClick(int x, int y) {
  auto retit =
      find_if(begin(mmenuItems), end(mmenuItems), [x, y](MenuItem const &m) -> bool {
        AbsRect r = mainWindow->GetAbsRectFromRel(m.rect);
        bool iny = r.top + r.height > y && r.top < y;
        bool inx = r.left < x && r.left + r.width > x;
        return iny && inx;
      });
  return retit != end(mmenuItems) ? retit->action : MenuResult::Nothing;
}

MenuResult MainMenu::GetMenuResponse(sf::RenderWindow &window) {
  sf::Event menuEvent;
  while ("forever") {
    while (window.pollEvent(menuEvent)) {
      if (menuEvent.type == sf::Event::MouseButtonPressed) {
        return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
      }
      if (menuEvent.type == sf::Event::Closed) {
        return MenuResult::Exit;
      }
    }
  }
  throw std::runtime_error(__FUNCTION__);
}
}
