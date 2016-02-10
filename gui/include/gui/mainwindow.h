#pragma once
#include "gui/gui.h"
#include "util/enum.h"

namespace gui {


class MainWindow {
public:
  MainWindow();
  MainWindow(MainWindow const&) = delete;
  MainWindow& operator=(MainWindow const&) = delete;

  DEF_ENUM_IN_CLASS(GameState,
    Uninitialized,
    ShowingSplash,
    Paused,
    ShowingMenu,
    Playing,
    Exiting
  );


  void Start();

  AbsRect GetAbsRectFromRel( RelRect r );

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
