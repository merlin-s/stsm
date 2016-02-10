#include "mainwindow.h"
#include "gui/fontmanager.h"
#include "gui/texturecache.h"
#include "hexagon.h"
#include "mainmenu.h"
#include "util/debug.h"

#include <iostream>

namespace gui {
const int INIT_SCREEN_WIDTH = 1024;
const int INIT_SCREEN_HEIGHT = 768;
MainWindow *mainWindow = 0;

MainWindow::MainWindow(){

}

void MainWindow::Start(void) {
  runtime_assert(gameState == GameState::Uninitialized, "invalid gamestate");
  FontManager::init();
  renderWindow.create(sf::VideoMode(INIT_SCREEN_WIDTH, INIT_SCREEN_HEIGHT, 32),
                      "STSM");
  // mainWindow.SetFramerateLimit(60);
  gameState = GameState::ShowingSplash;
  while (!IsExiting()) {
    GameLoop();
  }
  renderWindow.close();
}

bool MainWindow::IsExiting() {
  if (gameState == GameState::Exiting)
    return true;
  else
    return false;
}

sf::Event MainWindow::getInput() {
  static sf::Event currentEvent;
  renderWindow.pollEvent(currentEvent);
  return currentEvent;
}

#pragma GCC push
#pragma GCC diagnostic ignored "-Wswitch"
void MainWindow::GameLoop() {
  sf::Event currentEvent;
  const float scrollSpeed = 6.f;
  if (!renderWindow.pollEvent(currentEvent))
    return;
  switch (gameState) {
  case GameState::ShowingMenu: {
    ShowMenu();
    break;
  }
  case GameState::ShowingSplash: {
    ShowSplashScreen();
    gameState = GameState::ShowingMenu;
    break;
  }
  case GameState::Playing: {
    renderWindow.clear(sf::Color(0, 0, 0));
    // hexBoard.draw(renderWindow);
    renderWindow.display();
    // float scrollX = hexBoard.getScrollX();
    // float scrollY = hexBoard.getScrollY();
    switch (currentEvent.type) {
    case sf::Event::Closed: {
      gameState = GameState::Exiting;
      break;
    }
    case sf::Event::KeyPressed: {
      switch (currentEvent.key.code) {
      case sf::Keyboard::Escape: {
        gameState = GameState::ShowingMenu;
        break;
      }
        // case sf::Keyboard::Left: {
        //   scrollX += scrollSpeed;
        //   break;
        // }
        // case sf::Keyboard::Up: {
        //   scrollY += scrollSpeed;
        //   break;
        // }
        // case sf::Keyboard::Right: {
        //   scrollX -= scrollSpeed;
        //   break;
        // }
        // case sf::Keyboard::Down: {
        //   scrollY -= scrollSpeed;
        //   break;
        // }
      }
      // hexBoard.setScrollPos(scrollX, scrollY);
      break;
    }
    case sf::Event::MouseButtonReleased: {
      // hexBoard.handleClick(currentEvent.mouseButton, currentEvent.type);
      break;
    }
    case sf::Event::MouseButtonPressed: {
      // hexBoard.handleClick(currentEvent.mouseButton, currentEvent.type);
      break;
    }
    default:
      break;
    }
    break;
  }
  }
}
#pragma GCC pop

AbsRect MainWindow::GetAbsRectFromRel(RelRect r) {
  AbsRect ret;
  auto v = renderWindow.getSize();
  ret.left = gui::AbsType(r.left * v.x);
  ret.top = gui::AbsType(r.top * v.y);
  ret.height = gui::AbsType(r.height * v.y);
  ret.width = gui::AbsType(r.width * v.x);
  return ret;
}

void MainWindow::ShowSplashScreen() {
  sf::Sprite sprite = TextureCache::getSprite("splashscreen.png");

  renderWindow.draw(sprite);
  renderWindow.display();

  sf::Event event;
  while (true) {
    while (renderWindow.pollEvent(event)) {
      if (event.type == sf::Event::EventType::KeyPressed ||
          event.type == sf::Event::EventType::MouseButtonPressed ||
          event.type == sf::Event::EventType::Closed) {
        return;
      }
    }
  }
}

void MainWindow::ShowMenu() {
  MainMenu mainMenu;
  MenuResult result = mainMenu.Show(renderWindow);

  switch (result) {
  case MenuResult::Exit:
    gameState = GameState::Exiting;
    break;
  case MenuResult::Play:
    gameState = GameState::Playing;
    break;
  }
}
}
