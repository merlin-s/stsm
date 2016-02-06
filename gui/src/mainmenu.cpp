#include "mainmenu.h"
#include "hexagon.h"
#include "mainwindow.h"
#include "texturecache.h"
#include <algorithm>

namespace gui {
using namespace std;

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow &window) {

  // Load menu image from file
  sf::Sprite sprite = TextureCache::getSprite("mainmenu.png");

  // Setup clickable regions

  // Play menu item coordinates
  MenuItem playButton;
  playButton.rect = mainWindow->getRelRect(0.0, 145. / 768., 235. / 768., 1.0);
  playButton.action = MenuResult::Play;

  // Exit menu item coordinates
  MenuItem exitButton;
  exitButton.rect = mainWindow->getRelRect(0.0, 383. / 768., 180. / 768., 1.0);
  exitButton.action = MenuResult::Exit;

  mmenuItems.push_back(playButton);
  mmenuItems.push_back(exitButton);
  sf::Color c;
  sf::RectangleShape erect(
      sf::Vector2f(exitButton.rect.width, exitButton.rect.height));
  erect.setPosition(exitButton.rect.left, exitButton.rect.top);
  c = sf::Color::Blue;
  c.a = 125;
  erect.setFillColor(c);
  sf::RectangleShape prect(
      sf::Vector2f(playButton.rect.width, playButton.rect.height));
  prect.setPosition(playButton.rect.left, playButton.rect.top);
  c = sf::Color::Red;
  c.a = 125;
  prect.setFillColor(c);

  window.draw(sprite);
  window.draw(erect);
  window.draw(prect);
  window.display();

  return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y) {
  auto retit =
      find_if(begin(mmenuItems), end(mmenuItems), [x, y](MenuItem &m) -> bool {
        bool iny = m.rect.top + m.rect.height > y && m.rect.top < y;
        bool inx = m.rect.left < x && m.rect.left + m.rect.width > x;
        return iny && inx;
      });
  return retit != end(mmenuItems) ? retit->action : MenuResult::Nothing;
}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow &window) {
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
