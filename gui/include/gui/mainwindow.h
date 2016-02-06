#pragma once
#include "gui/gui.h"
#include "gui/hexboard.h"
#include "gui/hud.h"

namespace gui {
typedef int GameObjectManager;
class MainWindow {
public:
  void Start();

  gui::Rect getRelRect(double relx, double rely, double relheight,
                       double relwidth);

private:
  sf::Event getInput();
  bool IsExiting();
  void GameLoop();

  void ShowSplashScreen();
  void ShowMenu();

  enum class GameState {
    Uninitialized,
    ShowingSplash,
    Paused,
    ShowingMenu,
    Playing,
    Exiting
  };

  GameState gameState = GameState::Uninitialized;
  ;
  sf::RenderWindow renderWindow;
  GameObjectManager gameObjectManager;
  HexBoard hexBoard;
  HUD hud;
};
extern MainWindow *mainWindow;
}
