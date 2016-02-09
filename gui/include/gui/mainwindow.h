#pragma once
#include "gui/gui.h"
#include "util/enum.h"

namespace gui {


class MainWindow {
public:
  DEF_ENUM_IN_CLASS(GameState,
    Uninitialized,
    ShowingSplash,
    Paused,
    ShowingMenu,
    Playing,
    Exiting
  );


  void Start();

  AbsRect getRelRect(double relx, double rely, double relheight,
                     double relwidth);

private:
  sf::Event getInput();
  bool IsExiting();
  void GameLoop();

  void ShowSplashScreen();
  void ShowMenu();

  GameState gameState = GameState::Uninitialized;
  sf::RenderWindow renderWindow;
};
extern MainWindow *mainWindow;
}
